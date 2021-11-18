#pragma once

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Persona {
private:
	string cedula;
	string nombre;
public:
	Persona(string, string);
	virtual ~Persona();

	// MUTADORES Y ACCESORES

	//toString()
	string toString();
};