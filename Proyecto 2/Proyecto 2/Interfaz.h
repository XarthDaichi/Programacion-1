#pragma once
#include "Aerolinea.h"

class Interfaz {
public:
	static int menuPrincipal();
	static int subMenuMantenimiento();
	static int subMenuReservaciones();
	static int subsubMenuMantenRutas();
	static int subsubsubMenuModifiRutas();
	static int subsubMenuMantenPersonas();
	static int subsubsubMenuMantenPasajeros();
	static int subsubsubsubMenuModifiPasajeros();
	static int subsubsubMenuMantenTripulacion();
	static int subsubsubsubMenuModifiTripulacion();
	static int subsubMenuMantenVuelos();
	static int subsubsubMenuModifiVuelos();
};