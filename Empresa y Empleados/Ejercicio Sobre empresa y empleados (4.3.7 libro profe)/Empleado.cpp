#include "Empleado.h"

Empleado::Empleado() {
	cedula = "INDEFINIDA";
	nombre = "INDEFINIDO";
	edad = 0;
	ptrFam = NULL;
	ptrIng = NULL;
}

Empleado::Empleado(string ced, string nom, int ed) {
	cedula = ced;
	nombre = nom;
	edad = ed;
	ptrFam = NULL;
	ptrIng = NULL;
}
Empleado::Empleado(string ced, string nom, int ed, Familia* ptrF, Ingreso* ptrI) {
	cedula = ced;
	nombre = nom;
	edad = ed;
	ptrFam = ptrF;
	ptrIng = ptrI;
}

Empleado::~Empleado() { // Eliminacion de huesos...
	if (ptrFam != NULL) delete ptrFam;
	if (ptrIng != NULL) delete ptrIng;
}

// ACCESORES -set's
// MUTADORES - get's
// ToString();
string Empleado::toString() {
	stringstream s;
	s << "------------INFORMACION DEL EMPLEADO---------------" << endl
		<< "La cedula es: " << cedula << endl
		<< "El nombre es: " << nombre << endl
		<< "La edad es: " << edad << " anios." << endl;
	if (ptrFam) {
		s << ptrFam->toString() << endl;
	}
	if (ptrIng) {
		s << ptrIng->toString() << endl;
	}
	return s.str();
}