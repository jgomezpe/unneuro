//  RNSim.cpp     Red Neuronal De Simulacion.....


#include "RNSim.h"

float far funcSigmoide(float suma)
{
 return (1/(1+exp(-suma)));
};

float far funcLineal(float suma)
{
 return (suma);
};


float far funcTanh(float suma)
{
 return (tanh(suma));
};




void NeuronaSim::printOn(ostream& s)const
 {
  Neurona::printOn(s);
  s<<"sal:"<<salida<<endl;
 };

void ConexionSim::printOn(ostream& s)const
 {
  Conexion::printOn(s);
 };


RedNeuSim::~RedNeuSim()
  {
   if (Conexiones!=NULL)
   {
    delete[] Conexiones;
   };
   if (Neuronas!=NULL) 	 delete[] Neuronas;
   if (ConexionesHasta!=NULL) delete[] ConexionesHasta;
  };

ConexionSim& RedNeuSim::consulta(unsigned desde,unsigned hasta)const
{
 for(int i=0; i<NumConexiones; i++)
   if (Conexiones[i].getDesde()==desde && Conexiones[i].getHasta()==hasta)
    return Conexiones[i];
 return (ConexionSim&) ConexionSim();
};

void RedNeuSim::cadaNeurona(iterFuncType actionPtr, void *paramList)
{
 for(int i=0;i<NumNeuronas;i++)
 {
  (* actionPtr)(Neuronas[i], paramList);
 };
}


void RedNeuSim::cadaConexion(iterFuncType actionPtr, void *paramList)
{
 for(int i=0;i<NumConexiones;i++)
 {
  (* actionPtr)(Conexiones[i], paramList);
 };
}


void RedNeuSim::copiar(RedNeu&  destino)
{
 unsigned i;
 Neurona n;
 Conexion c;
 if (NumNeuronas>0)
  for(i=0;i<NumNeuronas;i++)
   {
	 n=Neuronas[i];
	 destino.add(n);
   };
 if (NumConexiones>0)
  for(i=0;i<NumConexiones;i++)
	{
	 c=Conexiones[i];
	 c.putDesde(c.getDesde()+1);
	 c.putHasta(c.getHasta()+1);
    destino.add(c);
   };
};

int RedNeuSim::add(const Neurona &  origen)
  {
   if (NumNeuronas >= MaxNeuronas) return 0;
	Neuronas[NumNeuronas++] = NeuronaSim(origen);
   return 1;
  };

int RedNeuSim::add(const Conexion &  origen)
  {
   if (NumConexiones >= MaxConexiones) return 0;
   Conexiones[NumConexiones++] =(ConexionSim&)origen;
   return 1;
  };

int RedNeuSim::putMaxConexiones(unsigned nuevo)
{
 ConexionSim * mat;
 unsigned * mat1;
 if (Conexiones!=NULL) delete[] Conexiones;
 if (ConexionesHasta!=NULL) delete[] ConexionesHasta;
 mat = new ConexionSim[nuevo];
 mat1= new unsigned[nuevo];
 Conexiones = mat;
 ConexionesHasta = mat1;
 NumConexiones = 0;
 if (mat == NULL)
 {
  if (mat1!=NULL)
  {
   ConexionesHasta=NULL;
   delete[] mat1;
  };
  MaxConexiones = 0;
  return 1;
 };
 if (mat1 == NULL)
 {
  if (mat!=NULL)
  {
   Conexiones = NULL;
   delete[] mat;
  };
  MaxConexiones = 0;
  return 1;
 };
 MaxConexiones = nuevo;
 return 0;
};

int RedNeuSim::putMaxNeuronas(unsigned nuevo)
{
 NeuronaSim * mat;
 if (Neuronas!=NULL) delete[] Neuronas;
 mat = new NeuronaSim[nuevo];
 Neuronas = mat;
 NumNeuronas = 0;
 if (mat == NULL)
 {
  MaxNeuronas = 0;
  return 1;
 };
 MaxNeuronas = nuevo;
 return 0;
};


