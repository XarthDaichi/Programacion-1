#pragma once
#include "ContenedorLVuelo.h"
#include "ContenedorLPasajero.h"

class Reservacion {
private:
	string codigoVuelo;
	string codigoPasajero;
	string codigo;
	int cantTiquetes;
	bool activo;
public:
	Reservacion(string, string, string, int, bool);
	virtual ~Reservacion();

	void setVuelo(string);
	string getCodigoVuelo();
	Vuelo* getVuelo(ContenedorLVuelo*);

	void setPasajero(string);
	string getCodigoPasajero();
	Pasajero* getPasajero(ContenedorLPasajero*);

	void setCodigo(string);
	string getCodigo();

	void setCantTiquetes(int);
	int getCantTiquetes();

	void setActivo(bool);
	bool getActivo();

	string toString(ContenedorLVuelo*, ContenedorLTripulacion*, ContenedorLRuta*) const;
};