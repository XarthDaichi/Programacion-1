#include "Bus.h"

Bus::Bus() {
	placa = "Indefinida";
	modelo = "Indefinido";
	marca = "Indefinida";
	numPasajeros = 0;
	rutaPtr = NULL;
	choferPtr = NULL;
}
Bus::Bus(string pla, string mod, string mar) {
	placa = pla;
	modelo = mod;
	marca = mar;
	numPasajeros = 0;
	rutaPtr = NULL;
	choferPtr = NULL;
}
Bus::Bus(string pla, string mod, string mar, int num) {
	placa = pla;
	modelo = mod;
	marca = mar;
	numPasajeros = num;
	rutaPtr = NULL;
	choferPtr = NULL;
}
Bus::Bus(string pla, string mod, string mar, int num, Ruta* ptrRu, Chofer* ptrCho) {
	placa = pla;
	modelo = mod;
	marca = mar;
	numPasajeros = num;
	rutaPtr = ptrRu;
	choferPtr = ptrCho;
}

Bus::~Bus() {
	if (rutaPtr != NULL) delete rutaPtr;
	if (choferPtr != NULL) delete choferPtr;
}

// Mutadores
void Bus::setPlaca(string pla) { placa = pla; }
void Bus::setModelo(string mod) { modelo = mod; }
void Bus::setMarca(string mar) { marca = mar; }
void Bus::setNumPasajeros(int num) { numPasajeros = num; }
void Bus::setRuta(Ruta* ptrRu) {
	if (rutaPtr != NULL) delete rutaPtr;
	rutaPtr = ptrRu;
}
void Bus::setChofer(Chofer* ptrCho) {
	if (choferPtr != NULL) delete choferPtr;
	choferPtr = ptrCho;
}

// Accesores
string Bus::getPlaca() { return placa; }
string Bus::getModelo() { return modelo; }
string Bus::getMarca() { return marca; }
int Bus::getNumPasajeros() { return numPasajeros; }
Ruta* Bus::getRuta() { return rutaPtr; }
Chofer* Bus::getChofer() { return choferPtr; }

// toString()
string Bus::toString() const {
	stringstream s;
	s << "-----------Bus-----------" << endl
		<< "Placa.................." << placa << endl
		<< "Modelo................." << modelo << endl
		<< "Marca.................." << marca << endl
		<< "Numero de Pasajeros...." << numPasajeros << endl;
	if (rutaPtr != NULL)
		s << rutaPtr->toString() << endl;
	if (choferPtr != NULL)
		s << choferPtr->toString() << endl;
}