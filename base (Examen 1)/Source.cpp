
#include <iostream>
#include <string>
using namespace std;

int  main ()
{

    int op = 1;
   while (op != 8)
   {
       cout << endl << endl;
       cout << "     MENU PRINCIPAL" << endl;
       cout << "1- Ingresar paciente" << endl;
       cout << "2- Mostrar todos los pacientes" << endl;
       cout << "3- Buscar paciente especifico"  << endl;
       cout << "4- Vacunar paciente" << endl;
       cout << "5- Lista pacientes vacunados (por genero)"   << endl;
       cout << "6- Porcentajes de vacunacion" << endl ;
       cout << "7- Vacunados por casa comercial" << endl;
       cout << "8- Salir" << endl << endl;
       cout << "Digite la opcion: ";
       cin >> op;
       system("cls");


       switch (op) {
           case 1:
               cout <<endl<<endl<< "              Registro del paciente "<<endl << endl;
          
     
              
              cout << "<Enter para continuar>" << endl;
              cin.get();
              cin.get();
              system("cls");
              break;
           case 2:
               cout << endl << endl << "              Pacientes Registrados " << endl << endl;
               cout << "<Enter para continuar>" << endl;
               cin.get();
               cin.get();
               system("cls");
               break;
           case 3:
               cout << endl << endl << "              Consulta de Paciente Especifico " << endl << endl;
               cout << "<Enter para continuar>" << endl;
               cin.get();
               cin.get();
               system("cls");
               break;
           case 4:
               cout << endl << endl << "              Vacunacion del paciente " << endl << endl;
               cout << "<Enter para continuar>" << endl;
               cin.get();
               cin.get();
               system("cls");
               break;

           case 5:
               cout << "Lista de mujeres vacunadas: "<<endl;
        
               cout << "Lista de Hombren vacunados: " << endl;
               cout << "<Enter para continuar>" << endl;
               cin.get();
               cin.get();
               system("cls");
               break;

           case 6:
               cout << endl << endl << "              Porcentaje de Vacunacion" << endl << endl;
               cout << "<Enter para continuar>" << endl;
               cin.get();
               cin.get();
               system("cls");
               break;

           case 7:
               cout << endl << endl << "              Vacunacion por Casa Comercial" << endl << endl;
               cout << "<Enter para continuar>" << endl;
               cin.get();
               cin.get();
               system("cls");
               break;

       }
        
             
       
   }


   return 0;
}