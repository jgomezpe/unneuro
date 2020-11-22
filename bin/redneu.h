// Clase Abstracta Red Neuronal

#if !defined( __REDNEU_H )
#define __REDNEU_H


#if !defined( __OBJECT_H )
#include <object.h>
#endif  // __Object_H


#define _EXPORT 

struct PosGrilla
{
 int X,Y;
};

class _EXPORT Neurona
 {
  protected:
   unsigned ID;
   double Umbral;
   unsigned Tipo;
   unsigned FuncActiva;
   unsigned FijoUmbral;
   PosGrilla POS;
  public:
   Neurona(): Tipo(0) , Umbral(0) , ID(0) , FuncActiva(0) , FijoUmbral(0)
   {
    POS.X=POS.Y=0;
   };
   Neurona(unsigned T, double U , unsigned FA, unsigned FU, PosGrilla P):
    Tipo(T) , Umbral(U) , ID(0) , FuncActiva(FA) , FijoUmbral(FU)
   { POS = P; };
   virtual ~Neurona(){};
   unsigned getTipo() { return Tipo; };
   double getUmbral() { return Umbral; };
   unsigned getID() { return ID; };
   unsigned getFuncActiva() { return FuncActiva; };
   unsigned getFijoUmbral() { return FijoUmbral; };
   PosGrilla getPOS() { return POS; };
   void putPOS( PosGrilla NewPOS ) { POS = NewPOS; };
   void putFijoUmbral( unsigned NewFU ) { FijoUmbral = NewFU; };
   void putFuncActiva( unsigned NewFA ) { FuncActiva = NewFA; };
   void putID( unsigned NewID ) { ID = NewID; };
   void putUmbral( double newUmbral) { Umbral = newUmbral; };
   void putTipo( unsigned newTipo) { Tipo = newTipo; };
   double activacion() { return 0; };
   void printOn( ostream& s) const
   { s<<ID<<' '<<Umbral<<' '<<Tipo<<' '<<FuncActiva<<' '<<FijoUmbral<<' '<<POS.X<<' '<<POS.Y<<endl; };
   void readOn(istream& e)
   { e>>ID>>Umbral>>Tipo>>FuncActiva>>FijoUmbral>>POS.X>>POS.Y; };
 };

class _EXPORT Conexion
{
 protected:
  unsigned desde,hasta;
  double peso;
  unsigned  fija;
 public:
  Conexion(unsigned d=0, unsigned h=0,
	   double p=0,unsigned char f=0):
	   desde(d),hasta(h),peso(p),fija(f){};
  virtual ~Conexion(){};
  unsigned getDesde()const {return desde;}
  unsigned getHasta()const {return hasta;}
  double   getPeso()const {return peso;}
  unsigned getFija()const {return fija;}
  void     putDesde(unsigned d){desde=d;}
  void     putHasta(unsigned h){hasta=h;}
  void     putPeso(double p) {peso=p;}
  void     putFija(unsigned char f){fija=f;}
  void printOn(ostream& s)   const
   { s<<desde<<' '<<hasta<<' '<<peso<<' '<<fija<<endl; };
  void readOn(istream& e)
   {e>>desde>>hasta>>peso>>fija; };
};




class _EXPORT RedNeu

{
 public:
  virtual ~RedNeu(){};
  virtual void copiar(RedNeu&  destino )=0;
  virtual int add(const Neurona & )=0;
  virtual int add(const Conexion &)=0;
  virtual unsigned numNeuronas()=0;
  virtual unsigned numConexiones()=0;
};

#endif //__REDNEU_H

