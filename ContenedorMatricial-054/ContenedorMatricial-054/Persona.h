#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Persona {
  private:
	string cedula;
	string nombre;
	int edad;
  public:
	Persona(string = "", string = "", int = 0);
	virtual ~Persona();
	void setCedula(string);
	void setNombre(string);
	void setEdad(int);
	string getCedula();
	string getNombre();
	int getEdad();
	string toString();
	bool esIgualA(const Persona&);
};
