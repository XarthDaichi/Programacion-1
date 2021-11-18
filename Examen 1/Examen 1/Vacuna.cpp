#include "Vacuna.h"

// CONSTRUCTOR Y DESTRUCTOR
Vacuna::Vacuna(int numDeLot, int numDeSer, string casaCom, string fechaV, string fechaA){
	casaComercial = casaCom;
	numeroDeLote = numDeLot;
	numeroDeSerie = numDeSer;
	fechaVencimiento = fechaV;
	fechaAplicada = fechaA;
}
Vacuna::~Vacuna(){}

// MUTADORES Y ACCESORES
void Vacuna::setCasaComercial(string casaCom) { casaComercial = casaCom; }
string Vacuna::getCasaComercial() { return casaComercial; }

void Vacuna::setNumeroDeLote(int numDeLot) { numeroDeLote = numDeLot; }
int Vacuna::getNumeroDeLote() { return numeroDeLote; }

void Vacuna::setNumeroDeSerie(int numDeSer) { numeroDeSerie = numDeSer; }
int Vacuna::getNumeroDeSerie() { return numeroDeSerie; }

void Vacuna::setFechaVencimiento(string fechaV) { fechaVencimiento = fechaV; }
string Vacuna::getFechaVencimiento() { return fechaVencimiento; }

void Vacuna::setFechaAplicada(string fechaA) { fechaAplicada = fechaA; }
string Vacuna::getFechaAplicada() { return fechaAplicada; }

// toString()
string Vacuna::toString(){
	stringstream s;
	s << "Numero De Lote... " << numeroDeLote << endl
		<< "Numero De Serie... " << numeroDeSerie << endl
		<< "Casa Comercial... " << casaComercial << endl
		<< "Fecha de Vencimiento... " << fechaVencimiento << endl
		<< "Fecha de Aplicacion... " << fechaAplicada << endl;
	return s.str();
}