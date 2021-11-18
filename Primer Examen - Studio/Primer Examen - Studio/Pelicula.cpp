#include"Pelicula.h"
//inicializacion de la variable static
double Pelicula::porcentajeCari = 0.05;

Pelicula::Pelicula() {
	codigo = "";
	nombreP = "";
	genero = "";
	calif = 0, 0;
	recaudado = 0, 0;
	dir = NULL;
}
Pelicula::Pelicula(string cod, string nomP, string gen, float cal, float rec, Director* dptr) {
	codigo = cod;
	nombreP = nomP;
	genero = gen;
	calif = cal;
	recaudado = rec;
	dir = dptr;
}
Pelicula::~Pelicula() {
}
void Pelicula::setCodigo(string co) {
	codigo = co;
}
void Pelicula::setNombreP(string nP) {
	nombreP = nP;
}
void Pelicula::setGenero(string ge) {
	genero = ge;
}
void Pelicula::setCalif(float ca) {
	calif = ca;
}
void Pelicula::setRecaudado(float re) {
	recaudado = re;
}
void Pelicula::setPorcentaje(double porc) {
	porcentajeCari = porc;
}
void Pelicula::setDirector(Director* dirptr) {
	dir = dirptr;
}
string Pelicula::getCodigo()const {
	return codigo;
}
string Pelicula::getNombreP()const {
	return nombreP;
}
string Pelicula::getGenero()const {
	return genero;
}
float Pelicula::getCalif()const {
	return calif;
}
float Pelicula::getRecaudado()const {
	return recaudado;
}
double Pelicula::getPorcentajeCari() {
	return porcentajeCari;
}
Director* Pelicula::getDirector()const {
	return dir;
}
double Pelicula::calculoCaridad() {
	double total = 0;
	total =  recaudado * porcentajeCari;
	return total;
}
string Pelicula::toString()const {
	stringstream s;
	s << "\t\tCodigo de la Pelicula: " << codigo << endl
		<< "\t\tNombre de la Pelicula: " << nombreP << endl
		<< "\t\tGenero de la Pelicula: " << genero << endl
		<< "\t\tCalificacion de la Pelicula: " << calif << endl
		<< "\t\tDinero recaudado: " << recaudado << endl;
	if (dir != NULL) {
		s << "\t\t----- DIRECTOR ----- " << endl;
		s << dir->toString() << endl;
	}
	else{
		s << "\t\t***** La pelicula aun no tiene director ***** " << endl;
	}
	return s.str();
}