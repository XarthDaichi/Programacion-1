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
    jug1->lanza(*dado);  // Aquí es donde se usa la relación de dependencia
                         // Relación de USO.  Es la relación UML más débil.

    system("pause");
    return 0;
}