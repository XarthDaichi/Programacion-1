#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Persona {
protected:
	string _cedula;
	string _nombre;
public:
	Persona(string, string);
	virtual ~Persona();

	void setCedula(string);
	string getCedula();

	void setNombre(string);
	string getNombre();

	virtual string toString();
};