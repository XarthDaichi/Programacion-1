#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Director {
private:
	string id;
	string nombre;
	float calificacion;
	float calificacionTemp;
	int cantPeliculas;
public:
	Director();
	Director(string, string);
	virtual ~Director();

	// ACCESORES Y MUTADORES
	void setId(string);
	string getId();

	void setNombre(string);
	string getNombre();

	void hizoPelicula();
	void eliminarPelicula();
	void updateCalificacion(float);

	string toString();
};