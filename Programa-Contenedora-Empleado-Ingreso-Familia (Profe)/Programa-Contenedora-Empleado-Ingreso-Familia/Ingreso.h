#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
// La clase Ingreso contiene, el salario neto mensual, el valor total del 
//pr�stamo, el inter�s fijo(18 % anual), el n�mero de cuotas totales(Por ejemplo : si es a 3
// a�os implica 36 cuotas) y finalmente, el n�mero de cuotas que se llevan canceladas.

class Ingreso {
   private:
	   double salarioNeto;
	   double valoraTotalPrestamo;
	   double interesFijo;
	   int numAnios;
	   int numCuotasTotales;
	   int numCuotasCanceladas;
   public:
	   Ingreso();    // Construc. sin par�metros.   o Constructor por defecto....
	   Ingreso(double, double, int, int, int);  // Constructor con par�metros...  
	   virtual ~Ingreso();
	   // ACCESORES
	   double getSalarioNeto();
	   // MUTADORES.
	   // M�todos de c�lculo..
	   double ganancia();
	   double valorCuotaMensual();
	   
	   // toString
	   string toString();
};