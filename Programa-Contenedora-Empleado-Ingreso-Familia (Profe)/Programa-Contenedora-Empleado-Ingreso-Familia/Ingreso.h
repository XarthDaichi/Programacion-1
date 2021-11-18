#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
// La clase Ingreso contiene, el salario neto mensual, el valor total del 
//préstamo, el interés fijo(18 % anual), el número de cuotas totales(Por ejemplo : si es a 3
// años implica 36 cuotas) y finalmente, el número de cuotas que se llevan canceladas.

class Ingreso {
   private:
	   double salarioNeto;
	   double valoraTotalPrestamo;
	   double interesFijo;
	   int numAnios;
	   int numCuotasTotales;
	   int numCuotasCanceladas;
   public:
	   Ingreso();    // Construc. sin parámetros.   o Constructor por defecto....
	   Ingreso(double, double, int, int, int);  // Constructor con parámetros...  
	   virtual ~Ingreso();
	   // ACCESORES
	   double getSalarioNeto();
	   // MUTADORES.
	   // Métodos de cálculo..
	   double ganancia();
	   double valorCuotaMensual();
	   
	   // toString
	   string toString();
};