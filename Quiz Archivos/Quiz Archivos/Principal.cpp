#include "Trabajador.h"
#include <fstream>

int main() {
	
	// Creacion de trabajadores
	Trabajador * tra1 = new Trabajador("11111", "Diego", 100000.0, 0.10, "Toyota", "Tercel", 1);
	Trabajador * tra2 = new Trabajador("22222", "Sofia", 111111.1, 0.20, "Kia", "Picanto", 2);
	Trabajador * tra3 = new Trabajador("33333", "Susanne", 122222.2, 0.30, "Honda", "Civic", 3);

	cout << tra1->toString() << endl;
	cout << tra2->toString() << endl;
	cout << tra3->toString() << endl;

	string rutaArchivo = "../trabajadores.txt";

	cout << "-------------Guardando en Archivo------------" << endl;
	ofstream out;
	out.open(rutaArchivo.c_str(), ios::trunc);
	tra1->guardar(out);
	tra2->guardar(out);
	tra3->guardar(out);
	out.close();

	cout << "-----------BORRANDO DEL RAM-----------" << endl;
	delete tra1;
	delete tra2;
	delete tra3;

	cout << "----------RECUPERANDO E IMPRIMIENDO-----------" << endl;
	ifstream in;
	in.open(rutaArchivo.c_str(), ios::in);

	while (in.good()) {
		Trabajador traTemp = Trabajador::recuperar(in);
		if (in.good()) cout << traTemp.toString() << endl;
	}
	in.close();
	
	cout << endl;
	system("pause");
	return 0;
}