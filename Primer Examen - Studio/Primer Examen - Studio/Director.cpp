#include"Director.h"
Director::Director() {
	id = "";
	nombre = "";
	calificacion = 0.0;
}
Director::Director(string i, string nom, float calif) {
	id = i;
	nombre = nom;
	calificacion = calif;
}
Director::~Director(){
}
void Director::setId(string ident) {
	id = ident;
}
void Director::setNombre(string nomb) {
	nombre = nomb;
}
void Director::setCalificacion(float cali) {
	calificacion = cali;
}
string Director::getId()const {
	return id;
}
string Director::getNombre()const {
	return nombre;
}
float Director::getCalificacion()const {
	return calificacion;
}
string Director::toString()const {
	stringstream s;
	s << "\t\tIdentificacion del director: " << id << endl
		<< "\t\tNombre del director: " << nombre << endl
		<< "\t\tCalificacion del director: " << calificacion << endl;
	return s.str();
}