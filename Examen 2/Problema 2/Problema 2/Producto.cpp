#include"Producto.h"

Producto::Producto(string nom, double pre) :nombreP(nom), precioP(pre){}
Producto::~Producto() {}
string Producto::getNombreP() { return nombreP; }
double Producto::getPrecioP() { return precioP; }
string Producto::toString() {
	stringstream s;
	s << "    Nombre del producto..." << nombreP <<"'\t' Precio = " << precioP << endl;
	return s.str();
}

bool Producto::esIgualA(Producto& pro2) {
	return this->getNombreP() == pro2.getNombreP() && this->getPrecioP() == pro2.getPrecioP();
}
