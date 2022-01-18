#pragma once
#include"Empleado.h"

class Vendedor : public Empleado {
protected:
    double cuota;
    double totalVentas;
    double porcentajeComision;
public:
    Vendedor(int = 0, string = "", string = "", Fecha* = NULL, double = 0.0, double = 0.0, double = 0.0);
    virtual ~Vendedor();
    virtual double getCuota();
    virtual double getTotalVentas();
    virtual double getPorcentajeComision();
    virtual void setCuota(double);
    virtual void setTotalVentas(double);
    virtual void setPorcentajeComision(double);
    virtual string toString() const;
    virtual double salario();
    virtual void guardar(ostream& out);
};