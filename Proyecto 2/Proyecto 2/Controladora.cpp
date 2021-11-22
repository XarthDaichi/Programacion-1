#include "Controladora.h"

Controladora::Controladora() {
	aero = new Aerolinea();
}
Controladora::~Controladora() {
	delete aero;
}

void Controladora::control_main() {
	int op = 0;
	// Creacion de Direcciones de Archivos
	string dir_ArchivoPasajero = "../Pasjeros.txt";
	string dir_ArchivoTripulacion = "../Tripulacion.txt";
	string dir_ArchivoRuta = "../Rutas.txt";
	string dir_ArchivoVuelo = "../Vuelos.txt";
	string dir_ArchivoReservacion = "../Reservaciones.txt";
	

	fstream inPasajeros(dir_ArchivoPasajero.c_str(), ios::in);
	fstream inTripulacion(dir_ArchivoTripulacion.c_str(), ios::in);
	fstream inRutas(dir_ArchivoRuta.c_str(), ios::in);
	fstream inVuelos(dir_ArchivoVuelo.c_str(), ios::in);
	fstream inReservaciones(dir_ArchivoReservacion.c_str(), ios::in);
	
	// recuperando
	cout << "---Recuperando---" << endl;
	aero->recuperarTodosContenedores(inPasajeros, inTripulacion, inRutas, inVuelos, inReservaciones);
	
	// Cerrando los documentos
	inPasajeros.close();
	inTripulacion.close();
	inRutas.close();
	inVuelos.close();
	inReservaciones.close();

	do {
		op = Interfaz::menuPrincipal();
		switch (op) {
		case 1:
			control_1();
			break;
		case 2:
			control_2();
			break;
		case 3:
			cout << "Gracias por haber venido" << endl;
			break;
		default:
			cout << "Error: Numero incorrecto" << endl;
			break;
		}
	} while (op != 3);
	
	
	



	// Creacion de Archivos de salida
	ofstream outPasajeros(dir_ArchivoPasajero.c_str(), ios::trunc);
	ofstream outTripulacion(dir_ArchivoTripulacion.c_str(), ios::trunc);
	ofstream outRutas(dir_ArchivoRuta.c_str(), ios::trunc);
	ofstream outVuelos(dir_ArchivoVuelo.c_str(), ios::trunc);
	ofstream outReservaciones(dir_ArchivoReservacion.c_str(), ios::trunc);
	
	// grabarndo registros en los archivos respectivos
	cout << "---Guardadndo---" << endl;
	aero->getContPasajero()->grabar(outPasajeros);
	aero->getContTripulacion()->grabar(outTripulacion);
	aero->getContRuta()->grabar(outRutas);
	aero->getContVuelo()->grabar(outVuelos);
	aero->getContReservacion()->grabar(outVuelos);
	
	// Cerrando los archivos
	outPasajeros.close();
	outTripulacion.close();
	outRutas.close();
	outVuelos.close();
	outReservaciones.close();
}

void Controladora::control_1() {
	int op1 = Interfaz::subMenuMantenimiento();
	switch (op1) {
	case 1:
		control_1_1();
		break;
	case 2:
		control_1_2();
		break;
	case 3:
		control_1_3();
		break;
	case 4:
		control_1_4();
		break;
	case 5:
		cout << "---Volviendo---" << endl;
		break;
	default:
		cout << "No es una opcion" << endl;
		break;
	}
	system("pause");
}

// Mantenimiento Personas
void Controladora::control_1_1(){
	int op2 = Interfaz::subsubMenuMantenPersonas();
	switch (op2) {
	case 1: 
		control_1_1_1();
		break;
	case 2:
		control_1_1_2();
		break;
	case 3:
		cout << "---Volviendo---" << endl;
		break;
	default:
		cout << "No es una opcion" << endl;
		break;
	}
	system("pause");
}
void Controladora::control_1_1_1(){
	int op3 = Interfaz::subsubsubMenuMantenPasajeros();
	switch (op3) {
	case 1:
		control_1_1_1_1();
		break;
	case 2:
		control_1_1_1_2();
		break;
	case 3:
		control_1_1_1_3();
		break;
	case 4:
		control_1_1_1_4();
		break;
	case 5:
		cout << "---Volviendo---" << endl;
		break;
	default:
		cout << "Esa no es una opcion" << endl;
		break;
	}
	system("pause");
}
// Mantenimiento Pasajeros
void Controladora::control_1_1_1_1(){
	string cedula, nombre, codigo_temp;
	int edad;
	stringstream codigo;
	codigo << "PA";
	cout << "Ingrese el numero de cedula: ";
	cin >> cedula;
	cout << "Ingrese el nombre: ";
	cin.ignore();
	getline(cin, nombre);

	cout << "Ingrese la edad: ";
	cin >> edad;
	cout << "Ingrese el numero de codigo que le quiere asignar al pasajero: ";
	cin >> codigo_temp;
	codigo << codigo_temp;
	Pasajero* temp = new Pasajero(cedula, nombre, edad, codigo.str());
	aero->ingresarPasajero(temp);
}

