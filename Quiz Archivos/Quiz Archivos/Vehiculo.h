#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Vehiculo {
private:
	string marca;
	string modelo;
	int cilindrada;
public:
	Vehiculo(string, string, int);
	virtual ~Vehiculo();

	void setMarca(string);
	string getMarca();

	void setModelo(string);
	string getModelo();

	void setCilindrada(int);
	int getCilindrada();

	string toString(); 
};