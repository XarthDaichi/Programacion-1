#pragma once
#include "Vuelo.h"

class NodoVuelo {
private:
	Vuelo* vuelo;
	NodoVuelo* siguiente;
public:
	NodoVuelo(Vuelo*, NodoVuelo*);
	virtual ~NodoVuelo();

	void setVuelo(Vuelo*);
	Vuelo* getVuelo();

	void setSiguiente(NodoVuelo*);
	NodoVuelo* getSiguiente();

	string toString(ContenedorLTripulacion*, ContenedorLRuta*) const;
};