void RedNeuSim::printOn(ostream& sal)
{
 sal<<"Entradas="<<NumEntradas<<"  Salidas="<<NumSalidas<<endl;
 for(int i=0;i<NumNeuronas;i++)
  Neuronas[i].printOn(sal);
 cin.get();
 for(i=0;i<NumConexiones;i++)
  Conexiones[i].printOn(sal);
 cin.get();
 for(i=0;i<NumConexiones;i++)
  sal<<i<<' '<<ConexionesHasta[i]<<endl;
 cin.get();
};


int far RNEntFunComCon(const void  *c1, const void  *c2)
{
 if ( ((Conexion *)c1)->getHasta() < ((Conexion *)c2)->getHasta() )
  return -1;
 if ( ((Conexion *)c1)->getHasta() > ((Conexion *)c2)->getHasta() )
  return  1;

  return 0;
 };




void RedNeuSim::intercambiar(unsigned a, unsigned b)
{
 NeuronaSim n;
 n=Neuronas[a];
 Neuronas[a]=Neuronas[b];
 Neuronas[b]=n;
};


int RedNeuSim::verifica(unsigned i, unsigned *iden)
{
 unsigned j;
 if(Neuronas[i].nConexionesEnt==0) return -1;
 for( j = Neuronas[i].apunConexionesEnt;
      j < Neuronas[i].apunConexionesEnt + Neuronas[i].nConexionesEnt;
      j++)
  if(iden[Conexiones[j].getDesde()]>=i) return iden[Conexiones[j].getDesde()];
 return -1;
};

int  RedNeuSim::ordena()
{
 unsigned i, cont, apun;
 int j;
 unsigned *iden;

// Ordena vector de conexiones segun 'hasta'.....
 qsort( (void *)Conexiones, NumConexiones, sizeof(ConexionSim), RNEntFunComCon);
// Llena campo conexiones de entrada de las neuronas....
 j=Conexiones[0].getHasta();
 cont=1;
 apun=0;
 for(i=1;i<NumConexiones;i++)
 {
  if (Conexiones[i].getHasta()!=j)
   {
     Neuronas[j-1].nConexionesEnt=cont;
     Neuronas[j-1].apunConexionesEnt=apun;
     j=Conexiones[i].getHasta();
     cont=0;
     apun=i;
    };
  cont++;
 };
 Neuronas[j-1].nConexionesEnt=cont;
 Neuronas[j-1].apunConexionesEnt=apun;
// Ordena vector de neuronas.........
 iden=new unsigned[NumNeuronas+1];
 for(i=1;i<=NumNeuronas;i++) iden[i]=i-1;
 NumEntradas = NumSalidas = j = 0;

//Cambia identificadores...
 for(i=0;i<NumNeuronas;i++)
  Neuronas[i].putID(iden[Neuronas[i].getID()]+1);
 for(i=0;i<NumConexiones;i++)
  {
   Conexiones[i].putDesde(iden[Conexiones[i].getDesde()]);
   Conexiones[i].putHasta(iden[Conexiones[i].getHasta()]);
  };

// Borra iden y retorna 0....
 delete[] iden;
 return 0;

 };


