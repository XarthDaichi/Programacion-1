#include "Aerolinea.h"
// CONSTRUCTOR Y DESTRUCTOR
Aerolinea::Aerolinea() {
	contPas = new ContenedorLPasajero();
	contTrip = new ContenedorLTripulacion();
	contRut = new ContenedorLRuta();
	contVue = new ContenedorLVuelo();
	contRes = new ContenedorLReservacion();
}
Aerolinea::~Aerolinea(){
	if (contPas) delete contPas;
	if (contTrip) delete contTrip;
	if (contRut) delete contRut;
	if (contVue) delete contVue;
	if (contRes) delete contRes;
}

// ACCESORES Y MUTADORES
void Aerolinea::setContPasajero(ContenedorLPasajero* contP){
	if (contPas) delete contPas;
	contPas = contP;
}
ContenedorLPasajero* Aerolinea::getContPasajero() { return contPas; }

void Aerolinea::setContTripulacion(ContenedorLTripulacion* contT){
	if (contTrip) delete contTrip;
	contTrip = contT;
}
ContenedorLTripulacion* Aerolinea::getContTripulacion() { return contTrip; }

void Aerolinea::setContRuta(ContenedorLRuta* contRu){
	if (contRut) delete contRut;
	contRut = contRu;
}
ContenedorLRuta* Aerolinea::getContRuta() { return contRut; }

void Aerolinea::setContVuelo(ContenedorLVuelo* contV){
	if (contVue) delete contVue;
	contVue = contV;
}
ContenedorLVuelo* Aerolinea::getContVuelo() { return contVue; }

void Aerolinea::setContReservacion(ContenedorLReservacion* contRe){
	if (contRes) delete contRes;
	contRes = contRe;
}
ContenedorLReservacion* Aerolinea::getContReservacion() { return contRes; }

// INGRESAR Y ELIMINAR Y DESUSO
bool Aerolinea::ingresarPasajero(Pasajero* ingreso) { return contPas->ingresarPasajero(ingreso); }
bool Aerolinea::ingresarPiloto(Piloto* ingreso){ return contTrip->ingresarPiloto(ingreso); }
bool Aerolinea::ingresarSobrecargo(Sobrecargo* ingreso){ return contTrip->ingresarSobrecargo(ingreso); }
bool Aerolinea::ingresarRuta(Ruta* ingreso){ return contRut->ingresarRuta(ingreso); }
bool Aerolinea::ingresarVuelo(Vuelo* ingreso){ return contVue->ingresarVuelo(contTrip, contRut, ingreso); }
bool Aerolinea::ingresarReservacion(Reservacion* ingreso) { return contRes->ingresarReservacion(contPas, contVue, ingreso); }

bool Aerolinea::eliminarPasajero(string codigo) { return contPas->eliminarPasajero(codigo); }
bool Aerolinea::eliminarTripulacion(string codigo) { return contTrip->eliminarTripulacion(codigo); }
bool Aerolinea::eliminarRuta(string codigo) { return contRut->eliminarRuta(codigo); }
bool Aerolinea::eliminarVuelo(string codigo) { return contVue->eliminarVuelo(codigo); }
bool Aerolinea::eliminarReservacion(string codigo) { return contRes->eliminarReservacion(codigo); }

