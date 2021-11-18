#include "Persona.h"

Persona::Persona(string ced, string nom, int ed) {
	cedula = ced;
	nombre = nom;
	edad = ed;
}

Persona::~Persona() {}

// Accesores (get's)
string Persona::getCedula() { return cedula; }

string Persona::getNombre() { return nombre; }

int Persona::getEdad() { return edad; }

// Mutadores (set's)
void Persona::setCedula(string ced) { cedula = ced; }

void Persona::setNombre(string nom) { nombre = nom; }

void Persona::setEdad(int ed) { edad = ed; }

string Persona::toString() const {
	stringstream s;
	s << "Cedula... " << cedula << endl 
		<< "Nombre... " << nombre << endl
		<< "Edad... " << edad << endl;
	return s.str();
}