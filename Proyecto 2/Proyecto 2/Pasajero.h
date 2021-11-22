#pragma once
#include "Persona.h"

class Pasajero: public Persona {
private:
	string codigo;
public:
	Pasajero(string, string, int, string);
	virtual ~Pasajero();

	virtual void setNombre(string);
	virtual string getNombre();

	virtual void setCedula(string);
	virtual string getCedula();

	virtual void setEdad(int);
	virtual int getEdad();
	
	void setCodigo(string);
	string getCodigo();

	virtual string toString() const;
};