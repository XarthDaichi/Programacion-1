#pragma once
#include "Tripulacion.h"

class Piloto: public Tripulacion {
private:
	string correoEl;
	char sexo;
public:
	Piloto(string, string, int, string, char);
	virtual ~Piloto();

	void setCorreo(string);
	string getCorreo();

	void setSexo(char);
	char getSexo();

	virtual string toString();
};