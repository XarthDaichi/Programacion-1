#include "Persona.h"

// CONSTRUCTOR Y DESTRUCTOR
Persona::Persona(string nom, string iden, float pes, float esta, int annio, char gen){
	nombre = nom;
	id = iden;
	peso = pes;
	estatura = esta;
	annioNacimiento = annio;
	genero = gen;

	vacPtr = NULL;
}
Persona::~Persona(){
	if (vacPtr != NULL) delete vacPtr;
}

// MUTADORES Y ACCESORES
void Persona::setNombre(string nom) { nombre = nom; }
string Persona::getNombre() { return nombre; }

void Persona::setId(string iden) { id = iden; }
string Persona::getId() { return id; }

void Persona::setPeso(float pes) { peso = pes; }
float Persona::getPeso() { return peso; }

void Persona::setEstatura(float esta) { estatura = esta; }
float Persona::getEstatura() { return estatura; }

void Persona::setAnnioNacimiento(int annio) { annioNacimiento = annio; }
int Persona::getAnnioNacimiento() { return annioNacimiento; }

void Persona::setGenero(char gen) { genero = gen; }
char Persona::getGenero() { return genero; }

void Persona::setVacuna(Vacuna* vac) {
	if (vacPtr != NULL) delete vacPtr;
	vacPtr = vac;
}
Vacuna* Persona::getVacuna() { return vacPtr; }


// toSTRINGS()
string Persona::toStringSimple(){
	stringstream s;
	s << "Nombre... " << nombre << endl
		<< "Id... " << id << endl;
	return s.str();
}
string Persona::toString() {
	stringstream s;
	s << "Nombre... " << nombre << endl
		<< "Id... " << id << endl
		<< "Peso.. " << peso << endl
		<< "Estatura..." << estatura << endl
		<< "Annio de nacimiento... " << annioNacimiento << endl
		<< "Genero... ";
	if (genero == 'm' || genero == 'M') {
		s << "Mujer" << endl;
	}
	else {
		s << "Hombre" << endl;
	}
	return s.str();
}