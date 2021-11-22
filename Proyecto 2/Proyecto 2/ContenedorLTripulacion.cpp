#include "ContenedorLTripulacion.h"

ContenedorLTripulacion::ContenedorLTripulacion() { ppio = NULL; }
ContenedorLTripulacion::~ContenedorLTripulacion() {
	NodoTripulacion* act = ppio;
	NodoTripulacion* siguiente;
	while (act != NULL) {
		siguiente = act->getSiguiente();
		delete act;
		act = siguiente;
	}
	ppio = NULL;
}

void ContenedorLTripulacion::setPpio(NodoTripulacion* nod) {
	if (ppio) delete ppio;
	ppio = nod;
}
NodoTripulacion* ContenedorLTripulacion::getPpio() { return ppio; }

bool ContenedorLTripulacion::ingresarPiloto(Piloto* ingreso) {
	if (ppio == NULL) {
		ppio = new NodoTripulacion(ingreso, NULL, NULL);
		return true;
	}
	else {
		NodoTripulacion* temp = ppio;
		while (temp->getSiguiente() != NULL) {
			if (temp->getPiloto()->getCodigo() == ingreso->getCodigo()) {
				cout << "Error: Codigo ya ingresado" << endl;
				return false;
			} else if (temp->getPiloto()->getCedula() == ingreso->getCedula()) {
				cout << "Error: Persona ya ingresada" << endl;
				return false;
			}
			temp = temp->getSiguiente();
		}
		NodoTripulacion* ptrNodo = new NodoTripulacion(ingreso, NULL, NULL);
		temp->setSiguiente(ptrNodo);
		return true;
	}
	return false;
}

bool ContenedorLTripulacion::ingresarSobrecargo(Sobrecargo* ingreso) {
	if (ppio == NULL) {
		ppio = new NodoTripulacion(NULL, ingreso, NULL);
		return true;
	}
	else {
		NodoTripulacion* temp = ppio;
		while (temp->getSiguiente() != NULL) {
			temp = temp->getSiguiente();
		}
		NodoTripulacion* ptrNodo = new NodoTripulacion(NULL, ingreso, NULL);
		temp->setSiguiente(ptrNodo);
		return true;
	}
	return false;
}

bool ContenedorLTripulacion::eliminarTripulacion(string cod) {
	NodoTripulacion* temp = ppio->getSiguiente();
	NodoTripulacion* antes = ppio;
	stringstream s;
	s << cod.at(0) << cod.at(1);
	if (s.str() == "PI") {
		if (ppio->getPiloto() != NULL) {
			if (ppio->getPiloto()->getCodigo() == cod) {
				ppio = temp;
				delete antes;
				return true;
			}
		}
		else {
			while (temp != NULL) {
				if (temp->getPiloto() != NULL) {
					if (temp->getPiloto()->getCodigo() == cod) {
						antes->setSiguiente(temp->getSiguiente());
						delete temp;
						return true;
					}
				}
				antes = temp;
				temp = temp->getSiguiente();
			}
			if (temp == NULL) {
				cout << "El Piloto no existe" << endl;
				return false;
			}
		}
	}
	else if(s.str() == "SO") {
		if (ppio->getSobrecargo() != NULL) {
			if (ppio->getSobrecargo()->getCodigo() == cod) {
				ppio = temp;
				delete antes;
				return true;
			}
		}
		else {
			while (temp != NULL) {
				if (temp->getSobrecargo() != NULL) {
					if (temp->getSobrecargo()->getCodigo() == cod) {
						antes->setSiguiente(temp->getSiguiente());
						delete temp;
						return true;
					}
				}
				antes = temp;
				temp = temp->getSiguiente();
			}
			if (temp == NULL) {
				cout << "El Sobrecargo no existe" << endl;
				return false;
			}
		}
	}
	else {
		cout << "Error: el tripulante no existe" << endl;
		return false;
	}
	
}

bool ContenedorLTripulacion::grabar(ostream& out) {
	NodoTripulacion* temp = ppio;
	if (ppio != NULL) {
		while (temp != NULL) {
			if (temp->getPiloto() != NULL) {
				out << temp->getPiloto()->getCodigo() << FIN_CAMPO
					<< temp->getPiloto()->getCedula() << FIN_CAMPO
					<< temp->getPiloto()->getNombre() << FIN_CAMPO
					<< temp->getPiloto()->getEdad() << FIN_CAMPO
					<< temp->getPiloto()->getCorreo() << FIN_CAMPO
					<< temp->getPiloto()->getSexo() << FIN_REGISTRO;
			}
			else {
				out << temp->getSobrecargo()->getCodigo() << FIN_CAMPO
					<< temp->getSobrecargo()->getCedula() << FIN_CAMPO
					<< temp->getSobrecargo()->getNombre() << FIN_CAMPO
					<< temp->getSobrecargo()->getEdad() << FIN_CAMPO
					<< temp->getSobrecargo()->getTitulo() << FIN_CAMPO
					<< temp->getSobrecargo()->getTelCelular() << FIN_CAMPO
					<< temp->getSobrecargo()->getGrado() << FIN_REGISTRO;
			}
		}
		return true;
	}
	else {
		cout << "No hay nada que guardar" << endl;
		return false;
	}
}

