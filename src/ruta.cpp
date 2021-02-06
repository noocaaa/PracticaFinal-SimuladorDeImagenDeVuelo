#include "../include/ruta.h"

void Ruta::Borrar(const Punto &p){

	typename list<Punto>::const_iterator it, ita;

	it = puntos.begin();
	ita = puntos.end();

	while (it != ita) {
		if ((*it) == p) {
			it = puntos.erase(it);
		} else {
			++it;
		}
	}
}

void Ruta::Insertar(const Punto &p){
	puntos.push_back(p);
}

string Ruta::GetCode() const{
	return code;
}

list<Punto> Ruta::GetPuntos() const {
	return puntos;
}

void Ruta::SetCode(const string &newcode){
	code = newcode;
}

bool Ruta::operator == (const Ruta &r)const{
	bool igual = false;

	if(code == r.code){
		igual = true;
	}

	return igual;
}

bool Ruta::operator < (const Ruta &r) const{
	bool menor = false;
	if(puntos < r.puntos){
		menor = true;
	}
	return menor;
}

int Ruta::size() const{
	return puntos.size();
}

istream & operator >> (istream &is, Ruta &r){
	string palabras, espacio;
	int num_puntos;
	Punto punto;

	if(is){

		is >> palabras;
		r.SetCode(palabras);

		is >> num_puntos;

		for(int i = 0; i < num_puntos; i++){
		  	is >> punto;
		  	r.Insertar(punto);
		}

	}
	
	return is;

}

ostream & operator << (ostream &os, const Ruta &r){
		
	if(os){
		Ruta::const_iterator it;
	    
		 os << r.GetCode() << " ";
		os << r.size() << " ";

		for (it=r.begin(); it!=r.end(); ++it){
			os << (*it);
		}

		os << endl;
	}

	return os;
}
