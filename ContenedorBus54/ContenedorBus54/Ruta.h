#pragma once
#include "Hora.h"  // La Ruta ve a la Hora   Ruta-->Hora.

// Aqui va la declaracion de la clase Ruta...

class Ruta {
private:
	string origen;
	string destino;
	double precio;
	// Vinculaciones..
	Hora* horaPtr; // Es una flecha o puntero que nos vincula a una hora determinada.
public:
	Ruta(); // constructor por defecto sin parameteros.
	Ruta(string, string, double); // Constructor con parametros sin hora vinculada.
	Ruta(string, string, double, Hora*); // Constructor con parametros con hora vinculada.
	// Ruta(string="", string="", double=0.0, Hora*=NULL)
	virtual ~Ruta();
	// Mutadores (set's)
	void setOrigen(string);
	void setDestino(string);
	void setPrecio(double);
	void setHora(Hora*);
	// Accesores (get's)
	string getOrigen();
	string getDestino();
	double getPrecio();
	Hora* getHora();
	// toString()
	string toString();
};	