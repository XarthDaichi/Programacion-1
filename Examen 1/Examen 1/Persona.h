#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Vacuna.h"
using namespace std;


class Persona {
private:
	// id, nombre, peso, genero, anio de nacimiento y estatura
	string nombre;
	string id;
	float peso;
	float estatura;
	int annioNacimiento;
	char genero;

	Vacuna* vacPtr;
public:
	// CONSTRUCTOR Y DESTRUCTOR
	Persona(string, string, float, float, int, char);
	virtual ~Persona();

	// MUTADORES Y ACCESORES
	void setNombre(string);
	string getNombre();

	void setId(string);
	string getId();

	void setPeso(float);
	float getPeso();

	void setEstatura(float);
	float getEstatura();

	void setAnnioNacimiento(int);
	int getAnnioNacimiento();

	void setGenero(char);
	char getGenero();

	void setVacuna(Vacuna*);
	Vacuna* getVacuna();

	// toSTRINGS()
	string toStringSimple();
	string toString();
};