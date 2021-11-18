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
	Hora(string);
	virtual ~Hora();

	string getTiempo();

	void setFuncion(Funcion*);
	Funcion* getFuncion();

	Asiento* getAsiento(char, int);

	void compraronAsiento(int);
	int getDisponible();

	string toString() const;
	string toStringDespuesCompra() const;
	string toStringAsientos() const;
};
