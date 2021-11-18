#pragma once
#include "Ruta.h"
#include "Chofer.h"

// Esta sera la declaracion de la clase Bus.. (o la interfaz de la clase Bus).

class Bus {
private:
	string placa;
	string modelo;
	string marca;
	int numPasajeros;
	// Vinculaciones..
	Ruta* rutaPtr;     // Esta flecha o puntero nos vincula con una Ruta
	Chofer* choferPtr; // Esta flecha o puntero nos vincula con un Chofer..
public:
	// Tarea Moral....
	Bus(); // Constructor por defecto sin parametros
	Bus(string, string, string);
	Bus(string, string, string, int);
	Bus(string, string, string, int, Ruta*, Chofer*);
	// sigan...
	virtual ~Bus();
	// Mutadores....
	void setPlaca(string);
	void setModelo(string);
	void setMarca(string);
	void setNumPasajeros(int);
	void setRuta(Ruta*);
	void setChofer(Chofer*);
	// Accesores....
	string getPlaca();
	string getModelo();
	string getMarca();
	int getNumPasajeros();
	Ruta* getRuta();
	Chofer* getChofer();
	// toString()....
	string toString() const;
};

// Se llevan los metodos a Bus.cpp y los desarrollan...( y lo compilan)

// Luego creamos un Contenedor.h y Contenedor.cpp (forma N.4) para guardar Buses.. 

// Finalmente hacen un main() donde probar el modelo....