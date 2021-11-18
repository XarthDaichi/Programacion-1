#pragma once
#include "Sala.h"

class Cinema {
private:
	// Atributos para contener salas
	int tama;
	int cant;
	Sala** vecSala;

	// Atributos para busqueda de funciones
	int vecPosibleSala[2196];
	int vecPosibleDia[2196];
	int vecPosibleHora[2196];
	int cantPosible;

	// Atributos para asientos seleccionados en factura final
	char vecFilas[60];
	int vecColumnas[60];
	int cantAsientos;
public:
	// CONSTRUCTOR Y DESTRUCTOR
	Cinema(int = 2);
	virtual ~Cinema();

	// ACCESORES Y MUTADORES
	int getCantidad();
	bool ingresarSala(Sala*);
	Sala* getSala(int);

	// PARA RESETEAR LOS VECTORES DE BUSQUEDA DE FUNCIONES
	void devolverValores();
	int getCantPosible();
	int getPosibleSala(int);
	int getPosibleDia(int);
	int getPosibleHora(int);

	// PARA RESETEAR LOS ASIENTOS SELECCIONADOS
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

	// Cambiar de mes-dia-annio a numero de dia
	int FehcaADia(int, int, int);

	// PARA INGRESAR UNA FUNCION A UNA SALA DIA Y HORA ESPECIFICA
	bool ingresarFuncion(Funcion*, int, int, int);

	// COMPRA Y SELECCION DE TIQUETES Y ASIENTOS
	float comprarTiquetes(int, int, int, int, int);
	bool comprarAsiento(int, int, int, char fila, int columna);
	bool confirmarAsiento(int, int, int, string);
	bool cancelanAsiento(int, int, int); // Para devolver los colores por si cancelan la orden
};