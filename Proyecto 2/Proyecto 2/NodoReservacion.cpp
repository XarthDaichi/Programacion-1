#include "NodoReservacion.h"

NodoReservacion::NodoReservacion(Reservacion* res, NodoReservacion* sig) : reservacion(res), siguiente(sig) {}
NodoReservacion::~NodoReservacion() {
	if (reservacion) delete reservacion;
}

void NodoReservacion::setReservacion(Reservacion* res) {
	if (reservacion) delete reservacion;
	reservacion = res;
}
Reservacion* NodoReservacion::getReservacion() { return reservacion; }

void NodoReservacion::setSiguiente(NodoReservacion* sig) {
	if (siguiente) delete siguiente;
	siguiente = sig;
}
NodoReservacion* NodoReservacion::getSiguiente() { return siguiente; }

string NodoReservacion::toString(ContenedorLVuelo* contV, ContenedorLTripulacion* contT, ContenedorLRuta* contRu) const {
	stringstream s;
	s << "---RESERVACION---" << endl
		<< reservacion->toString(contV, contT, contRu) << endl; 
	return s.str();
}