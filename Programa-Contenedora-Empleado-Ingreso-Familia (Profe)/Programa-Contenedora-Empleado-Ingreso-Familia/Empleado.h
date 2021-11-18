#pragma once

#include"Familia.h"
#include"Ingreso.h"

//  Empleado cuyos atributos son: cedula, nombre, apellido, 
//  edad, y un puntero hacia un objeto tipo Familia y un puntero 
//  hacia un objeto tipo Ingreso.

class Empleado {
    private:
        string cedula;
        string nombre;
        int edad;
        Familia* ptrFam;
        Ingreso* ptrIng;
    public:
        Empleado();
        Empleado(string, string, int);
        Empleado(string, string, int, Familia*, Ingreso*);
        virtual ~Empleado();
        // ACCESORES... get´s
           string getCedula();
           string getNombre();
           int getEdad();
           Familia* getFamilia();
           Ingreso* getIngreso();
        // MUTADORES... set's
        // ToString...
        string toString();
};