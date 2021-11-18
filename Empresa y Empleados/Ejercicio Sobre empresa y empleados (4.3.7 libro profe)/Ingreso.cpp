#include "Ingreso.h"

Ingreso::Ingreso() {
	salarioNetoMensual = 0.0;
	valorTotalPrestamo = 0.0;
	interesFijo = 18; // Es un 18% anual..
	numAnios = 0;
	numCuotasTotales = 0;
	numCuotasCanceladas = 0;
}

Ingreso::Ingreso(double SalNM, double vTP, int anios, int nCT, int nCC) {
	salarioNetoMensual = SalNM;
	valorTotalPrestamo = vTP;
	interesFijo = 18;
	numAnios = anios;
	numCuotasTotales = nCT;
	numCuotasCanceladas = nCC;
}

Ingreso::~Ingreso() {}

// ACCESORES - get's
float Ingreso::getSalarioNetoMensual() { return salarioNetoMensual; }
float Ingreso::getValorTotalPrestamo() { return valorTotalPrestamo; }
float Ingreso::getInteresFijo() { return interesFijo; }
int Ingreso::getNumAnios() { return numAnios; }
int Ingreso::getNumCuotrasTotales() { return numCuotasTotales; }
int Ingreso::getNumCuotasCanceladas() { return numCuotasCanceladas; }

// MUTADORES - set's
void Ingreso::setSalarioNetoMensual(double SalNM) { salarioNetoMensual = SalNM; }
void Ingreso::setValorTotalPrestamo(double vTP) { valorTotalPrestamo = vTP; }
void Ingreso::setInteresFijo(double inteF) { interesFijo = inteF; }
void Ingreso::setAnios(int anios) { numAnios = anios; }
void Ingreso::setNumCuotasTotales(int nCT) { numCuotasTotales = nCT; }
void Ingreso::setNumCuotasCanceladas(int nCC) { numCuotasCanceladas = nCC; }

// Metodos de Calculo..
double Ingreso::ganancia() {
	return valorTotalPrestamo * (interesFijo / 100) * numAnios;
}

double Ingreso::valorCuotaMensual() {
	return (valorTotalPrestamo + ganancia()) / numCuotasTotales;
}

// toString();
string Ingreso::toString() {
	stringstream s;
	s << "-----------INFORMACION DEL INGRESO---------" << endl
		<< "El Salario Neto es de: " << salarioNetoMensual << " colones." << endl
		<< "El valor total del prestamo es de: " << valorTotalPrestamo << " colones." << endl
		<< "El interes fijo, es de: " << interesFijo << "% anual." << endl // Es un 18% anual..
		<< "El tiempo de prestamo es de: " << numAnios << "anios." << endl
		<< "El total de cuotas del prestamo es de: " << numCuotasTotales << " cuotas." << endl
		<< "El numero de cuotas canceladas es de: " << numCuotasCanceladas << endl;
	return s.str();
}