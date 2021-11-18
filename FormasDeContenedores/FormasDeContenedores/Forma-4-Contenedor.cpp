#include<iostream>
#include<sstream>
#include<string>
using namespace std;

//---------------CONTENEDOR - FORMA - No.4----------------------------
//---------------Utiliza un vector de objetos Dinámicos-------------
//---------------Teoría y Práctica vista anteriormente con punteros---
//---------------Se crea dentro de contenedor un vector cuya longitud se crea en tiempo-
//---------------de ejecusión con objetos tipo Persona (Objetos dinámicos).

class Persona {
private:
	string cedula;
	string nombre;
	int edad;
public:
	Persona() {}
	Persona(string ced, string nom, int ed) : cedula(ced), nombre(nom), edad(ed) {}
	virtual ~Persona() { cout << "Persona Destruida" << endl; }
	// MUTADORES (SET´S).
	void setCedula(string ced) { cedula = ced; }
	string getCedula() { return cedula; }
	void setNombre(string nom) { nombre = nom; }
	string getNombre() { return nombre; }
	void setEdad(int ed) { edad = ed; }
	int getEdad() { return edad; }

	string toString() {
		stringstream s;
		s << "Cedula: " << cedula << " --> " << nombre << " " << edad << endl;
		return s.str();
	}
};

// I Forma Persona vec[10]; // Vector de 10 posiciones (tiempo de compilacion) con Persona Automaticas.
// II Forma Persona *vec; // Vector con longitud en tipo de Ejecusión con Personas Automaticas..
//III Forma Persona* vec[10]; // Vector de 10 posiciones (tipo de compilación) con Persona Dinamicas.
// IV Forma Persona* *vec; // Vector con longitud en tipo de Ejecusión con Personas Dinamicas.

class Contenedor {
private:
	Persona* *vec; // La longitud del vector se establece en tiempo de ejecusión y carga objetos dinámicos
	int cant;
	int tam;
public:
	Contenedor(int tama) {
		vec = new Persona * [tama];
		cant = 0;
		tam = tama;
		// Limpiar el vector...
		for (int i = 0; i < tam; i++)
			vec[i] = NULL;
	}

	virtual ~Contenedor() {
		for (int i = 0; i < cant; i++)
			delete vec[i]; // Borrar objetos dinámicos dentro del vector.
		delete[] vec; // Eliminar el vector...
	}

	bool ingresarPersona(Persona* per) {
		if (cant < tam) {
			vec[cant++] = per;
			return true;
		}
		else
			return false;
	}

	string toString() {
		stringstream s;
		s << "----------LISTADO DE PERSONAS-----------" << endl;
		for (int i = 0; i < cant; i++)
			s << vec[i]->toString() << endl;
		return s.str();
	}

	bool cedulaYaExiste(string ced) {
		for (int i = 0; i < cant; i++)
			if (vec[i]->getCedula() == ced)
				return true;
		return false;
	}

	// Tarea Moral ==> Aquella que está en las Formas anteriores..
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
	void invertirElVector() { // Solo se debe invertir la zona válida del vector.
		for (int i = 0; i < cant / 2; i++) {
			intercambia(i, cant - i - 1);
		}
	}
};

int main() {
	int tama;
	cout << "---------TRABAJANDO CON LA FORMA -4 DE CONTENEDOR----------" << endl;
	cout << endl;
	cout << "Creacion de Personas...." << endl;
	Persona* per1 = new Persona("11111", "Moe", 23);
	Persona* per2 = new Persona("22222", "Larry", 34);
	Persona* per3 = new Persona("33333", "Curly", 45);
	Persona* per4 = new Persona("44444", "Manson", 13);
	Persona* per5 = new Persona("55555", "Sonia", 50);
	cout << endl;
	cout << "Crear un Contenedor en Forma 4..." << endl;
	cout << "Ingrese el tamano del vector interno del Contenedor....";
	cin >> tama;
	Contenedor CO(tama); // Contenedor Automatico.
	// Contenedor Dinámico: Contenedor* ptrCO = new Contenedor(tama);
	cout << endl;
	cout << "Ingresar las Personas al Contenedor..." << endl;
	CO.ingresarPersona(per1);
	CO.ingresarPersona(per2);
	CO.ingresarPersona(per3);
	CO.ingresarPersona(per4);
	CO.ingresarPersona(per5);
	cout << endl;

	cout << "Generar un listado de las personas existentes en el Contenedor...." << endl;
	cout << CO.toString() << endl;

	// Variables comodín...
	Persona* per = NULL; // Puntero a Persona..
	int x = 3, ed;
	string ced, nom;
	char letra = 's';
	//-----------------------------------------------
	cout << "--------TRABAJANDO CON CONTENEDOR DE FORMA 4-------------" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << endl;
	// Crear un contenedor....
	Contenedor CO1(10); // Contenedor Automatico...
	                    // Contenedor Dinámico... Contenedor* ptrCO = new Contenedor();
	while (letra == 's') {
		cout << "-------------INGRESANDO PERSONA---------------------" << endl;
		cout << endl;
		cout << "Ingrese su cedula...";
		cin >> ced;

		// Tarea Moral
	   // Aquí se requiere hacer el proceso de validación la cedula.
	   // Si la cedula se repite, entonces hay que volverla a pedir.
		while (CO1.cedulaYaExiste(ced)) {
			cout << "Ingrese su cedula...";
			cin >> ced;
		}

		cout << "Ingrese su nombre...";
		cin >> nom;
		cout << "Ingrese su edad...";
		cin >> ed;

		per = new Persona(ced, nom, ed); // Construcción de objeto dinámico tipo persona...

		if (CO1.ingresarPersona(per)) // if(CO.ingresarPersona(per) == true)
			cout << "Si, si se pudo ingresar la persona." << endl;
		else
			cout << "No, no se pudo ingresar la persona." << endl;
		cout << endl;
		cout << "Desea seguir ingresando personas.....s/n ?...";
		cin >> letra;
	}

	// Se le solicita al Contenedor CO que imprima el listado de las Personas..
	cout << CO1.toString() << endl;

	system("pause");
	return 0;
}