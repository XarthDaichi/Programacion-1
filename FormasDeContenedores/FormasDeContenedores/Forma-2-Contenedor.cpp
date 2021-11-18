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

//---------------CONTENEDOR - FORMA - No.2----------------------------
//---------------Utiliza un vector de objetos Automaticos-------------
//---------------Teoría y Práctica vista anteriormente con punteros---
//---------------Se crea dentro de contenedor un vector en tiempo-
//---------------de ejecusión con objetos tipo Persona (Automaticos).

class Contenedor {
private:
	Persona *vec; // vec es un puntero (flecha)..... que posteriormente ve a una vector...
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

	// Tarea Moral
	int posDeLaPersonaMenor(int pos) {
		int menPos = pos;
		for (int i = pos + 1; i < cant; i++) {
			if (vec[menPos].getEdad() > vec[i].getEdad()) {
				menPos = i;
			}
		}
		return menPos;
	}
	void intercambia(int pos1, int pos2) {
		if (pos1 != pos2) {
			Persona temp = vec[pos1];
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
			if (vec[mayPos].getEdad() < vec[i].getEdad()) {
				mayPos = i;
			}
		}
		return mayPos;
	}
	double promedioDeEdades() {
		int suma = 0;
		for (int i = 0; i < cant; i++) {
			suma += vec[i].getEdad();
		}
		return suma / (double)cant;
	}
	void invertirElVector() { // Solo se debe invertir la zona válida del vector.
		for (int i = 0; i < cant / 2; i++) {
			intercambia(i, cant - i - 1);
		}
	}
};



/*int main() {
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
}*/