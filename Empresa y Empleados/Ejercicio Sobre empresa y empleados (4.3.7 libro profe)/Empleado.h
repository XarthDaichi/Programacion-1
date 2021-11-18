#pragma once

#include "Familia.h"
#include "Ingreso.h"

class Empleado {
private:
	string cedula;
	string nombre;
	int edad;
	Familia* ptrFam;
	Ingreso* ptrIng;
public:
	Empleado();
	Empleado(string, string, int);
	Empleado(string, string, int, Familia*, Ingreso*);
	virtual ~Empleado();

	// ACCESORES... get's
	string getCedula();
	string getNombre();
	int getEdad();
	Familia* getFamilia();
	Ingreso* getIngreso();

	// MUTADORES... set's
	void setCedula();
	void setNombre();
	void setEdad();
	void setFamilia();
	void setIngreso();

	// toString();
	string toString();

	bool cambioDeEdadDeHijos(int);
};