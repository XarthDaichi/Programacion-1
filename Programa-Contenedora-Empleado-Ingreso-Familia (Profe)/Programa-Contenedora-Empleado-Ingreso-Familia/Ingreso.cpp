#include"Ingreso.h"

Ingreso::Ingreso(){
	salarioNeto = 0.0;
	valoraTotalPrestamo = 0.0 ;
	interesFijo = 18.000;  // Es un 18% anual..
	numAnios = 0;
	numCuotasTotales = 0;
	numCuotasCanceladas = 0;
}   

Ingreso::Ingreso(double sN, double vTP, int nA, int nCT, int nCC){
	salarioNeto = sN;
	valoraTotalPrestamo = vTP;
	interesFijo = 18.000;
	numAnios = nA;
	numCuotasTotales = nCT;
	numCuotasCanceladas = nCC;
}

Ingreso::~Ingreso(){
}

// ACCESORES
double Ingreso::getSalarioNeto() { return salarioNeto; }
//  MUTADORES.
//  Métodos de cálculo..

double Ingreso::ganancia(){
	return valoraTotalPrestamo * (interesFijo / 100) * numAnios;
}

double Ingreso::valorCuotaMensual(){
	return (valoraTotalPrestamo + ganancia()) / numCuotasTotales;
}



// toString
string Ingreso::toString(){
	stringstream s;
	s << "--------------INFORMACION DEL INGRESO------------------" << endl
	  << "El salario Neto es de: "<<salarioNeto<<" colones."<<endl
	  << "El valor total del prestamo es de: " << valoraTotalPrestamo << " colones." << endl
	  << "El interes fijo, es de " << interesFijo << endl  // Es un 18% anual..
	  << "El tiempo de prestamo es de: " << numAnios<< "anios" << endl
	  << "El total de cuotas del prestamo es de: " << numCuotasTotales << " cuotas." << endl
	  << "El numero de cuotas canceladas, es de: " << numCuotasCanceladas <<endl;
	return s.str();
}