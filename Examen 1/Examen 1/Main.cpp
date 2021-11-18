#include <iostream>
#include <sstream>
#include <string>
#include "Contenedor.h"
using namespace std;

int main() {
	// DECLARACION DE VARIABLES
	int operacion;
	Contenedor CO(5000);

	Persona* tempPer = NULL;
	Vacuna* tempVac = NULL;

	// MENU (1,3,7)
	string tempNom, tempId;
	float tempPeso, tempEstatura;
	int tempAnnio;
	char tempGen;

	// MENU(4)
	string tempCasaCom, tempFechaV, tempFechaA;
	int tempNumDeLot, tempNumDeSer;

	do {
		cout << "     MENU PRINCIPAL     " << endl;
		cout << "1- Ingresar paciente" << endl;
		cout << "2- Mostrar todos los pacientes" << endl;
		cout << "3- Buscar paciente especifico" << endl;
		cout << "4- Vacunar paciente" << endl;
		cout << "5- Lista pacientes vacunados (por genero)" << endl;
		cout << "6- Porcentajes de vacunacion" << endl;
		cout << "7- Vacunados por casa comercial" << endl;
		cout << "8- Salir" << endl;
		cout << "------------------------" << endl;
		cout << "Ingrese el numero de la operacion que desea hacer: ";
		cin >> operacion;
		system("cls");

		switch (operacion) {
		case 1:
			cout << endl << endl << "          REGISTRO DEL PACIENTE" << endl << endl;
			
			cout << "Ingrese el nombre... ";
			cin >> tempNom;

			cout << "Ingrese el id... ";
			cin >> tempId;

			cout << "Ingrese el peso... ";
			cin >> tempPeso;

			cout << "Ingrese la estatura... ";
			cin >> tempEstatura;

			cout << "Ingrese el annio de nacimiento... ";
			cin >> tempAnnio;

			cout << "Ingrese el genero (M = mujer, H = hombre)... ";
			cin >> tempGen;

			system("cls");

			tempPer = new Persona(tempNom, tempId, tempPeso, tempEstatura, tempAnnio, tempGen);
			if (CO.ingresarPaciente(tempPer)) {
				cout << "Se ha ingresado correctamente." << endl;
			}
			else {
				cout << "Ha habido un error al ingresar." << endl;
			}
			
			cout << "<Enter para continuar>" << endl;
			cin.get();
			cin.get();
			break;
		case 2:
			cout << endl << endl << "          PACIENTES REGISTRADOS" << endl << endl;
			
			cout << CO.toString() << endl;
			
			cout << "<Enter para continuar>" << endl;
			cin.get();
			cin.get();
			break;
		case 3:
			cout << endl << endl << "          CONSULTA DE PACIENTE ESPECIFICO" << endl << endl;
			
			cout << "Ingrese la cedula de la persona que esta buscando... ";
			cin >> tempId;

			cout << CO.toStringPacienteEspecifico(tempId) << endl;

			cout << "<Enter para continuar>" << endl;
			cin.get();
			cin.get();
			break;
		case 4:
			cout << endl << endl << "          VACUNACION DEL PACIENTE" << endl << endl;
			
			cout << "     REGISTRO DE LA VACUNA    " << endl;
			cout << "Ingrese el numero de lote... ";
			cin >> tempNumDeLot;

			cout << "Ingrese el numero de serie... ";
			cin >> tempNumDeSer;

			cout << "Ingrese la casa comercial... ";
			cin >> tempCasaCom;

			cout << "Ingrese la fecha de vencimiento... ";
			cin >> tempFechaV;

			cout << "Ingrese la fecha de aplicacion... ";
			cin >> tempFechaA;

			tempVac = new Vacuna(tempNumDeLot, tempNumDeSer, tempCasaCom, tempFechaV, tempFechaA);
			
			system("cls");

			cout << "Ingrese la cedula de la persona que va a vacunar... ";
			cin >> tempId;

			if (CO.vacunarPaciente(tempId, tempVac)) {
				cout << "Se ha vacunado correctamente." << endl;
			}
			else {
				cout << "No se ha vacunado correctamente." << endl;
			}


			cout << "<Enter para continuar>" << endl;
			cin.get();
			cin.get();
			break;
		case 5:
			cout << "LISTA DE MUJERES VACUNADAS: " << endl;
			cout << CO.toStringMujeresVacunadas() << endl;
			cout << "LISTA DE HOMBRES VACUNADOS: " << endl;
			cout << CO.toStringHombresVacunados() << endl;

			cout << "<Enter para continuar>" << endl;
			cin.get();
			cin.get();
			break;
		case 6:
			cout << endl << endl << "            PORCENTAJE DE VACUNACION" << endl << endl;
			
			cout << "Porcentaje vacunado: " << CO.getPorcentajeVacunado() * 100 << "%." << endl;
			
			cout << "Porcentaje no vacunado: " << CO.getPorcentajeNoVacunado() * 100 << "%." << endl;

			cout << "<Enter para continuar>" << endl;
			cin.get();
			cin.get();
			break;
		case 7:
			cout << endl << endl << "         VACUNACION POR CASA COMERCIAL" << endl << endl;
			
			cout << "Ingrese la casa comercial que esta buscando... ";
			cin >> tempCasaCom;

			cout << CO.toSringCasaComercial(tempCasaCom) << endl;
			
			cout << "<Enter para continuar>" << endl;

			cin.get();
			cin.get();
			system("cls");
			break;
		case 8:
			break;
		default:
			cin.ignore();
			cout << "Opcion invalida vuelva a ingresar... " << endl;
			
			cout << "<Enter para continuar>" << endl;
			cin.get();
			cin.get();
			break;
		};

		system("cls");
	} while (operacion != 8);
	
	if (tempPer != NULL) delete tempPer;
	if (tempVac != NULL) delete tempVac;
	
	cout << "Muchas gracias que tenga un buen dia!!!";

	CO.~Contenedor();

	system("pause");
	return 0;
}