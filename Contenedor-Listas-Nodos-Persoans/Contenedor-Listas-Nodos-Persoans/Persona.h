#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Persona {
private:
	string nombre;
	string cedula;
	int edad;
public:
	Persona(); // Construc. Por defecto.
	Persona(string, string, int); // Construc. Parametrizado.
	~Persona();
	string getNombre();
	string getCedula();
	int getEdad();
	string toString();
};