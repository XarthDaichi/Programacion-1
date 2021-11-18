#include "Hora.h"

Hora::Hora(int ho, int mi, int se){
	h = ho;
	m = mi;
	s = se;
}
Hora::~Hora() {}
//Mutadoes (set's)
void Hora::setHoras(int ho) { h = ho; }
void Hora::setMinutos(int mi) { m = mi; }
void Hora::setSegundos(int se) { s = se; }
//Accesores (get's)
int Hora::getHoras() { return h; }
int Hora::getMinutos() { return m; }
int Hora::getSegundos() { return s; }
//toString()
string Hora::toString() {
	stringstream r;
	r << "->" << h << ":" << m << ":" << s << endl;
	return r.str();
}