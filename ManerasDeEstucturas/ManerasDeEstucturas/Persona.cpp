#include "Persona.h"

// Definicion de la clase
Persona::Persona(string ced = "Indefinida", string nom = "Indefinido") : cedula(ced), nombre(nom) {}
Persona:: ~Persona() {}

void Persona::setNombre(string nom) { nombre = nom; }
string Persona::toString() {
	stringstream s;
	s << "----------PERSONA-------";
	s << "Cedula... " << cedula << endl;
	s << "Nombre... " << nombre << endl << endl;
	return s.str();
}

void cambioSuNombre(Persona& per2) {
	string nomNuevo;
	cin >> nomNuevo;
	per2.setNombre(nomNuevo);
}

// Declara una funcion /Procedimiento
void cambiaNombre(Persona&);

int main() {

}

void cambiaNombre(Persona& per1) {
	string nom;
	cout << "ingrese el cambio de nombre... ";
	cin >> nom;
	per1.setNombre(nom);
}