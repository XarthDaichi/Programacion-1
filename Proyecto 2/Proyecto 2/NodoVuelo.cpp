#include "NodoVuelo.h"

NodoVuelo::NodoVuelo(Vuelo* vu, NodoVuelo* sig) : vuelo(vu), siguiente(sig) {}
NodoVuelo::~NodoVuelo() {
	if (vuelo) delete vuelo;
}

void NodoVuelo::setVuelo(Vuelo* vu) {
	if (vuelo) delete vuelo;
	vuelo = vu;
}
Vuelo* NodoVuelo::getVuelo() { return vuelo; }

void NodoVuelo::setSiguiente(NodoVuelo* sig) {
	if (siguiente) delete siguiente;
	siguiente = sig;
}
NodoVuelo* NodoVuelo::getSiguiente() { return siguiente; }

string NodoVuelo::toString(ContenedorLTripulacion* contT, ContenedorLRuta* contRu) const {
	stringstream s;
	s << "---Vuelo---" << endl
		<< vuelo->toString(contT, contRu) << endl;
	return s.str();
}