#include"Interfaz.h"

int Interfaz::menu() {
	int op;
	system("cls");
	cout << "-------------------------------------------------- MENU-------------------------------------------------------" << endl;
	cout << " 1 - Crear e ingresar Departamento con su respectivo codigo." << endl;
	cout << " 2 - Ingresar un empleado cajero en un determinado departamento." << endl;
	cout << " 3 - Ingresar un empleado vendedor en un determinado departamento." << endl;
	cout << " 4 - Ingresar un empleado supervisor en un determinado departamento." << endl;
	cout << " 5 - Opcion para recalificar el empleado por su ID. " << endl;
	cout << " 6 - Reportar cada empleado que tiene la tienda y la cantidad total de ellos." << endl;
	cout << " 7 - Reportar ID, nombre y salario de todos los cajeros de la tienda." << endl;
	cout << " 8 - Reportar cada empleado y el salario total de los empleados de un determinado departamento." << endl;
	cout << " 9 - Reportar los empleados que ingresaron el mismo dia a la tienda." << endl;
	cout << "10 - Reportar los empleados que ingresaron el mismo dia en un determinado departo." << endl;
	cout << "11 - Reportar los empleados y la suma del salario total de todos ellos. " << endl;
	cout << "12 - Reportar los empleados, que son cajeros de una determinada categoria. " << endl;
	cout << "13 - Reportar los empleados de la tienda que son supervisores y que ingresaron juntos en una fecha determinada." << endl;
	cout << "14 - Reportar el empleado que tiene el mayor salario de toda la tienda." << endl;
	cout << "15 - Salir." << endl;
	cout << "-------------------------------------------------------------------------------------------------------------" << endl;
	cout << "  Digitar la opcion: ";
	cin >> op;
	return op;
}

Empleado* Interfaz::creaEmpleado(int op) {
	int id, horasTrabajadas;
	string nombre;
	double cuota, porcentajeComision, porcentajeRecargo, salarioXhora, totalVenta;
	Fecha* fe = NULL;
	Empleado* emp = NULL;
	/*cout << "--CREACION DE UN EMPLEADO--" << endl;
	cout << "-- 1 --> Empleado"   << endl;
	cout << "-- 2 --> Cajero"     << endl;
	cout << "-- 3 --> Vendedor"   << endl;
	cout << "-- 4 --> Supervisor" << endl;
	cout << "Digite la opcion: ";
	cin >> op;*/
	switch (op) {
	case 1:
		cout << "Ingrese el id: ";
		cin >> id;
		cout << "Ingrese el nombre: ";
		cin.ignore();
		getline(cin, nombre);

		fe = creaFecha();
		emp = new Empleado(id, nombre, "002", fe);
		break;
	case 2:
		cout << "---CREACION DE UN CAJERO---" << endl;
		cout << "Ingrese el id: ";
		cin >> id;
		cout << "Ingrese el nombre: ";
		cin.ignore();
		getline(cin, nombre);

		fe = creaFecha();
		cout << "Ingrese las horas que trabajo: ";
		cin >> horasTrabajadas;
		// cout << "Ingrese el salario por hora: ";
		// cin >> salarioXhora;
		salarioXhora = 9;
		emp = new Cajero(id, nombre, "002", fe, horasTrabajadas, salarioXhora);
		break;
	case 3:
		cout << "---CREACION DE UN VENDEDOR---" << endl;
		cout << "Ingrese el id: ";
		cin >> id;
		cout << "Ingrese el nombre: ";
		cin.ignore();
		getline(cin, nombre);

		fe = creaFecha();
	
		// cout << "Ingrese la cuota del vendedor: ";
		// cin >> cuota;
		cuota = 800;
		cout << "Ingrese el total de ventas: ";
		cin >> totalVenta;
		// cout << "Ingrese el porcentaje por comision: ";
		// cin >> porcentajeComision;
		porcentajeComision = 0.15;
		emp = new Vendedor(id, nombre, "002", fe, cuota, totalVenta, porcentajeComision);
		break;
	case 4:
		cout << "--CREACION DE UN SUPERVISOR---" << endl;
		cout << "Ingrese el id: ";
		cin >> id;
		cout << "Ingrese el nombre: ";
		cin.ignore();
		getline(cin, nombre);

		fe = creaFecha();

		// cout << "Ingrese la cuota del vendedor: ";
		// cin >> cuota;
		cuota = 800;
		cout << "Ingrese el total de ventas: ";
		cin >> totalVenta;
		// cout << "Ingrese el porcentaje por comision: ";
		// cin >> porcentajeComision;
		porcentajeComision = 0.15;
		porcentajeRecargo = 0.10;
		emp = new Supervisor(id, nombre, "002", fe, cuota, totalVenta, porcentajeComision, porcentajeRecargo);
		break;
	default:
		cout << "No existe esa opcion" << endl;
		break;
	}
	return emp;
}

Fecha* Interfaz::creaFecha() {
	int d, m, a;
	cout << "--CREACION DE FECHA--" << endl;
	cout << "Digite el dia: ";
	cin >> d;
	cout << "Digite el mes: ";
	cin >> m;
	cout << "Digite el anio: ";
	cin >> a;
	return new Fecha(d, m, a);
}

Departamento* Interfaz::creaDepartamento() {
	Departamento* dep = NULL;
	int cod, tam;
	string des;
	cout << "Ingrese el codigo del Departamento: ";
	cin >> cod;
	cout << "Ingrese la descripcion del departamento: ";
	cin.ignore();
	getline(cin, des);
	cout << "Ingrese la cantidad de Empleados que va a tener el departamento: ";
	cin >> tam;
	dep = new Departamento(cod, des, tam);
	return dep;
}

Tienda* Interfaz::creaTienda() {
	Tienda* tien = NULL;
	int tam;
	cout << "Ingrese la cantidad de Departamentos que quiere tener en la tienda" << endl;
	cin >> tam;
	tien = new Tienda(tam);
	return tien;
}