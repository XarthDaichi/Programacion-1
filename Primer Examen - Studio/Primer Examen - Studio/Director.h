#pragma once
#include<iostream>
#include<sstream>
using namespace std;
class Director {
private: 
	string id;
	string nombre;
	float calificacion;
public:
	Director();
	Director(string, string, float);
	virtual ~Director();
	void setId(string);
	void setNombre(string);
	void setCalificacion(float);
	string getId()const;
	string getNombre()const;
	float getCalificacion()const;
	string toString()const;
};