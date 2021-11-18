#include"Estudiante.h"

Estudiante::Estudiante(string ced, string nom, string carr, int ed): Persona(ced, nom), carrera(carr), edad(ed){}
Estudiante::~Estudiante(){}
string Estudiante::toString() const{
	stringstream s;
	  s << "------------ESTUDIANTE--------------" << endl
		<< "   Cedula..." << cedula << endl
		<< "   Nombre..." << nombre << endl
		<< "   Carrera.." << carrera << endl
		<< "   Edad....." << edad << " anios." << endl;
	return s.str();
}