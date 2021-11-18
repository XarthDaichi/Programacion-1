#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

//La clase Familia contiene, numHijos y un vector de las edades de estos hijos, nombre de la 
//esposa y su cedula.


class Familia {
   private:
	   int numHijos;
	   int* vecEdades;  // Vector para crear en tiempo de ejecución..
	   string nombrePareja;
	   string cedulaPareja;
   public:
	   Familia();
	   Familia(int numH, string nP, string cP);
	   virtual ~Familia();
	   void llenadoDelVectorDeEdadesDeHijos();
	   // void incrementoDeHijoEnFamilia();
	   // ACCESORES- get's
	   // MUTADORES- set´s.
	   bool existenHijosMayoresDe12Anios();
	   // ToString();
	   string toString();
};