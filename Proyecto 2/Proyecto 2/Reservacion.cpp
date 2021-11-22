#include "Reservacion.h"

Reservacion::Reservacion(string cod, string codVu, string codPa, int cantTiq, bool act) : codigo(cod), codigoVuelo(codVu), codigoPasajero(codPa), cantTiquetes(cantTiq), activo(act) {}
Reservacion::~Reservacion() {}

void Reservacion::setVuelo(string codVu) { codigoVuelo = codVu; }
string Reservacion::getCodigoVuelo() { return codigoVuelo; }
Vuelo* Reservacion::getVuelo(ContenedorLVuelo* contV) { return contV->buscarPorCodigo(codigoVuelo); }

void Reservacion::setPasajero(string codPa) { codigoPasajero = codPa; }
string Reservacion::getCodigoPasajero() { return codigoPasajero; }
Pasajero* Reservacion::getPasajero(ContenedorLPasajero* contP) { return contP->buscarPorCodigo(codigoPasajero); }

void Reservacion::setCodigo(string cod) { codigo = cod; }
string Reservacion::getCodigo() { return codigo; }

void Reservacion::setCantTiquetes(int cantTiq) { cantTiquetes = cantTiq; }
int Reservacion::getCantTiquetes() { return cantTiquetes; }

void Reservacion::setActivo(bool act) { activo = act; }
bool Reservacion::getActivo() { return activo; }

string Reservacion::toString(ContenedorLVuelo* contV, ContenedorLTripulacion* contT, ContenedorLRuta* contRu) const {
	stringstream s;
	s << "Codigo: " << codigo << endl
		<< "Vuelo: " << contV->buscarPorCodigo(codigoVuelo)->toString(contT, contRu) << endl
		<< "Pasajero: " << codigoPasajero << endl
		<< "Cantidad de Tiquetes: " << cantTiquetes << endl;
	return s.str();
}
