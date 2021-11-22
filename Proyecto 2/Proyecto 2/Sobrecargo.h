#pragma once
#include "Tripulacion.h"

class Sobrecargo: public Tripulacion {
private:
	string titulo;
	string telCelular;
	string grado;
public:
	Sobrecargo(string, string, int, string, string, string, string);
	virtual ~Sobrecargo();

	virtual void setNombre(string);
	virtual string getNombre();

	virtual void setCedula(string);
	virtual string getCedula();

	virtual void setEdad(int);
	virtual int getEdad();

	void setTitulo(string);
	string getTitulo();

	void setTelCelular(string);
	string getTelCelular();

	void setGrado(string);
	string getGrado();

	virtual void setCodigo(string);
	virtual string getCodigo();

	virtual string toString() const;
};