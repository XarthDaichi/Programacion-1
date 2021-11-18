#pragma once
#include "Pelicula.h"

class Funcion {
private:
	char tipoLenguaje;
	int dimensiones;
	string pais;
	Pelicula* pel;
public:
	// CONSTRUCTOR Y DESTRUCTOR
	Funcion(char = ' ', int = 2, string = "", Pelicula* = NULL);
	virtual ~Funcion();

	// MUTADORES Y ACCESORES

	void setTipoLenguaje(char);
	char getTipoLenguaje();

	void setDimensiones(int);
	int getDimensiones();

	void setPais(string);
	string getPais();

	void setPelicula(Pelicula*);
	Pelicula* getPelicula();

	// toString
	string toString() const;
};