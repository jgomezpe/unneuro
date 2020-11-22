// RNDisco.h     Red Neuronal de disco............


#if !defined( __RNDISCO_H)
#define __RNDISCO_H

#if !defined( __FSTREAM_H )
#include <fstream.h>
#endif  // __FSTREAM_H

#if !defined( __REDNEU_H )
#include "RedNeu.h"
#endif  // __redeneu_H


class  _EXPORT RedNeuDisco: public RedNeu
 {
  private:
   fstream Archivo;
   int Abierto,Form,Comienzo;
   unsigned NumNeuronas, NumConexiones;
  public:
   RedNeuDisco(char far * arch, int form, unsigned com);
   ~RedNeuDisco();
   virtual int add(const Neurona& far origen)
   {
	NumNeuronas++;
	origen.printOn(Archivo);
	return Archivo.good();
   };
   virtual int add(const Conexion& far origen)
   {
	NumConexiones++;
	origen.printOn(Archivo);
	return Archivo.good();
   };
   virtual void copiar(RedNeu&  destino);
   virtual unsigned numNeuronas(){ return NumNeuronas; };
   virtual unsigned numConexiones() { return NumConexiones; };
   virtual int getAbierto()     { return Abierto; };
   enum {entrada,salida};
 };

#endif // __RNDISCO_H
