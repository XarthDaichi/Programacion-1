#include<iostream>
#include<sstream>
#include"Interfaz.h"
using namespace std;

int main() {
	int op, op1, op2, op3, op4, op5;

	do {
		op = Interfaz::menuPrincipal();
		system("cls");
		switch (op) {
		  case 1: {
			do{
			  op1 = Interfaz::subMenuMantenimiento();
			  system("cls");
			  switch (op1) {
			    case 1: {
					do {
						op1 = Interfaz::subsubMenuMantenRutas();
						system("cls");
						cout << endl << endl << endl;
						switch (op1) {
						    case 1: {cout << "   >>Proceso para Ingresar una Ruta." << endl; }break;   system("pause");
							case 2: {cout << "   >>Proceso para Eliminar una Ruta." << endl; }break;   system("pause");
							case 3: {cout << "   >>Proceso para Listar las Rutas."  << endl; }break;   system("pause");
							case 4: {cout << "   >>Proceso para Editar una Ruta."   << endl; }break;   system("pause");
							case 5: {                                                        }break;
						};
						if (op1 != 5)
							system("pause");
						system("cls");
					} while (op1 != 5);
			    }break;
			    case 2: {
				   do {
					   op1 = Interfaz::subsubMenuMantenPersonas();
					   system("cls");
					   cout << endl << endl << endl;
					   switch (op1) {
					   case 1: {cout << "   >>Proceso para Ingresar una Persona." << endl; }break;   system("pause");
					   case 2: {cout << "   >>Proceso para Eliminar una Persona." << endl; }break;   system("pause");
					   case 3: {cout << "   >>Proceso para Listar las Personas."  << endl; }break;   system("pause");
					   case 4: {cout << "   >>Proceso para Editar una Persona."   << endl; }break;   system("pause");
					   case 5: {                                                           }break;
					  };
					  if (op1 != 5)
						  system("pause");
					  system("cls");
				   } while (op1 != 5);
			    }break;
			    case 3: {
				  do {
					  op1 = Interfaz::subsubMenuMantenVuelos();
					  system("cls");
					  cout << endl << endl << endl;
					  switch (op1) {
					  case 1: {cout << "   >>Proceso para Ingresar un Vuelo." << endl; }break;   system("pause");
					  case 2: {cout << "   >>Proceso para Eliminar un Vuelo." << endl; }break;   system("pause");
					  case 3: {cout << "   >>Proceso para Listar los Vuelos." << endl; }break;   system("pause");
					  case 4: {cout << "   >>Proceso para Editar un Vuelo." << endl;   }break;   system("pause");
					  case 5: {                                                        }break;
					  };
					  if (op1 != 5)
						  system("pause");
					  system("cls");
				  } while (op1 != 5);
			    }break;
			    case 4: {
				  //cout << "--Salir--" << endl;
			    }break;
			    default: cout << "ERROR: Esa opcion no existe." << endl;
			  };
			  system("cls");
			} while (op1 != 4);
		  }break;
		  case 2: {
			  do {
				  op2 = Interfaz::subMenuReservaciones();
				  system("cls");
				  switch (op2) {
				    case 1: {
						cout << endl << endl << endl;
						cout << "--Sub-Sub-Menu LISTADO DE TODOS LOS VUELOS CON SU CODIGO--" << endl;
						system("pause");
				    }break;
				    case 2: {
					   cout << endl << endl << endl;
					   cout << "--Sub-Sub-Menu CREAR UNA NUEVA RESERVACION--" << endl;
					   cout << "----------------RESERVACION-----------------" << endl;
					   cout << "Seleccione la persona a viajar: " << endl;
					   system("pause");
					   cout << "Ingrese la fecha de reservacion: " << endl;
					   system("pause");
					   cout << "Ingrese el codigo del vuelo: " << endl;
					   system("pause");
				    }break;
				    case 3: {
					  cout << endl << endl << endl;
					  cout << "--Sub-Sub-Menu ELIMINAR RESERVACIÓN CON CODIGO DE VUELO--" << endl;
					  cout << "Digite el codigo del vuelo." << endl;
					  system("pause");
					  cout << "Digite la cedula de la persona." << endl;
					  system("pause");
				    }break;
				    case 4: {
						cout << endl << endl << endl;
						cout << "--Sub-Sub-Menu REPORTE DE PASAJEROS CON CODIGO DE VUELO--" << endl;
						cout << "Ingrese el codigo del vuelo..." << endl;
						system("pause");
				    }break;
					case 5: {
						
					}break;
					default: {
						cout << "ERROR: Esa opcion no existe." << endl;
						system("pause");
					}
				  };
				  system("cls");
			  } while (op2 != 5);
		  }break;
		  case 3: {
			  /*cout << "------------------SALIR-----------------" << endl;
			  cout << "- - - - M U C H A S   G R A C I A S - - " << endl;*/
		  }break;
		  default: cout << "ERROR: Esa opcion no existe." << endl;
		}
		/*if(op != 3)
		   system("pause");*/
		system("cls");
	} while (op != 3);
	cout << endl << endl << endl;
	cout << "------------------SALIR-----------------" << endl;
	cout << "- - - - M U C H A S   G R A C I A S - - " << endl;
	system("pause");
	return 0;
}



