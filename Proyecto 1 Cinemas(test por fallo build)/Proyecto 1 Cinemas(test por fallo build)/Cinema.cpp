#include "Cinema.h"

Cinema::Cinema(int tam) {
	tama = tam;
	cant = 0;
	vecSala = new Sala * [tama];
	for (int i = 0; i < tama; i++) {
		vecSala[i] = NULL;
	}
	cantPosible = 0;
	for (int i = 0; i < 2196; i++) {
		vecPosibleSala[i] = 0;
		vecPosibleDia[i] = 0;
		vecPosibleHora[i] = 0;
	}
	cantAsientos = 0;
	for (int i = 0; i < 60; i++) {
		vecFilas[i] = ' ';
		vecColumnas[i] = 0;
	}
}
Cinema::~Cinema() {
	for (int i = 0; i < cant; i++) {
		if (vecSala[i] != NULL) delete vecSala[i];
	}
	delete[] vecSala;
}

int Cinema::getCantidad() { return cant; }
bool Cinema::ingresarSala(Sala* sa) {
	if (cant < tama) {
		vecSala[cant++] = sa;
		cout << "Se ha ingresado correctamente." << endl;
		return true;
	}
	else {
		cout << "No se pueden ingresar mas salas!!!" << endl;
		return false;
	}
}

Sala* Cinema::getSala(int sala) { return vecSala[sala]; }

void Cinema::devolverValores() {
	for (int i = 0; i < cantPosible; i++) {
		vecPosibleSala[i] = 0;
		vecPosibleDia[i] = 0;
		vecPosibleHora[i] = 0;
	}
	cantPosible = 0;
}

int Cinema::getCantPosible() { return cantPosible++; }

int Cinema::getPosibleSala(int pos) {
	return vecPosibleSala[pos];
}

int Cinema::getPosibleDia(int pos) {
	return vecPosibleDia[pos];
}

int Cinema::getPosibleHora(int pos) {
	return vecPosibleHora[pos];
}

void Cinema::devolverAsientos() {
	for (int i = 0; i < cantAsientos; i++) {
		vecFilas[i] = ' ';
		vecColumnas[i] = 0;
	}
	cantAsientos = 0;
}
string Cinema::getAsientosComprados() {
	stringstream s;
	for (int i = 0; i < cantAsientos; i++) {
		s << vecFilas[i] << vecColumnas[i];
		if (i != cantAsientos - 1) {
			s << ", ";
		}
	}
	return s.str();
}

string Cinema::toString() {
	stringstream s;
	s << "CARTELERA: " << endl;
	for (int i = 0; i < cant; i++) {
		for (int j = 0; j < 366; j++) {
			for (int k = 0; k < 3; k++) {
				if (vecSala[i]->getDia(j)->getHora(k)->getFuncion() != NULL) {
					vecPosibleSala[cantPosible] = i;
					vecPosibleDia[cantPosible] = j;
					vecPosibleHora[cantPosible] = k;
					cantPosible++;
					s << cantPosible << ": " << endl;
					s << vecSala[i]->getDia(j)->getHora(k)->toString();
					s << vecSala[i]->getDia(j)->DiaAFecha(j + 1, vecSala[i]->getDia(j)->getAnnio());
					s << vecSala[i]->getNombre();
					if (vecSala[i]->getTipoSala() == 'r') {
						s << " (Tipo: Regular)" << endl;
					}
					else if (vecSala[i]->getTipoSala() == 'v') {
						s << " (Tipo: VIP)" << endl;
					}
					s << endl;
				}
			}
		}
	}
	return s.str();
}

