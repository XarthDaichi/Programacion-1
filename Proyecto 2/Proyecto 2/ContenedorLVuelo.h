#pragma once
#include "NodoVuelo.h"
#include "Utilidades.h"
#include <fstream>
#define FIN_CAMPO '\t'
#define FIN_REGISTRO '\n'
#define FIN_DATO ','

class ContenedorLVuelo {
private:
	NodoVuelo* ppio;
public:
	ContenedorLVuelo();
	virtual ~ContenedorLVuelo();

	void setPpio(NodoVuelo*);
	NodoVuelo* getPpio();

	bool ingresarVuelo(ContenedorLTripulacion*, ContenedorLRuta*, Vuelo*);
	bool eliminarVuelo(string);

	virtual bool grabar(ostream&);
	static Vuelo* recuperarVuelo(istream&);
	bool recuperarTodo(istream&);

	Vuelo* buscarPorCodigo(string);

	bool cambiarAvionVuelo(string, Avion*);
	bool cambiarPilotoVuelo(string, string);
	bool cambiarSobrecargoVuelo(string, int, string);
	bool cambiarRutaVuelo(ContenedorLRuta*, string, string);
	bool cambiarAeropuertoSalida(string, string);
	bool cambiarAeropuertoLlegada(string, string);
	bool cambiarFechaSalida(string, Fecha*);
	bool cambiarHoraSalida(string, Hora*);
	bool cambiarHoraLlegada(string, Hora*);
	bool cambiarCodigoVuelo(string, string);
	bool cambiarUsoVuelo(string, bool);

	string toString(ContenedorLTripulacion*, ContenedorLRuta*) const;
};