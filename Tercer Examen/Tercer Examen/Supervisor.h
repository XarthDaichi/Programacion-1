#pragma once
#include"Vendedor.h"

class Supervisor : public Vendedor {
private:
    double porcentajeRecargo;
public:
    Supervisor(int = 0, string = "", string = "", Fecha* = NULL, double = 0.0, double = 0.0, double = 0.0, double = 0.0);
    virtual ~Supervisor();
    virtual double getPorcentRecargo();
    virtual void setPorcentRecargo(double);
    virtual string toString() const;
    virtual double salario();
    virtual void guardar(ostream& out);
};