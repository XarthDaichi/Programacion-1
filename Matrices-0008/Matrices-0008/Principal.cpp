#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Persona {};

int main() {
	cout << "--------TRABAJANDO CON MATRICES A LA LIBRE-------" << endl;
	// int mat[4][4]; // es una matriz de elementos enteros llamada matriz cuadrada. fil = col
	// char mat2[3][9]; // tiene 3 filas y 9 columnas y es una matriz de char o sea de letras.
	// Persona matr3[3][3]; // Matriz de objetos automaticos tipo Persona... Tiempo de compilacion
	// Persona* mat4[8][8]; // Matriz de objetos dinamicos tipo Persona... Tiempo de compilacion
	// Persona** mat5; // Se establecen sus dimensiones en tiempo de ejecusion.
	// Persona*** mat6; // Se establecen sus dimensiones en tiempo de ejecusion.

	// RECORDANDO.... DE FUNDA...
	// int mat[4][4]; // es una matriz de elementos enteros llamada matriz cuadrada. fil = col

	// Hay basicamente tres tipo de maneras de llenar una matriz que son:
	// Forma (rapida, automatica, manual)...


	cout << "Llenado de una matriz (a la libre) de una forma rapida..." << endl;
	cout << endl;
	int mat[4][4] = { 1, 20, 3, 40,
					  50, 6, 7, 8,
					  90, 8, 7, 6,
					  1, 20, 3, 40 }; // Llenada de la matriz en tiempo de compilacion... 
									// La forma matricial al llenarlo es solo para verlo facilmente, en realidad es una fila de elementos

	for(int i = 0; i < 4; i++) { // Para recorrer la fila de arriba hacia abajo
		for (int j = 0; j < 4; j++) { // Para recorrer la fila (saltar de columna en columna)
			cout << mat[i][j] << '\t';   // '\n'     '\t'
		}
		cout << endl;
	}

	cout << "------------------------------------------------------------------" << endl;
	cout << "Llenado de una matriz (a la libre) de una forma automatica.. con datos aleatorios." << endl;
	int mat2[5][4]; // Declaracion de una matriz..

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			mat2[i][j] = rand() / 100;
		}
	}
	cout << endl << endl;

	cout << "Imprimir matriz de llenado automatico con valores aleatoris...." << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << mat2[i][j] << '\t';
		}
		cout << endl;
	}

	cout << endl << endl;

	cout << "--Llenado de una matriz de manera manula. Ir casilla por casilla llenando la matriz" << endl;
	char mat3[2][5];

	cout << "Llenado la matriz...." << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			cout << "Ingrese la letra..";
			cin >> mat3[i][j];
		}
	}

	cout << "Imprimir la matriz de letras ingresadas de manera manual..." << endl;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			cout << mat3[i][j] << '\t';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}