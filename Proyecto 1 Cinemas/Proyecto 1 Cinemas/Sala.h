#pragma once
#include "Dia.h"

class Sala {
private:
	string nombre;
	char tipoSala;
	Dia* *vec;
public:
	// CONSTRUCTOR Y DESTRUCTOR
	Sala(string, int, char = 'r');
	virtual ~Sala();

	// ACCESORES Y MUTADORES
	string getNombre();

	void setTipoSala(char);
	char getTipoSala();

	Dia* getDia(int);

	// toString
	string toString() const;
};