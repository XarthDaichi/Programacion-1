#include"Trabajador.h"

Trabajador::Trabajador(string ced, string nom, int numHs): Persona(ced, nom), numHijos(numHs) {
	vecEdadesHijos = new int[numHijos];
	for (int i = 0; i < numHijos; i++) {
		vecEdadesHijos[i] = 0;
	}
}

Trabajador::~Trabajador(){
	if (vecEdadesHijos != NULL)
		delete vecEdadesHijos;
}

void Trabajador::llenarVecDeEdades(){  // desde el teclado....
	for (int i = 0; i < numHijos; i++) {
		cout << "Ingrese la edad de su hij@: ";
		cin >> vecEdadesHijos[i];
	}
	system("pause");
}

