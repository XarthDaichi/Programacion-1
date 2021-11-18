#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "vacuna.h"
using namespace std;
class paciente
{
private:
	string nombre;
	string id;
	float	peso;
	float estatura;
	int  annioNacimiento;
	char genero;

// nota: entre los atributos no puede estar casaComercial, pues es atributo de vacuna
public:
	paciente(string, string, float, float, int, char);
	string getNombre();
	string getId();
	float	getPeso();
	int  getAnnioNacimiento();
	float getEstatura();
	char getGenero();

	 void setNombre(string);
	 void setId(string);
	 void setPeso(float);
	 void setAnnioNacimiento(int);
	 void setEstatura(float);
	 void setGenero(char);

};
