#include"Familia.h"


Familia::Familia(){
	numHijos = 0;
	nombrePareja = "indefinido";
	cedulaPareja = "indefinida";
	vecEdades = NULL;
}

Familia::Familia(int numH, string nP, string cP){  // Constructor con parámetros....
	numHijos = numH;
	nombrePareja = nP;
	cedulaPareja = cP;
	vecEdades = new int[numHijos];   // Creando el vector en tiempo de compilación..
	for (int i = 0; i < numHijos; i++)
		vecEdades[i] = 0;
}
Familia::~Familia(){
	if (vecEdades != NULL) delete[] vecEdades;      // if(vecEdades)  delete [] vecEdades;
}

void Familia::llenadoDelVectorDeEdadesDeHijos() {
	cout << "---Ingreso de las edades de todos los hijos----" << endl;
	for (int i = 0; i < numHijos; i++) {
		cout << "Ingrese la edad del hijo No." << i + 1 << "...";
		cin >> vecEdades[i];
	}
}

// ACCESORES- get's
// MUTADORES- set´s.








bool Familia::existenHijosMayoresDe12Anios() {
	for (int i = 0; i < numHijos; i++)
		if (vecEdades[i] > 12)
			return true;
	return false;
}
 










// ToString(){}
string Familia::toString(){
	stringstream s;
	  s << "-------------INFORMACION DE LA FAMILIA--------------" << endl
		<< " El numero de hijos de esta familia es de: " << numHijos << endl
		<< " El nombre de la pareja es: " << nombrePareja << endl
		<< " La cedula de la pareja es: " << cedulaPareja << endl;
	if (vecEdades != NULL) 
		for (int i = 0; i < numHijos; i++)
			s << "El hijo No." << i + 1 << " tiene " << vecEdades[i] << " anios." << endl;
	return s.str();
}