#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Persona {
protected:
	string nombre;
	string cedula;
	int edad;
public:
	Persona(string, string, int);
	virtual ~Persona();

	void setNombre(string);
	string getNombre();

	void setCedula(string);
	string getCedula();

	void setEdad(int);
	int getEdad();

	virtual string toString() = 0;
};