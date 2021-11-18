#pragma once
#include "Nodo.h"

class ContenedorL {
private:
	Nodo* ppio; // Es un puntero externo que solo ve al primer nodo de la lista.
public:
	ContenedorL();
	virtual ~ContenedorL();

	Nodo* getPpio();

	string toString();

	bool isEmpty();
	int cuentaNodos();

	void insertarAlInicio(Persona*);
	void insertarAlFinal(Persona*);
	bool insertarEnLugar(Persona*,int lug);
	
	bool eliminarElPrimero();
	bool eliminarElUltimo();
	bool eliminarEnLugar(int lug);

	Nodo* retPosUltimoLug();
	Persona* retPersUltimoLug();
	Nodo* retPosPrimerLug();
	Persona* retPersPrimerLug();
	Nodo* retPosLug(int lug);
	Persona* retPersEnLugar(int lug); // si no existe lug entonces retorna NULL

	double promedioEdades();  // sacar el promedio de edades de toda esa lista.
	Persona* persDeMayorEdad();
	Persona* persDeMenorEdad();

	void invertirOrdLista();
	void ordenarASCEdad();
};