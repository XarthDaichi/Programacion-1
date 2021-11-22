#pragma once
#include"Interfaz.h"

class Controladora {
private:
	Aerolinea* aero;
public:
	Controladora();
	virtual ~Controladora();

	void control_main();
	// Mantenimiento
	void control_1();
	// Mantenimiento Personas
	void control_1_1();
	void control_1_1_1();
	// Mantenimiento Pasajeros
	void control_1_1_1_1();

	void control_1_1_1_2();

	void control_1_1_1_3();
	// Modificacion Pasajeros
	void control_1_1_1_3_1();
	void control_1_1_1_3_2();
	void control_1_1_1_3_3();
	void control_1_1_1_3_4();
	void control_1_1_1_4();

	void control_1_1_2();
	// Mantenimiento Tripulacion
	void control_1_1_2_1();

	void control_1_1_2_2();

	void control_1_1_2_3();
	// Modificacion Tripulacion
	void control_1_1_2_3_1();
	void control_1_1_2_3_2();
	void control_1_1_2_3_3();
	void control_1_1_2_3_4();
	void control_1_1_2_3_5();
	void control_1_1_2_3_6();
	void control_1_1_2_3_7();
	void control_1_1_2_3_8();
	void control_1_1_2_3_9();

	void control_1_1_2_4();


	void control_1_2();


	void control_1_3();
	// Mantenimiento Rutas
	void control_1_3_1();
	void control_1_3_2();
	void control_1_3_3();
	// Modificacion Rutas
	void control_1_3_3_1();
	void control_1_3_3_2();
	void control_1_3_3_3();
	void control_1_3_3_4();
	void control_1_3_3_5();
	void control_1_3_3_6();
	void control_1_3_3_7();

	void control_1_3_4();

	void control_1_4();
	// Mantenimiento Vuelos
	void control_1_4_1();
	void control_1_4_2();
	void control_1_4_3();
	// Modificacion Vuelos;
	void control_1_4_3_1();
	void control_1_4_3_2();
	void control_1_4_3_3();
	void control_1_4_3_4();
	void control_1_4_3_5();
	void control_1_4_3_6();
	void control_1_4_3_7();
	void control_1_4_3_8();
	void control_1_4_3_9();
	void control_1_4_3_10();
	void control_1_4_3_11();

	void control_1_4_4();

	void control_2();
	void control_2_1();
	void control_2_2();
	void control_2_3();
	void control_2_4();
};