NodoTripulacion* ContenedorLTripulacion::recuperarTripulacion(istream& in) {
	stringstream s;
	string cedula, nombre, edad_temp, codigo, correo, sexo_temp, titulo, telcelular, grado;
	int edad;
	char sexo;
	getline(in, codigo, FIN_CAMPO);
	if (codigo != "") s << codigo.at(0) << codigo.at(1);
	getline(in, cedula, FIN_CAMPO);
	getline(in, nombre, FIN_CAMPO);
	getline(in, edad_temp, FIN_CAMPO);
	edad = convertirInt(edad_temp);
	if (s.str() == "PI") {
		getline(in, correo, FIN_CAMPO);
		getline(in, sexo_temp, FIN_REGISTRO);
		sexo = convertirChar(sexo_temp);
		Piloto* pilTemp = new Piloto(cedula, nombre, edad, codigo, correo, sexo);
		NodoTripulacion* tempNodo = new NodoTripulacion(pilTemp, NULL, NULL);
		return tempNodo;
	}
	else if (s.str() == "SO") {
		getline(in, titulo, FIN_CAMPO);
		getline(in, telcelular, FIN_CAMPO);
		getline(in, grado, FIN_REGISTRO);
		Sobrecargo* sobTemp = new Sobrecargo(cedula, nombre, edad, codigo, titulo, telcelular, grado);
		NodoTripulacion* tempNodo = new NodoTripulacion(NULL, sobTemp, NULL);
		return tempNodo;
	}
	else {
		return NULL;
	}
}

bool ContenedorLTripulacion::recuperarTodo(istream& in) {
	while (in.good()) {
		if (ppio == NULL) {
			ppio = recuperarTripulacion(in);
		}
		else {
			NodoTripulacion* temp = ppio;
			while (temp->getSiguiente() != NULL) {
				temp = temp->getSiguiente();
			}
			temp->setSiguiente(recuperarTripulacion(in));
		}
	}
	if (ppio == NULL) {
		cout << "Error: no habia ningun tripulante que recuperar" << endl;
		return false;
	}
	else {
		return true;
	}
}

Piloto* ContenedorLTripulacion::buscarPilotoPorCodigo(string cod) {
	NodoTripulacion* temp = ppio;
	while (temp != NULL) {
		if (temp->getPiloto() != NULL) {
			if (temp->getPiloto()->getCodigo() == cod) {
				return temp->getPiloto();
			}
		}
	}
	return NULL;
}

Sobrecargo* ContenedorLTripulacion::buscarSobrecargoPorCodigo(string cod) {
	NodoTripulacion* temp = ppio;
	while (temp != NULL) {
		if (temp->getSobrecargo() != NULL) {
			if (temp->getSobrecargo()->getCodigo() == cod) {
				return temp->getSobrecargo();
			}
		}
	}
	return NULL;
}

