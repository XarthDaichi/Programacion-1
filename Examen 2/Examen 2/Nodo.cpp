#include "Nodo.h"

Nodo::Nodo() {
	per = NULL;
	sig = NULL;
}

Nodo::Nodo(SuperClass* pe, Nodo* si) {
	per = pe;
	sig = si;
}

Nodo::~Nodo() {
	if (per != NULL) delete per;
	if (sig != NULL) delete sig;
}

void Nodo::setPersona(SuperClass* pe) {
	per = pe;
}

SuperClass* Nodo::getPersona() {
	return per;
}

void Nodo::setNodoSiguiente(Nodo* si) {
	sig = si;
}

Nodo* Nodo::getNodoSiguiente() {
	return sig;
}

string Nodo::toString() const {
	stringstream s;
	s << per->toString() << endl;
	return s.str();
}