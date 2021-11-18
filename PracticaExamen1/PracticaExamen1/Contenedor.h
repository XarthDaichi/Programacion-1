#pragma once
#include "Pelicula.h"

class Contenedor {
private:
	string nombreStudio;
	int tamD;
	int tamP;
	int canD;
	int canP;
	Director** vecD;
	Pelicula** vecP;
public:
	Contenedor(int tamd, int tamp);
	virtual ~Contenedor();
	
	string getNombreStudio();
	void setNombreStudio(string nom);

	bool ingresarPelicula(Pelicula* pelPtr);
	bool eliminarPelicula(string cod);

	bool ingresarDirector(Director* dirPtr);
	bool eliminarDirector(string id);

	string toString();
};