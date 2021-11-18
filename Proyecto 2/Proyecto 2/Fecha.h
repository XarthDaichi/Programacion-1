#pragma once

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Fecha {
private:
	int annio;
	int mes;
	int dia;
public:
	Fecha(int, int, int);
	virtual ~Fecha();

	void setAnnio(int);
	int getAnnio();

	void setMes(int);
	int getMes();

	void setDia(int);
	int getDia();

	string toString() const;
};