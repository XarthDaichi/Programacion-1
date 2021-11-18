#include "Persona.h"

int main() {
	cout << "-------------TRABAJANDO CON VARIABLES STATIC------------" << endl;
	cout << endl;
	cout << "Creando objetos...." << endl;
	Persona A("Jose", 20);
	Persona B("Xinia", 15);
	Persona C("Juan", 26);
	Persona D("Crisitna", 19);
	Persona* per1 = NULL; // (Es una flecha) y Es potencialmente un objeto dinamico

	cout << "Preguntando a A la cantidad de Personas..." << A.leeCantidadDePersonas() << endl;
	cout << "Preguntando a A la suma de edades..." << A.leeSumaDeEdades() << endl;
	cout << "Preguntando a A el promedio de edades..." << A.leePromedioEdades() << endl;
	cout << "Preguntando po su nombre es: " << A.leeNombre() << " y edad es " << A.leeEdad() << endl;
	
	cout << endl << endl;
	cout << "Ahora le vamos a preguntar a la clase directamente...." << endl;
	cout << "Preguntando a la clase Personas directa... " << Persona::leeCantidadDePersonas() << endl;
	cout << "Preguntando a la clase Personas directa... " << Persona::leeSumaDeEdades() << endl;
	cout << "Preguntando a la clase Personas directa... " << Persona::leePromedioEdades() << endl;

	system("pause");
	return 0;
}