#pragma once
#include "Hora.h"

class Dia {
private:
	int dia;
	int annio;
	Hora* *vec;
public:
	// CONSTRUCTOR Y DESTRUCTOR
	Dia(int, int);
	virtual ~Dia();

	// ACCESORES Y MUTADORES
	Hora* getHora(int);

	// Metodo para pasar de numero dia a una fecha (mes-dia-annio)
	string DiaAFecha(int, int);
	void setAnnio(int);
	int getAnnio();

	// toString
	string toString() const;
};