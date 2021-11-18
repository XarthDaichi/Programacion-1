#pragma once

#include"Persona.h"

class Nodo {
private:
	Persona* ptr; // Es una flecha o puntero a Persona.
	Nodo* sig; // Esto es un puntero de enlace a otro nodo (o puede ver a NULL).
public:
	Nodo(Persona*, Nodo*); // Constructor por defecto.
	virtual ~Nodo(); // Al destrir un nodo, se destruye la persona. (si hay).
	// Accesores
	Persona* getPersona(); // Retorna la persona que hay en el nodo.
	Nodo* getSiguiente(); // Retorna la posición del siguiente nodo. ( o return NULL).
	// Mutadores
	void setPersona(Persona*); // Instalar a una persona en el vagón..(Nodo)
	void setSiguiente(Nodo*); // Decirle al nodo que es lo que va a "ver".
	// La clase nodo no tiene toString();
};