#include "Persona.h"

Persona::Persona(string ced, string nom): cedula(ced), nombre(nom) {}

Persona::~Persona() {}

string Persona::toString() {
	stringstream s;
	s << "-----Persona------" << endl
		<< "Cedula... " << cedula << endl
		<< "Nombre... " << nombre << endl;
	return s.str();
}