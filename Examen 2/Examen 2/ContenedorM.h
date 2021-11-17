#pragma once
#include "SuperClass.h"

class ContenedorM {
private:
	int fila;
	int colu;
	SuperClass*** mat;
public:
	ContenedorM(int, int);
	virtual ~ContenedorM();

	bool ingresarPersona(SuperClass*);

	string toString() const;
};