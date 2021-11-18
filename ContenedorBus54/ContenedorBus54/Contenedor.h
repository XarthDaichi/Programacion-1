#pragma once
#include "Bus.h"

// Aqui va la declaracion de la clase Contenedor

class Contenedor {
private:
	int tamanno;
	int cantidad;
	Bus* *vec;
public:
	Contenedor(int);
	virtual ~Contenedor();

	// Mutadores
	void setTama(int);
	void setCant(int);

	// Accesores
	int getTama();
	int setCant();

	// IngresarObjeto
	bool ingresarBus(Bus*);

	// toString()
	string toString();
};

