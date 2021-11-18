#include "Persona.h"

// Zona que inicializa en algun valor las variables static...
int Persona::cantidadPersonas = 0;
int Persona::sumaEdades = 0;
double Persona::promedioDeEdades = 0;
//-----------------------------fin de la inicializacion---------------

Persona::Persona(string nom, int ed) :nombre(nom), edad(ed) {
	cantidadPersonas++;
	sumaEdades += edad;
	calcularPromedioDeEdades();
}

Persona::~Persona() {
	cantidadPersonas--;
	sumaEdades -= edad;
	calcularPromedioDeEdades();
}

string Persona::leeNombre() {
	return nombre;
}

int Persona::leeEdad() {
	return edad;
}
double Persona::leePromedioEdades() {
	return promedioDeEdades;
}
int Persona::leeCantidadDePersonas() {
	return cantidadPersonas;
}
int Persona::leeSumaDeEdades() {
	return sumaEdades;
}
void Persona::modificarEdad(int ed) { // no son static pero si pueden trabajar
	sumaEdades -= edad;               // variables static.
	edad = ed;
	sumaEdades += edad;
	calcularPromedioDeEdades();
}
void Persona::calcularPromedioDeEdades() {
	if (cantidadPersonas == 0) {
		promedioDeEdades = 0;
	}
	else {
		promedioDeEdades = (double) sumaEdades / cantidadPersonas;
	}
}