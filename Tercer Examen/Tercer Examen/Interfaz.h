#pragma once
#include"Tienda.h"

class Interfaz {
public:
	static int menu();
	static Tienda* creaTienda();
	static Departamento* creaDepartamento();
	static Empleado* creaEmpleado(int op);
	static Fecha* creaFecha();
	//..



};