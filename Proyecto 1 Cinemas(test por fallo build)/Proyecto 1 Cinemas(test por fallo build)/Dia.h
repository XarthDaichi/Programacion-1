#pragma once
#include "Hora.h"

class Dia {
private:
	int dia;
	int annio;
	Hora* vec[3];
public:
	Dia(int, int);
	virtual ~Dia();

	Hora* getHora(int);

	string DiaAFecha(int, int);
	void setAnnio(int);
	int getAnnio();

	string toString() const;
};