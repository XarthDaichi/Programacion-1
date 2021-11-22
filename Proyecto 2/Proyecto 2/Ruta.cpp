#include "Ruta.h"

Ruta::Ruta(string ori, string des, string dur, int cantDE, double valPas, string cod, bool us) : origen(ori), destino(des), duracion(dur), cantidadDeEscalas(cantDE), valorPasajeros(valPas), codigo(cod), usada(us) {}
Ruta::~Ruta() {}

void Ruta::setOrigen(string ori) { origen = ori; }
string Ruta::getOrigen() { return origen; }

void Ruta::setDestino(string des) { destino = des; }
string Ruta::getDestino() { return destino; }

void Ruta::setDuracion(string dur) { duracion = dur; }
string Ruta::getDuracion() { return duracion; }

void Ruta::setCantidadDeEscalas(int cantDE) { cantidadDeEscalas = cantDE; }
int Ruta::getCantidadDeEscalas() { return cantidadDeEscalas; }

void Ruta::setValorPasajeros(double valPas) { valorPasajeros = valPas; }
double Ruta::getValorPasajeros() { return valorPasajeros; }

void Ruta::setCodigo(string cod) { codigo = cod; }
string Ruta::getCodigo() { return codigo; }

void Ruta::setUsada(bool us) { usada = us; }
bool Ruta::getUsada() { return usada; }

string Ruta::toString() const {
	stringstream s;
	s << "Origen: " << origen << endl
		<< "Destino: " << destino << endl
		<< "Duracion: " << duracion << endl
		<< "Cantidad De Escalas: " << cantidadDeEscalas << endl
		<< "Valor de Pasajeros: " << valorPasajeros << endl
		<< "Codigo: " << codigo << endl;
	if (usada) {
		s << "En uso" << endl;
	}
	else {
		s << "Ya no se usa" << endl;
	}
	return s.str();
}