#pragma once
#include "Tripulacion.h"

class Piloto: public Tripulacion {
private:
	string correoEl;
	char sexo;
public:
	Piloto(string, string, int, string, string, char);
	virtual ~Piloto();

	virtual void setNombre(string);
	virtual string getNombre();

	virtual void setCedula(string);
	virtual string getCedula();

	virtual void setEdad(int);
	virtual int getEdad();

	void setCorreo(string);
	string getCorreo();

	void setSexo(char);
	char getSexo();

	virtual void setCodigo(string);
	virtual string getCodigo();

	virtual string toString() const;
};