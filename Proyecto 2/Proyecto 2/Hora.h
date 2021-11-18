#pragma once

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Hora {
private:
	int hora;
	int minuto;
public:
	Hora(int, int);
	virtual ~Hora();

	void setHora(int);
	int getHora();

	void setMinuto(int);
	int getMinuto();

	string toString() const;
};