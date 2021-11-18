#include "Piloto.h"

Piloto::Piloto(string ced, string nom, int ed, string correo, char se) : Tripulacion(ced, nom, ed), correoEl(correo), sexo(se) {}
Piloto::~Piloto() {}

void Piloto::setCorreo(string correo) { correoEl = correo; }
string Piloto::getCorreo() { return correoEl; }

void Piloto::setSexo(char se) { sexo = se; }
char Piloto::getSexo() { return sexo; }

string Piloto::toString() {
	stringstream s;
	s << "Cedula: " << cedula << endl
		<< "Nombre: " << nombre << endl
		<< "Edad: " << edad << endl
		<< "Correo: " << correoEl << endl
		<< "Sexo: " << sexo << endl;
	return s.str();
}
