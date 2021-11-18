#include "vacuna.h"

vacuna::vacuna(int nl, int ns, string fv, string fa, string cc) {  
	numLote=nl;
	numSerie=ns;
	fechaVencimiento=fv;
	fechaAplicacion=fa;
	casaComercial = cc;
}

int  vacuna::getNumLote() { return numLote; }
int vacuna::getNumSerie() { return numSerie; }
string vacuna::getFechaVencimiento() { return fechaVencimiento; }
string vacuna::getFechaAplicacion() { return fechaAplicacion; }
string vacuna::getCasaComercial() { return fechaAplicacion; }

void vacuna::setNumLote(int nl) { numLote = nl; }
void vacuna::setNumSerie(int ns) { numSerie = ns; }
void vacuna::setFechaVencimiento(string fv) { fechaVencimiento = fv; }
void vacuna::setFechaAplicacion(string fa) { fechaAplicacion = fa; }
void vacuna::setCasaComercial(string cc) { fechaAplicacion=cc; }