void Controladora::control_1_1_1_2() { cout << aero->toStringContPasajeros() << endl; }

void Controladora::control_1_1_1_3(){
	int op3 = Interfaz::subsubsubsubMenuModifiPasajeros();
	switch (op3) {
	case 1:
		control_1_1_1_3_1();
		break;
	case 2:
		control_1_1_1_3_2();
		break;
	case 3:
		control_1_1_1_3_3();
		break;
	case 4:
		control_1_1_1_3_4();
		break;
	case 5:
		cout << "---Volviendo---" << endl;
		break;
	default:
		cout << "No es una opcion" << endl;
		break;
	}
	system("pause");
}
// Modificacion Pasajeros
void Controladora::control_1_1_1_3_1() { 
	string codigo, cedula;
	cout << "Ingrese el codigo del pasajero que le quiere cambiar la cedula: ";
	cin >> codigo;
	cout << "Ingrese la nueva cedula: ";
	cin >> cedula;
	aero->cambiarCedulaPasajero(codigo, cedula);
}
void Controladora::control_1_1_1_3_2() {
	string codigo, nombre;
	cout << "Ingrese el codigo del pasajero que le quiere cambiar el nombre: ";
	cin >> codigo;
	cout << "Ingrese el nuevo nombre: ";
	cin >> nombre;
	aero->cambiarNombrePasajero(codigo, nombre);
}
void Controladora::control_1_1_1_3_3(){
	string codigo;
	int edad;
	cout << "Ingrese el codigo del pasajero que le quiere cambiar la edad: ";
	cin >> codigo;
	cout << "Ingrese la nueva edad: ";
	cin >> edad;
	aero->cambiarEdadPasajero(codigo, edad);
}
void Controladora::control_1_1_1_3_4(){
	string codigoViejo, codigoNuevo;
	cout << "Ingrese el codigo del pasajero que le quiere cambiar el codigo: ";
	cin >> codigoViejo;
	cout << "Ingrese el nuevo codigo: ";
	cin >> codigoNuevo;
	aero->cambiarCedulaPasajero(codigoViejo, codigoNuevo);
}
void Controladora::control_1_1_1_4(){
	string codigo;
	cout << "Ingrese el codigo del pasajero que quiere eliminar" << endl;
	cin.ignore();
	getline(cin, codigo);
	aero->eliminarPasajero(codigo);
}

