#include "Pasajero.h"
Pasajero::Pasajero(string ced, string nom, int ed, string cod) : Persona(ced, nom, ed), codigo(cod) {}
Pasajero::~Pasajero() {}

void Pasajero::setNombre(string nom) { nombre = nom; }
string Pasajero::getNombre() { return nombre; }

void Pasajero::setCedula(string ced) { cedula = ced; }
string Pasajero::getCedula() { return cedula; }

void Pasajero::setEdad(int ed) { edad = ed; }
int Pasajero::getEdad() { return edad; }

void Pasajero::setCodigo(string cod) { codigo = cod; }
string Pasajero::getCodigo() { return codigo; }


string Pasajero::toString() const{
	stringstream s;
	s << "Cedula: " << cedula << endl
		<< "Nombre: " << nombre << endl
		<< "Edad: " << edad << endl
		<< "Codigo: " << codigo << endl;
	return s.str();
}