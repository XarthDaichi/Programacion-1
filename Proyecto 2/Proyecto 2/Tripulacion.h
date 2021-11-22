#pragma once
#include "Persona.h"

class Tripulacion : public Persona {
protected:
	string codigo;
public:
	Tripulacion(string, string, int, string);
	virtual ~Tripulacion();

	virtual void setNombre(string) = 0;
	virtual string getNombre() = 0;

	virtual void setCedula(string) = 0;
	virtual string getCedula() = 0;

	virtual void setEdad(int) = 0;
	virtual int getEdad() = 0;

	virtual void setCodigo(string) = 0;
	virtual string getCodigo() = 0;

	virtual string toString() const = 0;
};