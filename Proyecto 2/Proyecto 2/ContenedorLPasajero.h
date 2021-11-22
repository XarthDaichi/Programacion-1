#pragma once
#include "NodoPasajero.h"
#include "Utilidades.h"
#include <fstream>
#define FIN_CAMPO '\t'
#define FIN_REGISTRO '\n'
#define FIN_DATO ','

class ContenedorLPasajero {
private:
	NodoPasajero* ppio;
public:
	ContenedorLPasajero();
	virtual ~ContenedorLPasajero();

	void setPpio(NodoPasajero*);
	NodoPasajero* getPpio();

	bool ingresarPasajero(Pasajero*);
	bool eliminarPasajero(string);

	virtual bool grabar(ostream&);
	static Pasajero* recuperarPasajero(istream&);
	bool recuperarTodo(istream&);

	Pasajero* buscarPorCodigo(string);

	bool cambiarCedulaPasajero(string, string);
	bool cambiarNombrePasajero(string, string);
	bool cambiarEdadPasajero(string, int);
	bool cambiarCodigoPasajero(string, string);

	string toString() const;
};