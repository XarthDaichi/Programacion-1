#include "Pelicula.h"

Pelicula::Pelicula() {
	codigo = "INDEFINIDO";
	nombre = "INDEFINIDO";
	genero = "INDEFINIDO";
	calificacion = 0;
	taquilla = 0;
	filantropia = 0;
	directorPtr = NULL;
}

Pelicula::Pelicula(string cod, string nom, string gen, float cal, float taq, Director* dir) {
	codigo = cod;
	nombre = nom;
	genero = gen;
	calificacion = cal;
	taquilla = taq;
	directorPtr = dir;
}

Pelicula::~Pelicula() {
	if (directorPtr != NULL) delete directorPtr;
}

string Pelicula::getCodigo() { return codigo; }
string Pelicula::getNombre() { return nombre; }
string Pelicula::getGenero() { return genero; }

void Pelicula::setCalificacion(float cal) { calificacion = cal; }
float Pelicula::getCalificacion() { return calificacion; }

void Pelicula::setTaquilla(float taq) { taquilla = taq; }
float Pelicula::getTaquilla() { return taquilla; }

void Pelicula::setFilantropia(float fil) { filantropia = fil; }
float Pelicula::getFilantropia() { return filantropia; }

void Pelicula::setDirector(Director* dir) {
	if (directorPtr != NULL) delete directorPtr;
	directorPtr = dir;
}
Director* Pelicula::getDirector() { return directorPtr; }

bool Pelicula::mismoDirector(Director* dir) { return directorPtr == dir; }

string Pelicula::toString() {

}