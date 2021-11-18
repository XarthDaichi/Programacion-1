#include"AdmUniversitario.h"

AdmUniversitario::AdmUniversitario(string ced, string nom, int NH, string titul, int AL)
: Trabajador(ced,nom,NH), titulo(titul),aniosLaborales(AL){
}

AdmUniversitario::~AdmUniversitario() {
}

string AdmUniversitario::toString() const {
		stringstream s;
		s << "-------------ADMINISTRADOR UNIVERSITARIO-----------------" << endl
			<< "Cedula: " << cedula << endl
			<< "Nombre: " << nombre << endl
			<< "Numero de hijos..." << numHijos << endl;
		for (int i = 0; i < numHijos; i++) {
			s << "Edad " << i + 1 << ": " << vecEdadesHijos[i] << endl;
		}
		s << "Titulo: " << titulo << endl
			<< "Anios Laborando: " << aniosLaborales << endl;

		return s.str();
}