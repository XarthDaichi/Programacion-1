#include "Persona.h"

// -------------CONTENEDOR - FORMA - No.1 -----------------------------
// -------------Utiliza un vector de objetos Automaticos---------------
// -------------Teoria y Practica vista en Fundamentos de Inf.---------
// -------------Se crea dentro de contenedor un vector en tiempo-------
// -------------De compilacion con objetos tipo Persona (Automaticos).-

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

class Contenedor {
private:
	Persona vec[20]; // Es un vector Automatico, y su tamaño se establece en tiempo de compilacion.
	int cant; // 1- cantidad de elementos validos en el vector 2- Posicion a ingresar nuevo elemento (Pers)
	int tam; // tam es el tamaño maximo del vector...
public:
	Contenedor() {
		cant = 0;
		tam = 20; // tam igual al numero entre el [] del vec
	}
	virtual ~Contenedor() {}

	bool ingresaPersona() {
		if (cant < tam) { // Este if me garantiza que estoy ingresando personas dentro del rango del vector.
			string ced, nom;
			int ed;
			cout << "Ingrese la cedula: ";
			cin >> ced;
			cout << "Ingrese el nombre: ";
			cin >> nom;
			cout << "Ingrese la edad: ";
			cin >> ed;
			vec[cant].setCedula(ced);
			vec[cant].setNombre(nom);
			vec[cant].setEdad(ed);
			cant++;
			return true;
		}
		else {
			return false;
		}
	}
	string toStrintg() {
		stringstream s;
		s << "-------LISTADO DE PERSONAS---------" << endl;
		for (int i = 0; i < cant; i++) {
			s << vec[i].toString() << endl;
		}
		return s.str();
	}

	// Tarea Moral...
	int posDeLaPersonaMenor(int men) { // busca la posicion de la persona con menor edad
		int menPos = men;
		for (int i = men + 1; i < cant; i++) {
			if (vec[menPos].getEdad() > vec[i].getEdad()) {
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
			if (vec[posMay].getEdad() < vec[i].getEdad()) {
				posMay = i;
			}
		}
		return posMay;
	}
	double promedioDeEdades() {
		double suma = 0;
		for (int i = 0; i < cant; i++) {
			suma += vec[i].getEdad();
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
	cout << "-----TRABAJANDO CON UN CONTENEDOR DE LA FORMA No.1-----------" << endl;
	cout << endl;
	// Crear un contenedor....
	Contenedor CO; // CO es un objeto contenedor automatico..

	int x = 3;
	while (x > 0) {
		if (CO.ingresaPersona()) {
			cout << "Si se ingreso, dicha persona.." << endl;
		}
		else {
			cout << "No se ingreso, dicha persona.." << endl;
		}
		x--;
	}

	// Imprimir el listado de personas que tiene el contenedor...
	cout << CO.toStrintg() << endl;
	system("pause");
	return 0;
}