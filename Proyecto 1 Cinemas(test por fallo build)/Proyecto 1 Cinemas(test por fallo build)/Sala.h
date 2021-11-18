#pragma once
#include "Dia.h"

class Sala {
private:
	string nombre;
	char tipoSala;
	Dia* vec[366];
public:
	Sala(string, int, char = 'r');
	virtual ~Sala();

	// ACCESORES Y MUTADORES
	string getNombre();

	void setTipoSala(char);
	char getTipoSala();

	Dia* getDia(int);

	string toString() const;
};