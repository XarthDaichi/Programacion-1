#pragma once
#include "Empleado.h"

class Contenedor {
private:
	Empleado** vec;
	int can;
	int tam;
public:
	Contenedor(int val);
	virtual ~Contenedor();
	bool ingresaEmpleado(Empleado* per);
	string toString() const;
};