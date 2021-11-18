#include"Contenedor.h"

#include<Windows.h>


int main() {  // MODO-1  // Esta aplicación trabaja correctamente al 100%.
	// Zona de variablese o identificadores comodines.  ( Variabls para ingreso por teclado );
	int op, tamano;          // zona del main
	int numHijs;            // Familia
	string nomPar, cedPar; // Familia
	double sN, vTP;       // Ingreso
	int nA, nCT, nCC;    // Ingreso
	string cedu, nomb;  // Empleado
	int eda;           // Empleado
	//------------------
	Familia* fam  = NULL;
	Ingreso* ing  = NULL;
	Empleado* emp = NULL;
	//---CONTENEDOR CREACION----
	cout << endl << endl << endl;
	cout << "Digite el tamano del contenedor..";
	cin >> tamano;
	Contenedor CO(tamano);   // Creación del contenedor en tiempo de ejecusión.
	
	// Ingresamos al program de una manera iterativa (Que el menu se esté repitiendo).
	do {
		system("cls");  // Borrar la pantalla.
		cout << "----TRABAJANDO CON EMPLEADOS DE LA EMPRESA-----" << endl;
		cout << endl;
		cout << "------------------MENU-------------------------" << endl;
		cout << endl;
		cout << "     1- Ingresar un empleado." << endl;
		cout << "     2- Eliminar empleado con base en su cedula" << endl;
		cout << "     3- Imprimir empleados." << endl;
		cout << "     4- Desplegar empleados con hijos mayores de 12 anios" << endl;
		cout << "     5- Desplegar empleados cuyo salario neto sea menor a 300 mil" << endl;
		cout << "     6- Desplegar empleados que la cuota mensual sea menos de 50 mil" << endl;
		cout << "     7- Salir." << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "     Digite la opcion...";
		cin >> op;
		switch (op) {
		     case 1: {  // Crear una Familia - Crear un Ingreso - Crear un Empleado
				        // Vincular Crear empleado y vincularlo con Familia e Ingreso
				        // -- Luego se ingresa el empleado al Contenedor  CO.
				  // Creacion de la Familia...
				 system("cls");  cout << endl << endl;
				 cout << "Primero: Solicitar informacion de la familia del empleado." << endl;
				 cout << endl;
				 cout << "Ingrese el numero de hijos...";
				 cin >> numHijs;
				 cout << "Ingrese el nombre de la pareja..";
				 cin >> nomPar;
				 cout << "Ingrese la cedula de la pareja..";
				 cin >> cedPar;
				 fam = new Familia(numHijs, nomPar, cedPar);
				 fam->llenadoDelVectorDeEdadesDeHijos();  // Objeto Familia Creado...

				 // Creacion del Ingreso..
				 system("cls");
				 cout << "Segundo: Solicitar informacion financiera del Empleado.." << endl;
				 cout << endl;
				 cout << "Ingrese el salario neto...";
				 cin >> sN;
				 cout << "Ingrese el valor total del prestamo...";
				 cin >> vTP;
				 cout << "Ingrese el numero de anios...";
				 cin >> nA;
				 cout << "Ingrese el numero de cuotas totales...";
				 cin >> nCT;
				 cout << "Ingrese el numero de cuotas canceladas..";
				 cin >> nCC;
				 ing = new Ingreso(sN, vTP, nA, nCT, nCC);
				 cout << endl;
				 cout << endl;
				 system("cls");
				 cout << "Tercero: Solicitud de informacion del empleado...";
				 cout << endl;
				 cout << "Ingrese el numero de cedula...";
				 cin >> cedu;
				 cout << "Ingrese el nombre del empleado..";
				 cin >> nomb;
				 cout << "Ingrese la edad del empleado...";
				 cin >> eda;
				 // En este momento ya puedo crear un empleado completo.
				 // Aqui se vincula el empleado con el ingreso y su familia
				 emp = new Empleado(cedu, nomb, eda, fam, ing);

				 // Cuarto: Ingresar el empleado al contenedor...   
				 cout << endl;
				 if (CO.ingresaEmpleado(emp))  // if(CO.ingresaEmpleado(emp) == true)
					 cout << "SI INGRESO CORRECTAMENTE EL EMPLEADO." << endl;
				 else 
					 cout << "NO INGRESO EL EMPLEADO." << endl;
			 } 
			  break;
			 case 2: {
				 system("cls");
				 cout << endl;
				 cout << "----ELIMINAR EMPLEADO CON BASE EN SU CEDULA-----" << endl;
				 cout << endl;
				 cout << "Digite la cedula del empleado..";
				 cin >> cedu;
				 if (CO.eliminaEmpleado(cedu)) {
					 cout << "Dicha cedula si existe..." << endl;
					 cout << "Por lo tanto, si se pudo eliminar ese empleado." << endl;
				 }
				 else {
					 cout << "Dicha cedula NO existe..." << endl;
					 cout << "Por lo tanto, NO se pudo eliminar ese empleado." << endl;
				 }
			 } 
			  break;
			 case 3: {
					 system("cls");
					 cout << endl;
					 cout << CO.toString() << endl;
			 } 
			  break;
			 case 4: {
				     cout << "" << endl;
				     system("cls");
					 CO.desplegarEmpleadosConHijosMayoresDe12Anios();
			 } 
			  break;
			 case 5: {
				 cout << "---Empleados que tienen Sal Net menor a 300 mil---." << endl;
					 cout << endl;
					 CO.desplegarSalariosNetosMenoresA300Mil();
			 } 
		      break;
			 case 6: {
				    // Tarea Moral
			 } 
		      break;
			 case 7: {

			 } 
			  break;

			 default: {cout << "Ingreso de opcion equivocada.." << endl; }
		};
		Sleep(5000);
	} while (op != 7);
	return 0;
}











