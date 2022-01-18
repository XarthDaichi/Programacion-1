#pragma once
#include<iostream>
#include<sstream>
#include"Departamento.h"
#define FIN_CAMPO '\t'
#define FIN_REGISTRO '\n'
using namespace std;

class Tienda {   // La Tienda viene siendo como un Contenedor de Departamentos.
private:
	string nombreTienda;
	string cedulaJuridica;
	//--------------------
	Departamento** vec;
	int can;
	int tam;
public:
	Tienda(int);    // Ingresar el número de departamentos.
	virtual ~Tienda();
	void setNombreTienda(string);
	void setCeduJuridica(string);
	string getNombreTienda();
	string getCedulaJuridica();
	int getCantidad();
	int getTamanio();
	bool ingresaDepartamento(Departamento* dep);
	bool ingresarEmpleado(int cod, Empleado* emp);

	// toStrings()
	string toString() const;
	string toStringEmpleados() const;
	string toStringCajeros() const;
	string toStringSalariosDepartamento(int) const;
	string toStringSalarioTotal() const;
	string toStringMismoDia(Fecha* fe) const;
	string toStringMismoDiaDepartamento(int, Fecha*) const;
	string toStringCajerosCategoria(string cat) const;
	string toStringSupervisorMismoDia(Fecha*) const;
	string toStringMayorSalario() const;

	bool departamentoYaExiste(int cod);
	bool empleadoYaExiste(int cod);
	bool recalificarEmpleado(int, string);
	double salarioTotal();
	//..
	//..

	void guardar(ostream& out);
	static Tienda* recuperar(istream& in);
};




