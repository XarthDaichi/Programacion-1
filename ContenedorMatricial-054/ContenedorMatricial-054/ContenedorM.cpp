#include"ContenedorM.h"

ContenedorM::ContenedorM(int fil, int col):filas(fil), colum(col){
	// Etapa..I
       mat = new Persona ** [filas]; //Crear la columna inicial.
    // Etapa II
     for (int i = 0; i < filas; i++) //Crear vectores relacionados
       mat[i] = new Persona * [colum]; //con la primera columna, para objetos dinámicos.
     // Etapa III
     for (int i = 0; i < filas; i++) //Llenar la matriz de 
         for (int j = 0; j < colum; j++) //null y así limpiarla
             mat[i][j] = NULL; // o inicializarla. 
}

ContenedorM::~ContenedorM(){
    // I Etapa:  == destrucción de objetos del contenedor básico.
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < colum; j++)
            if(mat[i][j] != NULL)
              delete mat[i][j];
    // II Etapa:  == > destruccion...de los vectores filas asociadas a la columna inicial.
      for (int fil = 0; fil < filas; fil++) {
          delete[] mat[fil];
          cout << "Destruír fila Numero.." << fil + 1 << endl;
      }
    // III Etapa: ==> Destrucción de la columna que se construyó inicialmente
      delete [] mat;
      cout << "Destruír columna inicial" << endl;
}

void ContenedorM::imprimeContenedor(){
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < colum; j++)
            if (mat[i][j] != NULL)
                cout<<mat[i][j]->toString()<<endl;
}

bool ContenedorM::ingresaPersona(Persona* per, int fi, int co) {
    if (fi >= 0 && co >= 0 && fi < filas && co < colum) {  // Si es cierto, ese lugar existe..
        if (mat[fi][co] != NULL) delete mat[fi][co];
        mat[fi][co] = per;
        return true;
    }
    else
        return false;
}

Persona* ContenedorM::obtenerPersona(int fi, int co) {
    if (fi >= 0 && co >= 0 && fi < filas && co < colum) {
        return mat[fi][co];
    }
    else
        return NULL;
}

// Planteo: Todo método tiene un planteo.
// Primero: Se asume que la persona que esta en [0][0] es la mayor
// Segundo: Recorrer la matriz hasta encontrar otras personas mayores.
// Tercero: Al recorrer dejar en PM el puntero a la persona mayor
// Cuarto:  Ese puntero de PM.

Persona& ContenedorM::laDeMayorEdad(){  // Este metodo se aplica a sabiendas de que mat no este vacia
    Persona* PM = mat[0][0];
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < colum; j++)
            if (mat[i][j] != NULL) {
                if (mat[i][j]->getEdad() > PM->getEdad()) {
                    PM = mat[i][j];   // Hay otra persona mayor a la anterior.
                }
            }
    return *PM;
}
// Planteo:

bool ContenedorM::comparaCotenedores(ContenedorM& CO){
    // Ver si las filas y las columnas son iguales..
    if (filas != CO.filas) return false;
    if (colum != CO.colum) return false;
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < colum; j++) {
            if (mat[i][j] != NULL) {
                if (!mat[i][j]->esIgualA(*CO.obtenerPersona(i, j)))
                    return false;
            }
        }
    return true;
}


//Persona& ContenedorM::laDeMenorEdad(){
//
//}
//void ContenedorM::ordenaPorEdad(){  // No lo hagan..
//
//}
//float ContenedorM::promedioDeEdades(){
//
//}

//void ContenedorM::reporteTodosConNombre(string nom){
//
//}
//void ContenedorM::reporteTodosConEdadMayorA(int ed){
//
//}