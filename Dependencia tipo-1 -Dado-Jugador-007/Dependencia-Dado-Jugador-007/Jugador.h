#pragma once
#include"Dado.h"


class Jugador {
   private:
	   string nombre;
   public:
	   Jugador(string);
	   virtual ~Jugador();
	   void lanza(Dado& );  // Aqu� se establece la relaci�n de Dependencia.  
};