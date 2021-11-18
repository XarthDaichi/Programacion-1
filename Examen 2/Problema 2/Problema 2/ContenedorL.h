#pragma once
#include"Nodo.h"

class ContenedorL {
   private:
      Nodo* ppio;   // Es un puntero externo que solo ve al primer nodo de la lista.
   public:
    ContenedorL();
    virtual ~ContenedorL();
    Nodo* getPpio();
    bool estaVacia();
    void ingresarProducto(Producto*);
    bool  compararaListasIguales(ContenedorL*);
    string toString();
    
};

