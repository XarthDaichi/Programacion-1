#include"ContenedorL.h"

int main() {
	int deseo;
	string nomP;
	double preP;

	cout << "------------TRABAJANDO CON CONTENEDORES TIPO LISTA------------------" << endl;
	cout << endl;

	cout << " Creacion de CONTENEDOR-1 TIPO LISTA Y PRODUCTOS...." << endl;
	ContenedorL* CO1 = new ContenedorL();
	cout << "Ingresando productos a ContenedorL-1" << endl;
	do {
		cout << "Ingrese el nombre del producto: ";
		getline(cin, nomP);
		cout << "Ingrese el precio del producto: ";
		cin >> preP;
		CO1->ingresarProducto(new Producto(nomP, preP));
		cout << "Desea ingresar mas?" << endl;
		cout << "Si = 1 || No = 0: ";
		cin >> deseo;
	} while (deseo == 1);

	cout << " Creacion de CONTENEDOR-2 TIPO LISTA Y PRODUCTOS...." << endl;
	ContenedorL* CO2 = new ContenedorL();
	
	cout << "Ingresando productos a ContenedorL-2" << endl;
	do {
		cout << "Ingrese el nombre del producto: ";
		cin >> nomP;
		cout << "Ingrese el precio del producto: ";
		cin >> preP;
		CO2->ingresarProducto(new Producto(nomP, preP));
		cout << "Desea ingresar mas?" << endl;
		cout << "Si = 1 || No = 0: ";
		cin >> deseo;
	} while (deseo == 1);

	cout << "---------------IMPRIMIENDO CONTENEDORES------------------" << endl;
	cout << "Contenedor 1: " << endl << CO1->toString() << endl;
	cout << "Contenedor 2: " << endl << CO2->toString() << endl;
	cout << "----------------COMPARACION DE CONTENEDORES----------------" << endl;
	cout << endl;

	if (CO1->compararaListasIguales(CO2) && CO2->compararaListasIguales(CO1))
		cout << "Si son iguales." << endl;
	else
		cout << "No son iguales." << endl;

	system("pause");
	return 0;
}

