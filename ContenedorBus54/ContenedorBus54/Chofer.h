#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Chofer {
private:
	string cedula;
	string nombre;
	int edad;
public:
	Chofer(string, string, int);
	virtual ~Chofer();
	// Mutadores (set's)
	void setCedula(string);
	void setNombre(string);
	void setEdad(int);
	//Accesores (get's)
	string getCedula();
	string getNombre();
	int getEdad();
	//toString()
	string toString();
};