#include"Habitacion.h"

Habitacion::Habitacion(int numH, int numAd, int numNi, char est, bool des): numHabitacion(numH), numCamasAdult(numAd), numCamasNinos(numNi), estado(est), desc(des) {}
Habitacion::~Habitacion(){}
void Habitacion::setNumHabitacion(int nH) { numHabitacion = nH; }
void Habitacion::setEstado(char mant) { estado = mant; }
void Habitacion::setDesc(bool des) { desc = des; }
int Habitacion::getNumHabitacion() { return numHabitacion; }
char Habitacion::getEstado() { return estado; }
bool Habitacion::getDesc() { return desc; }
string Habitacion::toString() const {
	stringstream s;
	s << "[Hab: " << numHabitacion << " Est: " << estado<<"] ";
	return s.str();
}