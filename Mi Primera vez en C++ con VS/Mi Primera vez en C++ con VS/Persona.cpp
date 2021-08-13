// Aqui es donde se define la clase Persona.
// Es darle "cuerpo" o desarrollar cada metodo...

#include"Persona.h"
#include <sstream>

Persona::Persona() { // constructor sin parametros
	cedula = "indefinida";
	nombre = "indefinido";
	edad = 0;
}

Persona::Persona(string ced, string nom, int ed) { // constructor con parametros        
	cedula = ced;
	nombre = nom;
	edad = ed;
}

Persona::~Persona() {
}

string Persona::getCedula() { return cedula; }

string Persona::getNombre() { return nombre; }

int Persona::getEdad() { return edad; }

void Persona::setCedula(string ced) { cedula = ced; }

void Persona::setNombre(string nom) { nombre = nom; }

void Persona::setEdad(int ed) { edad = ed; }

string Persona::toString() { // Pasa toda la informacion del objeto a una linea tipo string en un formato.
	stringstream s;
	s << "---------Persona----------" << endl;
	s << "Cedula......" << cedula << endl;
	s << "Nombre......" << nombre << endl;
	s << "Edad........" << edad << endl << endl;
	return s.str();
}
