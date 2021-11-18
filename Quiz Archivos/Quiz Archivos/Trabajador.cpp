#include "Trabajador.h"
#define FIN_CAMPO '\t'
#define FIN_REGISTRO '\n'

Trabajador::Trabajador(string ced, string nom, double sal, double pDT) : Persona(ced, nom), _salario(sal), _porcDeducTot(pDT) { veh = NULL; }
Trabajador::Trabajador(string ced, string nom, double sal, double pDT, string mar, string mod, int cili) : Persona(ced, nom), _salario(sal), _porcDeducTot(pDT) { veh = new Vehiculo(mar, mod, cili); }

Trabajador::~Trabajador() { if (veh) delete veh; }

void Trabajador::setSalario(double sal) { _salario = sal; }
double Trabajador::getSalario() { return _salario; }

void Trabajador::setPorcDeducTot(double pDT) { _porcDeducTot = pDT; }
double Trabajador::getPorcDeducTot() { return _porcDeducTot; }

bool Trabajador::asociarVehiculo(Vehiculo* ve) { 
	if (veh) {
		return false;
	}
	else {
		veh = ve;
		return true;
	}
}


string Trabajador::toString() {
	stringstream s;
	s << "Cedula: " << _cedula << endl
		<< "Nombre: " << _nombre << endl
		<< "Salario: " << _salario << endl
		<< "Porcentaje de Deduccion Total: " << _porcDeducTot << endl;
	if (veh) s << "Vehiculo: \n" << veh->toString();
	return s.str();
}

void Trabajador::guardar(ostream& out) {
	out << _cedula << FIN_CAMPO
		<< _nombre << FIN_CAMPO
		<< _salario << FIN_CAMPO
		<< _porcDeducTot << FIN_CAMPO;
	if (veh) {
		out << "Vehiculo: " << FIN_CAMPO;
		out << veh->getMarca() << FIN_CAMPO
			<< veh->getModelo() << FIN_CAMPO
			<< veh->getCilindrada();
	}
	out << FIN_CAMPO << FIN_REGISTRO;
}

Trabajador Trabajador::recuperar(istream& in) {
	string cedula, nombre, salario, porcDeducTot, vehiculo, marca, modelo, cilindrada;
	getline(in, cedula, FIN_CAMPO);
	getline(in, nombre, FIN_CAMPO);
	getline(in, salario, FIN_CAMPO);
	getline(in, porcDeducTot, FIN_CAMPO);
	double valSal = convertirDouble(salario);
	double valPDT = convertirDouble(porcDeducTot);
	getline(in, vehiculo, FIN_CAMPO);
	//if (vehiculo == "Vehiculo: ") {
		getline(in, marca, FIN_CAMPO);
		getline(in, modelo, FIN_CAMPO);
		getline(in, cilindrada, FIN_REGISTRO);
		int valCili = convertirInt(cilindrada);
		return Trabajador(cedula, nombre, valSal, valPDT, marca, modelo, valCili);
	//}
	//else {
		//getline(in, vehiculo, FIN_REGISTRO);
		//return Trabajador(cedula, nombre, valSal, valPDT);
	//}
	

}

double Trabajador::convertirDouble(string s) {
	stringstream r(s);
	double v;
	r >> v;
	return v;
}

int Trabajador::convertirInt(string s) {
	stringstream r(s);
	int v;
	r >> v;
	return v;
}