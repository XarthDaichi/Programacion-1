#include"Supervisor.h"


Supervisor::Supervisor(int id, string nom, string cat, Fecha* fc, double cuo, double totVen, double porcCom, double porcRec)
	:Vendedor(id, nom, cat, fc, cuo, totVen, porcCom), porcentajeRecargo(porcRec) { tipo = 'S'; }
Supervisor::~Supervisor() {}
double Supervisor::getPorcentRecargo() { return porcentajeRecargo; }
void Supervisor::setPorcentRecargo(double porcRec) { porcentajeRecargo = porcRec; }
string Supervisor::toString() const {
	stringstream s;
	s << Vendedor::toString() << '\t' << porcentajeRecargo << endl;
	return s.str();
}
double Supervisor::salario() {
	double sal = 320.0;
	if (totalVentas > cuota) {
		sal += sal * porcentajeComision;
	}
	sal += sal * porcentajeRecargo;
	sal += sal * CategTrabajador::bonoBeneficio(categoria);
	return sal;
}

void Supervisor::guardar(ostream& out) {
	Vendedor::guardar(out);
	out << porcentajeRecargo << FIN_CAMPO;
}