#include"Jugador.h"



Jugador::Jugador(string nom):nombre(nom){
}
Jugador::~Jugador() {
}
void Jugador::lanza(Dado& dado) {
	cout << "Al lanzar el dado este cae con cara con valor: " << dado.rodar() <<" puntos."<< endl;
}