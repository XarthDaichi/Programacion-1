#include "ContenedorV.h"

ContenedorV::ContenedorV(int tama) {
	tam = tama;
	can = 0;
	vec = new Persona * [tam];
	for (int i = 0; i < tam; i++) {
		vec[i] = NULL;
	}
}

ContenedorV::~ContenedorV() {
	for (int i = 0; i < can; i++) {
		delete vec[i];
	}
	delete[] vec;
}

// Accesores (get's)
int ContenedorV::getCantidad() { return can; }
int ContenedorV::getTamano() { return tam; }

// Mutadores (set's)
void ContenedorV::setCantidad(int cant) { can = cant; }


string ContenedorV::toString() const {
	stringstream s;
	s << "-----CONTENEDOR DE PERSONAS-------" << endl;
	for (int i = 0; i < can; i++) {
		s << vec[i]->toString() << endl;
	}
	return s.str();
}

void ContenedorV::ingresaPersonaEnOrdenDeEdad(Persona* per) {
	if (can < tam) {
		vec[can++] = per;
		for (int i = 0; i < can; i++) {
			for (int j = i + 1; j < can; j++) {
				if (vec[i]->getEdad() > vec[j]->getEdad()) {
					Persona* temp = vec[i];
					vec[i] = vec[j];
					vec[j] = temp;
				}
			}
		}
	}
}