#include "Funcion.h"

Funcion::Funcion(char ti, int dim, string pa, Pelicula* pe) : tipoLenguaje(ti), dimensiones(dim), pais(pa), pel(pe) {}
Funcion::~Funcion() {}

void Funcion::setTipoLenguaje(char ti) { tipoLenguaje = ti; }
char Funcion::getTipoLenguaje() { return tipoLenguaje; }

void Funcion::setDimensiones(int dim) { dimensiones = dim; }
int Funcion::getDimensiones() { return dimensiones; }

void Funcion::setPais(string pa) { pais = pa; }
string Funcion::getPais() { return pais; }

void Funcion::setPelicula(Pelicula* pe) {
	if (pel != NULL) delete pel;
	pel = pe;
}
Pelicula* Funcion::getPelicula() { return pel; }

string Funcion::toString() const {
	stringstream s;
	if (pel != NULL) {
		s << pel->toString();
		if (tipoLenguaje == 's' || tipoLenguaje == 'S') {
			s << "Subtitulada" << endl;
		}
		else {
			s << "Doblada" << endl;
		}
		if (dimensiones == 2) {
			s << "Dimensiones: 2D" << endl;
		}
		else {
			s << "Dimensiones: 3D" << endl;
		}
		s << "Pais: " << pais << endl;
	}
	return s.str();
}