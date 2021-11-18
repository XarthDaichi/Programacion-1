#include"ContenedorM.h"

int main() {
	int op = 0, num = 0, desc = 0;
	char est;
	cout << endl;
	cout << "Creando contenedor matricial...." << endl;
	ContenedorM* contMat = new ContenedorM();
	do {
		system("cls");
		cout << "------------HOTEL------------" << endl;
		cout << endl;
		cout << "----------------------------MENU------------------------" << endl;
		cout << "   1- Ingresar o establecer  estado de la  habitacion.  " << endl;
		cout << "   2- Reporte de habitaciones y su estado en el hotel.  " << endl;
		cout << "   3- Recaudo  total  por  dia  de  todo  hotel.        " << endl;
		cout << "   4- Salir.                                            " << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "    Digite la opcion..";
		cin >> op;
		switch (op) {
		case 1:
			cout << "----INGRESAR O HABILITAR HABITACION----" << endl;
			contMat->imprimeContenedor();
			cout << endl;
			cout << "Ingrese el numero de la habitacion a alquilar o cambiar su estado......";
			cin >> num;
			while (num < 1 && num > 24) {
				cout << "Error al digitar el numero de habitacion" << endl;
				cout << "Dado que la habitacion numero: " << num << " no existe." << endl;
				system("pause");
			}
			cout << "Ingrese el numero de estado al que lo quiere cambiar........ (Alquilar = 'O', Desocupado = 'D, Mantenimiento = 'M')";
			cin >> est;
			if (est == 'O') {
				cout << "Se le va a aplicar descuento?.......(Si = 1 || No = 0)";
				cin >> desc;
			}
			else {
				desc = 0;
			}
			if (contMat->establecerEstadoDeHabitacion(num, est, desc == 1))
				cout << "Si se pudo establecer el nuevo estado para esa habitacion." << endl;
			else
				cout << "No se pudo establecer un nuevo estado para esa habitacion." << endl;
			break;
		case 2:
			cout << "--------REPORTE DE HABITACIONES DEL HOTEL---------" << endl;
			cout << endl;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 6; j++) {
					cout << contMat->obtenerHabitacion(i, j)->toString() << " ";
					if (contMat->obtenerHabitacion(i, j)->getEstado() == 'O') {
						cout << "Pagar: " << contMat->calculoAPagarPorHabitacion(i, j);
					}
					cout << endl;
				}
			}

			break;
		case 3: 
			cout << "----------RECAUDO TOTAL POR DIA DEL HOTEL-------------" << endl;
			cout << endl;
			cout << "El recaudo total del hotel es: " << contMat->obtenerRecaudoDiarioTotal() << endl;
			break;
		case 4: 
			system("cls");
			cout << endl << endl;
			cout << "-----------GRACIAS POR PREFERIRNOS-----------------" << endl;
			cout << "----------HOTEL OCEAN DRIVE MADRID-----------------" << endl;
			cout << "---------------------------------------------------" << endl;
			break;
		default: cout << "Esa opcion NO EXISTE." << endl;
		};
		system("pause");
	} while (op != 4);
	cout << "--------------G R A C I A S------------------" << endl;
	delete contMat;
	system("pause");
	return 0;
}