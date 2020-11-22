//  RNSim.h     Red Neuronal De Simulacion.....
//


#if !defined( __RNSIM_H)
#define __RNSIM_H

#if !defined( __IOSTREAM_H )
#include <iostream.h>
#endif  // __IOSTREAM_H

#if !defined( __MATH_H )
#include <math.h>
#endif  // __MATH_H

#if !defined( __STDLIB_H )
#include <stdlib.h>
#endif  // __STDLIB_H


#if !defined( __REDNEU_H )
#include "RedNeu.h"
#endif  // __redeneu_H

#if !defined( __RNDISCO_H )
#include "RNDisco.h"
#endif  // __RNDISCO_H


class _EXPORT NeuronaSim;
class _EXPORT ConexionSim;

class  _EXPORT RedNeuSim : public RedNeu
{
 protected:
  ConexionSim *Conexiones;
  NeuronaSim  *Neuronas;
  unsigned    *ConexionesHasta;
  unsigned    NumNeuronas, NumConexiones, MaxNeuronas, MaxConexiones,
              NumEntradas,NumSalidas;

 public:
  RedNeuSim();
  virtual ~RedNeuSim();
  virtual void copiar(RedNeu&  destino);
  virtual int add(const Neurona & );
  virtual int add(const Conexion &);
  virtual unsigned numNeuronas();
  virtual unsigned numConexiones();
  virtual void cadaNeurona(iterFuncType actionPtr, void *paramList);
  virtual void cadaConexion(iterFuncType actionPtr, void *paramList);
  virtual NeuronaSim& consulta(unsigned ID)const;
  virtual ConexionSim& consulta(unsigned desde,unsigned hasta)const;
  virtual void cambiaSalida(unsigned ID, float valor);
  virtual int putMaxConexiones(unsigned nuevo);
  virtual int putMaxNeuronas(unsigned nuevo);
  virtual unsigned getMaxConexiones();
  virtual unsigned getMaxNeuronas();
  virtual unsigned getNumEntradas();
  virtual unsigned getNumSalidas();
  virtual void printOn(ostream& sal);
  virtual int ordena();
  virtual void intercambiar(unsigned a, unsigned b);
  virtual int verifica(unsigned i, unsigned * iden);
  virtual void propaga(float * vector=NULL);
  virtual float consultaSalida(unsigned ID);
};

class RedNeuSimBP: public RedNeuSim
{
 public:
  RedNeuSimBP();
  virtual ~RedNeuSimBP() {};
  virtual int ordena();
  virtual void propaga(float * vector=NULL);
  virtual void salidas(float * vector);
};

float far funcSigmoide(float suma);
float far funcLineal(float suma);
float far funcTanh(float suma);


typedef far float (* Funcion)(float);


class _EXPORT NeuronaSim: public Neurona , public Object
{
 protected:
  float    salida,anterior;
  unsigned nConexionesEnt;
  unsigned apunConexionesEnt;
  unsigned nConexionesSal;
  unsigned apunConexionesSal;
  Funcion  funcTransf;
 public:
  NeuronaSim(Neurona& n= Neurona(), unsigned nCEnt=0, unsigned aCEnt=0,
	     unsigned nCSal=0, unsigned aCSal=0): Neurona(n),
	     nConexionesEnt(nCEnt), apunConexionesEnt(aCEnt),
	     nConexionesSal(nCSal), apunConexionesSal(aCSal),
	     salida(0.0), anterior(0.0)
	     {
	      switch (FuncActiva)
	      {
	       case 1: funcTransf = funcTanh;
		       break;
	       case 2: funcTransf = funcLineal;
		       break;
	       default:funcTransf = funcSigmoide;
		       break;
	       };
	     };
  virtual void printOn(ostream& s)const;
  float getSalida()
  {
   return salida;
  };
   virtual classType isA() const { return 25002; };
   virtual hashValueType hashValue() const { return 0; };
   virtual char _FAR *nameOf() const { return "NeuronaSim"; };
   virtual int isEqual( const Object _FAR & neu) const
   {
    return ( ID == ((NeuronaSim &)neu).getID() );
   };
  friend RedNeuSim;
  friend RedNeuSimBP;
 };




class _EXPORT ConexionSim:public Conexion , public Object
{
 protected:
  float anterior;
 public:
  ConexionSim(Conexion & con= Conexion(), float ant = 0):
   Conexion(con), anterior(ant){};
   virtual classType isA() const { return 25003; };
   virtual hashValueType hashValue() const { return 0; };
   virtual char _FAR *nameOf() const { return "ConexionSim"; };
   virtual void printOn(ostream& s)const;
   virtual int isEqual( const Object _FAR & con) const
   {
    return ( desde == ((ConexionSim &)con).getDesde() &&
	     hasta == ((ConexionSim &)con).getHasta());
   };

 friend RedNeuSim;
};


inline RedNeuSim::RedNeuSim():NumNeuronas(0), NumConexiones(0), MaxNeuronas(0),
			   MaxConexiones(0), Neuronas(0), Conexiones(0),
			   NumEntradas(0), NumSalidas(0),
			   ConexionesHasta(0)
			   {};

inline unsigned RedNeuSim::numNeuronas()
{
 return NumNeuronas;
};

inline unsigned RedNeuSim::numConexiones()
{
 return NumConexiones;
};

inline NeuronaSim& RedNeuSim::consulta(unsigned ID)const
{
 return Neuronas[ID-1];
};

inline void RedNeuSim::cambiaSalida(unsigned ID, float valor)
{
 if (ID<=NumNeuronas)
  Neuronas[ID-1].salida=valor;
};

inline float RedNeuSim::consultaSalida(unsigned ID)
{
 if (ID<=NumNeuronas)
  return Neuronas[ID-1].salida;
 return 0.0;
};


inline unsigned RedNeuSim::getMaxConexiones()
{
 return MaxConexiones;
};


inline unsigned RedNeuSim::getNumEntradas()
{
 return NumEntradas;
};


inline unsigned RedNeuSim::getNumSalidas()
{
 return NumSalidas;
};


inline unsigned RedNeuSim::getMaxNeuronas()
{
 return MaxNeuronas;
};


inline RedNeuSimBP::RedNeuSimBP():RedNeuSim() {};

#endif 

