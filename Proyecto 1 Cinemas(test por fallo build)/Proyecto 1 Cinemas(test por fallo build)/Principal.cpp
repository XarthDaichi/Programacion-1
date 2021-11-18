#include "Cinema.h"

int main() {
	char tipoLenguajetemp, tipoSalatemp;
	int dimensionestemp, numSalatemp, numMestemp, numDiatemp, numAnniotemp = 0, numHoratemp;
	string paistemp, generotemp, nombretemp, sinopsistemp;
	bool paraNinnostemp;
	int tiqAdutemp, tiqNintemp = 0;

	Cinema Cine(2);

	int opcion, deseo1, deseo2, seleccionDeFuncion, tempNum, tempNum2, totalTiqtemp, pagar;

	char filatemp;
	int columnatemp;
	string cedulatemp;

	// Inicializacion de los punteros
	Sala* tempSala = NULL;
	Pelicula* tempPel = NULL;
	Funcion* tempFun = NULL;


	/*// Cosas para probar rapido el 3
	Sala* Sala1 = new Sala("Sala 1", 2021, 'r');
	Sala* Sala2 = new Sala("Sala 2", 2021, 'v');

	Pelicula* pel1 = new Pelicula("Drama", "Orgullo y Prejuicio", "Jane Austen es feminista", false);
	Pelicula* pel2 = new Pelicula("Comedia", "Paw Patrol", "Perros Salvan Mundo", true);
	Pelicula* pel3 = new Pelicula("Aventura", "Como entrenar a tu dragon", "Hiccup obtiene a Chimuelo", true);
	Pelicula* pel4 = new Pelicula("Accion", "Venom 2", "Venom obtine a Eddy", false);

	Funcion* fun1 = new Funcion('s', 2, "Costa Rica", pel1);
	Funcion* fun2 = new Funcion('d', 3, "Costa Rica", pel2);
	Funcion* fun3 = new Funcion('d', 2, "Costa Rica", pel3);
	Funcion* fun4 = new Funcion('s', 3, "Costa Rica", pel4);

	Cine.ingresarSala(Sala1);
	Cine.ingresarSala(Sala2);
	Cine.ingresarFuncion(fun1, 0, 0, 0);
	Cine.ingresarFuncion(fun2, 0, 0, 1);
	Cine.ingresarFuncion(fun3, 0, 2, 2);
	Cine.ingresarFuncion(fun1, 1, 0, 2);*/


	do {
		cout << "--------------------MENU-------------------" << endl;
		cout << "1- Ingresar Sala (Faltan: " << 2 - Cine.getCantidad() << " por ingresar)" << endl;
		cout << "2- Ingresar Funcion" << endl;
		cout << "3- Busqueda de Funcion y Compra de Tiquetes" << endl;
		cout << "4- Salir" << endl;
		cout << endl;
		cout << "Ingrese la operacion que desea: ";
		cin >> opcion;
		system("cls");

		switch (opcion) {
		case 1:
			if (numAnniotemp == 0) {
				cout << "Ingrese el annio: ";
				cin >> numAnniotemp;
			}

			if (Cine.getCantidad() == 0) {
				nombretemp = "Sala 1";
			}
			else if (Cine.getCantidad() == 1) {
				nombretemp = "Sala 2";
			}
			cout << "Ingrese el tipo de sala que quiere crear: " << endl;
			cout << "Regular: r | VIP: v " << endl;
			cin >> tipoSalatemp;


			tempSala = new Sala(nombretemp, numAnniotemp, tipoSalatemp);
			Cine.ingresarSala(tempSala);

			cout << "<Enter para continuar>" << endl;
			cin.get();
			cin.get();
			system("cls");

			break;
		case 2:
			cout << "Ingrese el nombre de la peliucla: ";
			cin.ignore();
			getline(cin, nombretemp);

			cout << "Ingrese el genero de la pelicula: ";
			getline(cin, generotemp);

			cout << "Ingrese la sinopsis de la pelicula: ";
			getline(cin, sinopsistemp);

			cout << "Ingrese si la pelicula es para ninnos: " << endl;
			cout << "Si: 1 | No: 0 " << endl;
			cin >> tempNum;
			paraNinnostemp = tempNum == 1;

			tempPel = new Pelicula(generotemp, nombretemp, sinopsistemp, paraNinnostemp);

			
			cout << "Ingrese si la funcion esta subtitulada o doblada: " << endl;
			cout << "Subtitulada: s | Doblada: d " << endl;
			cin >> tipoLenguajetemp;

			cout << "Ingrese la dimension en la que se va a ofrecer la funcion: " << endl;
			cout << "2D: 2 | 3D: 3 " << endl;
			cin >> dimensionestemp;
			
			cout << "Ingrese el pais en el que esta disponible la funcion: ";
			cin.ignore();
			getline(cin, paistemp);

			tempFun = new Funcion(tipoLenguajetemp, dimensionestemp, paistemp, tempPel);
			
			cout << "Ingrese el numero de Sala que quiere asignarle a la funcion: ";
			cin >> numSalatemp;
			
			cout << "Ingrese el mes que va a asignarle a la funcion: " << endl;
			cout << "  Enero: 1   |  Febrero: 2 |    Marzo: 3   |   Abril: 4\n   Mayo: 5   |   Junio: 6  |    Julio: 7   |   Agosto: 8\nSetiembre: 9 | Octubre: 10 | Noviembre: 11 | Diciembre: 12" << endl;
			cin >> numMestemp;
			
			cout << "Ingrese el dia que va a asignarle a la funcion: ";
			cin >> numDiatemp;

			numDiatemp = Cine.FehcaADia(numDiatemp, numMestemp, numAnniotemp);
			
			cout << "Ingrese la hora que va a asignarle a la funcion: " << endl;
			cout << "Manana: 1 | Tarde: 2 | Noche: 3 " << endl;
			cin >> numHoratemp;

			Cine.ingresarFuncion(tempFun, numSalatemp - 1, numDiatemp - 1, numHoratemp - 1);

			cout << "<Enter para continuar>" << endl;
			cin.get();
			cin.get();
			system("cls");
			break;
		case 3:
			Cine.devolverValores();

			cout << "1- Normal" << endl;
			cout << "2- Por Genero" << endl;
			cout << "3- Por Nombre" << endl;
			cout << "4- Por Tipo de Lenguaje" << endl;
			cout << "5- Por Dimensiones" << endl;
			cout << "6- Por Tipo de Sala" << endl;
			cout << "7- Por Tipo de Publico" << endl;
			cout << "Ingrese el tipo de cartelera que quiere ver: ";
			cin >> tempNum;

			switch (tempNum) {
			case 1:
				cout << Cine.toString() << endl;
				break;
			case 2:
				cout << "Ingrese el genero que quiere buscar: ";
				cin.ignore();
				getline(cin, generotemp);
				cout << Cine.toStringGenero(generotemp);
				break;
			case 3:
				cout << "Ingrese el nombre que quiere buscar: ";
				cin.ignore();
				getline(cin, nombretemp);
				cout << Cine.toStringNombre(nombretemp);
				break;
			case 4:
				cout << "Ingrese el tipo de Lenguaje que quiere: " << endl;
				cout << "Subtitulada: s | Doblada: d" << endl;
				cin >> tipoLenguajetemp;
				cout << Cine.toStringTipoLenguaje(tipoLenguajetemp);
				break;
			case 5:
				cout << "Ingrese la dimension que quiere buscar: " << endl;
				cout << "2D: 2 | 3D: 3" << endl;
				cin >> dimensionestemp;
				cout << Cine.toStringDimensiones(dimensionestemp);
				break;
			case 6:
				cout << "Ingrese el tipo de sala que quiere buscar: " << endl;
				cout << "Regular: r | VIP: v" << endl;
				cin >> tipoSalatemp;
				cout << Cine.toStringTipoSala(tipoSalatemp);
				break;
			case 7:
				cout << "Ingrese el tipo de publico que quiere buscar: " << endl;
				cout << "Ninnos: 1 | Adultos: 0";
				cin >> tempNum2;
				paraNinnostemp = tempNum2 == 1;
				cout << Cine.toStringTipoPublico(paraNinnostemp);
				break;
			default:
				cout << "Opcion incorrecta" << endl;
				break;
			}

			if (tempNum <= 7 && tempNum >= 1) {
				cout << "Ingrese la funcion que desea ver (-1 si no quiere): ";
				cin >> tempNum2;
				if (tempNum2 >= 1 && tempNum2 <= Cine.getCantPosible()) {
					numSalatemp = Cine.getPosibleSala(tempNum2 - 1);
					numDiatemp = Cine.getPosibleDia(tempNum2 - 1);
					numHoratemp = Cine.getPosibleHora(tempNum2 - 1);
					cout << "Ingrese la cantidad de tiquetes de adulto que quiere: ";
					cin >> tiqAdutemp;
					if (Cine.getSala(numSalatemp)->getDia(numDiatemp)->getHora(numHoratemp)->getFuncion()->getPelicula()->getParaNinnos() == true) {
						cout << "Ingrese la cantidad de tiquetes de ninno que quiere: ";
						cin >> tiqNintemp;
					}
					else {
						cout << "Pelicula no es para ninnos" << endl;
						tiqNintemp = 0;
					}
					pagar = Cine.comprarTiquetes(tiqAdutemp, tiqNintemp, numSalatemp, numDiatemp, numHoratemp);
					cout << "El monto seria: $" << pagar << endl << endl;
					cout << "Desea continuar?" << endl;
					cout << "Si: 1 | No: 0" << endl;
					cin >> deseo1;
					if (deseo1 == 1) {
						totalTiqtemp = tiqAdutemp + tiqNintemp;
						cout << Cine.getSala(numSalatemp)->getDia(numDiatemp)->getHora(numHoratemp)->toStringAsientos() << endl;
						do {
							for (int i = 0; i < totalTiqtemp; i++) {
								cout << "Ingrese el Asiento que quiere (A1 - F10): (Faltan " << totalTiqtemp - (i) << ") ";
								cin >> filatemp >> columnatemp;
								Cine.comprarAsiento(numSalatemp, numDiatemp, numHoratemp, filatemp, columnatemp);
							}
							cout << "Esta seguro que quiere estos asientos?" << endl;
							cout << "Si: 1 | No: 0" << endl;
							cin >> deseo2;
							if (deseo2 != 1) {
								Cine.cancelanAsiento(numSalatemp, numDiatemp, numHoratemp);
								Cine.devolverAsientos();
							}
						} while (deseo2 != 1);
						Cine.confirmarAsiento(numSalatemp, numDiatemp, numHoratemp, cedulatemp);

						cout << Cine.toStringFuncion(numSalatemp, numDiatemp, numHoratemp);
						cout << "Asientos: " << Cine.getAsientosComprados() << endl;
						cout << "Tiene que pagar: $" << pagar << endl << endl;
						Cine.devolverAsientos();
					}
				}
			}
			cout << "Muchas gracias!!!" << endl;

			cout << "<Enter para continuar>" << endl;
			cin.get();
			cin.get();
			system("cls");
			break;
		case 4:
			cout << "Gracias por haber venido!!!" << endl;

			cout << "<Enter para continuar>" << endl;
			cin.get();
			cin.get();
			system("cls");
			break;
		default:
			cout << "Opcion incorrecta" << endl;

			cout << "<Enter para continuar>" << endl;
			cin.get();
			cin.get();
			system("cls");
			break;
		}
	} while (opcion != 4);

	system("pause");
	return 0;
}