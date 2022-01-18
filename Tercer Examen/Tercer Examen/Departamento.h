#pragma once
#include"Empleado.h"
#include"Cajero.h"
#include"Vendedor.h"
#include"Supervisor.h"
#include"Utiles.h"
#include <fstream>

#define FIN_CAMPO '\t'
#define FIN_REGISTRO '\n'

class Departamento {  // El Departamento viene siendo como un contenedor de Empleados.
private:
	int codigo;
	string descripcion;
	//-------------
	Empleado** vec;
	int can;
	int tam;
public:
	Departamento(int cod, string des, int val);
	virtual ~Departamento();
	bool ingresaEmpleado(Empleado* emp);

	// toStrings()
	string toString() const;
	string toStringEmpleados() const;
	string toStringCajeros() const;
	string toStringSalarios() const;
	string toStringMismoDia(Fecha*) const;
	string toStringCajerosCategoria(string) const;
	string toStringSupervisorMismoDia(Fecha*) const;
	



	void setDescripcion(string);
	void setCodigo(int);
	string getDescripcion();
	int getCodigo();
	int getCan();
	int getCanCajeros();
	int getCanVendedores();
	int getCanSupervisores();
	bool empleadoYaExiste(int cod);
	Empleado* getEmpleado(int);
	bool esIgualA(int);
	bool recalificarEmpleado(int cod, string cal);
	double salarioDepartamento();
	Empleado* getMayorSalario();
	//...
	//...

	void guardarDepartamento(ostream& out);
	Departamento* recuperarDepartamento(istream& in);
	void setCan(int);
};