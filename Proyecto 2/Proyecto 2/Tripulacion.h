#pragma once
#include "Persona.h"

class Tripulacion : public Persona {
protected:
public:
	Tripulacion(string, string, int);
	virtual ~Tripulacion();
	virtual string toString() = 0;
};