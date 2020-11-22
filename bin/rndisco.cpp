// RNDisco.cpp           Red Neuronal de Disco.....

#include "RNDisco.h"
#include <string.h>



RedNeuDisco::RedNeuDisco(char* far arch, int form, unsigned com)
   {
         Abierto = 1;
         Comienzo = com;
	 Form = form;
	 NumNeuronas =0;
	 NumConexiones =0;
	 if (form)
	  {
	   Archivo. open(arch,ios::out);
	   Archivo <<"UN_Neuro\n";
	   Archivo << "                                          "<< endl;
	  }
	 else
	  {
	   Archivo.open(arch,ios::in);
	   if (Archivo)
	   {
	    char temp[256];
            Archivo.getline(temp,254);
            if (strcmp(temp,"UN_Neuro"))
             Abierto = 0;
	    else Archivo >> NumNeuronas >> NumConexiones;
           };
	  };
	 Abierto = Archivo.good() && Abierto;
   };

RedNeuDisco::~RedNeuDisco()
	{
	 if (Abierto)
	 {
	  if (Form)
	  {
	   Archivo.seekp(12,ios::beg);
	   Archivo << NumNeuronas << "   " << NumConexiones;
	  };
	  Archivo.close();
	};
   };


void RedNeuDisco::copiar(RedNeu& far destino)
 {
  unsigned IDCorrido=0;
  Neurona n;
  Conexion c;
  for(unsigned i=1; i<=NumNeuronas; i++)
  {
   n.readOn(Archivo);
   IDCorrido = n.getID() + Comienzo;
   n.putID(IDCorrido);
   destino.add(n);
  };
  for(i=1; i<=NumConexiones; i++)
  {
	c.readOn(Archivo);
	IDCorrido = c.getDesde() + Comienzo;
   c.putDesde(IDCorrido);
   IDCorrido = c.getHasta() + Comienzo;
   c.putHasta(IDCorrido);
   destino.add(c);
  };
 };
