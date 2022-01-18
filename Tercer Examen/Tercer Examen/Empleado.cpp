#include"Empleado.h"

Empleado::Empleado(int id, string nom, string cat, Fecha* fc) : ID(id), nombre(nom), categoria(cat), fec(fc), tipo(' ') {
}
Empleado::~Empleado() { if (fec) delete fec; }
int Empleado::getID() { return ID; }
string Empleado::getNombre() { return nombre; }
string Empleado::getCategoria() { return categoria; }
Fecha* Empleado::getFecha() { return fec; }
void Empleado::setID(int id) { ID = id; }
void Empleado::setNombre(string nom) { nombre = nom; }
void Empleado::setCategoria(string c) { categoria = c; }
void Empleado::setFecha(Fecha* fc) { fec = fc; }
void Empleado::setTipo(char tip) { tipo = tip; }
char Empleado::getTipo() { return tipo; }
bool Empleado::esIgualA(int id) { return ID == id; }

bool Empleado::esMismoDia(Fecha* fe) {
	return fec->getDia() == fe->getDia() && fec->getMes() == fe->getMes() && fec->getAnio() == fe->getAnio();
}
string Empleado::toString() const {
	stringstream s;
	s << "  -> " << ID << '\t' << nombre << '\t' << categoria << '\t';
	if (fec != NULL)
		s << fec->toString();
	return s.str();
}

double Empleado::salario() {
	return 0.0;
}

void Empleado::guardar(ostream& out) {
	out << ID << FIN_CAMPO
		<< nombre << FIN_CAMPO
		<< categoria << FIN_CAMPO
		<< tipo << FIN_CAMPO
		<< fec->getDia() << FIN_CAMPO
		<< fec->getMes() << FIN_CAMPO
		<< fec->getAnio() << FIN_CAMPO;
}