string Cinema::toStringGenero(string gen) {
	stringstream s;
	s << "CARTELERA POR GENERO: " << gen << endl;
	for (int i = 0; i < cant; i++) {
		for (int j = 0; j < 366; j++) {
			for (int k = 0; k < 3; k++) {
				Hora* temp = vecSala[i]->getDia(j)->getHora(k);
				if (temp->getFuncion() != NULL) {
					if (temp->getFuncion()->getPelicula()->getGenero() == gen) {
						vecPosibleSala[cantPosible] = i;
						vecPosibleDia[cantPosible] = j;
						vecPosibleHora[cantPosible] = k;
						cantPosible++;
						s << cantPosible << ": " << endl; 
						s << temp->toString() << vecSala[i]->getDia(j)->DiaAFecha(j + 1, vecSala[i]->getDia(j)->getAnnio());
						s << vecSala[i]->getNombre();
						if (vecSala[i]->getTipoSala() == 'r') {
							s << " (Tipo: Regular)" << endl;
						}
						else if (vecSala[i]->getTipoSala() == 'v') {
							s << " (Tipo: VIP)" << endl;
						}
					}
				}
			}
		}
	}
	return s.str();
}

string Cinema::toStringNombre(string nom) {
	stringstream s;
	s << "CARTELERA POR NOMBRE: " << nom << endl;
	for (int i = 0; i < cant; i++) {
		for (int j = 0; j < 366; j++) {
			for (int k = 0; k < 3; k++) {
				Hora* temp = vecSala[i]->getDia(j)->getHora(k);
				if (temp->getFuncion() != NULL) {
					if (temp->getFuncion()->getPelicula()->getNombre() == nom) {
						vecPosibleSala[cantPosible] = i;
						vecPosibleDia[cantPosible] = j;
						vecPosibleHora[cantPosible] = k;
						cantPosible++;
						s << cantPosible << ": " << endl;
						s << temp->toString() << vecSala[i]->getDia(j)->DiaAFecha(j + 1, vecSala[i]->getDia(j)->getAnnio());
						s << vecSala[i]->getNombre();
						if (vecSala[i]->getTipoSala() == 'r') {
							s << " (Tipo: Regular)" << endl;
						}
						else if (vecSala[i]->getTipoSala() == 'v') {
							s << " (Tipo: VIP)" << endl;
						}
					}
				}
			}
		}
	}
	return s.str();
}

string Cinema::toStringTipoLenguaje(char tipLen) {
	stringstream s;
	if (tipLen == 's') {
		s << "CARTELERA SUBTITULADA: " << endl;
	}
	else if (tipLen == 'd') {
		s << "CARTELERA DOBLADA: " << endl;
	}
	for (int i = 0; i < cant; i++) {
		for (int j = 0; j < 366; j++) {
			for (int k = 0; k < 3; k++) {
				Hora* temp = vecSala[i]->getDia(j)->getHora(k);
				if (temp->getFuncion() != NULL) {
					if (temp->getFuncion()->getTipoLenguaje() == tipLen) {
						vecPosibleSala[cantPosible] = i;
						vecPosibleDia[cantPosible] = j;
						vecPosibleHora[cantPosible] = k;
						cantPosible++;
						s << cantPosible << ": " << endl;
						s << temp->toString() << vecSala[i]->getDia(j)->DiaAFecha(j + 1, vecSala[i]->getDia(j)->getAnnio());
						s << vecSala[i]->getNombre();
						if (vecSala[i]->getTipoSala() == 'r') {
							s << " (Tipo: Regular)" << endl;
						}
						else if (vecSala[i]->getTipoSala() == 'v') {
							s << " (Tipo: VIP)" << endl;
						}
					}
				}
			}
		}
	}
	return s.str();
}

string Cinema::toStringDimensiones(int dim) {
	stringstream s;
	s << "CARTELERA POR DIMENSION " << dim << "D" << endl;
	for (int i = 0; i < cant; i++) {
		for (int j = 0; j < 366; j++) {
			for (int k = 0; k < 3; k++) {
				Hora* temp = vecSala[i]->getDia(j)->getHora(k);
				if (temp->getFuncion() != NULL) {
					if (temp->getFuncion()->getDimensiones() == dim) {
						vecPosibleSala[cantPosible] = i;
						vecPosibleDia[cantPosible] = j;
						vecPosibleHora[cantPosible] = k;
						cantPosible++;
						s << cantPosible << ": " << endl;
						s << temp->toString() << vecSala[i]->getDia(j)->DiaAFecha(j + 1, vecSala[i]->getDia(j)->getAnnio());
						s << vecSala[i]->getNombre();
						if (vecSala[i]->getTipoSala() == 'r') {
							s << " (Tipo: Regular)" << endl;
						}
						else if (vecSala[i]->getTipoSala() == 'v') {
							s << " (Tipo: VIP)" << endl;
						}
					}
				}
			}
		}
	}
	return s.str();
}

