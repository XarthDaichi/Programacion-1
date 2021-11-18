#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Persona {
private:
	string cedula;
	string nombre;
	int edad;
public:
	Persona(string ced = "Indefinida", string nom = "Indefinido", int ed = 0) : cedula(ced), nombre(nom), edad(ed) {}
	virtual ~Persona() {}
	// MODIFICADORES (SET'S)
	void setCedula(string ced) { cedula = ced; }
	void setNombre(string nom) { nombre = nom; }
	void setEdad(int ed) { edad = ed; }
	// ACCESORES (GET'S)
	string getCedula() { return cedula; }
	string getNombre() { return nombre; }
	int getEdad() { return edad; }

	string toString() {
		stringstream s;
		s << "Cedula: " << cedula << " --> " << nombre << " " << edad << endl;
		return s.str();
	}
};



//---------------CONTENEDOR - FORMA - No.3----------------------------
//---------------Utiliza un vector de objetos Din�micos-------------
//---------------Teor�a y Pr�ctica vista anteriormente con punteros---
//---------------Se crea dentro de contenedor un vector en tiempo-
//---------------de compilaci�n con objetos tipo Persona (Objetos din�micos).



class Contenedor {
private:
	Persona* vec[10]; // Esto es un vector de 10 posiciones donde hay un puntero tipo Persona en cada posici�n
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
	int posDeLaPersonaMenor(int pos) {
		int menPos = pos;
		for (int i = pos + 1; i < cant; i++) {
			if (vec[menPos]->getEdad() > vec[i]->getEdad()) {
				menPos = i;
			}
		}
		return menPos;
	}
	void intercambia(int pos1, int pos2) {
		if (pos1 != pos2) {
			Persona* temp = vec[pos1];
			vec[pos1] = vec[pos2];
			vec[pos2] = temp;
		}
	}
	void ordenarPorEdad() {
		for (int i = 0; i < cant; i++) {
			intercambia(i, posDeLaPersonaMenor(i));
		}
	}
	int posDeLaPersonaMayor() {
		int mayPos = 0;
		for (int i = 1; i < cant; i++) {
			if (vec[mayPos]->getEdad() < vec[i]->getEdad()) {
				mayPos = i;
			}
		}
		return mayPos;
	}
	double promedioDeEdades() {
		double suma = 0;
		for (int i = 0; i < cant; i++) {
			suma += vec[i]->getEdad();
		}
		return suma / (double)cant;
	}
	void invertirElVector() { // Solo se debe invertir la zona v�lida del vector.
		for (int i = 0; i < cant / 2; i++) {
			intercambia(i, cant - i - 1);
		}
	}
};

/*int main() {
	Persona* per = NULL; // Puntero a Persona..
	int x = 3, ed;
	string ced, nom;
	char letra = 's';
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

	CO.invertirElVector();
	cout << CO.toString() << endl;

	system("pause");
	return 0;
}*/