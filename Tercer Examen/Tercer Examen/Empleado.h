#pragma once
#include"CategTrabajador.h"
#include"Fecha.h"
#include <fstream>

#define FIN_CAMPO '\t'
#define FIN_REGISTRO '\n'

class Empleado {
protected:
	int ID;
	string nombre;
	string categoria;
	Fecha* fec;
	char tipo;
public:
	Empleado(int = 0, string = "", string = "", Fecha* = NULL);
	virtual ~Empleado();
	virtual int    getID();
	virtual string getNombre();
	virtual string getCategoria();
	virtual Fecha* getFecha();
	virtual void   setID(int);
	virtual void   setNombre(string);
	virtual void   setCategoria(string);
	virtual void   setFecha(Fecha*);
	virtual void setTipo(char);
	virtual char getTipo();
	virtual string toString() const;
	virtual bool   esIgualA(int);
	virtual bool esMismoDia(Fecha* fe);
	virtual double salario();
	virtual void guardar(ostream& out);
};