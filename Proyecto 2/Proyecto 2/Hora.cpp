#include "Hora.h"
Hora::Hora(int ho, int min) : hora(ho), minuto(min) {}
Hora::~Hora() {}

void Hora::setHora(int ho) { hora = ho;}
int Hora::getHora() { return hora; }

void Hora::setMinuto(int min) { minuto = min; }
int Hora::getMinuto() { return minuto; }

string Hora::toString() const {
	stringstream s;
	if (hora < 10) {
		s << "0";
	}
	s << hora << ":";
	if (minuto < 10) {
		s << "0";
	}
	s << minuto;
	return s.str();
}