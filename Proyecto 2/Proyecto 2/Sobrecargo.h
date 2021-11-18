#pragma once
#include "Tripulacion.h"

class Sobrecargo: public Tripulacion {
private:
	string titulo;
	string telCelular;
	int grado;
public:
	Sobrecargo(string, string, int, string, string, int);
	virtual ~Sobrecargo();

	void setTitulo(string);
	string getTitulo();

	void setTelCelular(string);
	string getTelCelular();

	void setGrado(int);
	int getGrado();

	virtual string toString();
};