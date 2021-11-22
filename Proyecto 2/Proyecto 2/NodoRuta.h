#pragma once
#include "Ruta.h"

class NodoRuta {
private:
	Ruta* ruta;
	NodoRuta* siguiente;
public:
	NodoRuta(Ruta*, NodoRuta*);
	virtual ~NodoRuta();

	void setRuta(Ruta*);
	Ruta* getRuta();

	void setSiguiente(NodoRuta*);
	NodoRuta* getSiguiente();

	string toString() const;
};