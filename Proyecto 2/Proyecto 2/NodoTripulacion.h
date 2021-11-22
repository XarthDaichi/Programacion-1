#pragma once
#include "Piloto.h"
#include "Sobrecargo.h"

class NodoTripulacion {
private:
	Piloto* piloto;
	Sobrecargo* sobrecargo;
	NodoTripulacion* siguiente;
public:
	NodoTripulacion(Piloto*, Sobrecargo*, NodoTripulacion*);
	virtual ~NodoTripulacion();

	void setPiloto(Piloto*);
	Piloto* getPiloto();

	void setSobrecargo(Sobrecargo*);
	Sobrecargo* getSobrecargo();

	void setSiguiente(NodoTripulacion*);
	NodoTripulacion* getSiguiente();

	string toString() const;
};