#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//Esta es la declaracion de la clase Hora...(
class Hora {
private: 
	int h;
	int m;
	int s;
public:
	Hora(int, int, int);
	virtual ~Hora();
	// Mutadores (Set's)
	void setHoras(int);
	void setMinutos(int);
	void setSegundos(int);
	// Accesores
	int getHoras();
	int getMinutos();
	int getSegundos();
	//toString()
	string toString();

};
