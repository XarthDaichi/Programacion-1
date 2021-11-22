#include "NodoTripulacion.h"

NodoTripulacion::NodoTripulacion(Piloto* pil, Sobrecargo* sob, NodoTripulacion* sig) : siguiente(sig) {
	if (pil != NULL && sob == NULL) {
		piloto = pil;
		sobrecargo = NULL;
	} else if (pil == NULL && sob != NULL) {
		piloto = NULL;
		sobrecargo = sob;
	} else {
		cout << "Error: no se pueden meter piloto y sobrecargo en el mismo nodo" << endl;
		piloto = NULL;
		sobrecargo = NULL;
	}
}
NodoTripulacion::~NodoTripulacion() {
	if (piloto) delete piloto;
	if (sobrecargo) delete sobrecargo;
}

void NodoTripulacion::setPiloto(Piloto* pil) {
	if (sobrecargo == NULL) {
		if (piloto) delete piloto;
		piloto = pil;
	}
	else {
		cout << "Error: no se puede ingresar piloto donde ya hay un sobrecargo" << endl;
	}
}
Piloto* NodoTripulacion::getPiloto() { return piloto; }

void NodoTripulacion::setSobrecargo(Sobrecargo* sob) {
	if (piloto == NULL) {
		if (sobrecargo) delete sobrecargo;
		sobrecargo = sob;
	}
	else {
		cout << "Error: no se puede ingresar sobrecargo donde ya hay un piloto" << endl;
	}
}
Sobrecargo* NodoTripulacion::getSobrecargo() { return sobrecargo; }

void NodoTripulacion::setSiguiente(NodoTripulacion* sig) { siguiente = sig; }
NodoTripulacion* NodoTripulacion::getSiguiente() { return siguiente; }

string NodoTripulacion::toString() const {
	stringstream s;
	if (piloto != NULL) s << "---PILOTO---" << endl << piloto->toString() << endl;
	else if (sobrecargo != NULL) s << "---SOBRECARGO---" << endl << sobrecargo->toString() << endl;
	else s << " ";
	return s.str();
}
