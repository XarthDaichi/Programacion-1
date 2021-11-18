#include "Asiento.h"

Asiento::Asiento() {
	cedula = "";
	color = 'V';
}
Asiento::~Asiento() {}

void Asiento::setCedula(string ced) { cedula = ced; }
string Asiento::getCedula() { return cedula; }

void Asiento::setColor(char col) { color = col; }
char Asiento::getColor() { return color; }

string Asiento::toString() const {
	stringstream s;
	if (color == 'V') {
		s << RESET << "(" << VERDE << color << RESET ")";
	}
	else if (color == 'G') {
		s << RESET << "(" << GRIS << color << RESET ")";
	}
	else if (color == 'R') {
		s << RESET << "(" << ROJO << color << RESET ")";
	}
	return s.str();
}

