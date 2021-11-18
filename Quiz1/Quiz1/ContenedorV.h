#pragma once
#include "Persona.h"

class ContenedorV {
private:
	Persona** vec;
	int can;
	int tam;
public:
	ContenedorV(int);
	virtual ~ContenedorV();

	// Accesores (get's)
	int getCantidad();
	int getTamano();

	// Mutadores (set's)
	void setCantidad(int);


	string toString() const;

	void ingresaPersonaEnOrdenDeEdad(Persona*);
};