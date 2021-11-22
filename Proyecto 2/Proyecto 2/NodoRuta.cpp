#include "NodoRuta.h"

NodoRuta::NodoRuta(Ruta* ru, NodoRuta* sig) : ruta(ru), siguiente(sig) {}
NodoRuta::~NodoRuta() {
	if (ruta) delete ruta;
}

void NodoRuta::setRuta(Ruta* ru) {
	if (ruta) delete ruta;
	ruta = ru;
}
Ruta* NodoRuta::getRuta() { return ruta; }

void NodoRuta::setSiguiente(NodoRuta* sig) {
	if (siguiente) delete siguiente;
	siguiente = sig;
}
NodoRuta* NodoRuta::getSiguiente() { return siguiente; }

string NodoRuta::toString() const {
	stringstream s;
	s << "---RUTA---" << endl
		<< ruta->toString() << endl;
	return s.str();
}