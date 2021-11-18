#include"ContenedorM.h"

ContenedorM::ContenedorM(){
	int num = 1;
	filas = 4;
	colum = 6;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < colum; j++) {
			mat[i][j] = new Habitacion(num++, 2, 3, 'D', false);
		}
	}
}

ContenedorM::~ContenedorM(){
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < colum; j++)
			delete mat[i][j];
}

void ContenedorM::imprimeContenedor(){
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < colum; j++)
			cout << mat[i][j]->toString()<<"'\t'";
		cout << endl;
	}
}

bool ContenedorM::establecerEstadoDeHabitacion(int num, char est, bool desc){
	if (num <= 6 && num >= 1) {
		if (mat[0][num - 1]->getEstado() == 'O') {
			if (est == 'O') {
				return false;
			}
		}
		else {
			mat[0][num - 1]->setEstado(est);
			mat[0][num - 1]->setDesc(desc);
			return true;
		}
	}
	else if (num >= 7 && num <= 12) {
		if (mat[1][num - 7]->getEstado() == 'O') {
			if (est == 'O') {
				return false;
			}
		}
		else {
			mat[1][num - 7]->setEstado(est);
			mat[1][num - 7]->setDesc(desc);
			return true;
		}
	} 
	else if (num >= 13 && num <= 18) {
		if (mat[2][num - 13]->getEstado() == 'O') {
			if (est == 'O') {
				return false;
			}
		}
		else {
			mat[2][num - 13]->setEstado(est);
			mat[2][num - 13]->setDesc(desc);
			return true;
		}
	}
	else if (num >= 19 && num <= 24) {
		if (mat[3][num - 19]->getEstado() == 'O') {
			if (est == 'O') {
				return false;
			}
		}
		else {
			mat[3][num - 19]->setEstado(est);
			mat[2][num - 19]->setDesc(desc);
			return true;
		}
	}
	return false;
}

Habitacion* ContenedorM::obtenerHabitacion(int i, int j){
	if (i >= 0 && i < filas && j >= 0 && j < colum) {
		return mat[i][j];
	}
	else
		return NULL;
}

double ContenedorM::calculoAPagarPorHabitacion(int i, int j) {

	if (mat[i][j] != NULL) {
		if (mat[i][j]->getEstado() == 'O') {
			if (mat[i][j]->getDesc() == true) {
				return 62500.00;
			}
			else {
				return 85000.00;
			}
		}
	}
	return 0.00;
}

double ContenedorM::obtenerRecaudoDiarioTotal() {
	double total = 0;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < colum; j++) {
			total += this->calculoAPagarPorHabitacion(i, j);
		}
	}
	return total;
}