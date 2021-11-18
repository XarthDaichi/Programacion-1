#pragma once

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Persona {
private:
	string cedula;
	string nombre;
	int edad;
public:
	Persona(string, string, int);
	virtual ~Persona();
	
	// Accesores (get's)
	string getNombre();
	string getCedula();
	int getEdad();

	// Mutadores (set's)
	void setNombre(string);
	void setCedula(string);
	void setEdad(int);

	string toString() const;
};