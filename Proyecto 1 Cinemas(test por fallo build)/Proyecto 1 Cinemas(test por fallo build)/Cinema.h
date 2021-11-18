#pragma once
#include "Sala.h"

class Cinema {
private:
	int tama;
	int cant;
	Sala** vecSala;
	int vecPosibleSala[2196];
	int vecPosibleDia[2196];
	int vecPosibleHora[2196];
	int cantPosible;
	char vecFilas[60];
	int vecColumnas[60];
	int cantAsientos;
public:
	Cinema(int = 2);
	virtual ~Cinema();

	// ACCESORES Y MUTADORES
	int getCantidad();
	bool ingresarSala(Sala*);
	Sala* getSala(int);

	void devolverValores();
	int getCantPosible();
	int getPosibleSala(int);
	int getPosibleDia(int);
	int getPosibleHora(int);

	void devolverAsientos();
	string getAsientosComprados();

	// toStrings
	string toString();
	string toStringGenero(string);
	string toStringNombre(string);
	string toStringTipoLenguaje(char);
	string toStringDimensiones(int);
	string toStringTipoSala(char);
	string toStringTipoPublico(bool);
	string toStringFuncion(int, int, int);


	int FehcaADia(int, int, int);

	bool ingresarFuncion(Funcion*, int, int, int);

	float comprarTiquetes(int, int, int, int, int);
	bool comprarAsiento(int, int, int, char fila, int columna);
	bool confirmarAsiento(int, int, int, string);
	bool cancelanAsiento(int, int, int);
};