#include "ContenedorLReservacion.h"

ContenedorLReservacion::ContenedorLReservacion() { ppio = NULL; }
ContenedorLReservacion::~ContenedorLReservacion() {
	NodoReservacion* act = ppio;
	NodoReservacion* siguiente;
	while (act != NULL) {
		siguiente = act->getSiguiente();
		delete act;
		act = siguiente;
	}
	ppio = NULL;
}

void ContenedorLReservacion::setPpio(NodoReservacion* nod) {
	if (ppio) delete ppio;
	ppio = nod;
}
NodoReservacion* ContenedorLReservacion::getPpio() { return ppio; }

bool ContenedorLReservacion::ingresarReservacion(ContenedorLPasajero* contP, ContenedorLVuelo* contV, Reservacion* ingreso) {
	if (!contV->buscarPorCodigo(ingreso->getCodigoVuelo())) {
		cout << "Error: el vuelo no existe" << endl;
		return false;
	}
	else if (!contP->buscarPorCodigo(ingreso->getCodigoPasajero())) {
		cout << "Error: el pasajero no existe" << endl;
		return false;
	}
	else if (ingreso->getCantTiquetes() > ingreso->getVuelo(contV)->getAsientosRestantes()) {
		cout << "Error: intentando comprar mas asientos de los que hay" << endl;
		return false;
	}
	if (ppio == NULL) {
		ppio = new NodoReservacion(ingreso, NULL);
		return true;
	}
	else {
		NodoReservacion* temp = ppio;
		while (temp->getSiguiente() != NULL) {
			if (temp->getReservacion()->getCodigo() == ingreso->getCodigo()) {
				cout << "Error: No se puede ingresar el mismo codigo" << endl;
				return false;
			}
			else if (temp->getReservacion()->getCodigoVuelo() == ingreso->getCodigoVuelo() && temp->getReservacion()->getCodigoPasajero() == ingreso->getCodigoPasajero()) {
				cout << "Error: No se puede ingresar el mismo pasajero en el mismo vuelo" << endl;
				return false;
			}
			else if (ingreso->getVuelo(contV)->getAvion()->militarAvion()) {
				cout << "Error: No se puede viajar en un avion militar" << endl;
				return false;
			}
			temp = temp->getSiguiente();
		}
		NodoReservacion* ptrNodo = new NodoReservacion(ingreso, NULL);
		temp->setSiguiente(ptrNodo);
		return true;
	}
	return false;
}

bool ContenedorLReservacion::eliminarReservacion(string cod) {
	NodoReservacion* temp = ppio->getSiguiente();
	NodoReservacion* antes = ppio;
	if (ppio->getReservacion()->getCodigo() == cod) {
		ppio = temp;
		delete antes;
		return true;
	}
	else {
		while (temp != NULL) {
			if (temp->getReservacion()->getCodigo() == cod) {
				antes->setSiguiente(temp->getSiguiente());
				delete temp;
				return true;
			}
			antes = temp;
			temp = temp->getSiguiente();
		}
		if (temp == NULL) {
			cout << "La reservacion no existe" << endl;
			return false;
		}
	}
	return false;
}

bool ContenedorLReservacion::grabar(ostream& out) {
	NodoReservacion* temp = ppio;
	if (ppio) {
		while (temp != NULL) {
			out << temp->getReservacion()->getCodigo() << FIN_CAMPO
				<< temp->getReservacion()->getCodigoVuelo() << FIN_CAMPO
<< temp->getReservacion()->getCodigoPasajero() << FIN_CAMPO
<< temp->getReservacion()->getCantTiquetes() << FIN_CAMPO;
if (temp->getReservacion()->getActivo()) {
	out << "TRUE" << FIN_REGISTRO;
}
else {
	out << "FALSE" << FIN_REGISTRO;
}
temp = temp->getSiguiente();
		}
		return true;
	}
	else {
	cout << "No hay nada que grabar" << endl;
	return false;
	}
}

Reservacion* ContenedorLReservacion::recuperarReservacion(istream& in) {
	string codigo, codigoVuelo, codigoPasajero, cantTiq_temp, act_temp;
	int cantTiquetes;
	bool act;
	getline(in, codigo, FIN_CAMPO);
	getline(in, codigoVuelo, FIN_CAMPO);
	getline(in, codigoPasajero, FIN_CAMPO);
	getline(in, cantTiq_temp, FIN_CAMPO);
	getline(in, act_temp, FIN_REGISTRO);

	cantTiquetes = convertirInt(cantTiq_temp);

	if (act_temp == "TRUE") {
		act = true;
	}
	else {
		act = false;
	}

	Reservacion* tempRe = new Reservacion(codigo, codigoVuelo, codigoPasajero, cantTiquetes, act);
	return tempRe;
}

