#include "Piloto.h"

Piloto::Piloto(string ced, string nom, int ed, string cod, string correo, char se) : Tripulacion(ced, nom, ed, cod), correoEl(correo), sexo(se) {}
Piloto::~Piloto() {}

void Piloto::setNombre(string nom) { nombre = nom; }
string Piloto::getNombre() { return nombre; }

void Piloto::setCedula(string ced) { cedula = ced; }
string Piloto::getCedula() { return cedula; }

void Piloto::setEdad(int ed) { edad = ed; }
int Piloto::getEdad() { return edad; }

void Piloto::setCorreo(string correo) { correoEl = correo; }
string Piloto::getCorreo() { return correoEl; }

void Piloto::setSexo(char se) { sexo = se; }
char Piloto::getSexo() { return sexo; }

void Piloto::setCodigo(string cod) { codigo = cod; }
string Piloto::getCodigo() { return codigo; }

string Piloto::toString() const {
	stringstream s;
	s << "Cedula: " << cedula << endl
		<< "Nombre: " << nombre << endl
		<< "Edad: " << edad << endl
		<< "Correo: " << correoEl << endl
		<< "Sexo: " << sexo << endl
		<< "Codigo: " << codigo << endl;
	return s.str();
}
