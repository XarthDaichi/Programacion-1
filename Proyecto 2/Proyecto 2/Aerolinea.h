#pragma once
#include "ContenedorLPasajero.h"
#include "ContenedorLTripulacion.h"
#include "ContenedorLRuta.h"
#include "ContenedorLVuelo.h"
#include "ContenedorLReservacion.h"

class Aerolinea {
private:
	ContenedorLPasajero* contPas;
	ContenedorLTripulacion* contTrip;
	ContenedorLRuta* contRut;
	ContenedorLVuelo* contVue;
	ContenedorLReservacion* contRes;
public:
	// CONSTRUCTOR Y DESTRUCTOR
	Aerolinea();
	virtual ~Aerolinea();

	// ACCESORES Y MUTADORES
	void setContPasajero(ContenedorLPasajero*);
	ContenedorLPasajero* getContPasajero();

	void setContTripulacion(ContenedorLTripulacion*);
	ContenedorLTripulacion* getContTripulacion();

	void setContRuta(ContenedorLRuta*);
	ContenedorLRuta* getContRuta();

	void setContVuelo(ContenedorLVuelo*);
	ContenedorLVuelo* getContVuelo();

	void setContReservacion(ContenedorLReservacion*);
	ContenedorLReservacion* getContReservacion();

	// INGRESAR Y ELIMINAR
	bool ingresarPasajero(Pasajero*);
	bool ingresarPiloto(Piloto*);
	bool ingresarSobrecargo(Sobrecargo*);
	bool ingresarRuta(Ruta*);
	bool ingresarVuelo(Vuelo*);
	bool ingresarReservacion(Reservacion*);

	bool eliminarPasajero(string);
	bool eliminarTripulacion(string);
	bool eliminarRuta(string);
	bool eliminarVuelo(string);
	bool eliminarReservacion(string);

	// MODIFICACIONES PERSONAS
	bool cambiarCedulaPasajero(string, string);
	bool cambiarCedulaTripulante(string, string);
	bool cambiarNombrePasajero(string, string);
	bool cambiarNombreTripulante(string, string);
	bool cambiarEdadPasajero(string, int);
	bool cambiarEdadTripulante(string, int);
	bool cambiarCodigoPasajero(string, string);
	bool cambiarCodigoTripulante(string, string);
	bool cambiarCorreoPiloto(string, string);
	bool cambiarSexoPiloto(string, char);
	bool cambiarTituloSobrecargo(string, string);
	bool cambiarTelCelularSobrecargo(string, string);
	bool cambiarGrado(string, string);

	// MODIFICACIONES RUTAS
	bool cambiarOrigen(string, string);
	bool cambiarDestino(string, string);
	bool cambiarDuracion(string, string);
	bool cambiarCantidadDeEscalas(string, int);
	bool cambiarValorPasajeros(string, double);
	bool cambiarCodigoRuta(string, string);
	bool cambiarUsoRuta(string, bool);

	// MODIFICACIONES VUELOS
	bool cambiarAvionVuelo(string, Avion*);
	bool cambiarPilotoVuelo(string, string);
	bool cambiarSobrecargoVuelo(string, int, string);
	bool cambiarRutaVuelo(string, string);
	bool cambiarAeropuertoSalida(string, string);
	bool cambiarAeropuertoLlegada(string, string);
	bool cambiarFechaSalida(string, Fecha*);
	bool cambiarHoraSalida(string, Hora*);
	bool cambiarHoraLlegada(string, Hora*);
	bool cambiarCodigoVuelo(string, string);
	bool cambiarUsoVuelo(string, bool);

	// MODIFICACIONES RESERVACION
	bool cambiarVueloReservacion(string, string);
	bool cambiarPasajero(string, string);
	bool cambiarCodigoReservacion(string, string);
	bool cambiarCantidadDeTiquetes(string, int);
	bool cambiarUsoReservacion(string, bool);

	// GRABAR Y RECUPERAR
	bool guardar(ostream&, ostream&, ostream&, ostream&, ostream&);
	void recuperarContPasajero(istream&);
	void recuperarContTripulacion(istream&);
	void recuperarContRuta(istream&);
	void recuperarContVuelo(istream&);
	void recuperarContReservacion(istream&);
	void recuperarTodosContenedores(istream&, istream&, istream&, istream&, istream&);

	// TOSTRING's
	string toString() const;
	string toStringContPasajeros() const;
	string toStringContTripulacion() const;
	string toStringFlota() const;
	string toStringContRuta() const;
	string toStringContVuelo() const;
	string toStringContReservacion() const;
};