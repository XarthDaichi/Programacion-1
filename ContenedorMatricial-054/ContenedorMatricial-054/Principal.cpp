#include"ContenedorM.h"

int main() { // MODO-0  se utilizan datos quemados...
	cout << "---------TRABAJANDO CON CONTENEDOR MATRICIAL------------" << endl;
	cout << endl;
	cout << "Creando algunas personas...." << endl;
	Persona* per1 = new Persona("11111", "Ana",18 );
	Persona* per2 = new Persona("22222", "Jose",19 );
	Persona* per3 = new Persona("33333", "Cristian",40 );
	Persona* per4 = new Persona("44444", "Juan",17 );
	cout << endl;
	Persona* per5 = new Persona("11111", "Ana", 18);;
	Persona* per6 = new Persona("22222", "Jose", 19);
	Persona* per7 = new Persona("33333", "Cristina", 40);
	Persona* per8 = new Persona("44444", "Juan", 17);

	cout << "Creando el Contenedor..COPTR1..." << endl;
	cout << "Creando otro Contenedor..COPTR2..." << endl;
	cout << endl;
	// ContenedorM CO(2, 2);    // SE pueden pedir las dimensiones en tiempo de ejecución...
	ContenedorM* COPTR1 = new ContenedorM(2, 2);   // Objeto dinámico tipo ContenedorM.
	ContenedorM* COPTR2 = new ContenedorM(2, 2);
	cout << endl;
	cout << "Ingresar personas al contenedor...COPTR1...." << endl;
	COPTR1->ingresaPersona(per1, 0,0);  // Ingresar en la esquina superior izquierda
	COPTR1->ingresaPersona(per2, 0,1);  // Ingresa en la esquina superior derecha
	COPTR1->ingresaPersona(per3, 1,0);  // Ingresa en la esquina inferior izquier
	COPTR1->ingresaPersona(per4, 1,1);  // Ingresa en la esquina inferior derecha..

	cout << endl;
	cout << "Ingresar personas al contenedor...COPTR2...." << endl;
	COPTR2->ingresaPersona(per5, 0, 0);  // Ingresar en la esquina superior izquierda
	COPTR2->ingresaPersona(per6, 0, 1);  // Ingresa en la esquina superior derecha
	COPTR2->ingresaPersona(per7, 1, 0);  // Ingresa en la esquina inferior izquier
	COPTR2->ingresaPersona(per8, 1, 1);  // Ingresa en la esquina inferior derecha..

	if (COPTR1->comparaCotenedores(*COPTR2) == true)  // if(COPTR1->comparaCotenedores(*COPTR2))
		cout << "Si, en efecto, ambos contenedores COPTR1 Y COPTR2 son identicos..." << endl;
	else
		cout << "NO, ambos contenedores COPTR1 Y COPTR2 son diferentes." << endl;

	system("pause");
	return 0;
}






/*cout << "Imprimiendo el contenedor COPTR1---" << endl;
COPTR1->imprimeContenedor();*/

//cout << "----------------PERSONA DE MAYOR EDAD-------------------------" << endl;
//cout << endl;
//cout << "La persona de mayor edad es: " << COPTR1->laDeMayorEdad().toString() << endl;
//               // NOTA:     punt  ==  & ref;                 // ref = *punt;


