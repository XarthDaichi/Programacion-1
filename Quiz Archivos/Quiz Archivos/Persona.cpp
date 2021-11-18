#include "Persona.h"

Persona::Persona(string ced, string nom) : _cedula(ced), _nombre(nom) {}
Persona::~Persona() {}

void Persona::setCedula(string ced) { _cedula = ced; }
string Persona::getCedula() { return _cedula; }

void Persona::setNombre(string nom) { _nombre = nom; }
string Persona::getNombre() { return _nombre; }

string Persona::toString() {
	stringstream s;
	s << "Cedula: " << _cedula << endl
		<< "Nombre: " << _nombre;
	return s.str();
}