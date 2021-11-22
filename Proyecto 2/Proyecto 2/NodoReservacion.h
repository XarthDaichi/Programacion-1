#pragma once
#include "Reservacion.h"

class NodoReservacion {
private:
	Reservacion* reservacion;
	NodoReservacion* siguiente;
public:
	NodoReservacion(Reservacion*, NodoReservacion*);
	virtual ~NodoReservacion();

	void setReservacion(Reservacion*);
	Reservacion* getReservacion();

	void setSiguiente(NodoReservacion*);
	NodoReservacion* getSiguiente();

	string toString(ContenedorLVuelo*, ContenedorLTripulacion*, ContenedorLRuta*) const;
};