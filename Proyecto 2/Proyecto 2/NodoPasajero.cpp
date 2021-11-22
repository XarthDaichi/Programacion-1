#include "NodoPasajero.h"

NodoPasajero::NodoPasajero(Pasajero* pas, NodoPasajero* sig): pasajero(pas), siguiente(sig) {}
NodoPasajero::~NodoPasajero() {
	if (pasajero) delete pasajero;
}

void NodoPasajero::setPasajero(Pasajero* pas) {
	if (pasajero) delete pasajero;
	pasajero = pas;
}
Pasajero* NodoPasajero::getPasajero() { return pasajero; }

void NodoPasajero::setSiguiente(NodoPasajero* sig) { 
	if (siguiente) delete siguiente;
	siguiente = sig; 
}
NodoPasajero* NodoPasajero::getSiguiente() { return siguiente; }

string NodoPasajero::toString() const {
	stringstream s;
	s << "---PASAJERO---" << endl
		<< pasajero->toString() << endl;
	return s.str();
}