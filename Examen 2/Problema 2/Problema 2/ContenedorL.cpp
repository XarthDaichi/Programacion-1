#include"ContenedorL.h"


ContenedorL::ContenedorL() {
	ppio = NULL;
}

ContenedorL::~ContenedorL() {
	Nodo* temp = ppio;
	Nodo* siguiente;
	while (temp != NULL) {
		siguiente = temp->getSiguiente();
		delete temp;
		temp = siguiente;
	}
	ppio = NULL;
}

Nodo* ContenedorL::getPpio() { return ppio; }

string ContenedorL::toString() {  
	stringstream s;
	Nodo* temp = ppio;
	while (temp != NULL) {
		s << temp->getProducto()->toString();
		temp = temp->getSiguiente();
	}
	return s.str();
}

bool ContenedorL::estaVacia() {  
	return ppio == NULL;
}

void ContenedorL::ingresarProducto(Producto* pro){
	Nodo* temp = ppio;
	Nodo* nuevo = new Nodo(pro, NULL);
	if (ppio == NULL) {
		nuevo->setSiguiente(ppio);
		ppio = nuevo;
	}
	else {
		while (temp->getSiguiente() != NULL) {
			temp = temp->getSiguiente();
		}
		temp->setSiguiente(nuevo);
	}
}

bool ContenedorL::compararaListasIguales(ContenedorL* contPtr2) {
	Nodo* tempThis = ppio;
	Nodo* tempCont2 = contPtr2->getPpio();
	bool salida = false, igualTemp = false;
	
	while (tempThis != NULL && !salida) {
		while (tempCont2 != NULL && !igualTemp) {
			if (tempThis->getProducto()->esIgualA(*tempCont2->getProducto())) {
				igualTemp = true;
			}
			else {
				tempCont2 = tempCont2->getSiguiente();
			}
		}
		tempThis = tempThis->getSiguiente();
		if (tempCont2 == NULL && igualTemp == false) {
			salida = true;
		}
		else {
			tempCont2 = contPtr2->getPpio();
			igualTemp = false;
		}
	}
	if (salida) {
		return false;
	}
	else {
		return true;
	}
}





