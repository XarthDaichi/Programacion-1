#include "ContenedorM.h"

ContenedorM::ContenedorM(int fi, int co) : fila(fi), colu(co) {
	mat = new SuperClass * *[fila];
	for (int i = 0; i < fila; i++) {
		mat[i] = new SuperClass * [colu];
	}
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < colu; j++) {
			mat[i][j] = NULL;
		}
	}
}

ContenedorM::~ContenedorM() {
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < colu; j++) {
			delete mat[i][j];
		}
	}
	for (int i = 0; i < fila; i++) {

	}
}	