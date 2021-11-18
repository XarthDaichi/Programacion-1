#include "Pelicula.h"

// CONSTRUCTOR
Pelicula::Pelicula(string gen, string nom, string sinop, bool nin) : genero(gen), nombre(nom), sinopsis(sinop), paraNinnos(nin) {}
// DESTRUCTOR
Pelicula::~Pelicula() {}

// ACCESORES Y MUTADORES
void Pelicula::setGenero(string gen) { genero = gen; }
string Pelicula::getGenero() { return genero; }

void Pelicula::setNombre(string nom) { nombre = nom; }
string Pelicula::getNombre() { return nombre; }

void Pelicula::setSinopsis(string sinop) { sinopsis = sinop; }
string Pelicula::getSinopsis() { return sinopsis; }

void Pelicula::setParaNinnos(bool nin) { paraNinnos = nin; }
bool Pelicula::getParaNinnos() { return paraNinnos; }

// toString
string Pelicula::toString() const {
	stringstream s;
	s << "Nombre... " << nombre << endl
		<< "Genero... " << genero << endl
		<< "Sinopsis... " << sinopsis << endl;
	if (paraNinnos) {
		s << "Para ninnos" << endl;
	}
	else {
		s << "Para adultos" << endl;
	}
	return s.str();
}