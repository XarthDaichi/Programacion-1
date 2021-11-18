#include "Persona.h"
using namespace std;

Persona::Persona(string ced = "Indefinida", string nom = "Indefinido", int ed = 0) : cedula(ced), nombre(nom), edad(ed) {}
Persona::~Persona() {}
void Persona::setCedula(string ced) { cedula = ced; }
void Persona::setNombre(string nom) { nombre = nom; }
void Persona::setEdad(int ed) { edad = ed; }
string Persona::getCedula() { return cedula; }
string Persona::getNombre() { return nombre; }
int Persona::getEdad() { return edad; }

string Persona::toString() {
	stringstream s;
	s << "Cedula: " << cedula << " --> " << nombre << " " << edad << endl;
	return s.str();
}



//---------------CONTENEDOR - FORMA - No.3----------------------------
//---------------Utiliza un vector de objetos Dinámicos-------------
//---------------Teoría y Práctica vista anteriormente con punteros---
//---------------Se crea dentro de contenedor un vector en tiempo-
//---------------de compilación con objetos tipo Persona (Objetos dinámicos).



class Contenedor {
private:
	Persona* vec[10]; // Esto es un vector de 10 posiciones donde hay un puntero tipo Persona en cada posición
	int cant;         // Este vector guarda en c/posicion objetos dinamicos tipo Persona..
	int tam;
public:
	Contenedor() {
		cant = 0;
		tam = 10;
		for (int i = 0; i < tam; i++) {
			vec[i] = NULL;
		}
	}
	virtual ~Contenedor() {
		for (int i = 0; i < cant; i++) {
			delete vec[i];
		}
	}
	bool ingresarPersona(Persona* ptr) {
		if (cant < tam) {
			vec[cant] = ptr;
			cant++; // Se utiliza cant y despues se incrementa
			// vec[++cant] = ptr; Se incrementa cant y despues se utiliza
			return true;
		}
		else {
			return false;
		}
	}
	string toString() {
		stringstream s;
		s << "--------LISTADO DE PERSONAS------------" << endl;
		for (int i = 0; i < cant; i++) {
			s << vec[i]->toString() << endl;
		}
		return s.str();
	}

	// Tarea Moral del ejercico anterior va aqui
	// Tarea Moral...
	int posDeLaPersonaMenor(int men) { // busca la posicion de la persona con menor edad
		int menPos = men;
		for (int i = men + 1; i < cant; i++) {
			if (vec[menPos]->getEdad() > vec[i]->getEdad()) {
				menPos = i;
			}
		}
		return menPos;
	}

	void intercambio(int pos1, int pos2) { // intercambia dos posiciones
		if (pos1 != pos2) {
			Persona temp = vec[pos1];
			vec[pos1] = vec[pos2];
			vec[pos2] = temp;
		}
	}

	void ordenarPorEdad() { // intercambia la posicion del primero y el menor despues del primero evaluando
		for (int i = 0; i < cant - 1; i++) {
			intercambio(i, posDeLaPersonaMenor(i));
		}
	}
	int posDeLaPersonaMayor() {
		int posMay = 0;
		for (int i = 1; i < cant; i++) {
			if (vec[posMay]->getEdad() < vec[i]->getEdad()) {
				posMay = i;
			}
		}
		return posMay;
	}
	double promedioDeEdades() {
		double suma = 0;
		for (int i = 0; i < cant; i++) {
			suma += vec[i]->getEdad();
		}
		return suma / (double)cant;
	}
	void invertirElVector() { // Solo se debe invertir la zona validad del vecotr.
		for (int i = 0; i < cant / 2; i++) {
			intercambio(i, cant - i);
		}
	}
};

int main() {
	Persona* per = NULL; // Puntero a Persona..
	int x = 3, ed;
	string ced, nom;
	char letra 's';
	cout << "----------TRABAJANDO CON CONTENEDOR DE FORMA 3---------" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << endl;
	// Crear un contenedor....
	Contenedor CO; // Contenedor Automatico...
				   // Contenedor Dinamico... Contenedor* ptrCO = new Contenedor();
	while (letra == 's') {
		cout << "---------INGRESANDO PERSONA----------------" << endl;
		cout << endl;
		cout << "Ingrese su cedula...";
		cin >> ced;
		cout << "Ingrese su nombre...";
		cin >> nom;
		cout << "Ingrese su edad...";
		cin >> ed;
		per = new Persona(ced, nom, ed); // Construccion de objeto dinamico tipo persona...

		if (CO.ingresarPersona(per)) { // if (CO.ingresarPersona(per) == true)
			cout << "Si, si se pudo ingresar la persona." << endl;
		}
		else {
			cout << "No, no se pudo ingresar la persona." << endl;
		}
		cout << "Desea seguir ingresando personas.......s/n ?... ";
		cin >> letra;
	}

	// Se le solicita al Contenedor CO que imprima el listado de las Personas..
	cout << CO.toString() << endl;

	system("pause");
	return 0;
}