void Controladora::control_1_1_2(){
	int(op3) = Interfaz::subsubsubMenuMantenTripulacion();
	switch (op3) {
	case 1:
		control_1_1_2_1();
		break;
	case 2:
		control_1_1_2_2();
		break;
	case 3:
		control_1_1_2_3();
		break;
	case 4:
		control_1_1_2_4();
		break;
	case 5:
		cout << "---Volviendo---" << endl;
		break;
	default:
		cout << "No es una opcion" << endl;
		break;
	}
	system("pause");
}
// Mantenimiento Tripulacion
void Controladora::control_1_1_2_1(){
	int op4;
	stringstream codigo;
	string cedula, nombre, codigo_temp, correo, titulo, telCelular, grado;
	int edad;
	char sexo;
	Piloto* tempPil;
	Sobrecargo* tempSob;

	cout << "1. Ingresar Piloto" << endl;
	cout << "2. Ingresar Sobrecargo" << endl;
	cout << "Elija el que quiere ingresar: " << endl;
	cin >> op4;
	switch (op4) {
	case 1:
		codigo << "PI";
		cout << "Ingrese la cedula: ";
		cin >> cedula;

		cout << "Ingrese el nombre: ";
		cin.ignore();
		getline(cin, nombre);

		cout << "Ingrese la edad: ";
		cin >> edad;
		
		cout << "Ingrese el codigo: ";
		cin >> codigo_temp;
		codigo << codigo_temp;

		cout << "Ingrese el correo: ";
		cin >> correo;

		cout << "Ingrese el sexo: (H: Hombre | M: Mujer)";
		cin >> sexo;

		tempPil = new Piloto(cedula, nombre, edad, codigo.str(), correo, sexo);
		aero->ingresarPiloto(tempPil);
		break;
	case 2:
		codigo << "SO" << endl;
		cout << "Ingrese la cedula: ";
		cin >> cedula;

		cout << "Ingrese el nombre: ";
		cin.ignore();
		getline(cin, nombre);

		cout << "Ingrese la edad: ";
		cin >> edad;

		cout << "Ingrese el codigo: ";
		cin >> codigo_temp;
		codigo << codigo_temp;

		cout << "Ingrese el titulo: ";
		cin >> titulo;

		cout << "Ingrese el telCelular: ";
		cin >> telCelular;

		cout << "Ingrese el grado: ";
		cin >> grado;

		tempSob = new Sobrecargo(cedula, nombre, edad, codigo.str(), titulo, telCelular, grado);
		aero->ingresarSobrecargo(tempSob);
		break;
	default:
		cout << "No es una opcion" << endl;
		break;
	}
}

void Controladora::control_1_1_2_2() { cout << aero->toStringContTripulacion() << endl; }

void Controladora::control_1_1_2_3(){
	int op3 = Interfaz::subsubsubsubMenuModifiTripulacion();
	switch (op3) {
	case 1:
		control_1_1_2_3_1();
		break;
	case 2:
		control_1_1_2_3_2();
		break;
	case 3:
		control_1_1_2_3_3();
		break;
	case 4:
		control_1_1_2_3_4();
		break;
	case 5:
		control_1_1_2_3_5();
		break;
	case 6:
		control_1_1_2_3_6();
		break;
	case 7:
		control_1_1_2_3_7();
		break;
	case 8:
		control_1_1_2_3_8();
		break;
	case 9:
		control_1_1_2_3_9();
		break;
	case 10:
		cout << "---Volviendo---" << endl;
		break;
	default:
		cout << "No es una opcion" << endl;
		break;
	}
}
// Modificacion Tripulacion
void Controladora::control_1_1_2_3_1(){
	string codigo, cedula;
	cout << "Ingrese el codigo del tripulante que le quiere cambiar la cedula: (incluir el PI o SO) ";
	cin >> codigo;
	cout << "Ingrese la nueva cedula: ";
	cin >> cedula;
	aero->cambiarCedulaTripulante(codigo, cedula);
}
void Controladora::control_1_1_2_3_2(){
	string codigo, nombre;
	cout << "Ingrese el codigo del tripulante que le quiere cambiar el nombre: (incluir el PI o SO) ";
	cin >> codigo;
	cout << "Ingrese el nuevo nombre: ";
	cin >> nombre;
	aero->cambiarCedulaTripulante(codigo, nombre);
}
void Controladora::control_1_1_2_3_3(){
	string codigo;
	int edad;
	cout << "Ingrese el codigo del tripulante que le quiere cambiar la edad: (incluir el PI o SO) ";
	cin >> codigo;
	cout << "Ingrese la nueva edad: ";
	cin >> edad;
	aero->cambiarEdadTripulante(codigo, edad);
}
void Controladora::control_1_1_2_3_4(){
	string codigoViejo, codigoNuevo;
	cout << "Ingrese el codigo del tripulante que le quiere cambiar el codigo: (incluir el PI o SO)";
	cin >> codigoViejo;
	cout << "Ingrese el nuevo codigo: (que traiga PI para piloto o SO para sobrecargo al principio) ";
	cin >> codigoNuevo;
	aero->cambiarCedulaTripulante(codigoViejo, codigoNuevo);
}
void Controladora::control_1_1_2_3_5(){
	string codigo, correo;
	cout << "Ingrese el codigo del piloto que le quiere cambiar el correo: (incluir el PI o SO)";
	cin >> codigo;
	cout << "Ingrese el nuev correo: ";
	cin >> correo;
	aero->cambiarCorreoPiloto(codigo, correo);
}
void Controladora::control_1_1_2_3_6(){
	string codigo;
	char sexo;
	cout << "Ingrese el codigo del piloto que le quiere cambiar el sexo: (incluir el PI o SO)";
	cin >> codigo;
	cout << "Ingrese el nuevo sexo: (H:Hombre | M:Mujer) ";
	cin >> sexo;
	aero->cambiarSexoPiloto(codigo, sexo);
}
void Controladora::control_1_1_2_3_7(){
	string codigo, titulo;
	cout << "Ingrese el codigo del sobrecargo que le quiere cambiar el titulo: (incluir el PI o SO)";
	cin >> codigo;
	cout << "Ingrese el nuevo titulo: ";
	cin >> titulo;
	aero->cambiarTituloSobrecargo(codigo, titulo);
}
void Controladora::control_1_1_2_3_8(){
	string codigo, telCelular;
	cout << "Ingrese el codigo del tripulante que le quiere cambiar el telefono celular: (incluir el PI o SO)";
	cin >> codigo;
	cout << "Ingrese el nuevo telefono celular: ";
	cin >> telCelular;
	aero->cambiarTelCelularSobrecargo(codigo, telCelular);
}
void Controladora::control_1_1_2_3_9(){
	string codigo, grado;
	cout << "Ingrese el codigo del tripulante que le quiere cambiar el grado: (incluir el PI o SO)";
	cin >> codigo;
	cout << "Ingrese el nuevo grado: ";
	cin >> grado;
	aero->cambiarTituloSobrecargo(codigo, grado);
}

