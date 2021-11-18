#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Persona {
private:
	string nombre;  // Este es una atributo propio de la clase Persona
	int edad;       // Este es una atributo propio de la clase Persona
	static int cantidadPersonas;
	static int sumaEdades;
	static double promedioDeEdades;
	void calcularPromedioDeEdades();  // Este metodo solo podra ser llamado por
public:                               // Metodos publicos.....
	Persona(string, int);  // Dado que la clase Persona solo tiene dos atributos propios
	virtual ~Persona();
	string leeNombre();
	int leeEdad();
	static double leePromedioEdades();
	static int leeCantidadDePersonas();
	static int leeSumaDeEdades();
	void modificarEdad(int ed);
};

// dado a que es static, no le tengo que preguntar a un objeto sino le puedo preguntar a la clase
// eg. cout << "La cantidad de personas que hay son: " << Personas::leeCantidadDePersonas();