#include "paciente.h"

paciente::paciente(string n, string i, float p, float e, int a, char g) {
	nombre=n;
	id=i;
	peso=p;
	estatura=e;
	annioNacimiento=a;
	genero = g;
}

string paciente::getNombre() { return nombre; }
string paciente::getId() { return id; }
float	paciente::getPeso() { return peso; }
int  paciente::getAnnioNacimiento() { return annioNacimiento; }
float paciente::getEstatura() { return estatura; }
char paciente::getGenero() { return genero; }

void paciente::setNombre(string n) { nombre = n; }
void paciente::setId(string i) { id = i; }
void	paciente::setPeso(float p) { peso = p; }
void paciente::setAnnioNacimiento(int a) { annioNacimiento = a; }
void paciente::setEstatura(float e) { estatura = e; }
void paciente::setGenero(char g) { genero = g; }