void Controladora::control_1_1_2_4(){
	string codigo;
	cout << "Ingrese el codigo del tripulante que quiere elminiar: (incluir el PI o SO)";
	cin.ignore();
	getline(cin, codigo);
	aero->eliminarTripulacion(codigo);
}


void Controladora::control_1_2(){
	cout << aero->toStringFlota() << endl;
}


void Controladora::control_1_3(){
	int op2 = Interfaz::subsubMenuMantenRutas();
	switch (op2) {
	case 1:
		control_1_3_1();
		break;
	case 2:
		control_1_3_2();
		break;
	case 3:
		control_1_3_3();
		break;
	case 4:
		control_1_3_4();
		break;
	case 5:
		cout << "---Volviendo---" << endl;
		break;
	default:
		cout << "No es una opcion" << endl;
		break;
	}
}
// Mantenimiento Rutas
void Controladora::control_1_3_1() { 
	string origen, destino, duracion, codigo_temp;
	stringstream codigo;
	codigo << "RU";
	int cantidadDeEscalas;
	double valorPasajeros;

	cout << "Ingrese el origen: ";
	cin.ignore();
	getline(cin, origen);

	cout << "Ingrese el destino: ";
	cin.ignore();
	getline(cin, destino);

	cout << "Ingrese la duracion: ";
	cin.ignore();
	getline(cin, duracion);

	cout << "Ingrese la cantidad de escalas: ";
	cin.ignore();
	cin >> cantidadDeEscalas;

	cout << "Ingrese el valor de pasajeros: ";
	cin >> valorPasajeros;

	cout << "Ingrese el codigo: ";
	cin >> codigo_temp;
	codigo << codigo_temp;
	Ruta* temp = new Ruta(origen, destino, duracion, cantidadDeEscalas, valorPasajeros, codigo.str(), true);
	aero->ingresarRuta(temp); 
}
void Controladora::control_1_3_2(){ 
	cout << aero->toStringContRuta() << endl;
}
void Controladora::control_1_3_3(){
	int op3 = Interfaz::subsubsubMenuModifiRutas();
	switch (op3) {
	case 1:
		control_1_3_3_1();
		break;
	case 2:
		control_1_3_3_2();
		break;
	case 3:
		control_1_3_3_3();
		break;
	case 4:
		control_1_3_3_4();
		break;
	case 5:
		control_1_3_3_5();
		break;
	case 6:
		control_1_3_3_6();
		break;
	case 7:
		control_1_3_3_7();
		break;
	case 8:
		cout << "---Volviendo---" << endl;
		break;
	default:
		cout << "No es una opcion" << endl;
		break;
	}
}
// Modificacion Rutas
void Controladora::control_1_3_3_1(){
	string codigo, origen;
	cout << "Ingrese el codigo de la Ruta: ";
	cin >> codigo;
	cout << "Ingrese el origen: ";
	cin.ignore();
	getline(cin, origen);
	aero->cambiarOrigen(codigo, origen);
}
void Controladora::control_1_3_3_2(){
	string codigo, destino;
	cout << "Ingrese el codigo de la Ruta: ";
	cin >> codigo;
	cout << "Ingrese el destino: ";
	cin.ignore();
	getline(cin, destino);
	aero->cambiarDestino(codigo, destino);
}
void Controladora::control_1_3_3_3(){
	string codigo, duracion;
	cout << "Ingrese el codigo de la Ruta: ";
	cin >> codigo;
	cout << "Ingrese la duracion: ";
	cin.ignore();
	getline(cin, duracion);
	aero->cambiarDuracion(codigo, duracion);
}
void Controladora::control_1_3_3_4(){
	string codigo;
	int cantidadDeEscalas;
	cout << "Ingrese el codigo de la Ruta: ";
	cin >> codigo;
	cout << "Ingrese la cantidad de escalas: ";
	cin >> cantidadDeEscalas;
	aero->cambiarCantidadDeEscalas(codigo, cantidadDeEscalas);
}
void Controladora::control_1_3_3_5(){
	string codigo;
	double valorPasajeros;
	cout << "Ingrese el codigo de la Ruta: ";
	cin >> codigo;
	cout << "Ingrese el valor del pasajero: ";
	cin >> valorPasajeros;
	aero->cambiarValorPasajeros(codigo, valorPasajeros);
}
void Controladora::control_1_3_3_6(){
	string codigoViejo, codigoNuevo;
	cout << "Ingrese el codigo de la Ruta: ";
	cin >> codigoViejo;
	cout << "Ingrese nuevo codigo: ";
	cin >> codigoNuevo;
	aero->cambiarCodigoRuta(codigoViejo, codigoNuevo);
}
void Controladora::control_1_3_3_7(){
	string codigo;
	int deseo;
	cout << "Ingrese el codigo de la Ruta: ";
	cin >> codigo;
	cout << "Ingrese si quiere que la ruta este en uso o no: (1:Si | 0: NO)";
	cin >> deseo;
	aero->cambiarUsoRuta(codigo, deseo == 1);
}

