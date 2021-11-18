#include "Dia.h"

Dia::Dia(int d, int an) {
	vec[0] = new Hora("Manana");
	vec[1] = new Hora("Tarde");
	vec[2] = new Hora("Noche");
	dia = d;
	annio = an;
}

Dia::~Dia() {
	for (int i = 0; i < 3; i++) {
		delete vec[i];
	}
}

Hora* Dia::getHora(int ho) { return vec[ho]; }

string Dia::DiaAFecha(int d, int an) {
	stringstream s;
	if (an % 4 == 0 && an % 100 == 0 && an % 400 == 0) {
		if (d <= 31) {
			s << "Enero " << d << ", " << an;
		}
		else if (d <= 60) {
			s << "Febrero " << d - 31 << ", " << an;
		}
		else if (d <= 91) {
			s << "Marzo " << d - 60 << ", " << an;
		}
		else if (d <= 121) {
			s << "Abril " << d - 91 << ", " << an;
		}
		else if (d <= 152) {
			s << "Mayo " << d - 121 << ", " << an;
		}
		else if (d <= 182) {
			s << "Junio " << d - 152 << ", " << an;
		}
		else if (d <= 213) {
			s << "Julio " << d - 182 << ", " << an;
		}
		else if (d <= 244) {
			s << "Agosto " << d - 213 << ", " << an;
		}
		else if (d <= 274) {
			s << "Septiembre " << d - 244 << ", " << an;
		}
		else if (d <= 305) {
			s << "Octubre " << d - 274 << ", " << an;
		}
		else if (d <= 335) {
			s << "Noviembre " << d - 305 << ", " << an;
		}
		else if (d <= 366) {
			s << "Diciembre " << d - 335 << ", " << an;
		}
	}
	else {
		if (d <= 31) {
			s << "Enero " << d << ", " << an;
		}
		else if (d <= 59) {
			s << "Febrero " << d - 31 << ", " << an;
		}
		else if (d <= 90) {
			s << "Marzo " << d - 60 << ", " << an;
		}
		else if (d <= 120) {
			s << "Abril " << d - 91 << ", " << an;
		}
		else if (d <= 151) {
			s << "Mayo " << d - 121 << ", " << an;
		}
		else if (d <= 181) {
			s << "Junio " << d - 152 << ", " << an;
		}
		else if (d <= 212) {
			s << "Julio " << d - 182 << ", " << an;
		}
		else if (d <= 243) {
			s << "Agosto " << d - 213 << ", " << an;
		}
		else if (d <= 273) {
			s << "Septiembre " << d - 244 << ", " << an;
		}
		else if (d <= 304) {
			s << "Octubre " << d - 274 << ", " << an;
		}
		else if (d <= 334) {
			s << "Noviembre " << d - 305 << ", " << an;
		}
		else if (d <= 365) {
			s << "Diciembre " << d - 335 << ", " << an;
		}
	}
	s << endl;
	return s.str();
}

void Dia::setAnnio(int an) { annio = an; }
int Dia::getAnnio() { return annio; }

string Dia::toString() const {
	stringstream s;
	for (int i = 0; i < 3; i++) {
		if (vec[i]->getFuncion() != NULL) {
			s << vec[i]->toString();
			if (annio % 4 == 0 && annio % 100 == 0 && annio % 400 == 0) {
				if (dia <= 31) {
					s << "Enero " << dia << ", " << annio;
				}
				else if (dia <= 60) {
					s << "Febrero " << dia - 31 << ", " << annio;
				}
				else if (dia <= 91) {
					s << "Marzo " << dia - 60 << ", " << annio;
				}
				else if (dia <= 121) {
					s << "Abril " << dia - 91 << ", " << annio;
				}
				else if (dia <= 152) {
					s << "Mayo " << dia - 121 << ", " << annio;
				}
				else if (dia <= 182) {
					s << "Junio " << dia - 152 << ", " << annio;
				}
				else if (dia <= 213) {
					s << "Julio " << dia - 182 << ", " << annio;
				}
				else if (dia <= 244) {
					s << "Agosto " << dia - 213 << ", " << annio;
				}
				else if (dia <= 274) {
					s << "Septiembre " << dia - 244 << ", " << annio;
				}
				else if (dia <= 305) {
					s << "Octubre " << dia - 274 << ", " << annio;
				}
				else if (dia <= 335) {
					s << "Noviembre " << dia - 305 << ", " << annio;
				}
				else if (dia <= 366) {
					s << "Diciembre " << dia - 335 << ", " << annio;
				}
			}
			else {
				if (dia <= 31) {
					s << "Enero " << dia << ", " << annio;
				}
				else if (dia <= 59) {
					s << "Febrero " << dia - 31 << ", " << annio;
				}
				else if (dia <= 90) {
					s << "Marzo " << dia - 60 << ", " << annio;
				}
				else if (dia <= 120) {
					s << "Abril " << dia - 91 << ", " << annio;
				}
				else if (dia <= 151) {
					s << "Mayo " << dia - 121 << ", " << annio;
				}
				else if (dia <= 181) {
					s << "Junio " << dia - 152 << ", " << annio;
				}
				else if (dia <= 212) {
					s << "Julio " << dia - 182 << ", " << annio;
				}
				else if (dia <= 243) {
					s << "Agosto " << dia - 213 << ", " << annio;
				}
				else if (dia <= 273) {
					s << "Septiembre " << dia - 244 << ", " << annio;
				}
				else if (dia <= 304) {
					s << "Octubre " << dia - 274 << ", " << annio;
				}
				else if (dia <= 334) {
					s << "Noviembre " << dia - 305 << ", " << annio;
				}
				else if (dia <= 365) {
					s << "Diciembre " << dia - 335 << ", " << annio;
				}
			}
			s << endl << endl;
		}
	}
	return s.str();
}