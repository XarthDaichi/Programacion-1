#include"Dado.h"

Dado::Dado() {
}

Dado::~Dado() {
}

int Dado::rodar() {
	// Generar un valor aleatorio de 1-6.
	srand(time(0));
	cara = rand() % 6 + 1;  // Genera valor aleatorio.
	return cara;
}