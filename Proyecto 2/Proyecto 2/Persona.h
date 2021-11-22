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

	virtual void setNombre(string) = 0;
	virtual string getNombre() = 0;

	virtual void setCedula(string) = 0;
	virtual string getCedula() = 0;

	virtual void setEdad(int) = 0;
	virtual int getEdad() = 0;

	virtual string toString() const = 0;
};