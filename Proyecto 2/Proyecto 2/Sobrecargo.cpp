#include "Sobrecargo.h"

Sobrecargo::Sobrecargo(string ced, string nom, int ed, string tit, string telC, int grad) : Tripulacion(ced, nom, ed), titulo(tit), telCelular(telC), grado(grad) {}
Sobrecargo::~Sobrecargo() {}

void Sobrecargo::setTitulo(string tit) { titulo = tit; }
string Sobrecargo::getTitulo() { return titulo; }

void Sobrecargo::setTelCelular(string telC) { telCelular = telC; }
string Sobrecargo::getTelCelular() { return telCelular; }

void Sobrecargo::setGrado(int grad) { grado = grad; }
int Sobrecargo::getGrado() { return grado; }

string Sobrecargo::toString() {
	stringstream s;
	s << "Cedula: " << cedula << endl
		<< "Nombre: " << nombre << endl
		<< "Edad: " << edad << endl
		<< "Titulo: " << titulo << endl
		<< "Telefono Celular: " << telCelular << endl
		<< "Grado: " << grado << endl;
	return s.str();
}
