#include "ContenedorLRuta.h"

ContenedorLRuta::ContenedorLRuta() { ppio = NULL; }
ContenedorLRuta::~ContenedorLRuta() {
	NodoRuta* act = ppio;
	NodoRuta* siguiente;
	while (act != NULL) {
		siguiente = act->getSiguiente();
		delete act;
		act = siguiente;
	}
	ppio = NULL;
}

void ContenedorLRuta::setPpio(NodoRuta* nod) {
	if (ppio) delete ppio;
	ppio = nod;
}
NodoRuta* ContenedorLRuta::getPpio() { return ppio; }

bool ContenedorLRuta::ingresarRuta(Ruta* ingreso) {
	if (ppio == NULL) {
		ppio = new NodoRuta(ingreso, NULL);
		return true;
	}
	else {
		NodoRuta* temp = ppio;
		while (temp->getSiguiente() != NULL) {
			if (temp->getRuta()->getCodigo() == ingreso->getCodigo()) {
				cout << "Error: Codigo ya ingresado" << endl;
				return false;
			}
			temp = temp->getSiguiente();
		}
		NodoRuta* ptrNodo = new NodoRuta(ingreso, NULL);
		temp->setSiguiente(ptrNodo);
		return true;
	}
	return false;
}
bool ContenedorLRuta::eliminarRuta(string cod) {
	NodoRuta* temp = ppio->getSiguiente();
	NodoRuta* antes = ppio;
	if (ppio->getRuta()->getCodigo() == cod) {
		ppio = temp;
		delete antes;
		return true;
	}
	else {
		while (temp != NULL) {
			if (temp->getRuta()->getCodigo() == cod) {
				antes->setSiguiente(temp->getSiguiente());
				delete temp;
				return true;
			}
			antes = temp;
			temp = temp->getSiguiente();
		}
		if (temp == NULL) {
			cout << "La Ruta no existe" << endl;
			return false;
		}
	}
	return false;
}

bool ContenedorLRuta::grabar(ostream& out) {
	NodoRuta* temp = ppio;
	if (ppio) {
		while (ppio != NULL) {
			out << temp->getRuta()->getOrigen() << FIN_CAMPO
				<< temp->getRuta()->getDestino() << FIN_CAMPO
				<< temp->getRuta()->getDuracion() << FIN_CAMPO
				<< temp->getRuta()->getCantidadDeEscalas() << FIN_CAMPO
				<< temp->getRuta()->getValorPasajeros() << FIN_CAMPO
				<< temp->getRuta()->getCodigo() << FIN_CAMPO;
			if (temp->getRuta()->getUsada()) {
				out << "TRUE" << FIN_REGISTRO;
			}
			else {
				out << "FLASE" << FIN_REGISTRO;
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

Ruta* ContenedorLRuta::recuperarRuta(istream& in) {
	string origen, destino, duracion, cantDeEsc_temp, valPas_temp, codigo, usada_temp;
	int cantidadDeEscalas;
	double valorPasajeros;
	bool usada;
	getline(in, origen, FIN_CAMPO);
	getline(in, destino, FIN_CAMPO);
	getline(in, duracion, FIN_CAMPO);
	getline(in, cantDeEsc_temp, FIN_CAMPO);
	getline(in, valPas_temp, FIN_CAMPO);
	getline(in, codigo, FIN_CAMPO);
	getline(in, usada_temp, FIN_REGISTRO);
	if (usada_temp == "TRUE") {
		usada = true;
	}
	else {
		usada = false;
	}

	cantidadDeEscalas = convertirInt(cantDeEsc_temp);
	valorPasajeros = convertirDouble(valPas_temp);

	Ruta* tempRu = new Ruta(origen, destino, duracion, cantidadDeEscalas, valorPasajeros, codigo, usada);
	return tempRu;
}

bool ContenedorLRuta::recuperarTodo(istream& in) {
	while (in.good()) {
		if (ppio == NULL) {
			ppio = new NodoRuta(recuperarRuta(in), NULL);
		}
		else {
			NodoRuta* temp = ppio;
			while (temp->getSiguiente() != NULL) {
				temp = temp->getSiguiente();
			}
			NodoRuta* ptrNodo = new NodoRuta(recuperarRuta(in), NULL);
			temp->setSiguiente(ptrNodo);
		}
	}
	if (ppio == NULL) {
		cout << "No hay ninguna Ruta que recuperar" << endl;
		return false;
	}
	else {
		return true;
	}
}

Ruta* ContenedorLRuta::buscarPorCodigo(string cod) {
	NodoRuta* temp = ppio;
	while (temp != NULL) {
		if (temp->getRuta()->getCodigo() == cod) {
			return temp->getRuta();
		}
		temp = temp->getSiguiente();
	}
	return NULL;
}

bool ContenedorLRuta::cambiarOrigen(string codigo, string origen) {
	if (buscarPorCodigo(codigo)) {
		buscarPorCodigo(codigo)->setOrigen(origen);
		return true;
	}
	else {
		cout << "Error: la ruta que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLRuta::cambiarDestino(string codigo, string destino) {
	if (buscarPorCodigo(codigo)) {
		buscarPorCodigo(codigo)->setDestino(destino);
		return true;
	}
	else {
		cout << "Error: la ruta que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLRuta::cambiarDuracion(string codigo, string duracion) {
	if (buscarPorCodigo(codigo)) {
		buscarPorCodigo(codigo)->setDuracion(duracion);
		return true;
	}
	else {
		cout << "Error: la ruta que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLRuta::cambiarCantidadDeEscalas(string codigo, int cantDeEsc) {
	if (buscarPorCodigo(codigo)) {
		buscarPorCodigo(codigo)->setCantidadDeEscalas(cantDeEsc);
		return true;
	}
	else {
		cout << "Error: la ruta que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLRuta::cambiarValorPasajeros(string codigo, double valPas) {
	if (buscarPorCodigo(codigo)) {
		buscarPorCodigo(codigo)->setValorPasajeros(valPas);
		return true;
	}
	else {
		cout << "Error: la ruta que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLRuta::cambiarCodigoRuta(string codigoViejo, string codigoNuevo) {
	NodoRuta* temp = ppio;
	while (temp != NULL) {
		if (temp->getRuta()->getCodigo() == codigoNuevo) {
			cout << "Error: el nuevo codigo que ingreso ya existe" << endl;
			return false;
		}
		temp = temp->getSiguiente();
	}
	if (buscarPorCodigo(codigoViejo)) {
		buscarPorCodigo(codigoViejo)->setCodigo(codigoNuevo);
		return true;
	}
	else {
		cout << "Error: la ruta que busca no existe" << endl;
		return false;
	}
}
bool ContenedorLRuta::cambiarUsoRuta(string codigo, bool uso) {
	if (buscarPorCodigo(codigo)) {
		buscarPorCodigo(codigo)->setUsada(uso);
		return true;
	}
	else {
		cout << "Error: la ruta que busca no existe" << endl;
		return false;
	}
}

string ContenedorLRuta::toString() const {
	stringstream s;
	NodoRuta* temp = ppio;
	s << "---COLECCION DE RUTAS---" << endl;
	while (temp != NULL) {
		s << temp->toString() << endl;
		temp = temp->getSiguiente();
	}
	return s.str();
}