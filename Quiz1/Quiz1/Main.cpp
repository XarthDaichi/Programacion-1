#include "ContenedorV.h"

int main() {
	Persona* per;
	int tama, deseo, ed, counter = 0;
	bool cont;
	string ced, nom;

	cout << "Ingrese el tamano del contenedor que quiere crear: ";
	cin >> tama;
	ContenedorV CO(tama);
	do {
		cout << "Ingrese la cedula de la persona: ";
		cin >> ced;
		cout << "Ingrese el nombre de la persona: ";
		cin >> nom;
		cout << "Ingrese la edad de la persona: ";
		cin >> ed;
		per = new Persona(ced, nom, ed);
		system("cls");

		CO.ingresaPersonaEnOrdenDeEdad(per);
		counter++;
		cout << CO.toString() << endl;

		if (counter < tama) {
			cout << "Desea ingresar mas? \n Si = 1|No = 0: ";
			cin >> deseo;
			cont = deseo == 1;
		}
	} while (cont && counter < tama);

	system("pause");
	CO.~ContenedorV();
	return 0;
}