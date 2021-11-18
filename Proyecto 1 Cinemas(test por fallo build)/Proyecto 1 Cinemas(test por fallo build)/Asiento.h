#pragma once
#include <iostream>
#include <sstream>
#include <string>
#define RESET "\033[0m"
#define ROJO "\033[31m"
#define VERDE "\033[32m"
#define GRIS "\033[1m\033[30m"
using namespace std;


class Asiento {
private:
	string cedula;
	char color;
public:
	Asiento();
	virtual ~Asiento();

	// ACCESORES Y MUTADORES
	void setCedula(string ced);
	string getCedula();

	void setColor(char col);
	char getColor();

	// toString()
	string toString() const;
};