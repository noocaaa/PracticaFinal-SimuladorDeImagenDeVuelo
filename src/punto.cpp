#include "../include/punto.h"

Punto::Punto(){
	latitud = longitud = 0;
}

Punto::Punto (double l, double L, string d){
	latitud = l;
	longitud = L;
}

double Punto::GetLatitud() const{
	return latitud;
}

double Punto::GetLongitud() const{
	return longitud;
}

void Punto::SetLatitud(double l) {
	latitud = l;
}

void Punto::SetLongitud (double l) {
	longitud = l;
}

bool Punto::operator< (const Punto &p) const {
	bool menor = false;

	if (latitud < p.GetLatitud()) { //latitud = eje x, menor cuando la latitud es menor
		menor = true;
	}

	return menor;
}

bool Punto::operator == (const Punto &p) const {
	bool igual = false;
	if (latitud == p.GetLatitud() && longitud == p.GetLongitud()) {
		igual = true;
	}
	return igual;	
}	

istream & operator >> (istream & is, Punto &p) {
	char separador;
	double lat, lon;

	if (is) { // (a, b)
				
		is >> separador >> lat >> separador >> lon >> separador;

		p.SetLatitud(lat);
		p.SetLongitud(lon);

	}

	return is;
}

ostream & operator << (ostream & os, const Punto &p){

	if (os) {
		os << "(" << p.GetLatitud() << "," << p.GetLongitud() << ") ";
	}
	return os;
}

