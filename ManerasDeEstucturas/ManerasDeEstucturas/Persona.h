#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Declaracion de la clase Persona
class Persona {
private:
	// Declaracion de Atributos
	string cedula;
	string nombre;
public:
	// Constructor y Desctructor
	Persona(string ced = "Indefinida", string nom = "Indefinido"); // Consturccion conjunto
	virtual ~Persona();

	// Accesores y Modificadores
	void setNombre(string nom);

	string toString();
	
	void cambioSuNombre(Persona&);
};

