#include "ContenedorLPasajero.h"

ContenedorLPasajero::ContenedorLPasajero() { ppio = NULL; }
ContenedorLPasajero::~ContenedorLPasajero() {
	NodoPasajero* act = ppio;
	NodoPasajero* siguiente;
	while (act != NULL) {
		siguiente = act->getSiguiente();
		delete act;
		act = siguiente;
	}
	ppio = NULL;
}

void ContenedorLPasajero::setPpio(NodoPasajero* nod) {
	if (ppio) delete ppio;
	ppio = nod;
}
NodoPasajero* ContenedorLPasajero::getPpio() { return ppio; }

bool ContenedorLPasajero::ingresarPasajero(Pasajero* ingreso) {
	if (ppio == NULL) {
		ppio = new NodoPasajero(ingreso, NULL);
		return true;
	}
	else {
		NodoPasajero* temp = ppio;
		while (temp->getSiguiente() != NULL) {
			if (temp->getPasajero()->getCodigo() == ingreso->getCodigo()) {
				cout << "Error: Codigo ya ingresado" << endl;
				return false;
			}
			else if (temp->getPasajero()->getCedula() == ingreso->getCedula()) {
				cout << "Error: Ya se ingreso la persona" << endl;
				return false;
			}
			temp = temp->getSiguiente();
		}
		NodoPasajero* ptrNodo = new NodoPasajero(ingreso, NULL);
		temp->setSiguiente(ptrNodo);
		return true;
	}
	return false;
}

bool ContenedorLPasajero::eliminarPasajero(string cod) {
	NodoPasajero* temp = ppio->getSiguiente();
	NodoPasajero* antes = ppio;
	if (ppio->getPasajero()->getCodigo() == cod) {
		ppio = temp;
		delete antes;
		return true;
	}
	else {
		while (temp != NULL) {
			if (temp->getPasajero()->getCodigo() == cod) {
				antes->setSiguiente(temp->getSiguiente());
				delete temp;
				return true;
			}
			antes = temp;
			temp = temp->getSiguiente();
		}
		if (temp == NULL) {
			cout << "El Pasajero no existe" << endl;
			return false;
		}
	}
	return false;
}

bool ContenedorLPasajero::grabar(ostream& out) {
	NodoPasajero* temp = ppio;
	if (temp != NULL) {
		while (temp != NULL) {
			out << temp->getPasajero()->getCedula() << FIN_CAMPO
				<< temp->getPasajero()->getNombre() << FIN_CAMPO
				<< temp->getPasajero()->getEdad() << FIN_CAMPO
				<< temp->getPasajero()->getCodigo() << FIN_REGISTRO;
			temp = temp->getSiguiente();
		}
		return true;
	}
	else {
		cout << "No hay nada que grabar";
		return false;
	}
}

Pasajero* ContenedorLPasajero::recuperarPasajero(istream& in) {
	string cedula, nombre, edad_temp, codigo;
	int edad;
	getline(in, cedula, FIN_CAMPO);
	getline(in, nombre, FIN_CAMPO);
	getline(in, edad_temp, FIN_CAMPO);
	getline(in, codigo, FIN_REGISTRO);

	edad = convertirInt(edad_temp);

	Pasajero* tempPa = new Pasajero(cedula, nombre, edad, codigo);
	return tempPa;
}

bool ContenedorLPasajero::recuperarTodo(istream& in) {
	while (in.good()) {
		if (ppio == NULL) {
			ppio = new NodoPasajero(recuperarPasajero(in), NULL);
		}
		else {
			NodoPasajero* temp = ppio;
			while (temp->getSiguiente() != NULL) {
				temp = temp->getSiguiente();
			}
			NodoPasajero* ptrNodo = new NodoPasajero(recuperarPasajero(in), NULL);
			temp->setSiguiente(ptrNodo);
		}
	}
	if (ppio == NULL) {
		cout << "No habia ningun Pasajero que recuperar" << endl;
		return false;
	}
	else {
		return true;
	}
}

Pasajero* ContenedorLPasajero::buscarPorCodigo(string cod) {
	NodoPasajero* temp = ppio;
	while (temp != NULL) {
		if (temp->getPasajero()->getCodigo() == cod) {
			return temp->getPasajero();
		}
		temp = temp->getSiguiente();
	}
	return NULL;
}

bool ContenedorLPasajero::cambiarCedulaPasajero(string codigo, string cedula) {
	NodoPasajero* temp = ppio;
	while (temp != NULL) {
		if (temp->getPasajero()->getCedula() == cedula) {
			cout << "La cedula ya existe" << endl;
			return false;
		}
		temp = temp->getSiguiente();
	}
	temp = ppio;
	if (buscarPorCodigo(codigo)) {
		buscarPorCodigo(codigo)->setCedula(cedula);
		return true;
	}
	else {
		cout << "Error: El pasajero que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLPasajero::cambiarNombrePasajero(string codigo, string nombre) {
	if (buscarPorCodigo(codigo)) {
		buscarPorCodigo(codigo)->setNombre(nombre);
		return true;
	}
	else {
		cout << "Error: El pasajero que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLPasajero::cambiarEdadPasajero(string codigo, int edad) {
	if (buscarPorCodigo(codigo)) {
		buscarPorCodigo(codigo)->setEdad(edad);
	}
	else {
		cout << "Error: El pasajero que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLPasajero::cambiarCodigoPasajero(string codigoViejo, string codigoNuevo) {
	if (buscarPorCodigo(codigoNuevo) ==  NULL) {
		if (buscarPorCodigo(codigoViejo)) {
			buscarPorCodigo(codigoViejo)->setCodigo(codigoNuevo);
			return true;
		}
		else {
			cout << "Error: La pasajero que busca no existe" << endl;
			return false;
		}
	}
	else {
		cout << "Error: el codigo nuevo que ingreso ya existe" << endl;
		return false;
	}
	return false;
}

string ContenedorLPasajero::toString() const {
	stringstream s;
	NodoPasajero* temp = ppio;
	s << "---COLECCION DE PASAJEROS---" << endl;
	while (temp != NULL) {
		s << temp->toString() << endl;
		temp = temp->getSiguiente();
	}
	return s.str();
}