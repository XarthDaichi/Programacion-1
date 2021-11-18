#pragma once
#include "Director.h"

class Pelicula {
private:
	string codigo;
	string nombre;
	string genero;
	float calificacion;
	float taquilla;
	static float filantropia;
	Director* directorPtr;
public:
	Pelicula();
	Pelicula(string, string, string, float, float, Director*);
	virtual ~Pelicula();

	// ACCESORES Y MUTADORES
	string getCodigo();
	string getNombre();
	string getGenero();

	void setCalificacion(float);
	float getCalificacion();

	void setTaquilla(float);
	float getTaquilla();

	static void setFilantropia(float);
	static float getFilantropia();

	void setDirector(Director*);
	Director* getDirector();
	
	bool mismoDirector(Director*);

	string toString();
};