#include"Ruta.h"

string Ruta::getDestino(int cod) {
	string respuesta;
	switch (cod) {
	case 121:
		respuesta = "Limon";
		break;
	case 234:
		respuesta = "Paso Canoas";
		break;
	case 456:
		respuesta = "Puntarenas";
		break;
	case 629:
		respuesta = "Peñas Blancas";
		break;
	case 987:
		respuesta = "Ciudad Quesdada";
		break;
	default:
		respuesta = "Codigo Incorrecto";
		break;
	}
	return respuesta;
}

double Ruta::getCostoPasaje(int cod) {
	double respuesta;
	switch (cod) {
	case 121:
		respuesta = 14500.00;
		break;
	case 234:
		respuesta = 15000.00;
		break;
	case 456:
		respuesta = 7500.00;
		break;
	case 629:
		respuesta = 13000.00;
		break;
	case 987:
		respuesta = 8600.00;
		break;
	default:
		respuesta = 0.0;
		break;
	}
	return respuesta;
}

double Ruta::tiempoDeRuta(int cod){
	double respuesta;
	switch (cod) {
	case 121:
		respuesta = 3.5;
		break;
	case 234:
		respuesta = 7.2;
		break;
	case 456:
		respuesta = 2.0;
		break;
	case 629:
		respuesta = 6.5;
		break;
	case 987:
		respuesta = 4.5;
		break;
	default:
		respuesta = 0.0;
		break;
	}
	return respuesta;
}