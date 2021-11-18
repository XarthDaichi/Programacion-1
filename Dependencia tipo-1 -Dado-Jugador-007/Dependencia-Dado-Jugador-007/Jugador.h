#pragma once
#include"Dado.h"


class Jugador {
   private:
	   string nombre;
   public:
	   Jugador(string);
	   virtual ~Jugador();
	   void lanza(Dado& );  // Aquí se establece la relación de Dependencia.  
};