#include "Chofer.h"

Chofer::Chofer(string ced, string nom, int ed) {
	cedula = ced;
	nombre = nom;
	edad = ed;
}
Chofer::~Chofer() {}
// Mutadores (set's)
void Chofer::setCedula(string ced) { cedula = ced; }
void Chofer::setNombre(string nom) { nombre = nom; }
void Chofer::setEdad(int ed) { edad = ed; }
// Accesores (get's)
string Chofer::getCedula() { return cedula; }
string Chofer::getNombre() { return nombre; }
int Chofer::getEdad() { return edad; }
// toString()
string Chofer::toString() {
	stringstream s;
	s << "------------Chofer------------" << endl
		<< "Cedula...." << cedula << endl
		<< "Nombre...." << cedula << endl
		<< "Edad......" << edad << endl;
	return s.str();
}