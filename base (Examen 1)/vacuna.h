#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class vacuna {
private:
    int  numLote;
    int numSerie;
    string fechaVencimiento;
    string fechaAplicacion;
    string casaComercial;

public:
    vacuna(int, int, string, string, string);

    int  getNumLote();
    int getNumSerie();
    string getFechaVencimiento();
    string getFechaAplicacion();
    string getCasaComercial();

    void setNumLote(int);
    void setNumSerie(int);
    void setFechaVencimiento(string);
    void setFechaAplicacion(string);
    void setCasaComercial(string);


};