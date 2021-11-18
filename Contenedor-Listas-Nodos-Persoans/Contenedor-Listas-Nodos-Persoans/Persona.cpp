#include"Persona.h"

Persona::Persona() {
	nombre = "";
	cedula = "";
	edad = 0;
}

Persona::Persona(string nom, string ced, int ed) {
	nombre = nom;
	cedula = ced;
	edad = ed;
}

Persona::~Persona() { cout << "Eliminando Persona"; }

string Persona::getNombre() { return nombre; }

string Persona::getCedula() { return cedula; }

int Persona::getEdad() { return edad; }

string Persona::toString() {
	stringstream s;
	s << "Nombre..." << nombre << endl
		<< "Cedula..." << cedula << endl
		<< "Edad....." << edad << endl << endl;
	return s.str();
}