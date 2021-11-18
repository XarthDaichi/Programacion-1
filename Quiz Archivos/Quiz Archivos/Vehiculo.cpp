#include "Vehiculo.h"

Vehiculo::Vehiculo(string mar, string mod, int cili) : marca(mar), modelo(mod), cilindrada(cili) {}
Vehiculo::~Vehiculo() {}

void Vehiculo::setMarca(string mar) { marca = mar; }
string Vehiculo::getMarca() { return marca; }

void Vehiculo::setModelo(string mod) { modelo = mod; }
string Vehiculo::getModelo() { return modelo; }

void Vehiculo::setCilindrada(int cili) { cilindrada = cili; }
int Vehiculo::getCilindrada() { return cilindrada; }

string Vehiculo::toString() {
	stringstream s;
	s << "Marca: " << marca << endl
		<< "Modelo: " << modelo << endl
		<< "Cilindrada: " << cilindrada << endl;
	return s.str();
}