int  RedNeuSimBP::ordena()
{
 unsigned i, cont, apun;
 int j;
 unsigned *iden;

// Ordena vector de conexiones segun 'hasta'.....
 qsort( (void *)Conexiones, NumConexiones, sizeof(ConexionSim), RNEntFunComCon);
// Llena campo conexiones de entrada de las neuronas....
 j=Conexiones[0].getHasta();
 cont=1;
 apun=0;
 for(i=1;i<NumConexiones;i++)
 {
  if (Conexiones[i].getHasta()!=j)
   {
     Neuronas[j-1].nConexionesEnt=cont;
     Neuronas[j-1].apunConexionesEnt=apun;
     j=Conexiones[i].getHasta();
     cont=0;
     apun=i;
    };
  cont++;
 };
 Neuronas[j-1].nConexionesEnt=cont;
 Neuronas[j-1].apunConexionesEnt=apun;
// Ordena vector de neuronas.........
 iden=new unsigned[NumNeuronas+1];
 for(i=1;i<=NumNeuronas;i++) iden[i]=i-1;
 NumEntradas = NumSalidas = j = 0;

//Ubica neuronas entrada al principio.....
 while(j<NumNeuronas)
  {
   if (Neuronas[j].Tipo==0)
    {
     intercambiar(NumEntradas,j);
     iden[Neuronas[NumEntradas].ID]=NumEntradas;
     iden[Neuronas[j].ID]=j;
     NumEntradas++;
    };
   j++;
  };


//Ubica Neuronas salida al final....
 j=NumNeuronas-1;
 while(j >= 0)
  {
   if (Neuronas[j].Tipo==2)
    {
     NumSalidas++;
     intercambiar(NumNeuronas-NumSalidas,j);
     iden[Neuronas[NumNeuronas-NumSalidas].ID]=NumNeuronas-NumSalidas;
     iden[Neuronas[j].ID]=j;
    };
   j--;
  };

//Ordena neuronas ocultas......
 if (NumEntradas+NumSalidas != NumNeuronas)
 {
  char * vecNeu= new char[NumNeuronas];
  for(i=NumEntradas;i<NumNeuronas-NumSalidas;i++)
  {
    for(j=0;j<NumNeuronas;vecNeu[j++]=0);
    j=1;
    while (j!=-1)
    {
     j=verifica(i,iden);
     if (j!=-1)
     {
      if (vecNeu[Neuronas[j].ID])
      {
       delete[] vecNeu;
       delete[] iden;
       return 1;
      };
      vecNeu[Neuronas[j].ID]=1;
      intercambiar(j,i);
      iden[Neuronas[i].ID]=i;
      iden[Neuronas[j].ID]=j;
     };
    };
  };
  delete[] vecNeu;
 };


//Cambia identificadores...
 for(i=0;i<NumNeuronas;i++)
  Neuronas[i].putID(iden[Neuronas[i].getID()]+1);
 for(i=0;i<NumConexiones;i++)
  {
   Conexiones[i].putDesde(iden[Conexiones[i].getDesde()]);
   Conexiones[i].putHasta(iden[Conexiones[i].getHasta()]);
  };

// Borra iden y retorna 0....
 delete[] iden;
 return 0;
 };

void  RedNeuSim::propaga(float * vector)
{
 unsigned i,j;
 float sum;
 for(i=0;i<NumNeuronas;i++)
 {
  sum=0;
  if(Neuronas[i].Tipo!=0 || Neuronas[i].nConexionesEnt!=0 )
  {
   if(Neuronas[i].nConexionesEnt!=0)
    for(j=Neuronas[i].apunConexionesEnt;
	j<Neuronas[i].apunConexionesEnt+Neuronas[i].nConexionesEnt;j++)
     sum += Neuronas[Conexiones[j].getDesde()].salida*Conexiones[j].getPeso();
    Neuronas[i].anterior=Neuronas[i].funcTransf(sum+Neuronas[i].Umbral);
  }
  else Neuronas[i].anterior=Neuronas[i].salida;
 };
 for(i=0;i<NumNeuronas;i++)
  Neuronas[i].salida=Neuronas[i].anterior;
};


void  RedNeuSimBP::propaga(float * vector)
{
 unsigned i,j;
 float sum;
 if (vector != NULL)
  for(i=0;i<NumEntradas;i++)
   Neuronas[i].salida=vector[i];
 for(i=NumEntradas;i<NumNeuronas;i++)
 {
  sum=0;
  if(Neuronas[i].nConexionesEnt!=0)
   for(j=Neuronas[i].apunConexionesEnt;
       j<Neuronas[i].apunConexionesEnt+Neuronas[i].nConexionesEnt;j++)
    sum += Neuronas[Conexiones[j].getDesde()].salida*Conexiones[j].getPeso();
  Neuronas[i].salida=Neuronas[i].funcTransf(sum+Neuronas[i].Umbral);
 };
};


void  RedNeuSimBP::salidas(float * vector)
{
 unsigned i;
 if (vector != NULL)
  for(i=NumNeuronas-NumSalidas;i<NumNeuronas;i++)
   vector[i-NumNeuronas+NumSalidas] = Neuronas[i].salida;
};


