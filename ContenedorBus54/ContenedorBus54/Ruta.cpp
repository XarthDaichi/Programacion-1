#include "Ruta.h"

Ruta::Ruta() { // POR DEFECTO
	origen = "Indefinido";
	destino = "Indefinido";
	precio = 0.0;
	horaPtr = NULL;
}
Ruta::Ruta(string ori, string des, double pre) {
	origen = ori;
	destino = des;
	precio = pre;
	horaPtr = NULL;
}
Ruta::Ruta(string ori, string des, double pre, Hora* ptrH) {
	origen = ori;
	destino = des;
	precio = pre;
	horaPtr = ptrH;
}

Ruta::~Ruta() {
	if (horaPtr != NULL) {
		delete horaPtr; // Eliminar el objeto dinamico vinculado a Ruta.
	}
}
// Mutadores (set's)
void Ruta::setOrigen(string ori) { origen = ori; }
void Ruta::setDestino(string des) { destino = des; }
void Ruta::setPrecio(double pre) { precio = pre; }
void Ruta::setHora(Hora* ptrH) {
	if (horaPtr != NULL) delete horaPtr;
	horaPtr = ptrH;
}
// Accesores (get's)
string Ruta::getOrigen() { return origen; }
string Ruta::getDestino() { return destino; }
double Ruta::getPrecio() { return precio; }
Hora* Ruta::getHora() { return horaPtr; }
// toString()
string Ruta::toString() {
	stringstream s;
	s << "---------------Ruta-------------" << endl
		<< "Origen...." << origen << endl
		<< "Destino..." << destino << endl
		<< "Precio...." << precio << endl;
	if (horaPtr != NULL) { // Si hay una hora vinculada al objeto Ruta..
		s << "La hora de salida es: " << horaPtr->toString() << endl;
	}
	return s.str();
}