void Controladora::control_1_3_4(){
	string codigo;
	cout << "Ingrese el codigo de la Ruta que quiere eliminar: ";
	cin.ignore();
	getline(cin, codigo);
	aero->eliminarRuta(codigo);
}

void Controladora::control_1_4(){
	int op2 = Interfaz::subsubMenuMantenVuelos();
	switch (op2) {
	case 1:
		control_1_4_1();
		break;
	case 2:
		control_1_4_2();
		break;
	case 3:
		control_1_4_3();
		break;
	case 4:
		control_1_4_4();
		break;
	case 5:
		cout << "No es una opcion" << endl;
		break;
	default:
		cout << "No es una opcion" << endl;
		break;
	}
}
// Mantenimiento Vuelos
void Controladora::control_1_4_1(){
	string categoria, codigoPiloto, codigoSob1, codigoSob2, codigoSob3, codigoRuta, aeropuertoSalida, aeropuertoLlegada, codigo_temp;
	stringstream codigo;
	codigo << "VU";
	int dia, mes, annio, hoSa, minSa, hoLl, minLl;

	cout << "Ingrese la categoria del avion: ";
	cin >> categoria;
	cout << "Ingrese el codigo del Piloto que quiere: ";
	cin >> codigoPiloto;
	cout << "Ingrese el codigo del sobrecargo 1: ";
	cin >> codigoSob1;
	cout << "Ingrese el codigo del sobrecargo 2: ";
	cin >> codigoSob2;
	cout << "Ingrese el codigo del sobrecargo 3: ";
	cin >> codigoSob3;
	cout << "Ingrese el codigo de Ruta: ";
	cin >> codigoRuta;
	cout << "Ingrese el aeropuerto de salida: ";
	cin >> aeropuertoSalida;
	cout << "Ingrese el aeropuerto de llegada: ";
	cin >> aeropuertoLlegada;
	cout << "Ingrese el dia de salida: ";
	cin >> dia;
	cout << "Ingrese el mes de salida: ";
	cin >> mes;
	cout << "Ingrese el annio de salida: ";
	cin >> annio;
	cout << "Ingrese la hora de salida: ";
	cin >> hoSa;
	cout << "Ingrese el  minuto de salida: ";
	cin >> minSa;
	cout << "Ingrese la hora de llegada: ";
	cin >> hoLl;
	cout << "Ingrese el minuto de llegada: ";
	cin >> minLl;
	cout << "Ingrese el codigo de vuelo: ";
	cin >> codigo_temp;
	codigo << codigo_temp;
	Fecha* tempFe = new Fecha(dia, mes, annio);
	Hora* tempHo1 = new Hora(hoSa, minSa);
	Hora* tempHo2 = new Hora(hoLl, minLl);
	Avion* tempAv = new Avion(categoria, codigoPiloto, codigoSob1, codigoSob2, codigoSob3);
	Vuelo* temp = new Vuelo(aeropuertoSalida, aeropuertoLlegada, tempAv, codigoRuta, tempFe, tempHo1, tempHo2, codigo.str(), true);
	aero->ingresarVuelo(temp);

}
void Controladora::control_1_4_2() { cout << aero->toStringContVuelo() << endl; }
void Controladora::control_1_4_3() {
	int op3 = Interfaz::subsubsubMenuModifiVuelos();
	switch (op3) {
	case 1:
		control_1_4_3_1();
		break;
	case 2:
		control_1_4_3_2();
		break;
	case 3:
		control_1_4_3_3();
		break;
	case 4:
		control_1_4_3_4();
		break;
	case 5:
		control_1_4_3_5();
		break;
	case 6:
		control_1_4_3_6();
		break;
	case 7:
		control_1_4_3_7();
		break;
	case 8:
		control_1_4_3_8();
		break;
	case 9:
		control_1_4_3_9();
		break;
	case 10:
		control_1_4_3_10();
		break;
	case 11:
		control_1_4_3_11();
		break;
	case 12:
		
		break;
	default:
		break;
	}
}
// Modificacion Vuelos{}
void Controladora::control_1_4_3_1() {
	string codigo, categoria, codigoPiloto, codigoSob1, codigoSob2, codigoSob3;

	cout << "Ingrese el codigo de la Vuelo: ";
	cin >> codigo;
	cout << "Ingrese la categoria del avion: ";
	cin >> categoria;
	cout << "Ingrese el codigo del piloto: ";
	cin >> codigoPiloto;
	cout << "Ingrese el codigo del sobrecargo 1: ";
	cin >> codigoSob1;
	cout << "Ingrese el codigo del sobrecargo 2: ";
	cin >> codigoSob2;
	cout << "Ingrese el codigo del sobrecargo 3: ";
	cin >> codigoSob3;
	Avion* avion = new Avion(categoria, codigoPiloto, codigoSob1, codigoSob2, codigoSob3);
	aero->cambiarAvionVuelo(codigo, avion);
}
void Controladora::control_1_4_3_2() {
	string codigo, codigoPiloto;
	cout << "Ingrese el codigo del vuelo: ";
	cin >> codigo;
	cout << "Ingrese el codigo de Piloto: ";
	cin >> codigoPiloto;
	aero->cambiarPilotoVuelo(codigo, codigoPiloto);
}
void Controladora::control_1_4_3_3() {
	string codigo, codigoSob;
	int pos;
	cout << "Ingrese el codigo del vuelo: ";
	cin >> codigo;
	cout << "Ingrese el codigo de Sobrecargo: ";
	cin >> codigoSob;
	cout << "Ingrese el numero de sobrecargo: (0-2) ";
	cin >> pos;
	aero->cambiarSobrecargoVuelo(codigo, pos, codigoSob);
}
void Controladora::control_1_4_3_4() {
	string codigo, codigoRuta;
	cout << "Ingrese el codigo del vuelo: ";
	cin >> codigo;
	cout << "Ingrese el codigo de Ruta: ";
	cin >> codigoRuta;
	aero->cambiarPilotoVuelo(codigo, codigoRuta);
}
void Controladora::control_1_4_3_5() {
	string codigo, aeSa;
	cout << "Ingrese el codigo del vuelo: ";
	cin >> codigo;
	cout << "Ingrese el Aeropuerto de Salida: ";
	cin >> aeSa;
	aero->cambiarAeropuertoSalida(codigo, aeSa);
}
void Controladora::control_1_4_3_6() {
	string codigo, aeLl;
	cout << "Ingrese el codigo del vuelo: ";
	cin >> codigo;
	cout << "Ingrese el aeropuertodeLlegada: ";
	cin >> aeLl;
	aero->cambiarAeropuertoLlegada(codigo, aeLl);
}
void Controladora::control_1_4_3_7() {
	string codigo;
	int dia, mes, annio;
	cout << "Ingrese el codigo del vuelo: ";
	cin >> codigo;
	cout << "Ingrese el dia: ";
	cin >> dia;
	cout << "Ingrese el mes: ";
	cin >> mes;
	cout << "Ingrese el annio: ";
	cin >> annio;
	Fecha* temp = new Fecha(dia, mes, annio);
	aero->cambiarFechaSalida(codigo, temp);
}
void Controladora::control_1_4_3_8() {
	string codigo;
	int hora, min;
	cout << "Ingrese el codigo del vuelo: ";
	cin >> codigo;
	cout << "Ingrese la hora: ";
	cin >> hora;
	cout << "Ingrese el minuto: ";
	cin >> min;
	Hora* temp = new Hora(hora, min);
	aero->cambiarHoraSalida(codigo, temp);
}
void Controladora::control_1_4_3_9() {
	string codigo;
	int hora, min;
	cout << "Ingrese el codigo del vuelo: ";
	cin >> codigo;
	cout << "Ingrese la hora: ";
	cin >> hora;
	cout << "Ingrese el minuto: ";
	cin >> min;
	Hora* temp = new Hora(hora, min);
	aero->cambiarHoraLlegada(codigo, temp);
}
void Controladora::control_1_4_3_10() {
	string codigoViejo, codigoNuevo;
	cout << "Ingrese el codigo del vuelo: ";
	cin >> codigoViejo;
	cout << "Ingrese el nuevo codigo: ";
	cin >> codigoNuevo;
	aero->cambiarCodigoVuelo(codigoViejo, codigoNuevo);
}
void Controladora::control_1_4_3_11() {
	string codigo;
	int deseo;
	cout << "Ingrese el codigo del vuelo: ";
	cin >> codigo;
	cout << "Ingrese si quiere que este en uso el vuelo: (Si: 1 | No: 0 ";
	cin >> deseo;
	aero->cambiarUsoVuelo(codigo, deseo == 1);
}

