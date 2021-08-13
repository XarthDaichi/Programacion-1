#pragma once
#include<iostream>
#include<string>
using namespace std;

// Aqui en este archivo (.h)
// Aqui se escribe la interfaz de la clase Persona..
// Aqui es donde se devlara la clase Persona. (Se estructura primero despues se le mete la carnita)

class Persona {
private:
	string cedula;
	string nombre;
	int edad;
public:
	Persona(); // constructor por defecto sin parametros
	Persona(string ced, string nom, int ed); // constructor parametrizado (en la declaracion lo puede dejar solo con el tipo de variable "string" no "string x")
	//Persona(string = "", string = "", int = 0) // constructor conjunto (se trabaja despues)
	virtual ~Persona(); // Destructor. (virtual nos lo responden en un mes)
	// ACCESORES GET'S
	string getCedula();
	string getNombre();
	int getEdad();
	// MUTADORES SET'S
	void setCedula(string ced);
	void setNombre(string nom);
	void setEdad(int ed);
	// TOSTRING()
	string toString();
};
