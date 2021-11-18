#pragma once
#include"Pelicula.h"
#include"Director.h"
class ContenedoraDob{
private:
	string nombreStudio;//nombre del estudio cinematografico
	int tamD;//tamaño del vector de directores
	int tamP;//tamaño del vector de peliculas
	int canD;//cantidad del vector de directores
	int canP;//cantidad del vector de peliculas
	Director** vec1;//vector de peliculas
	Pelicula** vec2;//vector de directores
public:
	ContenedoraDob(int tamd, int tamp);
	virtual ~ContenedoraDob();
	void setNombreStudio(string);
	string getNombreStudio()const;
	string toStringDir()const;
	string toStringPeli()const;
	bool insertaDir(Director*);
	bool insertaPel(string, Pelicula* pel);
	//void eliminarPelicula(string);
	void peliculasDirector(string);
	float totalRecaudadoCaridad();
	float califDirector(string);
	void actualizaCalifDir(string);
};