string Cinema::toStringTipoSala(char tipSal) {
	stringstream s;
	if (tipSal == 'r') {
		s << "CARTELERA POR SALA REGULAR" << endl;
	}
	else if (tipSal == 'v') {
		s << "CARTELERA POR SALA VIP" << endl;
	}
	for (int i = 0; i < cant; i++) {
		if (vecSala[i]->getTipoSala() == tipSal) {
			s << vecSala[i]->toString() << endl;
		}
	}
	return s.str();
}

string Cinema::toStringTipoPublico(bool tipPu) {
	stringstream s;
	if (tipPu == true) {
		s << "CARTELERA PARA NINNOS" << endl;
	}
	else {
		s << "CARTELERA PARA ADULTOS" << endl;
	}
	for (int i = 0; i < cant; i++) {
		for (int j = 0; j < 366; j++) {
			for (int k = 0; k < 3; k++) {
				Hora* temp = vecSala[i]->getDia(j)->getHora(k);
				if (temp->getFuncion() != NULL) {
					if (temp->getFuncion()->getPelicula()->getParaNinnos() == tipPu) {
						vecPosibleSala[cantPosible] = i;
						vecPosibleDia[cantPosible] = j;
						vecPosibleHora[cantPosible] = k;
						cantPosible++;
						s << cantPosible << ": " << endl;
						s << temp->toString() << vecSala[i]->getDia(j)->DiaAFecha(j + 1, vecSala[i]->getDia(j)->getAnnio());
						s << vecSala[i]->getNombre();
						if (vecSala[i]->getTipoSala() == 'r') {
							s << " (Tipo: Regular)" << endl;
						}
						else if (vecSala[i]->getTipoSala() == 'v') {
							s << " (Tipo: VIP)" << endl;
						}
					}
				}
			}
		}
	}
	return s.str();
}

string Cinema::toStringFuncion(int sala, int dia, int hora) {
	stringstream s;
	s << vecSala[sala]->getDia(dia)->getHora(hora)->toStringDespuesCompra();
	s << vecSala[sala]->getDia(dia)->DiaAFecha(dia + 1, vecSala[sala]->getDia(dia)->getAnnio());
	s << vecSala[sala]->getNombre();
	if (vecSala[sala]->getTipoSala() == 'r') {
		s << " (Tipo: Regular)" << endl;
	}
	else if (vecSala[sala]->getTipoSala() == 'v') {
		s << " (Tipo: VIP)" << endl;
	}
	return s.str();
}

