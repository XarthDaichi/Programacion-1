#pragma once
#include "Pasajero.h"

class NodoPasajero {
private:
	Pasajero* pasajero;
	NodoPasajero* siguiente;
public:
	NodoPasajero(Pasajero*, NodoPasajero*);
	virtual ~NodoPasajero();

	void setPasajero(Pasajero*);
	Pasajero* getPasajero();

	void setSiguiente(NodoPasajero*);
	NodoPasajero* getSiguiente();

	string toString() const;
};
