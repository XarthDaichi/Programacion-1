#pragma once
#include "Persona.h"
#include "Vehiculo.h"

class Trabajador: public Persona {
private:
	double _salario;
	double _porcDeducTot;
	Vehiculo* veh;
public:
	Trabajador(string, string, double, double);
	Trabajador(string, string, double, double, string, string, int);
	virtual ~Trabajador();

	void setSalario(double);
	double getSalario();

	void setPorcDeducTot(double);
	double getPorcDeducTot();

	bool asociarVehiculo(Vehiculo*);

	virtual string toString();

	virtual void guardar(ostream&);
	static Trabajador recuperar(istream&);

	static double convertirDouble(string);
	static int convertirInt(string);
};