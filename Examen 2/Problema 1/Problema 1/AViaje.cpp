#include"AViaje.h"

AViaje::AViaje(string nomE, string cedJ, string telCel): nombEmpresa(nomE), ceduJuridica(cedJ), teleCelular(telCel) { }
AViaje::~AViaje() { }
string AViaje::getNombEmpresa() { return nombEmpresa; }
string AViaje::getCeduJuridic() { return ceduJuridica;}
string AViaje::getTeleCelular() { return teleCelular; }
void AViaje::setNombEmpresa(string nomE)  { nombEmpresa  = nomE;  }
void AViaje::setCeduJuridic(string cedJ)  { ceduJuridica = cedJ;  }
void AViaje::setTeleCedular(string telCel){ teleCelular  = telCel;}
string AViaje::toString() const{
	stringstream s;
	s << "Informacion de la empresa:" << endl
		<< "Nombre: " << nombEmpresa << endl
		<< "Cdeula Juridica: " << ceduJuridica << endl
		<< "Telefono Celular: " << teleCelular << endl;
	return s.str();
}


void AViaje::infoDelViaje(int cat) {
	cout << "----------------------INFORMACION DE LA EMPRESA Y DEL VIAJE----------------------" << endl;
	cout << "Informacion de la empresa:" << endl
		<< "Nombre: " << nombEmpresa << endl
		<< "Cdeula Juridica: " << ceduJuridica << endl
		<< "Telefono Celular: " << teleCelular << endl;
	cout << "Informacion del viaje: " << endl;
	cout << "Destino: " << Ruta::getDestino(cat) << endl;
	cout << "Costo del Pasaje: " << Ruta::getCostoPasaje(cat) << endl;
	cout << "Tiempo de Ruta: " << Ruta::tiempoDeRuta(cat) << endl;
}