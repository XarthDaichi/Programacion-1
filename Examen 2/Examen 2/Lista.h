#pragma once
#include "Nodo.h"

class Lista {
private:
	Nodo* ppio;
public:
	Lista();
	virtual ~Lista();
	bool isEmpty();
	int cuentaPersonas();
	void insertarAlInicio(Persona* pe);
	void insertarAlUltimo(Persona* pe);
	bool insertarEnElLugar(Persona* pe, int lug);

	bool eliminaPrimero();
	bool eliminaUltimo();
	bool eliminaEnLugar(int num);

};