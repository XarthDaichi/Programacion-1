#include"ContenedoraDob.h"
ContenedoraDob::ContenedoraDob(int tamd, int tamp) {
	canD = 0;
	canP = 0;
	tamD = tamd;
	tamP = tamp;
	vec1 = new Director * [tamD];
	vec2 = new Pelicula * [tamP];
	for (int i = 0; i < tamD; i++) {
		vec1[i] = NULL;
	}
	for (int j = 0; j < tamP; j++) {
		vec2[j] = NULL;
	}
}
ContenedoraDob::~ContenedoraDob() {
	for (int i = 0; i < tamD; i++)
		delete vec1[i];
	delete[]vec1;
	for (int j = 0; j < tamP; j++)
		delete vec2[j];
	delete[]vec2;
}
void ContenedoraDob::setNombreStudio(string ns) {
	nombreStudio = ns;
}
string ContenedoraDob::getNombreStudio()const {
	return nombreStudio;
}
string ContenedoraDob::toStringDir()const {
	stringstream s;
	s << "\t\tNombre del Estudio: " << nombreStudio << endl;
	s << "\t\t----- LISTADO DE DIRECTORES ----- " << endl;
	for (int i = 0; i < canD; i++) {
		s << vec1[i]->toString() << endl;
	}
	s << "\t\t----- FIN DEL LISTADO ----- " << endl;
	return s.str();
}
string ContenedoraDob::toStringPeli()const {
	stringstream s;
	s << "\t\tNombre del Estudio: " << nombreStudio << endl;
	if (vec2[0] != NULL) {
		s << "\t\t----- LISTADO DE PELICULAS Y SUS DIRECTORES ----- " << endl;
		for (int j = 0; j < canP; j++) {
			s << vec2[j]->toString() << endl;
		}
	}
	s << "\t\t----- FIN DEL LISTADO ----- " << endl;
	return s.str();
}
bool ContenedoraDob::insertaDir(Director* di) {
	if (canD < tamD) {
		vec1[canD] = di;
		canD++;
		return true;
	}
	else
		return false;
}
bool ContenedoraDob::insertaPel(string id, Pelicula* peli) {
	for (int i = 0; i < canD; i++) {
		if (vec1[i]->getId() == id) {
			if (canP < tamP) {
				vec2[canP] = peli;
				canP++;
				return true;
			}
		}
	}
	return false;
}
//void ContenedoraDob::eliminarPelicula(string cod) {
//	for (int j = 0; j < canP; j++) {
//		if (vec2[j]->getCodigo() == cod) {
//			vec2[j] = NULL;
//		}
//	}
//}
void ContenedoraDob::peliculasDirector(string id) {
	bool bandera = false;
	for (int i = 0; i < canD; i++) {
		if (vec1[i]->getId() == id) {
			cout << toStringPeli() << endl;
			}
		
		}
	if (bandera == false) {
		cout << "\t\tNo hay ningun director con esa identificacion" << endl;
	}
}
float ContenedoraDob::totalRecaudadoCaridad() {
	float monto = 0;
	if (vec2[0] != NULL) {
		for (int j = 0; j < canP; j++) {
			monto += (double)vec2[j]->calculoCaridad();
		}
	}
	return monto;
}
float ContenedoraDob::califDirector(string id) {
	float total = 0;
	if (vec2[0] != NULL) {
		for (int i = 0; i < canD; i++) {
			if (vec1[i]->getId() == id) {
				for (int j = 0; j < canP; j++) {
					total += vec2[j]->getCalif();
				}
			}
		}
	}
	return total/canP;
}
void ContenedoraDob::actualizaCalifDir(string id) {
	for (int i = 0; i < canD; i++)
		if (vec1[i]->getId() == id) {
			vec1[i]->setCalificacion(califDirector(id));
		}
}