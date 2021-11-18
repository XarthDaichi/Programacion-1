#include"ClaseServicio.h"

int main() {
	cout << "---TRABAJANDO EN UNA FACTURA---" << endl;
	cout << endl;
	cout << "Servicio realizado fue la cat 1" << endl;
	cout << "La descripción de esa categoría es: " << ClaseServicio::getDescripcion(1) << endl;
	cout << "El valor de ese servicio es de: " << ClaseServicio::getValorServic(1) << endl;
	cout << "El descuento es: " << ClaseServicio::calculoDel20PorcientoDesc(1) <<" colones."<< endl;

	system("pause");
	return 0;
}