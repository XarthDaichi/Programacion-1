#include"Tienda.h"


Tienda::Tienda(int tama) {
	nombreTienda = "----------Tienda Programacion UNO-------------";
	cedulaJuridica = "COD-213444-KDWZ";
	//-------------------------------------------------------------
	tam = tama;
	can = 0;
	vec = new Departamento * [tama];
	for (int i = 0; i < tam; i++)
		vec[i] = NULL;
}
Tienda::~Tienda() {
	for (int i = 0; i < tam; i++)
		delete vec[i];
	delete[] vec;
}
void Tienda::setNombreTienda(string nom) { nombreTienda = nom; }

void Tienda::setCeduJuridica(string cJ) { cedulaJuridica = cJ; }

string Tienda::getNombreTienda() { return nombreTienda; }

string Tienda::getCedulaJuridica() { return cedulaJuridica; }

int Tienda::getCantidad() { return can; }

int Tienda::getTamanio() { return tam; }

bool   Tienda::ingresaDepartamento(Departamento* dep) {
	if (can < tam) {
		if (departamentoYaExiste(dep->getCodigo())) {
			cout << "Ya existe el departamento" << endl;
			return false;
		}
		else {
			vec[can++] = dep;
			cout << "Se ingreso correctamente" << endl;
			return true;
		}
	}
	else
		cout << "Ya no se puede ingresar mas departamentos" << endl;
		return false;
}

bool Tienda::ingresarEmpleado(int cod, Empleado* emp) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->esIgualA(cod)) {
			if (vec[i]->ingresaEmpleado(emp)) {
				cout << "Se ingreso correctamente" << endl;
				return true;
			}
			else {
				cout << "Error al ingresar empleado" << endl;
				return false;
			}
		}
	}
	cout << "El deparamento no existe" << endl;
	return false;
}

string Tienda::toString() const {
	stringstream s;
	s << "-----------Listado de Departamentos------------" << endl;
	for (int i = 0; i < can; i++)
		s << vec[i]->toString() << endl;
	return s.str();
}

string Tienda::toStringEmpleados() const{
	stringstream s;
	int cont = 0;
	for (int i = 0; i < can; i++) {
		cont += vec[i]->getCan();
	}
	s << "Cantidad de empleados: " << cont << endl;
	for (int i = 0; i < can; i++) {
		s << vec[i]->toStringEmpleados();
	}
	return s.str();
}

string Tienda::toStringCajeros() const {
	stringstream s;
	int cont = 0;
	for (int i = 0; i < can; i++) {
		cont += vec[i]->getCanCajeros();
	}
	s << "Cantidad de cajeros: " << cont << endl;
	for (int i = 0; i < can; i++) {
		s << vec[i]->toStringCajeros();
	}
	return s.str();
}

string Tienda::toStringSalariosDepartamento(int cod) const {
	stringstream s; 
	for (int i = 0; i < can; i++) {
		if (vec[i]->esIgualA(cod)) {
			s << vec[i]->toStringSalarios();
		}
	}
	return s.str();
}

string Tienda::toStringSalarioTotal() const {
	stringstream s;
	double total = 0;
	for (int i = 0; i < can; i++) {
		s << vec[i]->toStringSalarios() << endl;
	}
	for (int i = 0; i < can; i++) {
		total += vec[i]->salarioDepartamento();
	}
	s << "Total: " << total << endl;
	return s.str();
}

string Tienda::toStringMismoDia(Fecha* fe) const {
	stringstream s;
	for (int i = 0; i < can; i++) {
		s << vec[i]->toStringMismoDia(fe);
	}
	return s.str();
}

string Tienda::toStringMismoDiaDepartamento(int cod, Fecha* fe) const {
	stringstream s;
	for (int i = 0; i < can; i++) {
		if (vec[i]->getCodigo() == cod) {
			s << vec[i]->toStringMismoDia(fe) << endl;
		}
	}
	return s.str();
}

string Tienda::toStringCajerosCategoria(string cat) const {
	stringstream s;
	for (int i = 0; i < can; i++) {
		s << vec[i]->toStringCajerosCategoria(cat);
	}
	return s.str();
}

string Tienda::toStringSupervisorMismoDia(Fecha* fe) const {
	stringstream s;
	for (int i = 0; i < can; i++) {
		s << vec[i]->toStringSupervisorMismoDia(fe);
	}
	return s.str();
}

string Tienda::toStringMayorSalario() const {
	stringstream s;
	if (can != 0) {
		Empleado* mayor = vec[0]->getMayorSalario();
		for (int i = 1; i < can; i++) {
			if (vec[i]->getMayorSalario()->salario() > mayor->salario()) {
				mayor = vec[i]->getMayorSalario();
			}
		}
		s << mayor->toString() << endl;
	}
	return s.str();
}

bool Tienda::departamentoYaExiste(int cod) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->esIgualA(cod)) {
			return true;
		}
	}
	return false;
}
bool Tienda::empleadoYaExiste(int cod) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->empleadoYaExiste(cod)) {
			return true;
		}
	}
	return false;
}

bool Tienda::recalificarEmpleado(int cod, string cal) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->empleadoYaExiste(cod)) {
			vec[i]->recalificarEmpleado(cod, cal);
			return true;
		}
	}
	cout << "El empleado no existe" << endl;
	return false;
}

double Tienda::salarioTotal() {
	double total = 0;
	for (int i = 0; i < can; i++) {
		total = vec[i]->salarioDepartamento();
	}
	return total;
}

void Tienda::guardar(ostream& out) {
	out << tam << FIN_CAMPO
		<< can << FIN_CAMPO;
	for (int i = 0; i < can; i++) {
		vec[i]->guardarDepartamento(out);
	}
	out << FIN_REGISTRO;
}

Tienda* Tienda::recuperar(istream& in) {
	int tam, can;
	string tam_temp, can_temp;
	Departamento* dep = NULL;
	getline(in, tam_temp, FIN_CAMPO);
	getline(in, can_temp, FIN_CAMPO);
	tam = convertirInt(tam_temp);
	can = convertirInt(tam_temp);
	Tienda* tien = new Tienda(tam);
	for (int i = 0; i < can; i++) {
		dep = dep->recuperarDepartamento(in);
		tien->ingresaDepartamento(dep);
	}
	return tien;
}