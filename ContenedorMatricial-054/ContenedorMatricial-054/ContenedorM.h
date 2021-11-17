#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include"Persona.h"
using namespace std;

class ContenedorM {
  private:
	Persona *** mat;                // bool ** mat;     // int ** mat      // int *** mat;
	int filas;
	int colum;
  public:
	ContenedorM(int, int);
	virtual ~ContenedorM();
	void imprimeContenedor();
	bool ingresaPersona(Persona*, int, int);  // Ingresar persona en alguna posición de la mat.
	Persona* obtenerPersona(int, int);   // Si la persona no está deberíamos de retornat un NULL.

	Persona& laDeMayorEdad();
	Persona& laDeMenorEdad();
	void ordenaPorEdad();
	float promedioDeEdades();
	bool comparaCotenedores(ContenedorM& cont);
	void reporteTodosConNombre(string nom);
	void reporteTodosConEdadMayorA(int ed);
};