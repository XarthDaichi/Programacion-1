#include "Interfaz.h"

int Interfaz::menuPrincipal() {
	system("cls");
	int opcion;
	cout << " -----MENU PRINCIPAL-----" << endl
		<< " 1.    Mantenimiento     " << endl
		<< " 2.    Reservaciones     " << endl
		<< " 3.       Salida         " << endl
		<< " Elija la opcion que quiere: ";
	cin >> opcion;
	return opcion;
}
int Interfaz::subMenuMantenimiento() {
	system("cls");
	int opcion;
	cout << "------- SUB-MENU MANTENIMIENTO -------" << endl
		<< "1.     Mantenimiento de Personas      " << endl
		<< "2.       Revision de la Flota         " << endl
		<< "3.     Mantenimineto de las Rutas     " << endl
		<< "4.     Mantenimiento de los Vuelos    " << endl
		<< "5.      Volver a Menu Principal       " << endl
		<< " Elija la opcion que quiere: ";
	cin >> opcion;
	return opcion;
}
int Interfaz::subMenuReservaciones() {
	system("cls");
	int opcion;
	cout << "--- SUB-MENU RESERVACIONES ---" << endl
		<< "1.     Imprimir Vuelos" << endl
		<< "2.      Reservaciones" << endl
		<< "3.  Ingrese una Reservacion" << endl
		<< "4.  Eliminar una Reservacion" << endl
		<< "5.    Volver al Menu Princpial" << endl
		<< "Elija la opcion que quiera: ";
	cin >> opcion;
	return opcion;
}
int Interfaz::subsubMenuMantenRutas() {
	system("cls");
	int opcion;
	cout << "--- SUB-SUB-MENU MANTENIMIENTO DE RUTAS ---" << endl
		<< "1.          Ingresar Nueva Ruta" << endl
		<< "2.             Imprimir Rutas" << endl
		<< "3.             Modificar Rutas" << endl
		<< "4.              Eliminar Ruta" << endl
		<< "5.         Volver al Menu Principal" << endl
		<< "Elija la opcion que quiere: ";
	cin >> opcion;
	return opcion;
}

int Interfaz::subsubsubMenuModifiRutas() {
	system("cls");
	int opcion;
	cout << "--- SUB-SUB-SUB-MENU MODIFICACION DE RUTAS ---" << endl
		<< "1.             Cambiar Origen" << endl
		<< "2.             Cambiar Destino" << endl
		<< "3.             Cambiar Duracion" << endl
		<< "4.           Cambiar Cantidad De Escalas" << endl
		<< "5.           Cambiar Valor de Pasajeros" << endl
		<< "6.             Cambiar Codigo" << endl
		<< "7.              Cambiar Uso" << endl
		<< "8.           Volver al Menu Principal" << endl
		<< "Elija la opcion que quiere: ";
	cin >> opcion;
	return opcion;
}

int Interfaz::subsubMenuMantenPersonas() {
	system("cls");
	int opcion;
	cout << "--- SUB-SUB-MENU MANTENIMIENTO DE PERSONAS ---" << endl
		<< "1.	    Mantenimiento de la Pasajeros       " << endl
		<< "2.     Mantenimiento de los Tipulacion         " << endl
		<< "3.        Volver al Menu Principal            " << endl
		<< "Elija la opcion que quiere: ";
	cin >> opcion;
	return opcion;
}

int Interfaz::subsubsubMenuMantenPasajeros() {
	int opcion;
	cout << "--- SUB-SUB-SUB-MENU MANTENIMIENTO DE PASAJEROS ---" << endl
		<< "1.              Ingresar Nuevo Pasajero" << endl
		<< "2.                 Imprimir Pasajeros" << endl
		<< "3.                 Modificar Pasajeros" << endl
		<< "4.                  Eliminar Pasajero" << endl
		<< "5.              Volver al Menu Principal" << endl
		<< "Elija la opcion que quiere : ";
	cin >> opcion;
	return opcion;

}

int Interfaz::subsubsubsubMenuModifiPasajeros() {
	int opcion;
	cout << "--- SUB-SUB-SUB-SUB-MENU MODIFICACION DE PASAJEROS ---" << endl
		<< "1.                 Cambiar Cedula" << endl
		<< "2.                 Cambiar Nombre" << endl
		<< "3.                 Cambiar Edad" << endl
		<< "4.                 Cambiar Codigo" << endl
		<< "5.            Volver al Menu Principal" << endl
		<< "Elija la opcion que quiere : ";
	cin >> opcion;
	return opcion;
}

int Interfaz::subsubsubMenuMantenTripulacion() {
	int opcion;
	cout << "--- SUB-SUB-SUB-MENU MANTENIMIENTO DE TRIPULACION ---" << endl
		<< "1.             Ingresar Nuevo Tripulante" << endl
		<< "2.                Imprimir Tripulacion" << endl
		<< "3.                Modificar Tripulantes" << endl
		<< "4.                 Eliminar Tripulante" << endl
		<< "5.               Volver al Menu Principal" << endl
		<< "Elija la opcion que quiere : ";
	cin >> opcion;
	return opcion;
}

int Interfaz::subsubsubsubMenuModifiTripulacion() {
	int opcion;
	cout << "--- SUB-SUB-SUB-SUB-MENU MODIFICACION DE TRIPULACION ---" << endl
		<< "1.                 Cambiar Cedula" << endl
		<< "2.                 Cambiar Nombre" << endl
		<< "3.                 Cambiar Edad" << endl
		<< "4.                 Cambiar Codigo" << endl
		<< "5.              Cambiar Correo Piloto" << endl
		<< "6.               Cambiar Sexo Piloto" << endl
		<< "7.            Cambiar Titulo Sobrecargo" << endl
		<< "8.       Cambiar Telefono Celular Sobrecargo" << endl
		<< "9.             Cambiar Grado Sobrecargo" << endl
		<< "10.            Volver al Menu Principal" << endl
		<< "Elija la opcion que quiere : ";
	cin >> opcion;
	return opcion;
}

int Interfaz::subsubMenuMantenVuelos() {
	int opcion;
	cout << "--- SUB-SUB-MENU MANTENIMIENTO DE VUELOS ---" << endl
		<< "1.          Ingresar Nuevo Vuelo" << endl
		<< "2.             Imprimir Vuelos" << endl
		<< "3.             Modificar Vuelos" << endl
		<< "4.              Eliminar Vuelos" << endl
		<< "5.         Volver al Menu Principal" << endl
		<< "Elija la opcion que quiere: ";
	cin >> opcion;
	return opcion;
}

int Interfaz::subsubsubMenuModifiVuelos() {
	int opcion;
	cout << "--- SUB-SUB-SUB-MENU MODIFICACION DE VUELOS ---" << endl
		<< "1.              Cambiar Avion" << endl
		<< "2.              Cambiar Piloto" << endl
		<< "3.            Cambiar Sobrecargo" << endl
		<< "4.               Cambiar Ruta" << endl
		<< "5.        Cambiar Aeropuerto de Salida" << endl
		<< "6.        Cambiar Aeropuerto de Llegada" << endl
		<< "7.            Cambiar Fecha Salida" << endl
		<< "8.            Cambiar Hora Salida" << endl
		<< "9.            Cambiar Hora Llegada" << endl
		<< "10.           Cambiar Codigo Vuelo" << endl
		<< "11.            Cambiar Uso Vuelo" << endl
		<< "12.          Volver al Menu Principal" << endl
		<< "Elija la opcion que quiere: ";
	cin >> opcion;
	return opcion;
}