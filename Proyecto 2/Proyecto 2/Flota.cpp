#include "Flota.h"

string Flota::getCategoria(string marca) {
	stringstream s;
	int temp;
	s << toupper(marca.at(0)) << toupper(marca.at(1));
	if (!isdigit(marca.at(marca.length() - 1))) {
		s << toupper(marca.at(2)) << "-1";
	}
	else {
		if (!isdigit(marca.at(marca.length() - 2))) {
			s << toupper(marca.at(2)) << "-" << marca.at(marca.length() - 1);
		}
		else {

		}
	}
	return s.str(); 
}

string Flota::getCodigo() {
	stringstream s;

	return s.str();
}