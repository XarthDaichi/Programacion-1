#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std;

class Pelicula {
private:
	string genero;
	string nombre;
	string sinopsis;
	bool paraNinnos;
public:
	// CONSTRUCTOR Y DESTRUCTOR
	Pelicula(string = "", string = "", string = "", bool = false);
	virtual ~Pelicula();

	// MUTADORES Y ACCESORES
	void setGenero(string);
	string getGenero();

	void setNombre(string);
	string getNombre();

	void setSinopsis(string);
	string getSinopsis();

	void setParaNinnos(bool);
	bool getParaNinnos();

	// toString()
	string toString() const;
};