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
	Persona(string = "Indefinida", string = "Indefinido", int = 0);
	virtual ~Persona();

	// MUTADORES (SET'S)
	void setCedula(string);
	void setNombre(string);
	void setEdad(int);

	// ACCESORES (GET'S)
	string getCedula();
	string getNombre();
	int getEdad();

	string toString();
};