//int main() {  // MODO-0   ==> prueba con dATOS QUEMADOS    
//	 Tarea Moral..  // Con datos quemados...
//	 Primero: Crear la clase Contenedor (.h)(.cpp)  // Forma NO.4 ==> YA
//
//	 SEgundo: Crear en el main objetos familia  (2)
//	  Familia(int numH, string nP, string cP);
//	Familia* fam1 = new Familia(4, "Xinia", "99999");   // Internamen.. se crea el vector de edades.
//	Familia* fam2 = new Familia(2, "Jose", "88888");   // Internamen.. se crea el vector de edades. 
//
//	 LLenar las edades de los hijos cada una de las familias...
//	fam1->llenadoDelVectorDeEdadesDeHijos();
//	cout << "-------------------------------------------------------" << endl;
//	fam2->llenadoDelVectorDeEdadesDeHijos();
//	cout << "-------------------------------------------------------" << endl;
//
//	 Tercero: Crear objetos Ingreso (2)
//	Ingreso::Ingreso(double sN, double vTP, int nA, int nCT, int nCC)
//	Ingreso* ing1 = new Ingreso(1400000, 5000000, 7, 84, 12);
//	Ingreso* ing2 = new Ingreso(300000, 1000000, 2, 24, 6);
//
//	 Cuarto: Crear objetos Empleado (2), ayudado con objetos anteriores..
//	 Empleado(string ced, string nom, int ed, Familia* ptrF, Ingreso* ptrI)
//	Empleado* emp1 = new Empleado("11111", "Felix", 24, fam1, ing1);
//	Empleado* emp2 = new Empleado("22222", "Marcelo", 30, fam2, ing2);
//
//	 Quinto: Crear un contenedor..(1)
//	Contenedor* CO = new Contenedor(5);  // Contenedor de Empleado...
//
//    Sesto: Ingresar los Empleados al contenedor.
//	CO->ingresaEmpleado(emp1);
//	CO->ingresaEmpleado(emp2);
//
//	 Setimo: Imprimir a todos los empleados ingredos desde el contenedor con toString;
//	cout << CO->toString() << endl;
//
//	 Otra situación...
//
//	system("pause");
//	return 0;
//}