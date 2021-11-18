#include "Contenedor.h"

Contenedor::Contenedor(int tama) {
	vec = new Bus * [tama];
	cantidad = 0;
	tamanno = tama;
	
	// Limipar el vector...
	for (int i = 0; i < tamanno; i++) {
		vec[i] = NULL;
	}
}

Contenedor::~Contenedor() {
	for (int i = 0; i < cantidad; i++) {
		delete vec[i]; // Borrar objetos dinamicos dentro del vector
	}
	delete[] vec; // Eliminar el vector...
}

// Mutadores
void Contenedor::setTama(int tama) { tamanno = tama; }
void Contenedor::setCant(int cant) { cantidad = cant; }

// Accesores
int Contenedor::getTama() { return tamanno; }
int Contenedor::setCant() { return cantidad; }

// Ingresar objecto
bool Contenedor::ingresarBus(Bus* bus) {
	if (cantidad < tamanno) {
		vec[cantidad++] = bus;
		return true;
	}
	else {
		return false;
	}
}

// toString()
string Contenedor::toString() {
	stringstream s;
	s << "----------LISTADO DE BUSES-----------" << endl;
	for (int i = 0; i < cantidad; i++) {
		s << vec[i]->toString() << endl;
	}
	return s.str();
}