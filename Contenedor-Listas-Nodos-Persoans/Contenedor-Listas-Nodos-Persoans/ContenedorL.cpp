# include "ContenedorL.h"

ContenedorL::ContenedorL(){

}
ContenedorL::~ContenedorL(){

}

Nodo* ContenedorL::getPpio(){
	return ppio;
}

string ContenedorL::toString(){

}

bool ContenedorL::isEmpty(){
	return (ppio == NULL);
}
int ContenedorL::cuentaNodos(){
	Nodo* p = ppio;
	int cont = 0;
	while (p != NULL) {
		cont++;
		p = ppio->getSiguiente(); // La flecha o puntero externo p, se pasa hacia otro nodo
	}
	return cont;
}

void ContenedorL::insertarAlInicio(Persona* per) {
	ppio = new Nodo(per, ppio);
}

// void ContenedorL::insertarAlInicio(Persona* per){ // Ya viene el objeto dinamico en per.
	// Nodo* nuevo = new Nodo(per, NULL); // Este es el nodo a insertat al inicio.
	// nuevo->setSiguiente(ppio); // COnecto el nuevo nodo con lo que "ve" ppio.
	// ppio = nuevo; // aqui conecto ppio con el nuevo nodo, quedando el nuevo nodo como primero
// }

void ContenedorL::insertarAlFinal(Persona* per){
	Nodo* p = ppio;
	Nodo* nuevo = new Nodo(per, NULL);
	if (p == NULL) {

	}
}
bool ContenedorL::insertarEnLugar(Persona*, int lug){

}

bool ContenedorL::eliminarElPrimero(){

}
bool ContenedorL::eliminarElUltimo(){

}
bool ContenedorL::eliminarEnLugar(int lug) { // Tarea Moral ==> Muy Importante..
	Nodo* borrado = NULL;
	int cant = this->cuentaNodos(); // La ineficiencia no se valua en Progra-1
	int cont = 1; // Es para contar los nodos en proceso de desplazamiento hacia la derecha en la lista..
	Nodo* p = ppio;
	if (cant >= lug) {
		// En caso de eliminar el primer elemento válido de la lista..
		if (lug == 1) {
			borrado = ppio;
			if (borrado != NULL) {
				ppio = borrado->getSiguiente();
				delete borrado;
			}
			return true;
		}
		while (cont < lug - 1) {
			p = p->getSiguiente();
			cont++;
		}
		// Aquí empieza el borrado del siguiente....
		borrado = p->getSiguiente();
		if (borrado != NULL) { // esto es como tener cuidado de que borrado sea una posición donde nada exista.
			p->setSiguiente(borrado->getSiguiente());
			delete borrado; // Esto elimina al nodo y su pasajero del lugar lug.
		}
		return true;
	}
	else {
		cout << "Ese lugar no existe en esa lista" << endl;
		return false;
	}
}

Nodo* ContenedorL::retPosUltimoLug(){

}
Persona* ContenedorL::retPersUltimoLug(){

}
Nodo* ContenedorL::retPosPrimerLug(){

}
Persona* ContenedorL::retPersPrimerLug(){

}
Nodo* ContenedorL::retPosLug(int lug){

}
Persona* ContenedorL::retPersEnLugar(int lug){

}

double ContenedorL::promedioEdades(){

}
Persona* ContenedorL::persDeMayorEdad(){

}
Persona* ContenedorL::persDeMenorEdad(){

}

void ContenedorL::invertirOrdLista(){

}
void ContenedorL::ordenarASCEdad(){

}