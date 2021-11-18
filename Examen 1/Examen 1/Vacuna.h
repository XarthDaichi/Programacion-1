#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


class Vacuna {
private:
	// casa comercial, numero de lote, numero de serie, fecha vencimineto, fecha aplicacion
	string casaComercial;
	int numeroDeLote;
	int numeroDeSerie;
	string fechaVencimiento;
	string fechaAplicada;
public:
	// CONSTRUCTOR Y DESTRUCTOR
	Vacuna(int, int, string, string, string);
	virtual ~Vacuna();

	// MUTADORES Y ACCESORES
	void setCasaComercial(string);
	string getCasaComercial();

	void setNumeroDeLote(int);
	int getNumeroDeLote();

	void setNumeroDeSerie(int);
	int getNumeroDeSerie();

	void setFechaVencimiento(string);
	string getFechaVencimiento();

	void setFechaAplicada(string);
	string getFechaAplicada();

	// toString()
	string toString();
};