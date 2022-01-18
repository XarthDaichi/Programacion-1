#include"Departamento.h"

Departamento::Departamento(int cod, string des, int val) {
	codigo = cod;
	descripcion = des;
	//----------------
	tam = val;
	can = 0;
	vec = new Empleado * [val];
	for (int i = 0; i < tam; i++)
		vec[i] = NULL;
}

Departamento::~Departamento() {
	for (int i = 0; i < tam; i++)
		delete vec[i];
	delete[] vec;
}

bool Departamento::ingresaEmpleado(Empleado* emp) {
	if (can < tam) {
		if (empleadoYaExiste(emp->getID())) {
			cout << "El empleado ya existe" << endl;
			return false;
		}
		else {
			vec[can++] = emp;
			return true;
		}
	}
	else
		cout << "No se pueden ingresar mas empleados" << endl;
		return false;
}

string Departamento::toString() const {
	stringstream s;
	s << "--> Descripcion del departamento: " << descripcion << endl
		<< "--> El codigo del departamento: " << codigo << endl
		<< "-------------Listado de Empleados------------" << endl;
	for (int i = 0; i < can; i++)
		s << vec[i]->toString() << endl;
	return s.str();
}

string Departamento::toStringEmpleados() const {
	stringstream s;
	for (int i = 0; i < can; i++) {
		if (vec[i]->getTipo() == 'C')
			s << vec[i]->toString() << endl;
	}
	for (int i = 0; i < can; i++) {
		if (vec[i]->getTipo() == 'V')
			s << vec[i]->toString() << endl;
	}
	for (int i = 0; i < can; i++) {
		if (vec[i]->getTipo() == 'S') 
			s << vec[i]->toString() << endl;
	}
	return s.str();
}

string Departamento::toStringCajeros() const {
	stringstream s;
	for (int i = 0; i < can; i++) {
		if (vec[i]->getTipo() == 'C') {
			s << vec[i]->getID() << '\t' << vec[i]->getNombre() << '\t' << vec[i]->salario() << endl;
		}
	}
	return s.str();
}

string Departamento::toStringSalarios() const {
	stringstream s;
	double total = 0;
	for (int i = 0; i < can; i++) {
		s << vec[i]->getID() << '\t' << vec[i]->getNombre() << '\t';
		if (vec[i]->getTipo() == 'C') {
			s << "Cajero" << '\t';
		}
		else if (vec[i]->getTipo() == 'V') {
			s << "Vendedor" << '\t';
		}
		else if (vec[i]->getTipo() == 'S') {
			s << "Supervisor" << '\t';
		}
		s << vec[i]->salario() << endl;
		total += vec[i]->salario();
	}
	s << "El salario del departamento es: " << total << endl;
	return s.str();
}

string Departamento::toStringMismoDia(Fecha* fe) const {
	stringstream s;
	for (int i = 0; i < can; i++) {
		if (vec[i]->esMismoDia(fe)) {
			s << vec[i]->toString() << endl;
		}
	}
	return s.str();
}

string Departamento::toStringCajerosCategoria(string cat) const {
	stringstream s;
	for (int i = 0; i < can; i++) {
		if (vec[i]->getTipo() == 'C') {
			if (vec[i]->getCategoria() == cat) {
				s << vec[i]->toString() << endl;
			}
		}
	}
	return s.str();
}

string Departamento::toStringSupervisorMismoDia(Fecha* fe) const {
	stringstream s;
	for (int i = 0; i < can; i++) {
		if (vec[i]->getTipo() == 'S') {
			if (vec[i]->esMismoDia(fe)) {
				s << vec[i]->toString() << endl;
			}
		}
	}
	return s.str();
}

void Departamento::setDescripcion(string desc) { descripcion = desc; }

string Departamento::getDescripcion() { return descripcion; }

void Departamento::setCodigo(int cod) { codigo = cod; }

int  Departamento::getCodigo() { return codigo; }

int Departamento::getCan() { return can; }

int Departamento::getCanCajeros() {
	int cont = 0;
	for (int i = 0; i < can; i++) {
		if (vec[i]->getTipo() == 'C') {
			cont++;
		}
	}
	return cont;
}

int Departamento::getCanVendedores() {
	int cont = 0;
	for (int i = 0; i < can; i++) {
		if (vec[i]->getTipo() == 'V') {
			cont++;
		}
	}
	return cont;
}

int Departamento::getCanSupervisores() {
	int cont = 0;
	for (int i = 0; i < can; i++) {
		if (vec[i]->getTipo() == 'S') {
			cont++;
		}
	}
	return cont;
}

bool Departamento::empleadoYaExiste(int cod) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->esIgualA(cod)) {
			return true;
		}
	}
	return false;
}

