#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "--------TRABAJANDO CON PUNTEROS--------" << endl;
	cout << endl;

	cout << "Crear algunos identificadores, ....." << endl;
	char letra = 'a';
	int x = 15;
	double y = 3.7854;
	string frase = "Hola Mundo";
	cout << endl;
	cout << "Creando punteros para esos identificadores....." << endl;
	// Aquie son declarados y definidos o inicializados...
	char* ptr1 = NULL;
	int* ptr2 = NULL;
	double* ptr3 = NULL;
	string* ptr4 = NULL;
	cout << "Dar a esos punteros las respectivas direcciones de la memoria.." << endl;
	ptr1 = &eltra; // Aqui le sacamos la direccion al identificador letra;
	ptr2 = &x; // Aqui le sacamos la direccion al identificador x
	ptr3 = &y; // Aqui le sacamos la direccion al identificador y
	ptr4 = &frase;  // Aqui le sacamos la direccion al identificador frase
	cout << "Se puede ver el contenido de un puntero o de una flecha.?" << endl;
	cout << "Claro que si, si se puede ver el contenido de lo que ve el puntero." << endl;
	cout << endl;
	cout << "primero vamos a imprimir las direcciones de memoria....." << endl;
	cout << "Imrprimir la direccion de memoria de la variable letra" << ptr1 << endl;
	cout << "Imrprimir la direccion de memoria de la variable x" << ptr2 << endl;
	cout << "Imrprimir la direccion de memoria de la variable y" << ptr3 << endl;
	cout << "Imrprimir la direccion de memoria de la variable frase" << ptr4 << endl;
	cout << endl;


	cout << "Imprimir los contenidos o valores de lo que ven los punteros...." << endl;
	cout << "Imprimiendo el contenido de lo que ve el puntero ptr1 " << *ptr1 << endl;
	cout << "Imprimiendo el contenido de lo que ve el puntero ptr2 " << *ptr2 << endl;
	cout << "Imprimiendo el contenido de lo que ve el puntero ptr3 " << *ptr3 << endl;
	cout << "Imprimiendo el contenido de lo que ve el puntero ptr4 " << *ptr4 << endl;

	cout << "Se puede trabajar con los contenidos que ven los punteros.?" << endl;
	cout << "CLARO QUE SI" << endl;
	cout << "Al multiplicar los contenidos de lo que ven la flechas ptr2 y ptr3 es: ";
	cout << " x * y = " << *ptr2 * *ptr3 << endl;
	cout << "Al sumar los contenidos de lo que ven las flechas ptr2 y ptr3 es: ";
	cout << " x + y = " << *ptr2 + *ptr3 << endl;
	cout << endl << endl;

	cout << "Cambiando el valor de x = 15 a valor de x = 18 por medio del puntero.." << endl;
	*ptr2 = 18;
	cout << "El valor de la x es: " << x << endl;


	system("pause");
	return 0;
}