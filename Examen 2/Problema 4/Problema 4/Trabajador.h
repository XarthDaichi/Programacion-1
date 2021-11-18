#pragma once
#include"Persona.h"

class Trabajador : public Persona {
   protected:
	   int* vecEdadesHijos;
	   int numHijos;
   public:
	   Trabajador(string, string, int);
	   virtual ~Trabajador();
	   void llenarVecDeEdades();
	   virtual string toString() const = 0;
};
