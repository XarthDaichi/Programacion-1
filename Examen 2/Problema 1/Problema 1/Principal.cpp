#include"AViaje.h"

int main() {
	int cat;
	string nomE, cedJud, teleCel;
	cout << "-------------VIAJES DE COSTA RICA-----------------" << endl;
	cout << "Creación de un objeto AViaje.." << endl;
	cout << "Ingrese el Nombre de la Empresa: ";
	getline(cin, nomE);
	cout << "Ingrese la Cedula Juridica: ";
	cin >> cedJud;
	cout << "Ingrese el Telefono Celular: ";
	cin >> teleCel;
	AViaje via(nomE, cedJud, teleCel);

	cout << endl;
	cout << "Ingrese el codigo o categoria del viaje: ";
	cin >> cat;
	cout << "Con base en lo anterior, se tiene que: " << endl;
	cout << endl;
	via.infoDelViaje(cat);

	system("pause");
	return 0;
}