#include "Director.h"

Director::Director() {
	id = "INDEFINIDO";
	nombre = "INDEFINIDO";
	calificacion = 0;
	calificacionTemp = 0;
	cantPeliculas = 0;
}

Director::Director(string i, string nom) {
	id = i;
	nombre = nom;
	calificacion = 0;
	calificacionTemp = 0;
	cantPeliculas = 0;
}

Director::Director() {}

void Director::setId(string i) { id = i; }

string Director::getId() { return id; }

void Director::setNombre(string nom) { nombre = nom; }

string Director::getNombre() { return nombre; }

void Director::hizoPelicula() { cantPeliculas++; }
void Director::eliminarPelicula() { cantPeliculas--; }

void Director::updateCalificacion(float cal) {
	calificacionTemp += cal;
	if (cantPeliculas == 0) {
		calificacion = 0;
	}
	else {
		calificacion = (float) calificacionTemp / cantPeliculas;
	}
}

string Director::toString() {
	stringstream s;
	s << "Identificacion... " << id << endl
		<< "Nombre... " << nombre << endl
		<< "Calificacion... " << calificacion << endl;
	return s.str();
}