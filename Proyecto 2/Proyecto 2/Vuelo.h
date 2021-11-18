#pragma once
#include "Avion.h"
#include "Ruta.h"
#include "Fecha.h"
#include "Hora.h"

class Vuelo {
private:
	Avion* av;
	Ruta* ru;
	string aeropuertoSalida;
	string aeropuertoLlegada;
	Fecha* fechaSalida;
	Hora* horaSalida;
	Hora* horaLlegada;
public:
	Vuelo(string, string, Fecha*, Hora*, Hora*, Ruta*, Avion*);
	virtual ~Vuelo();

	void setAeropuertoSalida(string);
	string getAeropuertoSalida();

	void setAeropuertoLlegada(string);
	string getAeropuertoLlegada();

	void setFechaSalida(Fecha*);
	Fecha* getFechaSalida();

	void setHoraSalida(Hora*);
	Hora* getHoraSalida();

	void setHoraLlegada(Hora*);
	Hora* getHoraLlegada();

	void setAvion(Avion*);
	Avion* getAvion();

	void setRuta(Ruta*);
	Ruta* getRuta();

	string toString() const;
};