void Controladora::control_1_4_4(){
	string codigo;
	cout << "Ingrese el codigo del Vuelo que quiere eliminar" << endl;
	cin >> codigo;
	aero->eliminarVuelo(codigo);
}

void Controladora::control_2() {
	int op2 = Interfaz::subMenuReservaciones();
	switch (op2) {
	case 1:
		control_2_1();
		break;
	case 2:
		control_2_2();
		break;
	case 3:
		control_2_3();
		break;
	case 4:
		control_2_4();
	case 5:
		cout << "--- Volviendo ---" << endl;
		break;
	default:
		break;
	}
}

void Controladora::control_2_1() {
	cout << aero->toStringContVuelo() << endl;
}
void Controladora::control_2_2() {
	cout << aero->toStringContReservacion() << endl;
}
void Controladora::control_2_3() {
	string codigo_temp, codigoVuelo, codigoPasajero;
	stringstream codigo;
	codigo << "RE";
	int cant;

	cout << "Ingrese el codigo de la reservacion: ";
	cin >> codigo_temp;
	codigo << codigo_temp;

	cout << "Ingrese el codigo del vuelo de la reservacion: ";
	cin >> codigoVuelo;

	cout << "Ingrese el codigo del pasajero de la reservacion: ";
	cin >> codigoPasajero;

	cout << "Ingrese la cantidad de tiquetes que va a comprar: ";
	cin >> cant;

	Reservacion* temp = new Reservacion(codigo.str(), codigoVuelo, codigoPasajero, cant, true);
	aero->ingresarReservacion(temp);
	
}
void Controladora::control_2_4() {
	string codigo;
	cout << "Ingrese el codigo de la reservacion de quiere eliminar" << endl;
	cin.ignore();
	getline(cin, codigo);
	aero->eliminarReservacion(codigo);
}

