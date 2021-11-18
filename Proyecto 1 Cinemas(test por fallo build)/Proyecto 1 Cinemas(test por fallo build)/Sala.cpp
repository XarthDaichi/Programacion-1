#include "Sala.h"

Sala::Sala(string nom, int annio, char tipS) :nombre(nom), tipoSala(tipS) {
	for (int i = 0; i < 366; i++) {
		vec[i] = new Dia(i + 1, annio);
	}
}
Sala::~Sala() {
	for (int i = 0; i < 366; i++) {
		delete vec[i];
	}
}

string Sala::getNombre() { return nombre; }

void Sala::setTipoSala(char tipS) { tipoSala = tipS; }
char Sala::getTipoSala() { return tipoSala; }

Dia* Sala::getDia(int d) { return vec[d]; }

string Sala::toString() const {
	stringstream s;
	for (int i = 0; i < 366; i++) {
		for (int j = 0; j < 3; j++) {
			if (vec[i]->getHora(j)->getFuncion() != NULL) {
				s << vec[i]->getHora(j)->toString();
				s << vec[i]->DiaAFecha(i + 1, vec[i]->getAnnio());
				s << nombre;
				if (tipoSala == 'r') {
					s << " (Tipo: Regular)" << endl;
				}
				else if (tipoSala == 'v') {
					s << " (Tipo: VIP)" << endl;
				}
				s << endl;
			}
		}

	}
	return s.str();
}