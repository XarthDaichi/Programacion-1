#include"Nodo.h"

Nodo::Nodo(Persona* per, Nodo* si) {
	ptr = per;  // aqui recibe la persona.
	sig = si;  // recibe lo que quiero que vea ese nodo.
}
Nodo::~Nodo() {
	if (ptr) delete ptr; // if(ptr != NULL) delete ptr;
}

Persona* Nodo::getPersona() {
	return ptr;
}
Nodo* Nodo::getSiguiente() {
	return sig;
}

void Nodo::setPersona(Persona* per) {
	if (ptr) delete ptr;
	ptr = per;
}
void Nodo::setSiguiente(Nodo* si) {
	if (sig) delete sig;
	sig = si;
}