#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Ruta {
private:
	string origen;
	string destino;
	string duracion;
	string cantidadDeEscalas;
	double valorPasajeros;
public:
	Ruta(string, string, string, string, double);
	virtual ~Ruta();

	void setOrigen(string);
	string getOrigen();

	void setDestino(string);
	string getDestino();

	void setDuracion(string);
	string getDuracion();

	void setCantidadDeEscalas(string);
	string getCantidadDeEscalas();

	void setValorPasajeros(double);
	double getValorPasajeros();

	string toString() const;
};