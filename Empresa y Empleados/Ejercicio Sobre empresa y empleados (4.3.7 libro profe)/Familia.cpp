#include "Familia.h"

Familia::Familia() {
	numHijos = 0;
	nombrePareja = "INDEFINIDO";
	cedulaPareja = "INDEFINIDA";
	vecEdades = NULL;
}
Familia::Familia(int numH, string nP, string cP) {
	numHijos = numH;
	nombrePareja = nP;
	cedulaPareja = cP;
	vecEdades = new int[numHijos]; // Creando el vector en tiempo de compilacion ..
	for (int i = 0; i < numHijos; i++) {
		vecEdades[i] = 0;
	}
}
Familia::~Familia() {
	if (vecEdades != NULL) {
		delete[] vecEdades;
	}
}
// ACCESORES - get's
int Familia::getNumHijos() { return numHijos; }
string Familia::getNombrePareja() { return nombrePareja; }
string Familia::getCedulaPareja() { return cedulaPareja; }

// MUTADORES - set's
void Familia::setNumHijos(int numH) { numHijos = numH; }
void Familia::setNombrePareja(string nP) { nombrePareja = nP; }
void Familia::setCedulaPareja(string cP) { cedulaPareja = cP; }
void Familia::llenadoDelVectorDeEdadesDeHijos() { 
	cout << "---Ingreso de las edades de todos los hijos---" << endl;
	for (int i = 0; i < numHijos; i++) {
		cout << "Ingrese la edad del hijo No." << i + 1 << "...";
		cin >> vecEdades[i];
	}
}
void Familia::incrementoDeHijoFamilia() {}

// toString();
string Familia::toString() {
	stringstream s;
	s << "-----------INFORMACION DE LA FAMILIA-------------" << endl
		<< "El numero de hijos de esta familia es de: " << numHijos << endl
		<< "El nombre de la pareja es: " << nombrePareja << endl
		<< "La cedula de la pareja es: " << cedulaPareja << endl;
	if (vecEdades != NULL) {
		for (int i = 0; i < numHijos; i++) {
			s << "El hijo No." << i + 1 << " tiene " << vecEdades[i] << " anios." << endl;
		}
	}
	return s.str();
}