#include"Jugador.h"


int main() {
    cout << "----RELACION (UML) DE DEPENDENCIA-----" << endl;
    cout << "--------------------------------------" << endl;
    cout << endl;
    
    cout << "Crear un dado..." << endl;
    Dado* dado = new Dado();

    cout << "Crear un jugador..." << endl;
    Jugador* jug1 = new Jugador("Cristina");

    cout << "El lugador toma el dado y lo lanza..." << endl;
    jug1->lanza(*dado);  // Aqu� es donde se usa la relaci�n de dependencia
                         // Relaci�n de USO.  Es la relaci�n UML m�s d�bil.

    system("pause");
    return 0;
}