Empleado* Departamento::getEmpleado(int cod) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->esIgualA(cod)) {
			return vec[i];
		}
	}
	return NULL;
}

bool Departamento::esIgualA(int cod) {
	return codigo == cod;
}

bool Departamento::recalificarEmpleado(int cod, string cal) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->esIgualA(cod)) {
			vec[i]->setCategoria(cal);
			return true;
		}
	}
	return false;
}

double Departamento::salarioDepartamento() {
	double total = 0;
	for (int i = 0; i < can; i++) {
		total = vec[i]->salario();
	}
	return total;
}

Empleado* Departamento::getMayorSalario() {
	Empleado* anterior = vec[0];
	for (int i = 1; i < can; i++) {
		if (vec[i]->salario() > anterior->salario()) {
			anterior = vec[i];
		}
	}
	return anterior;
}

void Departamento::guardarDepartamento(ostream& out) {
	out << codigo << FIN_CAMPO
		<< descripcion << FIN_CAMPO
		<< tam << FIN_CAMPO
		<< can << FIN_CAMPO;
	for (int i = 0; i < can; i++) {
		vec[i]->guardar(out);
	}
}
Departamento* Departamento::recuperarDepartamento(istream& in) {
	int codigo, tam, can;
	string descripcion;
	int id, horasTrabajadas, dia, mes, anio;
	string nombre, categoria;
	double cuota, porcentajeComision, porcentajeRecargo, salarioXhora, totalVenta;
	char tipo;
	string codigo_temp, tam_temp, can_temp, id_temp, horasTra_temp, dia_temp, mes_temp, anio_temp, cuo_temp, porCo_temp, porRe_temp, salXH_temp, totVen_temp, tipo_temp;
	Fecha* fe = NULL;
	Empleado* emp = NULL;
	Departamento* dep = NULL;
	getline(in, codigo_temp, FIN_CAMPO);
	getline(in, descripcion, FIN_CAMPO);
	getline(in, tam_temp, FIN_CAMPO);
	getline(in, can_temp, FIN_CAMPO);
	codigo = convertirInt(codigo_temp);
	tam = convertirInt(tam_temp);
	can = convertirInt(can_temp);
	dep = new Departamento(codigo, descripcion, tam);
	for (int i = 0; i < can; i++) {
		getline(in, id_temp, FIN_CAMPO);
		getline(in, nombre, FIN_CAMPO);
		getline(in, categoria, FIN_CAMPO);
		getline(in, tipo_temp, FIN_CAMPO);
		getline(in, dia_temp, FIN_CAMPO);
		getline(in, mes_temp, FIN_CAMPO);
		getline(in, anio_temp, FIN_CAMPO);
		id = convertirInt(id_temp);
		tipo = convertirChar(tipo_temp);
		dia = convertirInt(dia_temp);
		mes = convertirInt(mes_temp);
		anio = convertirInt(anio_temp);
		fe = new Fecha(dia, mes, anio);
		if (tipo == 'C') {
			getline(in, horasTra_temp, FIN_CAMPO);
			getline(in, salXH_temp, FIN_CAMPO);
			horasTrabajadas = convertirInt(horasTra_temp);
			salarioXhora = convertirInt(salXH_temp);
			emp = new Cajero(id, nombre, categoria, fe, horasTrabajadas, salarioXhora);
			dep->ingresaEmpleado(emp);
		}
		else if (tipo == 'V') {
			getline(in, cuo_temp, FIN_CAMPO);
			getline(in, totVen_temp , FIN_CAMPO);
			getline(in, porCo_temp, FIN_CAMPO);
			cuota = convertirDouble(cuo_temp);
			totalVenta = convertirDouble(totVen_temp);
			porcentajeComision = convertirDouble(porCo_temp);
			emp = new Vendedor(id, nombre, categoria, fe, cuota, totalVenta, porcentajeComision);
			dep->ingresaEmpleado(emp);
		}
		else if (tipo == 'S') {
			getline(in, cuo_temp, FIN_CAMPO);
			getline(in, totVen_temp, FIN_CAMPO);
			getline(in, porCo_temp, FIN_CAMPO);
			getline(in, porRe_temp, FIN_CAMPO);
			cuota = convertirDouble(cuo_temp);
			totalVenta = convertirDouble(totVen_temp);
			porcentajeComision = convertirDouble(porCo_temp);
			porcentajeRecargo = convertirDouble(porRe_temp);
			emp = new Supervisor(id, nombre, categoria, fe, cuota, totalVenta, porcentajeComision, porcentajeRecargo);
			dep->ingresaEmpleado(emp);
		}

	}
	return dep;
}

void Departamento::setCan(int cant) { can = cant; }