#include "Flota.h"

string Flota::marcaAvion(string cat) {
	if (cat == "AI-19") return "AIRBUS 319";
	if (cat == "AI-20") return "AIRBUS 320";
	if (cat == "AI-21") return "AIRBUS 321";
	if (cat == "AI-30") return "ARIBUS 330";
	if (cat == "AI-40") return "AIRBUS 340";
	if (cat == "AI-60") return "AIRBUS 600";
	if (cat == "BO-73") return "BOEING 737";
	if (cat == "BO-77") return "BOEING 777";
	if (cat == "ANT-1") return "ANTONOV";
	return "";
}

double Flota::cargaAvion(string cat) {
	if (cat == "AI-19") return 27.7;
	if (cat == "AI-20") return 37.40;
	if (cat == "AI-21") return 51.70;
	if (cat == "AI-30") return 158.4;
	if (cat == "AI-40") return 207.6;
	if (cat == "AI-60") return 1400;
	if (cat == "BO-73") return 52.5;
	if (cat == "BO-77") return 653;
	if (cat == "ANT-1") return 1300;
	return 0;
}

int Flota::pasajerosAvion(string cat) {
	if (cat == "AI-19") return 156;
	if (cat == "AI-20") return 220;
	if (cat == "AI-21") return 220;
	if (cat == "AI-30") return 335;
	if (cat == "AI-40") return 419;
	if (cat == "AI-60") return 0;
	if (cat == "BO-73") return 215;
	if (cat == "BO-77") return 550;
	if (cat == "ANT-1") return 0;
	return 0;
}

bool Flota::militarAvion(string cat) {
	if (cat == "AI-19") return false;
	if (cat == "AI-20") return false;
	if (cat == "AI-21") return false;
	if (cat == "AI-30") return false;
	if (cat == "AI-40") return false;
	if (cat == "AI-60") return true;
	if (cat == "BO-73") return false;
	if (cat == "BO-77") return false;
	if (cat == "ANT-1") return true;
	return false;
}

double Flota::alcanceAvion(string cat) {
	if (cat == "AI-19") return 7200;
	if (cat == "AI-20") return 3100;
	if (cat == "AI-21") return 5600;
	if (cat == "AI-30") return 13450;
	if (cat == "AI-40") return 14630;
	if (cat == "AI-60") return 4630;
	if (cat == "BO-73") return 9955;
	if (cat == "BO-77") return 17370;
	if (cat == "ANT-1") return 4000;
	return 0;
}

string Flota::codigoAvion(string cat) {
	if (cat == "AI-19") return "001";
	if (cat == "AI-20") return "002";
	if (cat == "AI-21") return "003";
	if (cat == "AI-30") return "004";
	if (cat == "AI-40") return "005";
	if (cat == "AI-60") return "006";
	if (cat == "BO-73") return "007";
	if (cat == "BO-77") return "008";
	if (cat == "ANT-1") return "009";
	return "";
}

string Flota::toString(string cat) {
	stringstream s;
	s << "Categoria: " << cat << endl
		<<"Marca: " << marcaAvion(cat) << endl
		<< "Carga: " << cargaAvion(cat) << "m^3" << endl
		<< "Pasajeros Max: " << pasajerosAvion(cat) << endl
		<< " Militr: ";
	if (militarAvion(cat)) {
		s << "Si";
	}
	else {
		s << "No";
	}
	s << endl
		<< "Alcance: " << alcanceAvion(cat) << "km" << endl
		<< "Codigo: " << codigoAvion(cat) << endl;
	return s.str();
}