#pragma once
#include"Director.h"
using namespace std;
class Pelicula {
private:
	string codigo;
	string nombreP;
	string genero;
	float calif;
	float recaudado;
	static double porcentajeCari;
	Director* dir;
public:
	Pelicula();
	Pelicula(string, string, string, float, float, Director*);
	virtual ~Pelicula();
	void setCodigo(string);
	void setNombreP(string);
	void setGenero(string);
	void setCalif(float);
	void setRecaudado(float);
	void setPorcentaje(double);
	void setDirector(Director*);
	string getCodigo()const;
	string getNombreP()const;
	string getGenero()const;
	float getCalif()const;
	float getRecaudado()const;
	static double getPorcentajeCari();
	Director* getDirector()const;
	string toString()const;
	double calculoCaridad();
};