int Cinema::FehcaADia(int dia, int mes, int annio) {
	int counter = 0;
	if (annio % 4 == 0 && annio % 100 == 0 && annio % 400 == 0) {
		switch (mes) {
		case 1:
			counter += dia;
			break;
		case 2:
			counter += 31 + dia;
			break;
		case 3:
			counter += 31 + 29 + dia;
			break;
		case 4:
			counter += 31 + 29 + 31 + dia;
			break;
		case 5:
			counter += 31 + 29 + 31 + 30 + dia;
			break;
		case 6:
			counter += 31 + 29 + 31 + 30 + 31 + dia;
			break;
		case 7:
			counter += 31 + 29 + 31 + 30 + 31 + 30 + dia;
			break;
		case 8:
			counter += 31 + 29 + 31 + 30 + 31 + 30 + 31 + dia;
			break;
		case 9:
			counter += 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + dia;
			break;
		case 10:
			counter += 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + dia;
			break;
		case 11:
			counter += 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + dia;
			break;
		case 12:
			counter += 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + dia;
			break;
		}
	}
	else {
		switch (mes) {
		case 1:
			counter += dia;
			break;
		case 2:
			counter += 31 + dia;
			break;
		case 3:
			counter += 31 + 28 + dia;
			break;
		case 4:
			counter += 31 + 28 + 31 + dia;
			break;
		case 5:
			counter += 31 + 28 + 31 + 30 + dia;
			break;
		case 6:
			counter += 31 + 28 + 31 + 30 + 31 + dia;
			break;
		case 7:
			counter += 31 + 28 + 31 + 30 + 31 + 30 + dia;
			break;
		case 8:
			counter += 31 + 28 + 31 + 30 + 31 + 30 + 31 + dia;
			break;
		case 9:
			counter += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + dia;
			break;
		case 10:
			counter += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + dia;
			break;
		case 11:
			counter += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + dia;
			break;
		case 12:
			counter += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + dia;
			break;
		}
	}
	return counter;
}

bool Cinema::ingresarFuncion(Funcion* fun, int sala, int dia, int hora) {
	if (vecSala[sala]->getDia(dia)->getHora(hora)->getFuncion() == NULL) {
		vecSala[sala]->getDia(dia)->getHora(hora)->setFuncion(fun);
		return true;
	}
	else {
		cout << "Ya existe una Funcion a esa hora";
		return false;
	}
}

float Cinema::comprarTiquetes(int numAdu, int numNin, int sala, int dia, int hora) {
	int totalTiquetes = numAdu + numNin;
	float precio = 0;
	if (totalTiquetes <= vecSala[sala]->getDia(dia)->getHora(hora)->getDisponible()) {
		if (vecSala[sala]->getTipoSala() == 'r') {
			precio += 3000 * numNin;
			precio += 5000 * numAdu;
		}
		else if (vecSala[sala]->getTipoSala() == 'v') {
			precio += 4500 * numNin;
			precio += 6500 * numAdu;
		}
	}
	else {
		cout << "No hay suficientes asientos en la sala" << endl;
	}
	return precio;
}

bool Cinema::comprarAsiento(int sala, int dia, int hora, char fila, int columna) {
	Hora* temp = vecSala[sala]->getDia(dia)->getHora(hora);
	if (temp->getFuncion() != NULL) {
		if (temp->getAsiento(fila, columna)->getColor() == 'V') {
			vecFilas[cantAsientos] = fila;
			vecColumnas[cantAsientos] = columna;
			cantAsientos++;
			temp->getAsiento(fila, columna)->setColor('G');
			cout << temp->toStringAsientos() << endl;
			return true;
		}
		else {
			cout << "Asiento ya esta comprado" << endl;
			return false;
		}
	}
	else {
		cout << "No hay funcion en ese horario" << endl;
		return false;
	}
}

bool Cinema::confirmarAsiento(int sala, int dia, int hora, string ced) {
	int counter = 0;
	Hora* temp = vecSala[sala]->getDia(dia)->getHora(hora);
	for (int i = 'A'; i <= 'F'; i++) {
		for (int j = 1; j <= 10; j++) {
			if (temp->getAsiento(i, j)->getColor() == 'G') {
				temp->getAsiento(i, j)->setColor('R');
				temp->getAsiento(i, j)->setCedula(ced);
				counter++;
			}
		}
	}
	temp->compraronAsiento(counter);
	cout << temp->toStringAsientos() << endl;
	return true;
}

bool Cinema::cancelanAsiento(int sala, int dia, int hora) {
	Hora* temp = vecSala[sala]->getDia(dia)->getHora(hora);
	for (int i = 'A'; i <= 'F'; i++) {
		for (int j = 1; j <= 10; j++) {
			if (temp->getAsiento(i, j)->getColor() == 'G') {
				temp->getAsiento(i, j)->setColor('V');
			}
		}
	}
	cout << temp->toStringAsientos() << endl;
	return true;
}
