#include "Vuelo.h"

Vuelo::Vuelo(string aeSa, string aeLl, Avion* av, string codRu, Fecha* feSa, Hora* hoSa, Hora* hoLl, string cod, bool us) : aeropuertoSalida(aeSa), aeropuertoLlegada(aeLl), avion(av), codigoRuta(codRu), fechaSalida(feSa), horaSalida(hoSa), horaLlegada(hoLl), codigo(cod) { 
	uso = us;
	asientosRestantes = avion->pasajerosAvion(); 
}
Vuelo::~Vuelo() {}

void Vuelo::setAeropuertoSalida(string aeSa) { aeropuertoSalida = aeSa; }
string Vuelo::getAeropuertoSalida() { return aeropuertoSalida; }

void Vuelo::setAeropuertoLlegada(string aeLl) { aeropuertoLlegada = aeLl; }
string Vuelo::getAeropuertoLlegada() { return aeropuertoLlegada; }

void Vuelo::setFechaSalida(Fecha* feSa) {
	if (fechaSalida) delete fechaSalida;
	fechaSalida = feSa;
}
Fecha* Vuelo::getFechaSalida() { return fechaSalida; }

void Vuelo::setHoraSalida(Hora* hoSa) {
	if (horaSalida) delete horaSalida;
	horaSalida = hoSa;
}
Hora* Vuelo::getHoraSalida() { return horaSalida; }

void Vuelo::setHoraLlegada(Hora* hoLl) {
	if (horaLlegada) delete horaLlegada;
	horaLlegada = hoLl;
}
Hora* Vuelo::getHoraLlegada() { return horaLlegada; }

void Vuelo::setAvion(Avion* av) { 
	if (avion) delete avion;
	avion = av; 
}
Avion* Vuelo::getAvion() { return avion; }

void Vuelo::setRuta(string codRu) { codigoRuta = codRu; }
string Vuelo::getCodigoRuta() { return codigoRuta; }
Ruta* Vuelo::getRuta(ContenedorLRuta* contRu) { return contRu->buscarPorCodigo(codigoRuta); }

void Vuelo::setCodigo(string cod) { codigo = cod; }
string Vuelo::getCodigo() { return codigo; }

void Vuelo::devolverAsientos(int dev) { asientosRestantes = asientosRestantes + dev; }
void Vuelo::comprarAsientos(int com) { asientosRestantes = asientosRestantes - com; }
void Vuelo::setAsientosRestantes(int asRes) { asientosRestantes = avion->pasajerosAvion() - asRes; }
int Vuelo::getAsientosRestantes() { return asientosRestantes; }

void Vuelo::setUso(bool us) { uso = us; }
bool Vuelo::getUso() { return uso; }

string Vuelo::toString(ContenedorLTripulacion* contT, ContenedorLRuta* contRu) const {
	stringstream s;
	s << "Aeropuerto de Salida: " << aeropuertoSalida << endl
		<< "Aeropuerto de Llegada: " << aeropuertoLlegada << endl
		<< "Fecha de Salida: " << fechaSalida->toString() << endl
		<< "Hora de Salida: " << horaSalida->toString() << endl
		<< "Hora de Llegada: " << horaLlegada->toString() << endl
		<< "Avion: " << avion->toStringTodo(contT) << endl
		<< "Ruta: " << contRu->buscarPorCodigo(codigoRuta)->toString() << endl
		<< "Asientos Restantes: " << asientosRestantes << endl
		<< "Codigo de Vuelo: " << endl;
	return s.str();
}