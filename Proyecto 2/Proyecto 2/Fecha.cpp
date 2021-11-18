#include "Fecha.h"

Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), annio(a) {}
Fecha::~Fecha() {}

void Fecha::setAnnio(int a) { annio = a; }
int Fecha::getAnnio() { return annio; }

void Fecha::setMes(int m) { mes = m; }
int Fecha::getMes() { return mes; }

void Fecha::setDia(int d) { dia = d; }
int Fecha::getDia() { return dia; }

string Fecha::toString() const {
	stringstream s;
	if (dia < 10){
		s << "0";
	}
	s << dia << "/";
	if (mes < 10) {
		s << "0";
	}
	s << mes << "/" << annio;
	return s.str();
}
