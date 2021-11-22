#pragma once
#include "ContenedorLTripulacion.h"
#include "Flota.h"

class Avion {
	string categoria;
	string codigoPiloto;
	string sobcar[3];
public:
	Avion(string, string, string, string, string);
	virtual ~Avion();

	void setCategoria(string);
	string getCategoria();

	void setCodigo(string);
	string getCodigo();

	void setPiloto(string);
	string getCodigoPiloto();
	Piloto* getPiloto(ContenedorLTripulacion*);

	void setSobrecargo(string, int);
	string getCodigoSobrecargo(int);
	Sobrecargo* getSobrecargo(ContenedorLTripulacion*, int);

	string marcaAvion();
	double cargaAvion();
	int pasajerosAvion();
	bool militarAvion();
	double alcanceAvion();
	string codigoAvion();
	string toStringInfo();

	string toString() const;
	string toStringTripu(ContenedorLTripulacion*) const;
	string toStringTodo(ContenedorLTripulacion*) const;
};