bool ContenedorLTripulacion::cambiarCedulaTripulante(string codigo, string cedula) {
	NodoTripulacion* temp = ppio;
	stringstream s;
	s << codigo.at(0) << codigo.at(1);
	while (temp != NULL) {
		if (s.str() == "PI") {
			if (temp->getPiloto() != NULL) {
				if (temp->getPiloto()->getCedula() == cedula) {
					cout << "Error: La cedula que ingreso ya existe" << endl;
					return false;
				}
			}
		}
		else if (s.str() == "SO") {
			if (temp->getSobrecargo() != NULL) {
				if (temp->getSobrecargo()->getCedula() == cedula) {
					cout << "Error: La cedula que ingreso ya existe" << endl;
					return false;
				}
			}
		}
		temp = temp->getSiguiente();
	}
	if (s.str() == "PI") {
		if (buscarPilotoPorCodigo(codigo)) {
			buscarPilotoPorCodigo(codigo)->setCedula(cedula);
			return true;
		}
		else {
			cout << "Error: el piloto que busca no existe" << endl;
			return false;
		}
	}
	else if (s.str() == "SO") {
		if (buscarSobrecargoPorCodigo(codigo)) {
			buscarSobrecargoPorCodigo(codigo)->setCedula(cedula);
			return true;
		}
		else {
			cout << "Error: el sobrecargo que busca no existe" << endl;
			return false;
		}
	}
	else {
		cout << "Error: El tripulante que busca no existe" << endl;
		return false;
	}
	
}
bool ContenedorLTripulacion::cambiarNombreTripulante(string codigo, string nombre) {
	stringstream s;
	s << codigo.at(0) << codigo.at(1);
	if (s.str() == "PI") {
		if (buscarPilotoPorCodigo(codigo)) {
			buscarPilotoPorCodigo(codigo)->setNombre(nombre);
			return true;
		}
		else {
			cout << "Error: el Piloto que busca no existe" << endl;
			return false;
		}
	}
	else if (s.str() == "SO") {
		if (buscarSobrecargoPorCodigo(codigo)) {
			buscarSobrecargoPorCodigo(codigo)->setCedula(nombre);
			return true;
		}
		else {
			cout << "Error: el sobrecargo que busca no existe" << endl;
			return false;
		}
	}
	else {
		cout << "Error: El tripulante que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLTripulacion::cambiarEdadTripulante(string codigo, int edad) {
	stringstream s;
	s << codigo.at(0) << codigo.at(1);
	if (s.str() == "PI") {
		if (buscarPilotoPorCodigo(codigo)) {
			buscarPilotoPorCodigo(codigo)->setEdad(edad);
			return true;
		}
		else {
			cout << "Error: el Piloto que busca no existe" << endl;
			return false;
		}
	}
	else if (s.str() == "SO") {
		if (buscarSobrecargoPorCodigo(codigo)) {
			buscarSobrecargoPorCodigo(codigo)->setEdad(edad);
			return true;
		}
		else {
			cout << "Error: el sobrecargo que busca no existe" << endl;
			return true;
		}
	}
	else {
		cout << "Error: El tripulante que busca no existe" << endl;
		return false;
	}
}

bool ContenedorLTripulacion::cambiarCodigoTripulante(string codigoViejo, string codigoNuevo) {
	stringstream sN, sV;
	sV << codigoViejo.at(0) << codigoViejo.at(1);
	sN << codigoNuevo.at(0) << codigoNuevo.at(1);
	if (sN.str() == "PI") {
		if (buscarPilotoPorCodigo(codigoNuevo) == NULL) {
			if (buscarPilotoPorCodigo(codigoViejo)) {
				buscarPilotoPorCodigo(codigoViejo)->setCodigo(codigoNuevo);
				return true;
			}
			else {
				cout << "Error: el piloto que busca no existe" << endl;
				return false;
			}
		}
		else {
			cout << "Error: el codigo que esta buscando ya existe" << endl;
			return false;
		}
	}
	else if (sN.str() == "SO") {
		if (buscarSobrecargoPorCodigo(codigoNuevo) == NULL) {
			if (buscarSobrecargoPorCodigo(codigoViejo)) {
				buscarSobrecargoPorCodigo(codigoViejo)->setCodigo(codigoNuevo);
				return true;
			}
			else {
				cout << "Error: el sobrecargo que busca no existe" << endl;
				return false;
			}
		}
		else {
			cout << "Error: el codigo que esta buscando ya existe" << endl;
			return false;
		}
	}
	else {
		cout << "Error: el tripulante que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLTripulacion::cambiarCorreoPiloto(string codigo, string correo) {
	NodoTripulacion* temp = ppio;
	while (temp != NULL) {
		if (temp->getPiloto() != NULL) {
			if (temp->getPiloto()->getCorreo() == correo) {
				cout << "Error: el correo ya existe" << endl;
				return false;
			}
		}
		temp = temp->getSiguiente();
	}
	if (buscarPilotoPorCodigo(codigo)) {
		buscarPilotoPorCodigo(codigo)->setCorreo(correo);
		return true;
	}
	else {
		cout << "Error: el piloto que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLTripulacion::cambiarSexoPiloto(string codigo, char sexo) {
	NodoTripulacion* temp = ppio;
	while (temp != NULL) {
		if (temp->getPiloto() != NULL) {
			if (temp->getPiloto()->getSexo() == sexo) {
				cout << "Error: el correo ya existe" << endl;
				return false;
			}
		}
		temp = temp->getSiguiente();
	}
	if (buscarPilotoPorCodigo(codigo)) {
		buscarPilotoPorCodigo(codigo)->setSexo(sexo);
		return true;
	}
	else {
		cout << "Error: el piloto que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLTripulacion::cambiarTituloSobrecargo(string codigo, string titulo) {
	if (buscarSobrecargoPorCodigo(codigo)) {
		buscarSobrecargoPorCodigo(codigo)->setTitulo(titulo);
		return true;
	}
	else {
		cout << "Error: el sobrecargo que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLTripulacion::cambiarTelCelularSobrecargo(string codigo, string telCelular) {
	NodoTripulacion* temp = ppio;
	while (temp != NULL) {
		if (temp->getSobrecargo() != NULL) {
			if (temp->getSobrecargo()->getTelCelular() == telCelular) {
				cout << "Error: el telefono celular ya existe" << endl;
				return false;
			}
		}
		temp = temp->getSiguiente();
	}
	if (buscarSobrecargoPorCodigo(codigo)) {
		buscarSobrecargoPorCodigo(codigo)->setTelCelular(telCelular);
		return true;
	}
	else {
		cout << "Error: el sobrecargo que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLTripulacion::cambiarGrado(string codigo, string grado) {
	if (buscarSobrecargoPorCodigo(codigo)) {
		buscarSobrecargoPorCodigo(codigo)->setGrado(grado);
		return true;
	}
	else {
		cout << "Error: el sobrecargo que busca no existe" << endl;
		return false;
	}
}

string ContenedorLTripulacion::toString() const {
	stringstream s;
	NodoTripulacion* temp = ppio;
	s << "---TRIPULACION---" << endl;
	while (temp != NULL) {
		s << temp->toString() << endl;
	}
	return s.str();
}