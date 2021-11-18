#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Habitacion {
   private:
	   int numHabitacion;  // El numero de habitaci�n va desde 1, hasta el 24.
	   int numCamasAdult;  // Tiene dos (2) camas para adulto
	   int numCamasNinos;  // Tiene tres (3) camas para ni�os
	   char estado;        // O = Ocupado   D = Desocupado    M = Mantenimiento.
	   bool desc;          // desc (true/false) Si true, se debe aplicar 50% de descuento a las camas de ni�os.
   public:
	   Habitacion(int, int = 2, int = 3, char = 'D', bool = false);
	   virtual ~Habitacion();
	   void setNumHabitacion(int);
	   void setEstado(char);
	   void setDesc(bool);

	   int getNumHabitacion();
	   char getEstado();
	   bool getDesc();
	   string toString() const;
};