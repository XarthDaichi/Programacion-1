#pragma once
#include "NodoRuta.h"
#include "Utilidades.h"
#include <fstream>
#define FIN_CAMPO '\t'
#define FIN_REGISTRO '\n'
#define FIN_DATO ','

class ContenedorLRuta {
private:
	NodoRuta* ppio;
public:
	ContenedorLRuta();
	virtual ~ContenedorLRuta();

	void setPpio(NodoRuta*);
	NodoRuta* getPpio();

	bool ingresarRuta(Ruta*);
	bool eliminarRuta(string);

	virtual bool grabar(ostream&);
	static Ruta* recuperarRuta(istream&);
	bool recuperarTodo(istream&);

	Ruta* buscarPorCodigo(string);

	bool cambiarOrigen(string, string);
	bool cambiarDestino(string, string);
	bool cambiarDuracion(string, string);
	bool cambiarCantidadDeEscalas(string, int);
	bool cambiarValorPasajeros(string, double);
	bool cambiarCodigoRuta(string, string);
	bool cambiarUsoRuta(string, bool);

	string toString() const;
};