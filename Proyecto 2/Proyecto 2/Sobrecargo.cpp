#include "Sobrecargo.h"

Sobrecargo::Sobrecargo(string ced, string nom, int ed, string cod, string tit, string telC, string grad) : Tripulacion(ced, nom, ed, cod), titulo(tit), telCelular(telC), grado(grad) {}
Sobrecargo::~Sobrecargo() {}

void Sobrecargo::setNombre(string nom) { nombre = nom; }
string Sobrecargo::getNombre() { return nombre; }

void Sobrecargo::setCedula(string ced) { cedula = ced; }
string Sobrecargo::getCedula() { return cedula; }

void Sobrecargo::setEdad(int ed) { edad = ed; }
int Sobrecargo::getEdad() { return edad; }

void Sobrecargo::setTitulo(string tit) { titulo = tit; }
string Sobrecargo::getTitulo() { return titulo; }

void Sobrecargo::setTelCelular(string telC) { telCelular = telC; }
string Sobrecargo::getTelCelular() { return telCelular; }

void Sobrecargo::setGrado(string grad) { grado = grad; }
string Sobrecargo::getGrado() { return grado; }

void Sobrecargo::setCodigo(string cod) { codigo = cod; }
string Sobrecargo::getCodigo() { return codigo; }

string Sobrecargo::toString() const {
	stringstream s;
	s << "Cedula: " << cedula << endl
		<< "Nombre: " << nombre << endl
		<< "Edad: " << edad << endl
		<< "Titulo: " << titulo << endl
		<< "Telefono Celular: " << telCelular << endl
		<< "Grado: " << grado << endl
		<< "Codigo: " << codigo << endl;
	return s.str();
}
