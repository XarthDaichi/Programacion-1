#pragma once
#include "Avion.h"
#include "ContenedorLRuta.h"
#include "Fecha.h"
#include "Hora.h"

class Vuelo {
private:
	Avion* avion;
	string codigoRuta;
	string aeropuertoSalida;
	string aeropuertoLlegada;
	Fecha* fechaSalida;
	Hora* horaSalida;
	Hora* horaLlegada;
	string codigo;
	int asientosRestantes;
	bool uso;
public:
	Vuelo(string, string, Avion*, string, Fecha*, Hora*, Hora*, string, bool);
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

	void setRuta(string);
	string getCodigoRuta();
	Ruta* getRuta(ContenedorLRuta*);

	void setCodigo(string);
	string getCodigo();

	void devolverAsientos(int);
	void comprarAsientos(int);
	void setAsientosRestantes(int);
	int getAsientosRestantes();

	void setUso(bool);
	bool getUso();


	string toString(ContenedorLTripulacion*, ContenedorLRuta*) const;
};