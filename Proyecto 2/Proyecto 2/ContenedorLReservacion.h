#pragma once
#include "NodoReservacion.h"
#include "Utilidades.h"
#include <fstream>
#define FIN_CAMPO '\t'
#define FIN_REGISTRO '\n'
#define FIN_DATO ','

class ContenedorLReservacion {
private:
	NodoReservacion* ppio;
public:
	ContenedorLReservacion();
	virtual ~ContenedorLReservacion();

	void setPpio(NodoReservacion*);
	NodoReservacion* getPpio();

	bool ingresarReservacion(ContenedorLPasajero*, ContenedorLVuelo*, Reservacion*);
	bool eliminarReservacion(string);

	virtual bool grabar(ostream&);
	static Reservacion* recuperarReservacion(istream&);
	bool recuperarTodo(istream&);

	Reservacion* buscarPorCodigo(string);

	bool cambiarVueloReservacion(ContenedorLVuelo*, string, string);
	bool cambiarPasajero(string, string);
	bool cambiarCodigoReservacion(string, string);
	bool cambiarCantidadDeTiquetes(ContenedorLVuelo*, string, int);
	bool cambiarUsoReservacion(string, bool);

	string toString(ContenedorLVuelo*, ContenedorLTripulacion*, ContenedorLRuta*) const;
};