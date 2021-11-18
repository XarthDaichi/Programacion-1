#include "Pasajero.h"
Pasajero::Pasajero(string ced, string nom, int ed) : Persona(ced, nom, ed) {}
Pasajero::~Pasajero() {}

string Pasajero::toString() {
	stringstream s;
	s << "Cedula: " << cedula << endl
		<< "Nombre: " << nombre << endl
		<< "Edad: " << edad << endl;
	return s.str();
}