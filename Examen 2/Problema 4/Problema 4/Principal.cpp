#include"Estudiante.h"
#include"ProfUniversitario.h"
#include"AdmUniversitario.h"

int main() {
    string ced, nom;
    int ed;
    string carr;
    int numHi;
    bool prop;
    string gradoAc;
    string titu;
    int aniosL;

    cout << "---------------Creacion de 3 objetos------------------" << endl;
    cout << endl;

    cout << "1- Creacion de un Estudiante..." << endl;
    cout << "Ingrese la cedula: ";
    cin >> ced;
    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline(cin, nom);
    cout << "Ingrese la carrera: ";
    getline(cin, carr);
    cout << "Ingrese la edad: ";
    cin >> ed;
    Persona* per1 = new Estudiante(ced, nom, carr, ed);
    cout << endl;

    cout << "2- Creacion de un Profesor Universitario...." << endl;
    cout << "Ingrese la cedula: ";
    cin >> ced;
    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline(cin, nom);
    cout << "Ingrese la cantidad de hijos que tiene: ";
    cin >> numHi;
    cout << "Ingrese si tiene propiedad: (Si = 1 || No = 0) ";
    cin >> prop;
    cout << "Ingrese el grado academico: ";
    cin.ignore();
    getline(cin, gradoAc);
    Trabajador* per2 = new ProfUniversitario(ced, nom, numHi, prop, gradoAc);
    per2->llenarVecDeEdades();
    cout << endl;

    cout << "3- Creacion de un Administrador Universitario...." << endl;
    cout << "Ingrese la cedula: ";
    cin >> ced;
    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline(cin, nom);
    cout << "Ingrese la cantidad de hijos que tiene: ";
    cin >> numHi;
    cout << "Ingrese el titulo de la persona: ";
    cin.ignore();
    getline(cin, titu);
    cout << "Ingrese los anios laborales que tiene: ";
    cin >> aniosL;
    Trabajador* per3 = new AdmUniversitario(ced, nom, numHi, titu, aniosL);
    per3->llenarVecDeEdades();

    system("cls");
    
    cout << "------------------------------------------------------" << endl;
    cout << endl;
    cout << "--------------IMPRESION DE UNIVERSITARIOS-------------" << endl;
    cout << endl;
    cout << "Impresion de un Estudiante..." << endl;
    cout << per1->toString() << endl;

    cout << "Impresion de un profesor universitario...." << endl;
    cout << per2->toString() << endl;

    cout << "Impresion de un administrador universitario..." << endl;
    cout << per3->toString() << endl;

    system("pause");
    cout << "Eliminar personas universitarias..." << endl;
    delete per1;
    delete per2;
    delete per3;

    system("pause");
    return 0;
}