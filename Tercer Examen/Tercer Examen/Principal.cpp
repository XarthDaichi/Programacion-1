#include"Cajero.h"
#include"Supervisor.h"
#include"Interfaz.h"
#include"Departamento.h"
#include"Tienda.h"
#include"Empleado.h"
#include <fstream>
using namespace std;

int main() {
	Tienda* tien = NULL;
	string rutaArchivo = "../tienda.txt";
	ifstream in(rutaArchivo.c_str(), ios::in);
	while (in.good()) {
		tien = tien->recuperar(in);
	}
	in.close();
	int op;
	int id, cod;
	string calificacion;
	Fecha* fe;
	Empleado* emp = NULL;
	Departamento* dep = NULL;
	ofstream out;
	if (tien == NULL) {
		tien = Interfaz::creaTienda();
	}
	do {
		op = Interfaz::menu();
		switch (op) {
		case 1: {
			cout << ">>>>  1 - Crear e ingresar Departamento con su respectivo codigo." << endl;
			dep = Interfaz::creaDepartamento();
			tien->ingresaDepartamento(dep);
		}break;
		case 2: {
			cout << ">>>>  2 - Ingresar un empleado cajero en un determinado departamento." << endl;
			emp = Interfaz::creaEmpleado(2);
			cout << "Ingrese el codigo del departamento al cual lo quiere meter: " << endl;
			cin >> cod;
			tien->ingresarEmpleado(cod, emp);
		}break;
		case 3: {
			cout << ">>>>  3 - Ingresar un empleado vendedor en un determinado departamento." << endl;
			emp = Interfaz::creaEmpleado(3);
			cout << "Ingrese el codigo del departamento al cual lo quiere meter: " << endl;
			cin >> cod;
			tien->ingresarEmpleado(cod, emp);
		}break;
		case 4: {
			cout << ">>>>  4 - Ingresar un empleado supervisor en un determinado departamento." << endl;
			emp = Interfaz::creaEmpleado(4);
			cout << "Ingrese el codigo del departamento al cual lo quiere meter: " << endl;
			cin >> cod;
			tien->ingresarEmpleado(cod, emp);
		}break;
		case 5: {
			cout << ">>>>  5 - Opcion para recalificar a cualquier empleado por su ID. " << endl;
			cout << "Ingrese el id del empleado que quiere recalificar: ";
			cin >> id;
			cout << "Ingrese la calificacion nueva: (Malo:001 | Aceptable:002 | Muy Bueno:003 | Excelente:004) ";
			cin >> calificacion;
			tien->recalificarEmpleado(id, calificacion);
		}break;
		case 6: {
			cout << ">>>>  6 - Reportar cada empleado que tiene la tienda y la cantidad total de ellos." << endl;
			cout << tien->toStringEmpleados() << endl;
		}break;
		case 7: {
			cout << ">>>>  7 - Reportar ID, nombre y salario de todos los cajeros de la tienda." << endl;
			cout << tien->toStringCajeros() << endl;
		}break;
		case 8: {
			cout << ">>>>  8 - Reportar cada empleado y el salario total de los empleados de un determinado departamento." << endl;
			cout << "Ingrese el codigo del departamento que quiere revisar: ";
			cin >> cod;
			cout << tien->toStringSalariosDepartamento(cod) << endl;
		}break;
		case 9: {
			cout << ">>>>  9 - Reportar los empleados que ingresaron el mismo dia a la tienda." << endl;
			fe = Interfaz::creaFecha();
			cout << tien->toStringMismoDia(fe) << endl;
		}break;
		case 10: {
			cout << ">>>> 10 - Reportar los empleados que ingresaron el mismo dia en un determinado departamento." << endl;
			fe = Interfaz::creaFecha();
			cout << "Ingrese el codigo del departamento que quiere revisar: ";
			cin >> cod;
			cout << tien->toStringMismoDiaDepartamento(cod, fe) << endl;
		}break;
		case 11: {
			cout << ">>>> 11 - Reportar los empleados y la suma del salario total de toda la tienda. " << endl;
			cout << tien->toStringSalarioTotal() << endl;
		}break;
		case 12: {
			cout << ">>>> 12 - Reportar los empleados, que son cajeros de una determinada categoria. " << endl;
			cout << "Ingrese la categoria que quiere buscar: (Malo:001 | Aceptable:002 | Muy Bueno:003 | Excelente:004) ";
			cin >> calificacion;
			cout << tien->toStringCajerosCategoria(calificacion) << endl;
		}break;
		case 13: {
			cout << ">>>> 13 - Reportar los empleados de la tienda que son supervisores y que ingresaron juntos en una fecha determinada." << endl;
			fe = Interfaz::creaFecha();
			cout << tien->toStringSupervisorMismoDia(fe) << endl;
		}break;
		case 14: {
			cout << ">>>> 14 - Reportar el empleado que tiene el mayor salario de toda la tienda." << endl;
			cout << tien->toStringMayorSalario() << endl;
		}break;
		case 15: {
			cout << ">>>> 15 - Salir." << endl;
			cout << "----Guardando----" << endl;
			out.open(rutaArchivo.c_str(), ios::trunc);
			tien->guardar(out);
			out.close();
			cout << "---Borrando de la RAM---" << endl;
			cout << "Muchas gracias por haber venido, hasta luego" << endl;
		}break;
		default: cout << ">>>> ERROR: Digite una opcion valida." << endl;
		} // fin del switch
		system("pause");
	} while (op != 15);  // fin del while
	return 0;
}
