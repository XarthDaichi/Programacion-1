#include "Contenedor.h"

Contenedor::Contenedor(int tamd, int tamp) {
	vecD = new Director * [tamd];
	tamD = tamd;
	canD = 0;
	for (int i = 0; i < tamD; i++) {
		vecD[i] = NULL;
	}

	vecP = new Pelicula * [tamp];
	tamP = tamp;
	canP = 0;
	for (int i = 0; i < tamP; i++) {
		vecP[i] = NULL;
	}
}

Contenedor::~Contenedor() {
	for (int i = 0, int j = 0; i < canD, j < canP; i++, j++) {
		if (vecD[i]) delete vecD[i];
		if (vecP[j]) delete vecP[j];
		delete[] vecD;
		delete[] vecP;
	}
}

string Contenedor::getNombreStudio() { return nombreStudio; }
void Contenedor::setNombreStudio(string nom) { nombreStudio = nom; }

bool Contenedor::ingresarPelicula(Pelicula* pelPtr) {
	if (canP < tamP) {
		vecP[canP++] = pelPtr;
		return true;
	}
	return false;
}
bool Contenedor::eliminarPelicula(string cod) {
	for (int i = 0; i < canP; i++) {
		if (vecP[i]->getCodigo() == cod) {
			vecP[i]->getDirector()->eliminarPelicula();
			vecP[i]->getDirector()->updateCalificacion(-(vecP[i]->getCalificacion()));
			for (int j = i; j < canP; j++) {
				Pelicula* temp = vecP[j];
				vecP[j] = vecP[j + 1];
				vecP[j + 1] = temp;
			}
			delete vecP[canP--];
			return true;
		}
	}
	return false;
}

bool Contenedor::ingresarDirector(Director* dirPtr) {
	if (canD < tamD) {
		vecD[canD++] = dirPtr;
		return true;
	}
	return false;
}

bool Contenedor::eliminarDirector(string id) {
	for (int i = 0; i < canD; i++) {
		if (vecD[i]->getId() == id) {
			for (int j = 0; j < canP; j++) {
				if (vecP[j]->getDirector()->getId() == id) {
					for (int k = j; k < canP; k++) {
						Pelicula* temp = vecP[k];
						vecP[k] = vecP[k + 1];
						vecP[k + 1] = temp;
					}
					delete vecP[canP--];
				}
			}
			for (int j = i; j < canD; j++) {
				Director* temp = vecD[j];
				vecD[j] = vecD[j + 1];
				vecD[j + 1] = temp;
			}
			delete vecD[canD--];
		}
	}
}

string Contenedor::toString() {

}