#include "Avion.h"

Avion::Avion(string cat, string codPi, string codSo1, string codSo2, string codSo3) : categoria(cat), codigoPiloto(codPi) {
	sobcar[0] = codSo1;
	sobcar[1] = codSo2;
	sobcar[2] = codSo3;
}

Avion::~Avion() {}

void Avion::setCategoria(string cat) { categoria = cat; }
string Avion::getCategoria() { return categoria; }

void Avion::setPiloto(string codigoPi) { codigoPiloto = codigoPi; }
string Avion::getCodigoPiloto() { return codigoPiloto; }
Piloto* Avion::getPiloto(ContenedorLTripulacion* contT) { return contT->buscarPilotoPorCodigo(codigoPiloto); }

void Avion::setSobrecargo(string codSoTemp, int pos) { sobcar[pos] = codSoTemp; }
string Avion::getCodigoSobrecargo(int pos) { return sobcar[pos]; }
Sobrecargo* Avion::getSobrecargo(ContenedorLTripulacion* contT, int pos) { return contT->buscarSobrecargoPorCodigo(sobcar[pos]); }

string Avion::marcaAvion() { return Flota::marcaAvion(categoria); }
double Avion::cargaAvion() { return Flota::cargaAvion(categoria); }
int Avion::pasajerosAvion() { return Flota::pasajerosAvion(categoria); }
bool Avion::militarAvion() { return Flota::militarAvion(categoria); }
double Avion::alcanceAvion() { return Flota::alcanceAvion(categoria); }
string Avion::codigoAvion() { return Flota::codigoAvion(categoria); }
string Avion::toStringInfo() { return Flota::toString(categoria); }

string Avion::toString() const {
	stringstream s;
	s << "-------Detalles del Avion-------" << endl
		<< "Categoria: " << categoria << endl
		<< Flota::toString(categoria) << endl;
	return s.str();
}

string Avion::toStringTripu(ContenedorLTripulacion* contT) const{
	stringstream s;
	s << "Piloto: " << contT->buscarPilotoPorCodigo(codigoPiloto)->toString() << endl;
	for (int i = 0; i < 3; i++) {
		s << "Sobrecargo " << i + 1 << ": " << contT->buscarSobrecargoPorCodigo(sobcar[i])->toString() << endl;
	}
	return s.str();
}

string Avion::toStringTodo(ContenedorLTripulacion* contT) const {
	stringstream s;
	s << toString() << toStringTripu(contT) << endl;
	return s.str();
}
