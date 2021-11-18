#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Ingreso {
private:
	double salarioNetoMensual;
	double valorTotalPrestamo;
	double interesFijo;
	int numAnios;
	int numCuotasTotales;
	int numCuotasCanceladas;
public:
	Ingreso();
	Ingreso(double, double, int, int, int);
	virtual ~Ingreso();

	// ACCESORES - get's
	float getSalarioNetoMensual();
	float getValorTotalPrestamo();
	float getInteresFijo();
	int getNumAnios();
	int getNumCuotrasTotales();
	int getNumCuotasCanceladas();

	// MUTADORES - set's
	void setSalarioNetoMensual(double);
	void setValorTotalPrestamo(double);
	void setInteresFijo(double);
	void setAnios(int);
	void setNumCuotasTotales(int);
	void setNumCuotasCanceladas(int);

	// Metodos de calculo..
	double ganancia();
	double valorCuotaMensual();

	// toString();
	string toString();
};