#include"ProfUniversitario.h"

ProfUniversitario::ProfUniversitario(string ced, string nom, int nH, bool prop, string GA)
:Trabajador(ced,nom,nH),propiedad(prop),gradoAcademico(GA){
}

ProfUniversitario::~ProfUniversitario(){
}

string ProfUniversitario::toString() const{
	stringstream s;
	s << "-------------PROFESOR UNIVERSITARIO-----------------" << endl
		<< "Cedula: " << cedula << endl
		<< "Nombre: " << nombre << endl
		<< "Numero de hijos..." << numHijos << endl;
	for (int i = 0; i < numHijos; i++) {
		s << "Edad " << i + 1 << ": " << vecEdadesHijos[i] << endl;
	}
	if (propiedad) {
		s << "Si tiene propiedad." << endl;
	}
	else {
		s << "No tiene propiedad." << endl;
	}
	s << "Grado Academico: " << gradoAcademico << endl;

	return s.str();
}

