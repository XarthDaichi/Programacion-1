#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Motor {
private:
	bool estadoM; //true: encendido false: apagado
public:
	Motor();
	virtual ~Motor();
	void setEstadoM(bool est) { estadoM = est; }
	bool arrancar() { // si es void tiene que enviar mensajes, si es bool los mensajes van en otro metodo
		if (estadoM == false) {
			// cout << "Ingresando las llaves.   Ok... arrancando el motor. Brrrrrrrrrmmmmmm.." << endl;
			setEstadoM(true);
			return true;
		}
		else {
			// cout << "Error el motor no se puede encender, dado que esta encendido.." << endl;
			return false;
		}
		void aparar();
		string toString();
	}
};

class Ventana {
private:
	bool estadoV; // true: abierta   false:cerrada
public:
	Ventana();
	virtual ~Ventana();
	void setEstadoV(bool est) { estadoV = est; }
	bool abrirVentana();
	bool cerrarVentana();
	string toString();
};

class Puerta {
private:
	bool estadoP; // true:abierta   false:cerrada
	Ventana* ven; // flecha hacia ventana...
public:
	Puerta() {
		estadoP = false;
		ven = new Ventana();
	}
	virtual ~Puerta();
	Ventana* getVentana();
	void setEstadoP(bool est);
	bool abrirPuerta();
	bool cerrarPuerta();
	string toString();
};

class Llanta {
private:
	int direccion; // 1:izquierda 2:centrada 3:derecha
	bool estadoLl; // bien: true // pinchada: false
	double presion;
public:
	Llanta();
	virtual ~Llanta();
	bool girarAlaIzquierda();
	bool girarAlaDerecha();
	bool mantenerCentrada();
	bool frena();
	bool noFrenar();
	string toString();
};

class Vehiculo { // Contenedor del segundo tipo.
private:
	string marca;
	string modelo;
	string placa;
	Motor* mot;
	Puerta* pI;
	Puerta* pD;
	Llanta* llI;
	Llanta* llD;
public:
	Vehiculo(string mar, string mod, string pla, Motor* moto, Puerta* pd, Puerta* pi, Llanta* lli, Llanta* lld) :marca(mar), modelo(mod), placa(pla), mot(moto), pD(pd), pI(pi), llI(lli), llD(lld) {}
	virtual ~Vehiculo() {
		if (mot) delete mot;
		if (pI) delete pI;
		if (pD) delete pD;
		if (llI) delete llI;
		if (llD) delete llD;
	}

	void arrancarMotor();
	void apagarMotor();
	void abrirPuertaIzquierda();
	void abrirPuertaDerecha();
	void cerrarPuertaIzquierda();
	void cerrarPuertaDerecha();
	void girarHaciaLaDerecha();
	void girarHaciaLaIzquierda();
	void abrirVentanaIzquierda();
	void abrirVentanaDerecha();
	Puerta* getPuertaIzquierda();
	Puerta* getPuertaDerecha();
};
// Tarea Moral.
// Desarrollar los metodos de las clases.

int main() {
	// Probar el modelo con datos quemados... o datos de prueba.

	system("pause");
	return 0;
}