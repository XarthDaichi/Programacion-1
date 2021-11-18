#include "Contenedor.h"

// MODO-0 ... es probar el modelo.
// Aqui se utilizaran datos de prueba..
// Se ingresan datos de prueba en tiempo de compilacion.
// Saber si semanticamente todo funciona.. (ya no sitacticamente).
// Se llaman datos de prueba o datos quemados o datos a lo rudo.

int main() {
	// Se debe seguir una ruta logica en la implementacion de la aplicacion.
	// Primero: Es crear los objetos tipo Hora que se van a utilizar..
	Hora* h1 = new Hora(7, 30, 0);
	Hora* h2 = new Hora(10, 00, 0);
	Hora* h3 = new Hora(15, 45, 0);

	// Segundo: Crear objetos tipo Ruta, e Incluir una hora de salida en los objetos tipo Ruta..
	Ruta* rut1 = new Ruta("San Jose", "Puntarenas", 5600.00, h1);
	Ruta* rut2 = new Ruta("Alajuela", "San Carlos", 4800.00, h2);
	Ruta* rut3 = new Ruta("Heredia", "Limon", 6700.00, h3);

	// Tercero: es crear objetos tipo Chofer .....
	Chofer* chof1 = new Chofer("11111", "Juan", 54);
	Chofer* chof2 = new Chofer("22222", "Cristina", 18);
	Chofer* chof3 = new Chofer("33333", "Jose", 20);

	//Cuarto: Es crear buses, donde se vinculan sus choferes y rutas de una...
	// string marca, string modelo, string placa, int numPasajeros, Ruta* rut, Chofer* chof;

	Bus* bu1 = new Bus("Toyota", "2017", "99999", 56, rut1, chof1);
	Bus* bu2 = new Bus("Nissan", "2018", "77777", 60, rut2, chof2);
	Bus* bu3 = new Bus("Hyundai", "2013", "44444", 65, rut3, chof3);

	// Quinto: Es crear una Contenedora

	Contenedor* CO = new Contenedor(10);

	// Sexto: Ingresar los buses a la Contenedora
	CO->ingresarBus(bu1);
	CO->ingresarBus(bu2);
	CO->ingresarBus(bu3);

	//Setimo: Generar un listado total de buses que hay dentro de la controladora... (basico).
	cout << CO->toString() << endl;

	delete CO; // Aqui destruimos a la Contenedora

	system("pause");
	return 0;
}