#include"Interfaz.h"


int Interfaz::menuPrincipal() {
	        int op;
	        cout << "--------AEROLINEA-------" << endl;
			cout << "-----------MENU---------" << endl;
			cout << "     1- Mantenimiento   " << endl;
			cout << "     2- Reservaciones   " << endl;
			cout << "     3- Salir.          " << endl;
			cout << "------------------------" << endl;
			cout << "     Digite la opcion: ";
			cin >> op;
			return op;
}

int Interfaz::subMenuMantenimiento() {
	            int op;
	            cout << "           MATENIMIENTO      " << endl;
				cout << "     --------SUB-MENU--------" << endl;
				cout << "          1- Rutas           " << endl;
				cout << "          2- Personas        " << endl;
				cout << "          3- Vuelos          " << endl;
				cout << "          4- Salir           " << endl;
				cout << "     ------------------------" << endl;
				cout << "          Digite la opcion: ";
				cin >> op;
	            return op;
}

int Interfaz::subMenuReservaciones() {
	                  int op;
	                  cout << "                          RESERVACIONES                " << endl;
					  cout << "     -----------------------SUB-MENU-------------------" << endl;
					  cout << "          1- Reporte de todos los vuelos y sus codigos." << endl;
					  cout << "          2- Ingresar Reservacion con codigo de vuelo.." << endl;
					  cout << "          3- Eliminar Reservacion con codigo de vuelo.." << endl;
					  cout << "          4- Reporte de pasajeros por codigo de vuelo..." << endl;
					  cout << "          5- Salir                                     " << endl;
					  cout << "     --------------------------------------------------" << endl;
					  cout << "          Digite la opcion: ";
					  cin >> op;
	                  return op;
}

int Interfaz::subsubMenuMantenRutas() {
	int op;
	cout << "             -------RUTAS--------" << endl;
	cout << "             ----Sub-Sub-Menu----" << endl;
	cout << "               1- Ingresar Ruta  " << endl;
	cout << "               2- Eliminar Ruta  " << endl;
	cout << "               3- Listar rutas   " << endl;
	cout << "               4- Editar ruta    " << endl;
	cout << "               5- Salir          " << endl;
	cout << "             --------------------" << endl;
	cout << "               Digite opcion: " ;
	cin >> op;
	return op;
}

int Interfaz::subsubMenuMantenPersonas() {
	int op;
	cout << "             -------PERSONAS--------" << endl;
	cout << "             -------Sub-Sub-Menu----" << endl;
	cout << "               1- Ingresar Persona  " << endl;
	cout << "               2- Eliminar Persona  " << endl;
	cout << "               3- Listar Personas   " << endl;
	cout << "               4- Editar Persona    " << endl;
	cout << "               5- Salir             " << endl;
	cout << "             -----------------------" << endl;
	cout << "               Digite opcion: ";
	cin >> op;
	return op;
}

int Interfaz::subsubMenuMantenVuelos() {
	int op;
	cout << "             ---------VUELOS--------" << endl;
	cout << "             -------Sub-Sub-Menu----" << endl;
	cout << "               1- Ingresar Vuelo    " << endl;
	cout << "               2- Eliminar Vuelo    " << endl;
	cout << "               3- Listar Vuelos     " << endl;
	cout << "               4- Editar Vuelo      " << endl;
	cout << "               5- Salir             " << endl;
	cout << "             -----------------------" << endl;
	cout << "               Digite opcion: ";
	cin >> op;
	return op;
}