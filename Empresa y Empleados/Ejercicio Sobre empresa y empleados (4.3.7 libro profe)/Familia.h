#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// La clase Familia contiene, numHijos y un vector de las edades de estos hijos, nombre de la 
// esposa y su cedula.


class Familia {
private:
	int numHijos;
	int* vecEdades; // Vector para crear en tiempo de ejecucion.
	string nombrePareja;
	string cedulaPareja;
public:
	Familia();
	Familia(int, string, string);
	virtual ~Familia();
	
	// ACCESORES - get's
	int getNumHijos();
	string getNombrePareja();
	string getCedulaPareja();
	
	// MUTADORES - set's
	void setNumHijos(int);
	void setNombrePareja(string);
	void setCedulaPareja(string);
	void llenadoDelVectorDeEdadesDeHijos();
	void incrementoDeHijoFamilia();
	
	// toString();
	string toString();
};