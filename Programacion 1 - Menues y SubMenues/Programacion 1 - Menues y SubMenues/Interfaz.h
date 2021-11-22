#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Interfaz {
   public:
	   static int menuPrincipal();
	   static int subMenuMantenimiento();
	   static int subMenuReservaciones();
	   static int subsubMenuMantenRutas();
	   static int subsubMenuMantenPersonas();
	   static int subsubMenuMantenVuelos();

};