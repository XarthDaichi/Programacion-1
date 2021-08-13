#include "Persona.h" // Aqui incluyen las interfaces de la clases

int main() {
	cout << "Hola Mundo.." << endl;
	int x = 4;
	cout << "El valor de x es: " << x << endl;

	Persona per1; // Objeto tipo Persona.. con constructor sin parametros
	Persona per2("1111111", "Cristina", 1); // con constructor paramatrizado.

	cout << "--------------------------------------------------------------------" << endl;
	cout << per1.toString() << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << per2.toString() << endl;

	system("pause");
	return 0;
}
