#include "ContenedorLVuelo.h"

ContenedorLVuelo::ContenedorLVuelo() { ppio = NULL; }
ContenedorLVuelo::~ContenedorLVuelo() {
	NodoVuelo* act = ppio;
	NodoVuelo* siguiente;
	while (act != NULL) {
		siguiente = act->getSiguiente();
		delete act;
		act = siguiente;
	}
	ppio = NULL;
}

void ContenedorLVuelo::setPpio(NodoVuelo* nod) {
	if (ppio) delete ppio;
	ppio = nod;
}
NodoVuelo* ContenedorLVuelo::getPpio() { return ppio; }

bool ContenedorLVuelo::ingresarVuelo(ContenedorLTripulacion* contT, ContenedorLRuta* contRu, Vuelo* ingreso) {
	if (ppio == NULL) {
		ppio = new NodoVuelo(ingreso, NULL);
		return true;
	}
	else {
		NodoVuelo* temp = ppio;
		while (temp->getSiguiente() != NULL) {
			if (temp->getVuelo()->getCodigo() == ingreso->getCodigo()) {
				cout << "Error: No puede ingresar dos vuelos con el mismo codigo" << endl;
				return false;
			}
			else if (!ingreso->getUso()) {
				cout << "Error: El Vuelo no está en uso" << endl;
				return false;
			}
			else if (!contRu->buscarPorCodigo(ingreso->getCodigoRuta())) {
				cout << "Error: La Ruta no existe" << endl;
				return false;
			}
			else if (!ingreso->getRuta(contRu)->getUsada()) {
				cout << "Error: La Ruta no esta en uso" << endl;
				return false;
			}
			else if (!contT->buscarPilotoPorCodigo(ingreso->getAvion()->getCodigoPiloto())) {
				cout << "Error: El Piloto no existe" << endl;
				return false;
			}
			else if (!contT->buscarSobrecargoPorCodigo(ingreso->getAvion()->getCodigoSobrecargo(0)) || !contT->buscarSobrecargoPorCodigo(ingreso->getAvion()->getCodigoSobrecargo(1)) || !contT->buscarSobrecargoPorCodigo(ingreso->getAvion()->getCodigoSobrecargo(2))) {
				cout << "Error: El Sobrecargo no existe" << endl;
				return false;
			} else if (temp->getVuelo()->getFechaSalida()->getDia() == ingreso->getFechaSalida()->getDia() && temp->getVuelo()->getFechaSalida()->getMes() == ingreso->getFechaSalida()->getMes() && temp->getVuelo()->getFechaSalida()->getAnnio() == ingreso->getFechaSalida()->getAnnio()) {
				if ((temp->getVuelo()->getHoraSalida()->getHora() <= ingreso->getHoraSalida()->getHora() && ingreso->getHoraSalida()->getHora() <= temp->getVuelo()->getHoraLlegada()->getHora()) || (temp->getVuelo()->getHoraSalida()->getHora() <= ingreso->getHoraLlegada()->getHora() && ingreso->getHoraLlegada()->getHora() <= temp->getVuelo()->getHoraLlegada()->getHora())) {
					if (temp->getVuelo()->getAvion()->getCategoria() == ingreso->getAvion()->getCategoria()) {
						cout << "Error: No puede ingresar el mismo Avion en dos vuelos a la misma hora" << endl;
						return false;
					}
					else if (temp->getVuelo()->getAvion()->getCodigoPiloto() == ingreso->getAvion()->getCodigoPiloto()){
						cout << "Error: No puede ingresar el mismo Piloto en dos vuelos a la misma hora" << endl;
						return false;
					}
					else {
						for (int i = 0; i < 3; i++) {
							for (int j = 0; j < 3; j++){
								if (temp->getVuelo()->getAvion()->getCodigoSobrecargo(i) == ingreso->getAvion()->getCodigoSobrecargo(j)) {
									cout << "Error: No puede ingresar el mismo sobrecargo en dos vuelos a la misma hora" << endl;
									return false;
								}
							}
						}
					}
				}
			}
			temp = temp->getSiguiente();
		}
		NodoVuelo* ptrNodo = new NodoVuelo(ingreso, NULL);
		temp->setSiguiente(ptrNodo);
		return true;
	}
	return false;
}

