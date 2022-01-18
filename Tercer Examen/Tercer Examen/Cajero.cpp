#include"Cajero.h"


Cajero::Cajero(int id, string nom, string cat, Fecha* fc, int hT, double sXh)
	:Empleado(id, nom, cat, fc), horasTrabajadas(hT), salarioXhora(sXh) { tipo = 'C'; }
Cajero::~Cajero() { }
int Cajero::getHorasTrabajadas() { return horasTrabajadas; }
double Cajero::getSalarioXHora() { return salarioXhora; }
void Cajero::setHorasTrabajadas(int hT) { horasTrabajadas = hT; }
void Cajero::setSalarioXHora(double sXh) { salarioXhora = sXh; }
string Cajero::toString() const {
	stringstream s;
	s << Empleado::toString() << '\t' << horasTrabajadas << '\t' << salarioXhora;
	return s.str();
}

double Cajero::salario() {
	double sal = 0.0;
	if (horasTrabajadas > 48) {
		sal += ((double) horasTrabajadas - 48.0) * 2 * salarioXhora;
		sal += 48.0 * salarioXhora;
	}
	else {
		sal += (double)horasTrabajadas * salarioXhora;
	}
	sal += sal * CategTrabajador::bonoBeneficio(categoria);
	return sal;
}

void Cajero::guardar(ostream& out) {
	Empleado::guardar(out);
	out << horasTrabajadas << FIN_CAMPO
		<< salarioXhora << FIN_CAMPO;
}