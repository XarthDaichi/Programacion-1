#pragma once
#include "Persona.h"

class Pasajero: public Persona {
public:
	Pasajero(string, string, int);
	virtual ~Pasajero();
	
	virtual string toString();
};