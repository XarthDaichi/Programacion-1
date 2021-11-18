#include"Nodo.h"

Nodo::Nodo(Producto* pro, Nodo* si) {
	ptr = pro;  
	sig = si;   
}
Nodo::~Nodo() {
	if (ptr) delete ptr;    
}
Producto* Nodo::getProducto() {
	return ptr;
}
Nodo* Nodo::getSiguiente() {
	return sig;
}
void Nodo::setProducto(Producto* pro) {
	ptr = pro;
}
void Nodo::setSiguiente(Nodo* si) {
	sig = si;
}