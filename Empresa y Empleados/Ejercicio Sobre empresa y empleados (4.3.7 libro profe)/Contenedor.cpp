#include "Contenedor.h"

Contenedor::Contenedor(int val) {
	vec = new Empleado * [val];
	tam = val;
	can = 0;
	for (int i = 0; i < tam; i++) {
		vec[i] = NULL;
	}
}

Contenedor::~Contenedor() {
	for (int i = 0; i < can; i++) {
		if (vec[i]) delete vec[i];
	}
	delete[] vec;
}

bool Contenedor::ingresaEmpleado(Empleado* per) {
	if (can < tam) {
		vec[can++] = per;
		return true;
	}
	else {
		return false;
	}
}

string Contenedor::toString() const {
	stringstream s;
	s << "--------------LISTADO DE EMPLEADOS----------------" << endl;
	for (int i = 0; i < can; i++) {
		s << vec[i]->toString() << endl;
	}
	return s.str();
}