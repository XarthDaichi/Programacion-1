#pragma once
#include "NodoTripulacion.h"
#include "Utilidades.h"
#include <fstream>
#define FIN_CAMPO '\t'
#define FIN_REGISTRO '\n'
#define FIN_DATO ','

class ContenedorLTripulacion {
private:
	NodoTripulacion* ppio;
public:
	ContenedorLTripulacion();
	virtual ~ContenedorLTripulacion();

	void setPpio(NodoTripulacion*);
	NodoTripulacion* getPpio();

	bool ingresarPiloto(Piloto*);
	bool ingresarSobrecargo(Sobrecargo*);
	bool eliminarTripulacion(string);

	virtual bool grabar(ostream&);
	static NodoTripulacion* recuperarTripulacion(istream&);
	bool recuperarTodo(istream&);

	Piloto* buscarPilotoPorCodigo(string);
	Sobrecargo* buscarSobrecargoPorCodigo(string);

	bool cambiarCedulaTripulante(string, string);
	bool cambiarNombreTripulante(string, string);
	bool cambiarEdadTripulante(string, int);

	bool cambiarCodigoTripulante(string, string);
	bool cambiarCorreoPiloto(string, string);
	bool cambiarSexoPiloto(string, char);
	bool cambiarTituloSobrecargo(string, string);
	bool cambiarTelCelularSobrecargo(string, string);
	bool cambiarGrado(string, string);

	string toString() const;
};