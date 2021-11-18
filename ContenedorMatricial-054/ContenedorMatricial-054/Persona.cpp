#include"Persona.h"


Persona::Persona(string ced, string nom, int ed)
	:cedula(ced), nombre(nom), edad(ed) {
}

Persona::~Persona() {
}

void Persona::setCedula(string ced) { cedula = ced; }
void Persona::setNombre(string nom) { nombre = nom; }
void Persona::setEdad(int ed) { edad = ed; }

string Persona::toString() {
	stringstream s;
	s << "----------Persona-------------" << endl
		<< "Cedula..." << cedula << endl
		<< "Nombre..." << nombre << endl
		<< "Edad....." << edad << endl;
	return s.str();
}

bool Persona::esIgualA(const Persona& per2) {
	return  (cedula == per2.cedula && nombre == per2.nombre && edad == per2.edad);
}

string Persona::getCedula() { return cedula; }
string Persona::getNombre() { return nombre; }
int Persona::getEdad() { return edad; }