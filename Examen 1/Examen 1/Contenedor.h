#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Persona.h"
using namespace std;

// visualizar todos los pacientes (mostrar solamente nomrbe, id y si esta vacunado
// al registrar no se permite ingresar pacientes repetidos
// buscar paciente por numero de cedula y mostrar la info del paciente, en caso de ser vacunado mostrar info de vacuna
// vacunar un paciente, buscar paciente, no se permite un paciente que no este registrado o ya haya sido vacunado
// Mostrar pacientes vacunados, ordenados por genero primero mujeres y despues hombres (solo id y nombre)
// Porcentaje de pacientes vacunados y pacientes no vacunados
// Pacientes vacunados en la misma vasa comercial, ingresar casa comercial y mostrar pacientes vacunados, solo id y nombre
class Contenedor {
private:
	int tam;
	int cant;
	Persona** vec;


	static int personasVacunadas;
	static float porcentajeVacunado;
	void updatePorcentajeVacunado();
	static float porcentajeNoVacunado;
	void updatePorcentajeNoVacunado();
public:
	Contenedor(int);
	virtual ~Contenedor();

	// MUTADORES Y ACCESORES
	int getCant();

	// INGRESAR AL VECTOR
	bool ingresarPaciente(Persona*);
	bool pacienteExiste(string, int&);
	
	// VACUNAR PACIENTE
	bool pacienteVacunado(string);
	bool vacunarPaciente(string, Vacuna*);

	// TOSTRINGS()
	string toString();
	string toStringPacienteEspecifico(string);
	string toStringMujeresVacunadas();
	string toStringHombresVacunados();
	string toSringCasaComercial(string);

	// PORCENTAJES
	static int getPersonasVacunadas();
	static float getPorcentajeVacunado();
	static float getPorcentajeNoVacunado();
};