#include"Vendedor.h"

Vendedor::Vendedor(int id, string nom, string cat, Fecha* fc, double cuo, double totVen, double porcCom)
	:Empleado(id, nom, cat, fc), cuota(cuo), totalVentas(totVen), porcentajeComision(porcCom) { tipo = 'V'; }
Vendedor::~Vendedor() {}
double Vendedor::getCuota() { return cuota; }
double Vendedor::getTotalVentas() { return totalVentas; }
double Vendedor::getPorcentajeComision() { return porcentajeComision; }
void Vendedor::setCuota(double cuo) { cuota = cuo; }
void Vendedor::setTotalVentas(double tV) { totalVentas = tV; }
void Vendedor::setPorcentajeComision(double pC) { porcentajeComision = pC; }
string Vendedor::toString() const {
	stringstream s;
	s << Empleado::toString() << '\t' << cuota << '\t' << totalVentas << '\t' << porcentajeComision;
	return s.str();
}
double Vendedor::salario() {
	double sal = 320.0;
	if (totalVentas > cuota) {
		sal += sal * porcentajeComision;
	}
	sal += sal * CategTrabajador::bonoBeneficio(categoria);
	return sal;
}

void Vendedor::guardar(ostream& out) {
	Empleado::guardar(out);
	out << cuota << FIN_CAMPO
		<< totalVentas << FIN_CAMPO
		<< porcentajeComision << FIN_CAMPO;
}