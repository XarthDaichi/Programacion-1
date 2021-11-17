#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

// Este tipo(No.2) de dependencia, es cuando un
// objeto de la clase A, le pregunta o le solicita
// información o cálculos a una clase (B).

class ClaseServicio {
   public:
	   static string getDescripcion(int);      // Cuando se escriben métodos static es porque se puede preguntar a la clase
	   static double getValorServic(int);
	   static double calculoDel20PorcientoDesc(int);
};

//----------------- Definición de lo métodos static ----------------------

string ClaseServicio::getDescripcion(int Tservicio) {
	switch (Tservicio) {
	  case 1:
		return "Corte de cabello sencillo";
		break;

	  case 2:
		return "Asesoria de Imagen";
		break;

	  case 3:
		return "Bronceado salvaje";
		break;

	  case 4:
		return "Tratamiento de lineas de expresion";
		break;
	} // fin del switch.
	return " ";
}


double ClaseServicio::getValorServic(int Tservicio) {
	switch (Tservicio) {
	case 1:
		return 6000.00;
		break;

	case 2:
		return 25000.00;
		break;

	case 3:
		return 34600.00;
		break;

	case 4:
		return 55000.00;
		break;
	} // fin del switch.
	return 0;
}

double ClaseServicio::calculoDel20PorcientoDesc(int Tservicio) {
	return  20 * getValorServic(Tservicio) / 100;
}