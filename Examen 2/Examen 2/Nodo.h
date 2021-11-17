#pragma once
#include "SuperClass.h"

class Nodo {
private:
	SuperClass* per;
	Nodo* sig;
public:
	Nodo();
	Nodo(SuperClass*, Nodo*);
	virtual ~Nodo();

	void setPersona(SuperClass*);
	SuperClass* getPersona();

	void setNodoSiguiente(Nodo*);
	Nodo* getNodoSiguiente();

	string toString() const;
};