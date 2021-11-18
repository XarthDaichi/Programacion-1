#include"Contenedor.h"



Contenedor::Contenedor(int val){
	vec = new Empleado * [val];
	tam = val;
	can = 0;
	for (int i = 0; i < tam; i++)  // Limpieza del contenedor...
		vec[i] = NULL;
}

Contenedor::~Contenedor(){
	for (int i = 0; i < can; i++)
		delete vec[i];
	delete[] vec;
}
bool Contenedor::ingresaEmpleado(Empleado* per){
	if (can < tam) {
		vec[can++] = per;
		return true;
	}
	else
		return false;
}








int Contenedor::existeCedula(string ced) {
	for (int i = 0; i < can; i++)
		if (vec[i]->getCedula() == ced)
			return i;
	return -1;
}








// Hay que realizar un corrimiento de elementos 
// hacia la izquierda, en la eliminación de un 
// elemento en un vector.
bool Contenedor::eliminaEmpleado(string cedu) {
	int pos = existeCedula(cedu);
	if (pos >= 0) {
		delete vec[pos];
		for (int i = pos; i <can; i++) {  // Corrimiento hacia la izquierda..
			vec[i] = vec[i + 1];
		}
		can--;
		return true;  // Si se pudo eliminar ese empleado...
	}else 
		return false;
}









void Contenedor::desplegarEmpleadosConHijosMayoresDe12Anios() {
	for (int i = 0; i < can; i++) {
		if (vec[i]->getFamilia() != NULL) {  // Se el empleado en esa pos, tiene famil vinculada
			if (vec[i]->getFamilia()->existenHijosMayoresDe12Anios() == true)
				cout << vec[i]->toString() << endl;
		}
	}
}





void Contenedor::desplegarSalariosNetosMenoresA300Mil() {
	for (int i = 0; i < can; i++) {
		if (vec[i]->getIngreso() != NULL) {
			if (vec[i]->getIngreso()->getSalarioNeto() < 300000)
				cout << vec[i]->toString() << endl;
		}
	}
}


string Contenedor::toString() const{
	stringstream s;
	s << "----------------LISTADO DE EMPLEADOS--------------------" << endl;
	for (int i = 0; i < can; i++)
		s << vec[i]->toString() << endl;
	return s.str();
}