#pragma once
#include"Empleado.h"

class Contenedor{  
 private:
	Empleado ** vec;
	int can;
	int tam;
  public:
	Contenedor(int val);
	virtual ~Contenedor();
	bool ingresaEmpleado(Empleado* per);
	int existeCedula(string);
	bool eliminaEmpleado(string);     // CO.eliminaEmpleado(cedula);
	void desplegarEmpleadosConHijosMayoresDe12Anios();


	void desplegarSalariosNetosMenoresA300Mil();


	string toString() const;
};

