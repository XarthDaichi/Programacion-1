#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Parte del primer codigo de la clase
// Paso por puntero... (hay 2 razones fuertes).

void cambiarValor(int*); // aquí se recibe un puntero..en esta declaración..

// Parte del segundo codigo de la clase
class Persona {
private:
	string cedula;
	string nombre;
	int edad;
public:
	// Persona() {} constructor sin parametros
	// Persona(string ce, string nom, int ed): cedula(ce), nombre(nom), edad(ed) {} constructor con parametros
	Persona(string ce = "Indefinida", string nom = "Indefinido", int ed = 0) : cedula(ce), nombre(nom), edad(ed) {}
	virtual ~Persona() {}
	string getCedeula() { return cedula; }
	string getNombre() { return nombre; }
	int getEdad() { return edad; }
	void setCedula(string ce) { cedula = ce; }
	void setNombre(string nom) { nombre = nom; }
	void setEdad(int ed) { edad = ed; }
	string toString() {
		stringstream s;
		s << "Cedula " << cedula << endl
			<< "Nombre " << nombre << endl
			<< "Edad " << edad << endl;
		return s.str();
	}
	bool esMayorEnEdadQue(Persona* ptr2) {
		//if (edad > ptr2->getEdad()) {
		//	return true;
		// }
		// else {
		// 	return false;
		// }
		return edad > ptr2->getEdad();
	}
	double promedioDeEdades(Persona* ptr2) {
		return (edad + ptr2->getEdad()) / 2;
	}
	void cambiarNombreA(Persona* ptr2) {
		string nom; // Variable comodin...
		cout << "Ingrese el nuevo nombre...";
		cin >> nom;
		ptr2->setNombre(nom);
	}
};

int main() {
	// Parte del primer codigo de la clase
	cout << "---PASO POR PUNTERO---" << endl;
	cout << endl;
	int x = 3;
	cout << "El valor del identificador de x es: " << x << endl;
	int* ptr = &x; // entrego la direccion del identificador x al puntero ptr.
	cambiarValor(ptr);
	cout << "Despues de enviar la direccion del identificador x a la funcion quedara asi:" << endl;
	cout << "El valor nuevo del identificador x es de: " << x << endl << endl;

	// Parte del segundo codigo de la clase
	// Trabajando con objetos dinamics...
	cout << "----CREACION DE OBJETOS DINAMICOS CON TIPOS DE DATO PRIMITIVOS O BASICOS----" << endl;
	cout << endl;
	//int x = 3;
	int* ptr1 = new int(x);
	char letra = 'a';
	char* ptr2 = new char(letra);
	cout << "Imprimiendo el contenido del objeto dinamico ptr1: " << *ptr1 << endl;
	cout << "Imprimiendo el contenido del objeto dinamico ptr2 : " << *ptr2 << endl;
	cout << endl;
	cout << "----CREACION DE OBETOS DINAMICO CON TIPOS DE DATO TIPO PERSONA----" << endl;
	cout << endl;
	Persona* ptrP0 = new Persona; // Creacion de objeto dinamico de Persona construido con contructor sin parametros.
	Persona* ptrP1 = new Persona("11111", "Julia", 19); // Utilizando el constructor parametrizado, o con parametros.
	Persona* ptrP2 = new Persona("22222", "Cristianito", 1);

	// Hago lo que sea...
	cout << "La informacion de ptrP1 es: " << endl << ptrP1->toString() << endl;
	cout << "La informacion de ptrP2 es: " << endl << ptrP2->toString() << endl; // Al usar punteros se usan flechas y no los puntos
	// ptrP2 = NULL; si hago eso antes del delete ptrP2, la persona queda en el RAM
	if (ptrP1->esMayorEnEdadQue(ptrP2)) {
		cout << "La persona llamada: " << ptrP1->getNombre() << " es mayor a la persona llamada: " << ptrP2->getNombre() << endl;
	}
	else {
		cout << "La persona llamada: " << ptrP1->getNombre() << " no es mayor a la persona llamada: " << ptrP2->getNombre() << endl;
	}

	// Sacar el promedio de edades de los dos objets...
	cout << "El promedio de edades de los objetos ptrp1 y ptrp2 es de: " << ptrP1->promedioDeEdades(ptrP2) << " anios." << endl << endl;

	// Un objeto le cambia el nombre a otro que llega por puntero "parametro"...
	ptrP1->cambiarNombreA(ptrP2);
	cout << "La nueva informacion de ptrP2 es: " << endl << ptrP2->toString() << endl << endl;


	// Borra o libera la memoria que tenian atrapada los objetos dinamics...
	delete ptr1;
	delete ptr2;
	delete ptrP0;
	delete ptrP1;
	delete ptrP2;

	system("pause");
	return 0;
}

void cambiarValor(int* ptrX) {
	*ptrX = 28;
}