bool ContenedorLVuelo::eliminarVuelo(string cod) {
	NodoVuelo* temp = ppio->getSiguiente();
	NodoVuelo* antes = ppio;
	if (ppio->getVuelo()->getCodigo() == cod) {
		ppio = temp;
		delete antes;
		return true;
	}
	else {
		while (temp != NULL) {
			if (temp->getVuelo()->getCodigo() == cod) {
				antes->setSiguiente(temp->getSiguiente());
				delete temp;
				return true;
			}
			antes = temp;
			temp = temp->getSiguiente();
		}
		if (temp == NULL) {
			cout << "El vuelo no existe" << endl;
			return false;
		}
	}
	return false;
}

bool ContenedorLVuelo::grabar(ostream& out) {
	NodoVuelo* temp = ppio;
	if (temp != NULL) {
		while (temp != NULL) {
			out << temp->getVuelo()->getAeropuertoSalida() << FIN_CAMPO
				<< temp->getVuelo()->getAeropuertoLlegada() << FIN_CAMPO
				<< temp->getVuelo()->getFechaSalida()->getDia() << FIN_DATO
				<< temp->getVuelo()->getFechaSalida()->getMes() << FIN_DATO
				<< temp->getVuelo()->getFechaSalida()->getAnnio() << FIN_CAMPO
				<< temp->getVuelo()->getHoraSalida()->getMinuto() << FIN_DATO
				<< temp->getVuelo()->getHoraSalida()->getHora() << FIN_CAMPO
				<< temp->getVuelo()->getHoraLlegada()->getMinuto() << FIN_DATO
				<< temp->getVuelo()->getHoraLlegada()->getHora() << FIN_CAMPO
				<< temp->getVuelo()->getAvion()->getCategoria() << FIN_DATO
				<< temp->getVuelo()->getAvion()->getCodigoPiloto() << FIN_DATO
				<< temp->getVuelo()->getAvion()->getCodigoSobrecargo(0) << FIN_DATO
				<< temp->getVuelo()->getAvion()->getCodigoSobrecargo(1) << FIN_DATO
				<< temp->getVuelo()->getAvion()->getCodigoSobrecargo(2) << FIN_CAMPO
				<< temp->getVuelo()->getCodigoRuta() << FIN_CAMPO
				<< temp->getVuelo()->getCodigo() << FIN_CAMPO;
				if (temp->getVuelo()->getUso()) {
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

Vuelo* ContenedorLVuelo::recuperarVuelo(istream& in) {
	string aeroSalida, aeroLlegada, dia_temp, mes_temp, annio_temp, minuto_tempSa, hora_tempSa, minuto_tempLl, hora_tempLl, categoria, codigoPil, codigoSob1, codigoSob2, codigoSob3, codigoRu, codigoVu, uso_temp;
	int dia, mes, annio, minutoSa, horaSa, minutoLl, horaLl;
	bool uso;
	getline(in, aeroSalida, FIN_CAMPO);
	getline(in, aeroLlegada, FIN_CAMPO);
	getline(in, dia_temp, FIN_DATO);
	getline(in, mes_temp, FIN_DATO);
	getline(in, annio_temp, FIN_CAMPO);
	getline(in, minuto_tempSa, FIN_DATO);
	getline(in, hora_tempLl, FIN_CAMPO);
	getline(in, minuto_tempSa, FIN_DATO);
	getline(in, hora_tempLl, FIN_CAMPO);
	getline(in, categoria, FIN_DATO);
	getline(in, codigoPil, FIN_DATO);
	getline(in, codigoSob1, FIN_DATO);
	getline(in, codigoSob2, FIN_DATO);
	getline(in, codigoSob3, FIN_CAMPO);
	getline(in, codigoRu, FIN_CAMPO);
	getline(in, codigoVu, FIN_CAMPO);
	getline(in, uso_temp, FIN_REGISTRO);

	dia = convertirInt(dia_temp);
	mes = convertirInt(mes_temp);
	annio = convertirInt(annio_temp);

	minutoSa = convertirInt(minuto_tempSa);
	horaSa = convertirInt(hora_tempSa);
	minutoLl = convertirInt(minuto_tempLl);
	horaLl = convertirInt(hora_tempLl);

	if (uso_temp == "TRUE") {
		uso = true;
	}
	else {
		uso = false;
	} 
	Avion* tempAv = new Avion(categoria, codigoPil, codigoSob1, codigoSob2, codigoSob3);
	Fecha* tempFe = new Fecha(dia, mes, annio);
	Hora* tempHoSa = new Hora(horaSa, minutoSa);
	Hora* tempHoLl = new Hora(horaLl, minutoLl);
	Vuelo* tempVu = new Vuelo(aeroSalida, aeroLlegada, tempAv, codigoRu, tempFe, tempHoSa, tempHoLl, codigoVu, uso);
	return tempVu;
}

bool ContenedorLVuelo::recuperarTodo(istream& in) {
	while (in.good()) {
		if (ppio == NULL) {
			ppio = new NodoVuelo(recuperarVuelo(in), NULL);
		}
		else {
			NodoVuelo* temp = ppio;
			while (temp->getSiguiente() != NULL) {
				temp = temp->getSiguiente();
			}
			NodoVuelo* ptrNodo = new NodoVuelo(recuperarVuelo(in), NULL);
			temp->setSiguiente(ptrNodo);
		}
	}
	if (ppio == NULL) {
		cout << "No hay nada ningun Vuelo que recuperar" << endl;
		return false;
	}
	else {
		return true;
	}
}

Vuelo* ContenedorLVuelo::buscarPorCodigo(string cod) {
	NodoVuelo* temp = ppio;
	while (temp != NULL) {
		if (temp->getVuelo()->getCodigo() == cod) {
			return temp->getVuelo();
		}
		temp = temp->getSiguiente();
	}
	return NULL;
}

bool ContenedorLVuelo::cambiarAvionVuelo(string codigo, Avion* av) {
	NodoVuelo* temp = ppio;
	if (buscarPorCodigo(codigo)) {
		while (temp != NULL) {
			if (temp->getVuelo()->getAvion()->getCategoria() == av->getCategoria()) {
				if (temp->getVuelo()->getFechaSalida()->getAnnio() == buscarPorCodigo(codigo)->getFechaSalida()->getAnnio()) {
					if (temp->getVuelo()->getFechaSalida()->getMes() == buscarPorCodigo(codigo)->getFechaSalida()->getMes()) {
						if (temp->getVuelo()->getFechaSalida()->getDia() == buscarPorCodigo(codigo)->getFechaSalida()->getDia()) {
							if ((temp->getVuelo()->getHoraSalida()->getHora() <= buscarPorCodigo(codigo)->getHoraSalida()->getHora() && temp->getVuelo()->getHoraLlegada()->getHora() >= buscarPorCodigo(codigo)->getHoraSalida()->getHora()) || (temp->getVuelo()->getHoraSalida()->getHora() <= buscarPorCodigo(codigo)->getHoraLlegada()->getHora() && temp->getVuelo()->getHoraLlegada()->getHora() >= buscarPorCodigo(codigo)->getHoraLlegada()->getHora())) {
								cout << "Error: El mismo avion no puede estar en dos vuelos a la misma hora" << endl;
								return false;
							}
						}
					}
				}
			}
			temp = temp->getSiguiente();
		}
		buscarPorCodigo(codigo)->setAvion(av);
		return true;
	}
	else {
		cout << "Error: no existe el vuelo que busca" << endl;
		return false;
	}

}
bool ContenedorLVuelo::cambiarPilotoVuelo(string codigo, string codigoPiloto) {
	NodoVuelo* temp = ppio;
	if (buscarPorCodigo(codigo)) {
		while (temp != NULL) {
			if (temp->getVuelo()->getAvion()->getCodigoPiloto() == codigoPiloto) {
				if (temp->getVuelo()->getFechaSalida()->getAnnio() == buscarPorCodigo(codigo)->getFechaSalida()->getAnnio()) {
					if (temp->getVuelo()->getFechaSalida()->getMes() == buscarPorCodigo(codigo)->getFechaSalida()->getMes()) {
						if (temp->getVuelo()->getFechaSalida()->getDia() == buscarPorCodigo(codigo)->getFechaSalida()->getDia()) {
							if ((temp->getVuelo()->getHoraSalida()->getHora() <= buscarPorCodigo(codigo)->getHoraSalida()->getHora() && temp->getVuelo()->getHoraLlegada()->getHora() >= buscarPorCodigo(codigo)->getHoraSalida()->getHora()) || (temp->getVuelo()->getHoraSalida()->getHora() <= buscarPorCodigo(codigo)->getHoraLlegada()->getHora() && temp->getVuelo()->getHoraLlegada()->getHora() >= buscarPorCodigo(codigo)->getHoraLlegada()->getHora())) {
								cout << "Error: El mismo piloto no puede estar en dos vuelos a la misma hora" << endl;
								return false;
							}
						}
					}
				}
			}
			temp = temp->getSiguiente();
		}
		buscarPorCodigo(codigo)->getAvion()->getCodigoPiloto();
		return true;
	}
	else {
		cout << "Error: no existe el vuelo que busca" << endl;
		return false;
	}
}
bool ContenedorLVuelo::cambiarSobrecargoVuelo(string codigo, int pos, string codigoSobrecargo) {
	NodoVuelo* temp = ppio;
	if (buscarPorCodigo(codigo)) {
		while (temp != NULL) {
			if (temp->getVuelo()->getAvion()->getCodigoSobrecargo(0) == codigoSobrecargo || temp->getVuelo()->getAvion()->getCodigoSobrecargo(1) == codigoSobrecargo || temp->getVuelo()->getAvion()->getCodigoSobrecargo(2) == codigoSobrecargo) {
				if (temp->getVuelo()->getFechaSalida()->getAnnio() == buscarPorCodigo(codigo)->getFechaSalida()->getAnnio()) {
					if (temp->getVuelo()->getFechaSalida()->getMes() == buscarPorCodigo(codigo)->getFechaSalida()->getMes()) {
						if (temp->getVuelo()->getFechaSalida()->getDia() == buscarPorCodigo(codigo)->getFechaSalida()->getDia()) {
							if ((temp->getVuelo()->getHoraSalida()->getHora() <= buscarPorCodigo(codigo)->getHoraSalida()->getHora() && temp->getVuelo()->getHoraLlegada()->getHora() >= buscarPorCodigo(codigo)->getHoraSalida()->getHora()) || (temp->getVuelo()->getHoraSalida()->getHora() <= buscarPorCodigo(codigo)->getHoraLlegada()->getHora() && temp->getVuelo()->getHoraLlegada()->getHora() >= buscarPorCodigo(codigo)->getHoraLlegada()->getHora())) {
								cout << "Error: El mismo sobrecargo no puede estar en dos vuelos a la misma hora" << endl;
								return false;
							}
						}
					}
				}
			}
			temp = temp->getSiguiente();
		}
		buscarPorCodigo(codigo)->getAvion()->setSobrecargo(codigoSobrecargo, pos);
		return true;
	}
	else {
		cout << "Error: no existe el vuelo que busca" << endl;
		return false;
	}
}
bool ContenedorLVuelo::cambiarRutaVuelo(ContenedorLRuta* contRu,string codigo, string codigoRuta) {
	if (buscarPorCodigo(codigo)) {
		if (contRu->buscarPorCodigo(codigoRuta)) {
			buscarPorCodigo(codigo)->setRuta(codigoRuta);
			return true;
		}
		else {
			cout << "Error: La ruta no existe" << endl;
			return false;
		}

	}
	else {
		cout << "Error: el vuelo no existe" << endl;
		return false;
	}
}
bool ContenedorLVuelo::cambiarAeropuertoSalida(string codigo, string aeropuertoSalida) {
	if (buscarPorCodigo(codigo)) {
		buscarPorCodigo(codigo)->setAeropuertoSalida(aeropuertoSalida);
		return true;
	}
	else {
		cout << "Error: el vuelo no existe" << endl;
		return false;
	}
}
bool ContenedorLVuelo::cambiarAeropuertoLlegada(string codigo, string aeropuertoLlegada) {
	if (buscarPorCodigo(codigo)) {
		buscarPorCodigo(codigo)->setAeropuertoLlegada(aeropuertoLlegada);
		return true;
	}
	else {
		cout << "Error: el vuelo no existe" << endl;
		return false;
	}
}
bool ContenedorLVuelo::cambiarFechaSalida(string codigo, Fecha* fe) {
	NodoVuelo* temp = ppio;
	if (buscarPorCodigo(codigo)) {
		while (temp != NULL) {
			if (temp->getVuelo()->getFechaSalida()->getAnnio() == fe->getAnnio()) {
				if (temp->getVuelo()->getFechaSalida()->getMes() == fe->getMes()) {
					if (temp->getVuelo()->getFechaSalida()->getDia() == fe->getDia()) {
						if ((temp->getVuelo()->getHoraSalida()->getHora() <= buscarPorCodigo(codigo)->getHoraSalida()->getHora() && temp->getVuelo()->getHoraLlegada()->getHora() >= buscarPorCodigo(codigo)->getHoraSalida()->getHora()) || (temp->getVuelo()->getHoraSalida()->getHora() <= buscarPorCodigo(codigo)->getHoraLlegada()->getHora() && temp->getVuelo()->getHoraLlegada()->getHora() >= buscarPorCodigo(codigo)->getHoraLlegada()->getHora())) {
							if (temp->getVuelo()->getAvion()->getCategoria() == buscarPorCodigo(codigo)->getAvion()->getCategoria()) {
								cout << "Error: mismo avion dos vuelos mismo tiempo" << endl;
								return false;
							}
							else if (temp->getVuelo()->getAvion()->getCodigoPiloto() == buscarPorCodigo(codigo)->getAvion()->getCodigoPiloto()) {
								cout << "Error: mismo piloto dos vuelos mismo tiempo" << endl;
								return false;
							}
							else {
								for (int i = 0; i < 3; i++) {
									for (int j = 0; j < 3; j++) {
										if (temp->getVuelo()->getAvion()->getCodigoSobrecargo(i) == buscarPorCodigo(codigo)->getAvion()->getCodigoSobrecargo(j)) {
											cout << "Error: mismo sobrecargo dos vuelos mismo tiepmo" << endl;
											return false;
										}
									}
								}
							}
						}
					}
				}
			}
			temp = temp->getSiguiente();
		}
		buscarPorCodigo(codigo)->setFechaSalida(fe);
		return true;
	}
	else {
		cout << "Error: el vuelo no existe" << endl;
		return false;
	}
	
}
bool ContenedorLVuelo::cambiarHoraSalida(string codigo, Hora* hoSa) {
	NodoVuelo* temp = ppio;
	if (buscarPorCodigo(codigo)) {
		while (temp != NULL) {
			if (temp->getVuelo()->getCodigo() != codigo) {
				if (temp->getVuelo()->getFechaSalida()->getAnnio() == buscarPorCodigo(codigo)->getFechaSalida()->getAnnio()) {
					if (temp->getVuelo()->getFechaSalida()->getMes() == buscarPorCodigo(codigo)->getFechaSalida()->getMes()) {
						if (temp->getVuelo()->getFechaSalida()->getDia() == buscarPorCodigo(codigo)->getFechaSalida()->getDia()) {
							if ((temp->getVuelo()->getHoraSalida()->getHora() <= hoSa->getHora() && temp->getVuelo()->getHoraLlegada()->getHora() >= hoSa->getHora())) {
								if (temp->getVuelo()->getAvion()->getCategoria() == buscarPorCodigo(codigo)->getAvion()->getCategoria()) {
									cout << "Error: mismo avion dos vuelos mismo tiempo" << endl;
									return false;
								}
								else if (temp->getVuelo()->getAvion()->getCodigoPiloto() == buscarPorCodigo(codigo)->getAvion()->getCodigoPiloto()) {
									cout << "Error: mismo piloto dos vuelos mismo tiempo" << endl;
									return false;
								}
								else {
									for (int i = 0; i < 3; i++) {
										for (int j = 0; j < 3; j++) {
											if (temp->getVuelo()->getAvion()->getCodigoSobrecargo(i) == buscarPorCodigo(codigo)->getAvion()->getCodigoSobrecargo(j)) {
												cout << "Error: mismo sobrecargo dos vuelos mismo tiepmo" << endl;
												return false;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			temp = temp->getSiguiente();
		}
		buscarPorCodigo(codigo)->setHoraSalida(hoSa);
		return true;
	}
	else {
		cout << "Error: el vuelo no existe" << endl;
		return false;
	}
}
bool ContenedorLVuelo::cambiarHoraLlegada(string codigo, Hora* hoLl) {
	NodoVuelo* temp = ppio;
	if (buscarPorCodigo(codigo)) {
		while (temp != NULL) {
			if (temp->getVuelo()->getCodigo() != codigo) {
				if (temp->getVuelo()->getFechaSalida()->getAnnio() == buscarPorCodigo(codigo)->getFechaSalida()->getAnnio()) {
					if (temp->getVuelo()->getFechaSalida()->getMes() == buscarPorCodigo(codigo)->getFechaSalida()->getMes()) {
						if (temp->getVuelo()->getFechaSalida()->getDia() == buscarPorCodigo(codigo)->getFechaSalida()->getDia()) {
							if ((temp->getVuelo()->getHoraSalida()->getHora() <= hoLl->getHora() && temp->getVuelo()->getHoraLlegada()->getHora() >= hoLl->getHora())) {
								if (temp->getVuelo()->getAvion()->getCategoria() == buscarPorCodigo(codigo)->getAvion()->getCategoria()) {
									cout << "Error: mismo avion dos vuelos mismo tiempo" << endl;
									return false;
								}
								else if (temp->getVuelo()->getAvion()->getCodigoPiloto() == buscarPorCodigo(codigo)->getAvion()->getCodigoPiloto()) {
									cout << "Error: mismo piloto dos vuelos mismo tiempo" << endl;
									return false;
								}
								else {
									for (int i = 0; i < 3; i++) {
										for (int j = 0; j < 3; j++) {
											if (temp->getVuelo()->getAvion()->getCodigoSobrecargo(i) == buscarPorCodigo(codigo)->getAvion()->getCodigoSobrecargo(j)) {
												cout << "Error: mismo sobrecargo dos vuelos mismo tiepmo" << endl;
												return false;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			temp = temp->getSiguiente();
		}
		buscarPorCodigo(codigo)->setHoraLlegada(hoLl);
		return true;
	}
	else {
		cout << "Error: el vuelo no existe" << endl;
		return false;
	}
}
bool ContenedorLVuelo::cambiarCodigoVuelo(string codigoViejo, string codigoNuevo) {
	NodoVuelo* temp = ppio;
	if (buscarPorCodigo(codigoViejo)) {
		while (temp != NULL) {
			if (temp->getVuelo()->getCodigo() == codigoNuevo) {
				cout << "Error: el codigo nuevo que ingreso ya existe" << endl;
				return false;
			}
			temp = temp->getSiguiente();
		}
		buscarPorCodigo(codigoViejo)->setCodigo(codigoNuevo);
		return true;
	}
	else {
		cout << "Error: no existe vuelo con el codigo viejo" << endl;
		return false;
	}

}
bool ContenedorLVuelo::cambiarUsoVuelo(string codigo, bool uso) {
	if (buscarPorCodigo(codigo)) {
		buscarPorCodigo(codigo)->setUso(uso);
		return true;
	}
	else {
		cout << "Error: el vuelo no existe" << endl;
		return false;
	}
}

string ContenedorLVuelo::toString(ContenedorLTripulacion* contT, ContenedorLRuta* contRu) const {
	stringstream s;
	NodoVuelo* temp = ppio;
	s << "---COLECCION DE VUELOS---" << endl;
	while (temp != NULL) {
		s << temp->toString(contT, contRu) << endl;
		temp = temp->getSiguiente();
	}
	return s.str();
}