// MODIFICACIONES PERSONAS
bool Aerolinea::cambiarCedulaPasajero(string codigo, string cedula) {
	if (contPas->cambiarCedulaPasajero(codigo, cedula)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << " No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarCedulaTripulante(string codigo, string cedula) {
	if (contTrip->cambiarCedulaTripulante(codigo, cedula)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarNombrePasajero(string codigo, string nombre) {
	if (contPas->cambiarNombrePasajero(codigo, nombre)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarNombreTripulante(string codigo, string nombre) {
	if (contTrip->cambiarNombreTripulante(codigo, nombre)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarEdadPasajero(string codigo, int edad) {
	if (contPas->cambiarEdadPasajero(codigo, edad)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarEdadTripulante(string codigo, int edad) {
	if (contTrip->cambiarEdadTripulante(codigo, edad)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarCodigoPasajero(string codigoViejo, string codigoNuevo) {
	if (contPas->cambiarCodigoPasajero(codigoViejo, codigoNuevo)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarCodigoTripulante(string codigoViejo, string codigoNuevo) {
	if (contTrip->cambiarCodigoTripulante(codigoViejo, codigoNuevo)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarCorreoPiloto(string codigo, string correo) {
	if (contTrip->cambiarCorreoPiloto(codigo, correo)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarSexoPiloto(string codigo, char sexo) {
	if (contTrip->cambiarSexoPiloto(codigo, sexo)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarTituloSobrecargo(string codigo, string titulo) {
	if (contTrip->cambiarTituloSobrecargo(codigo, titulo)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarTelCelularSobrecargo(string codigo, string telCelular) {
	if (contTrip->cambiarTelCelularSobrecargo(codigo, telCelular)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarGrado(string codigo, string grado) {
	if (contTrip->cambiarGrado(codigo, grado)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}

// MODIFICACIONES RUTAS
bool Aerolinea::cambiarOrigen(string codigo, string origen) {
	if (contRut->cambiarOrigen(codigo, origen)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarDestino(string codigo, string destino) {
	if (contRut->cambiarDestino(codigo, destino)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarDuracion(string codigo, string duracion) {
	if (contRut->cambiarDuracion(codigo, duracion)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarCantidadDeEscalas(string codigo, int cantidadDeEscalas) {
	if (contRut->cambiarCantidadDeEscalas(codigo, cantidadDeEscalas)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarValorPasajeros(string codigo, double valorPasajeros) {
	if (contRut->cambiarValorPasajeros(codigo, valorPasajeros)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarCodigoRuta(string codigoViejo, string codigoNuevo) {
	if (contRut->cambiarCodigoRuta(codigoViejo, codigoNuevo)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarUsoRuta(string codigo, bool uso) {
	if (contRut->cambiarUsoRuta(codigo, uso)) {
		cout << "Se Cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}

// MODIFICACIONES VUELOS
bool Aerolinea::cambiarAvionVuelo(string codigo, Avion* av) {
	if (contVue->cambiarAvionVuelo(codigo, av)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false; 
	}
}
bool Aerolinea::cambiarPilotoVuelo(string codigo, string codigoPiloto) {
	if (contVue->cambiarPilotoVuelo(codigo, codigoPiloto)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarSobrecargoVuelo(string codigo, int pos, string codigoSobrecargo) {
	if (contVue->cambiarSobrecargoVuelo(codigo, pos, codigoSobrecargo)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarRutaVuelo(string codigo, string codigoRuta) {
	if (contVue->cambiarRutaVuelo(contRut, codigo, codigoRuta)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarAeropuertoSalida(string codigo, string aeSa) {
	if (contVue->cambiarAeropuertoSalida(codigo, aeSa)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarAeropuertoLlegada(string codigo, string aeLl) {
	if (contVue->cambiarAeropuertoLlegada(codigo, aeLl)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarFechaSalida(string codigo, Fecha* fe) {
	if (contVue->cambiarFechaSalida(codigo, fe)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarHoraSalida(string codigo, Hora* hoSa) {
	if (contVue->cambiarHoraSalida(codigo, hoSa)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarHoraLlegada(string codigo, Hora* hoLl) {
	if (contVue->cambiarHoraLlegada(codigo, hoLl)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarCodigoVuelo(string codigoViejo, string codigoNuevo) {
	if (contVue->cambiarCodigoVuelo(codigoViejo, codigoNuevo)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarUsoVuelo(string codigo, bool uso) {
	if (contVue->cambiarUsoVuelo(codigo, uso)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}

// MODIFICACIONES RESERVACION
bool Aerolinea::cambiarVueloReservacion(string codigo, string codigoVuelo) {
	if (contRes->cambiarVueloReservacion(contVue, codigo, codigoVuelo)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarPasajero(string codigo, string codigoPasajero) {
	if (contRes->cambiarPasajero(codigo, codigoPasajero)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarCodigoReservacion(string codigoViejo, string codigoNuevo) {
	if (contRes->cambiarCodigoReservacion(codigoViejo, codigoNuevo)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarCantidadDeTiquetes(string codigo, int cant) {
	if (contRes->cambiarCantidadDeTiquetes(contVue, codigo, cant)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}
bool Aerolinea::cambiarUsoReservacion(string codigo, bool uso) {
	if (contRes->cambiarUsoReservacion(codigo, uso)) {
		cout << "Si se cambio" << endl;
		return true;
	}
	else {
		cout << "No se cambio" << endl;
		return false;
	}
}

// GRABAR Y RECUPERAR
bool Aerolinea::guardar(ostream& outP, ostream& outT, ostream& outRu, ostream& outV, ostream& outRe) { return contPas->grabar(outP) && contTrip->grabar(outT) && contRut->grabar(outRu) && contVue->grabar(outV) && contRes->grabar(outRe); }
void Aerolinea::recuperarContPasajero(istream& in){ contPas->recuperarTodo(in);}
void Aerolinea::recuperarContTripulacion(istream& in) { contTrip->recuperarTodo(in); }
void Aerolinea::recuperarContRuta(istream& in) { contRut->recuperarTodo(in);  }
void Aerolinea::recuperarContVuelo(istream& in) { contVue->recuperarTodo(in);  }
void Aerolinea::recuperarContReservacion(istream& in) { contRes->recuperarTodo(in); }
void Aerolinea::recuperarTodosContenedores(istream& inP, istream& inT, istream& inRu, istream& inV, istream& inRe) { recuperarContPasajero(inP); recuperarContTripulacion(inT); recuperarContRuta(inRu); recuperarContVuelo(inV); recuperarContReservacion(inRe); }

// TOSTRING's
string Aerolinea::toString() const{
	stringstream s;
	s << "---TODAS LAS COLECCIONES---" << endl
		<< contPas->toString() << endl
		<< contTrip->toString() << endl
		<< contRut->toString() << endl
		<< contVue->toString(contTrip,contRut) << endl
		<< contRes->toString(contVue, contTrip, contRut) << endl;
	return s.str();
}
string Aerolinea::toStringContPasajeros() const {
	stringstream s;
	s << contPas->toString() << endl;
	return s.str();
}
string Aerolinea::toStringContTripulacion() const{
	stringstream s;
	s << contTrip->toString() << endl;
	return s.str();
}
string Aerolinea::toStringFlota() const {
	stringstream s;
	s << "---FLOTA---" << endl
		<< Flota::toString("AI-19") << endl
		<< Flota::toString("AI-20") << endl
		<< Flota::toString("AI-21") << endl
		<< Flota::toString("AI-30") << endl
		<< Flota::toString("AI-40") << endl
		<< Flota::toString("AI-60") << endl
		<< Flota::toString("BO-73") << endl
		<< Flota::toString("BO-77") << endl
		<< Flota::toString("ANT-1") << endl;
	return s.str();
}
string Aerolinea::toStringContRuta() const{
	stringstream s;
	s << contRut->toString() << endl;
	return s.str();
}
string Aerolinea::toStringContVuelo() const{
	stringstream s;
	s << contVue->toString(contTrip, contRut) << endl;
	return s.str();
}
string Aerolinea::toStringContReservacion() const{
	stringstream s;
	s << contRes->toString(contVue, contTrip, contRut) << endl;
	return s.str();
}