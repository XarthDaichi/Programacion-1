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




//---------------CONTENEDOR - FORMA - No.2----------------------------
//---------------Utiliza un vector de objetos Automaticos-------------
//---------------Teoría y Práctica vista anteriormente con punteros---
//---------------Se crea dentro de contenedor un vector en tiempo-
//---------------de ejecusión con objetos tipo Persona (Automaticos).



class Contenedor {
private:
	Persona* vec; // vec es un puntero (flecha)..... que posteriormente ve a una vector...
	int cant;
	int tam;
public:
	Contenedor(int n) { // Aquí se recibe a n como futuro tamaño de la longitud del vector interno del contened.
		cant = 0;
		tam = n;
		vec = new Persona[tam]; // Creando un vector dinámico con objetos Automáticos dentro.
	}



	virtual ~Contenedor() {
		delete[] vec; // se borra el vector (libera la memoria que tenia atrapada el vector).
		cout << "Aqui se destruye el vector usado en este contenedor." << endl;
	}



	bool ingresaPersona() {
		if (cant < tam) { // Este if me garantiza que estoy ingresando personas dentro del rango del vector.
			string ced, nom;
			int ed;
			cout << "Ingrese la cedula: ";
			cin >> ced;
			cout << "Ingrese el nombre: ";
			cin >> nom;
			cout << "Ingrese la edad..: ";
			cin >> ed;
			vec[cant].setCedula(ced);
			vec[cant].setNombre(nom);
			vec[cant].setEdad(ed);
			cant++;
			return true;
		}
		else
			return false;
	}



	string toString() {
		stringstream s;
		s << "--------------LISTADO DE PERSONAS-------------" << endl;
		for (int i = 0; i < cant; i++)
			s << vec[i].toString() << endl;
		return s.str();
	}
};



int main() {
	{
		int tama;
		cout << "-----TRABAJANDO CON UN CONTENEDOR DE LA FORMA No.2------" << endl;
		cout << endl;
		cout << "Digite el tamano del contenedor....";
		cin >> tama;
		// Creando el contenedor de Objetos (automaticos) Persona cuya longitud del vector
		// se da en tiempo de ejecusión....
		// CREANDO EL CONTENEDOR..
		Contenedor CO(tama);
		//---------------------------------------



		int x = 3;
		while (x > 0) {
			if (CO.ingresaPersona()) // if(CO.ingresaPersona() == true)
				cout << "Si se ingreso, dicha persona.." << endl;
			else
				cout << "No se ingreso, dicha persona.." << endl;
			x--;
		}
		// Imprimir el listado de personas que tiene el contenedor...
		cout << CO.toString() << endl;
	} // <--- aquí se destruye el contenedor...
	system("pause");
	return 0;
}