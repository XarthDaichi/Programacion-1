#include "Persona.h"

Persona::Persona(string ced, string nom, int ed) : nombre(nom), cedula(ced), edad(ed) {}

Persona::~Persona() {}

void Persona::setNombre(string nom) { nombre = nom; }
string Persona::getNombre() { return nombre; }

void Persona::setCedula(string ced) { cedula = ced; }
string Persona::getCedula() { return cedula; }

void Persona::setEdad(int ed) { edad = ed; }
int Persona::getEdad() { return edad; }
