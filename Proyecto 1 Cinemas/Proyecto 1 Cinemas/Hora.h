#pragma once
#include "Asiento.h"
#include "Funcion.h"

class Hora {
private:
	string tiempo;
	Funcion* fun;
	Asiento* mat[6][10];
	int disponible;
public:
	// CONSTRUCTOR Y DESTRUCTOR
	Hora(string);
	virtual ~Hora();

	// ACCESORES Y MUTADORES
	string getTiempo();

	void setFuncion(Funcion*);
	Funcion* getFuncion();

	Asiento* getAsiento(char, int);

	void compraronAsiento(int);
	int getDisponible();

	// toStrings
	string toString() const; // Funcion y disponibilidad
	string toStringDespuesCompra() const; // Solo Funcion
	string toStringAsientos() const; // para la matriz de asientos
};