bool ContenedorLReservacion::recuperarTodo(istream& in) {
	while (in.good()) {
		if (ppio == NULL) {
			ppio = new NodoReservacion(recuperarReservacion(in), NULL);
		}
		else {
			NodoReservacion* temp = ppio;
			while (temp->getSiguiente() != NULL) {
				temp = temp->getSiguiente();
			}
			NodoReservacion* ptrNodo = new NodoReservacion(recuperarReservacion(in), NULL);
			temp->setSiguiente(ptrNodo);
		}
	}
	if (ppio == NULL) {
		cout << "No hay ninguna Reservacion que recuperar" << endl;
		return false;
	}
	else {
		return true;
	}
}

Reservacion* ContenedorLReservacion::buscarPorCodigo(string cod) {
	NodoReservacion* temp = ppio;
	while (temp != NULL) {
		if (temp->getReservacion()->getCodigo() == cod) {
			return temp->getReservacion();
		}
		temp = temp->getSiguiente();
	}
	return NULL;
}

bool ContenedorLReservacion::cambiarVueloReservacion(ContenedorLVuelo* contV, string codigo, string codigoVuelo) {
	NodoReservacion* temp = ppio;
	if (buscarPorCodigo(codigo)) {
		while (temp != NULL) {
			if (temp->getReservacion()->getCodigoPasajero() == buscarPorCodigo(codigo)->getCodigoPasajero()) {
				if (temp->getReservacion()->getCodigoVuelo() == codigoVuelo) {
					cout << "Error: El pasajero ya esta en el vuelo" << endl;
					return false;
				}
				else if (temp->getReservacion()->getCantTiquetes() > contV->buscarPorCodigo(codigoVuelo)->getAsientosRestantes()) {
					cout << "Error: La cantidad de tiquetes pedida es mayor a la disponible en el vuelo" << endl;
					return false;
				}
			}
			temp = temp->getSiguiente();
		}
		buscarPorCodigo(codigo)->getVuelo(contV)->devolverAsientos(buscarPorCodigo(codigo)->getCantTiquetes());
		buscarPorCodigo(codigo)->setVuelo(codigoVuelo);
		contV->buscarPorCodigo(codigoVuelo)->comprarAsientos(buscarPorCodigo(codigo)->getCantTiquetes());
		return true;
	}
	else {
		cout << "Error: la reservacion no existe" << endl;
		return false;
	}
}
bool ContenedorLReservacion::cambiarPasajero(string codigo, string codigoPasajero) {
	NodoReservacion* temp = ppio;
	if (buscarPorCodigo(codigo)) {
		while (temp != NULL) {
			if (temp->getReservacion()->getCodigoPasajero() == codigoPasajero) {
				if (temp->getReservacion()->getCodigoVuelo() == buscarPorCodigo(codigo)->getCodigoVuelo()) {
					cout << "Error: el pasajero ya esta en el vuelo" << endl;
					return false;
				}
			}
			temp = temp->getSiguiente();
		}
		buscarPorCodigo(codigo)->setPasajero(codigoPasajero);
		return true;
	}
	else {
		cout << "Error: la reservacion no existe" << endl;
		return false;
	}
}
bool ContenedorLReservacion::cambiarCodigoReservacion(string codigoViejo, string codigoNuevo) {
	if (buscarPorCodigo(codigoViejo)) {
		if (buscarPorCodigo(codigoNuevo) == NULL) {
			buscarPorCodigo(codigoViejo)->setCodigo(codigoNuevo);
			return true;
		}
		else {
			cout << "Error: el codigo nuevo ya existe" << endl;
			return false;
		}
	}
	else {
		cout << "Error: la reservacion no existe (codigo viejo)" << endl;
		return false;
	}
}
bool ContenedorLReservacion::cambiarCantidadDeTiquetes(ContenedorLVuelo* contV, string codigo, int cant) {
	if (buscarPorCodigo(codigo)) {
		int original = buscarPorCodigo(codigo)->getCantTiquetes();
		buscarPorCodigo(codigo)->setCantTiquetes(cant);
		buscarPorCodigo(codigo)->getVuelo(contV)->comprarAsientos(buscarPorCodigo(codigo)->getCantTiquetes() - original);
		return true;
	}
	else {
		cout << "Error: la reservacion no existe (codigo viejo)" << endl;
		return false;
	}
}
bool ContenedorLReservacion::cambiarUsoReservacion(string codigo, bool uso) {
	if (buscarPorCodigo(codigo)) {
		buscarPorCodigo(codigo)->setActivo(uso);
		return true;
	}
	else {
		cout << "Error: la reservacion no existe (codigo viejo)" << endl;
		return false;
	}
}

string ContenedorLReservacion::toString(ContenedorLVuelo* contV, ContenedorLTripulacion* contT, ContenedorLRuta* contRu) const {
	stringstream s;
	NodoReservacion* temp = ppio;
	s << "---COLECCION DE RESERVACIONES---" << endl;
	while (temp != NULL) {
		s << temp->toString(contV, contT, contRu) << endl;
		temp = temp->getSiguiente();
	}
	return s.str();
}