#include "Contenedor.h"

// INICIALIZACION DE VARIABLES STATIC
int Contenedor::personasVacunadas = 0;
float Contenedor::porcentajeVacunado = 0;
float Contenedor::porcentajeNoVacunado = 0;


Contenedor::Contenedor(int tama){
	tam = tama;
	cant = 0;
	vec = new Persona * [tam];
	for (int i = 0; i < tam; i++) {
		vec[i] = NULL;
	}
}
Contenedor::~Contenedor(){
	for (int i = 0; i < cant; i++) {
		if (vec[i] != NULL) delete vec[i];
	}
	delete[] vec;
}

// MUTADORES Y ACCESORES
int Contenedor::getCant() { return cant; }

// INGRESAR AL VECTOR
bool Contenedor::ingresarPaciente(Persona* per){
	int tempPos;
	if (cant < tam) {
		if (pacienteExiste(per->getId(), tempPos)) {
			cout << "El paciente ya existe." << endl;
			return false;
		}
		else {
			vec[cant++] = per;
			return true;
		}
	}
	else {
		return false;
	}
}
bool Contenedor::pacienteExiste(string ced, int& pos){
	for(int i = 0; i < cant; i++) {
		if (vec[i]->getId() == ced) {
			pos = i;
			return true;
		}
	}
	return false;
}

// VACUNAR PACIENTE
bool Contenedor::pacienteVacunado(string ced) {
	for (int i = 0; i < cant; i++) {
		if (vec[i]->getId() == ced) {
			if (vec[i]->getVacuna() != NULL) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
bool Contenedor::vacunarPaciente(string ced, Vacuna* vac) {
	int pos;
	if (pacienteExiste(ced, pos)) {
		if (!pacienteVacunado(ced)) {
			vec[pos]->setVacuna(vac);
			personasVacunadas++;
			updatePorcentajeVacunado();
			updatePorcentajeNoVacunado();
			return true;
		}
		else {
			cout << "Paciente ya esta vacunado." << endl;
			return false;
		}
	}
	else {
		cout << "Paciente no existe." << endl;
		return false;
	}
}

// TOSTRINGS()
string Contenedor::toString(){
	stringstream s;
	for (int i = 0; i < cant; i++) {
		s << vec[i]->toStringSimple();
		if (vec[i]->getVacuna() != NULL) {
			s << "Si esta vacunado." << endl << endl;
		}
		else {
			s << "No esta vacunado." << endl << endl;
		}
	}
	return s.str();
}
string Contenedor::toStringPacienteEspecifico(string ced){
	stringstream s;
	for (int i = 0; i < cant; i++) {
		if (vec[i]->getId() == ced) {
			s << vec[i]->toString();
			if (vec[i]->getVacuna() != NULL) {
				s << vec[i]->getVacuna()->toString() << endl;
			}
			return s.str();
		}
	}
	return "No se encontro";
}
string Contenedor::toStringMujeresVacunadas(){
	stringstream s;
	for (int i = 0; i < cant; i++) {
		if (vec[i]->getVacuna() != NULL) {
			if (vec[i]->getGenero() == 'm' || vec[i]->getGenero() == 'M') {
				s << vec[i]->toStringSimple() << endl;
			}
		}
	}
	return s.str();
}
string Contenedor::toStringHombresVacunados(){
	stringstream s;
	for (int i = 0; i < cant; i++) {
		if (vec[i]->getVacuna() != NULL) {
			if (vec[i]->getGenero() == 'h' || vec[i]->getGenero() == 'H') {
				s << vec[i]->toStringSimple() << endl;
			}
		}
	}
	return s.str();
}
string Contenedor::toSringCasaComercial(string casaCom){
	stringstream s;
	for (int i = 0; i < cant; i++) {
		if (vec[i]->getVacuna() != NULL) {
			if (vec[i]->getVacuna()->getCasaComercial() == casaCom) {
				s << vec[i]->toStringSimple() << endl;
			}
		}
	}
	return s.str();
}

// PORCENTAJES
int Contenedor::getPersonasVacunadas() { return personasVacunadas; }

void Contenedor::updatePorcentajeVacunado(){
	if (cant != 0) {
		porcentajeVacunado = (float)personasVacunadas / cant;
	}
	else {
		porcentajeVacunado = 0;
	}
}
float Contenedor::getPorcentajeVacunado() { return porcentajeVacunado; }

void Contenedor::updatePorcentajeNoVacunado(){
	if (cant != 0) {
		porcentajeNoVacunado = (float)(cant - personasVacunadas) / cant;
	}
	else {
		porcentajeNoVacunado = 0;
	}
}
float Contenedor::getPorcentajeNoVacunado() { return porcentajeNoVacunado; }