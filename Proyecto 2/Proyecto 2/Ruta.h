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
	int cantidadDeEscalas;
	double valorPasajeros;
	string codigo;
	bool usada;
public:
	Ruta(string, string, string, int, double, string, bool);
	virtual ~Ruta();

	void setOrigen(string);
	string getOrigen();

	void setDestino(string);
	string getDestino();

	void setDuracion(string);
	string getDuracion();

	void setCantidadDeEscalas(int);
	int getCantidadDeEscalas();

	void setValorPasajeros(double);
	double getValorPasajeros();

	void setCodigo(string);
	string getCodigo();

	void setUsada(bool);
	bool getUsada();

	string toString() const;
};