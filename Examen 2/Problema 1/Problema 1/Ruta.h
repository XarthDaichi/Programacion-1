#pragma once
#include<iostream>
#include"AViaje.h"
using namespace std;


class Ruta {
   public:
	   static string getDestino(int);
	   static double getCostoPasaje(int);
	   static double tiempoDeRuta(int);
};