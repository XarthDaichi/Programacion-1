#include "Hora.h"

Hora::Hora(string ho) {
	tiempo = ho;
	fun = NULL;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			mat[i][j] = new Asiento();
		}
	}
	disponible = 60;
}
Hora::~Hora() {
	if (fun != NULL) delete fun;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			delete mat[i][j];
		}
	}
}

string Hora::getTiempo() { return tiempo; }

void Hora::setFuncion(Funcion* fu) {
	if (fun != NULL) delete fun;
	fun = fu;
}
Funcion* Hora::getFuncion() { return fun; }

Asiento* Hora::getAsiento(char fila, int columna) { return mat[fila - 'A'][columna - 1]; }

void Hora::compraronAsiento(int cant) {
	disponible -= cant;
}
int Hora::getDisponible() { return disponible; }

string Hora::toString() const {
	stringstream s;
	if (fun != NULL) {
		s << fun->toString();
		s << "Asientos Disponibles: " << disponible << endl;
	}
	else {
		s << "No hay pelicula a esta hora" << endl;
	}
	s << tiempo << ", ";
	return s.str();
}

string Hora::toStringDespuesCompra() const {
	stringstream s;
	if (fun != NULL) {
		s << fun->toString();
	}
	else {
		s << "No hay pelicula a esta hora" << endl;
	}
	s << tiempo << ", ";
	return s.str();
}

string Hora::toStringAsientos() const {
	stringstream s;
	for (int i = 1; i <= 10; i++) {
		s << " " << i << " " << '\t';
		if (i == 5) {
			s << " \t";
		}
	}
	s << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			s << mat[i][j]->toString() << '\t';
			if (j == 4) {
				s << "|\t";
			}
		}
		s << endl;
	}
	return s.str();
}
