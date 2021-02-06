#include "../include/almacen_rutas.h"

void Almacen_Rutas::Insertar(const Ruta &r){
	pair <string,Ruta> rut (r.GetCode(),r);
	rutas.insert(rut);
}

void Almacen_Rutas::Borrar(const Ruta &r){
	map<string,Ruta>::iterator it = rutas.lower_bound(r.GetCode());
	rutas.erase(it);
}

Ruta Almacen_Rutas::GetRuta(const string &ruta){
	bool continuar = true;
	Ruta r; //para devolver una vacia.
	map<string,Ruta>::iterator it = rutas.begin();

	for (; it != rutas.end() && continuar; ++it) {

		if ((*it).first == ruta) {
			continuar = false;
			return (*it).second;
		}
	}

}

istream & operator >> (istream &is, Almacen_Rutas &AR){
	string mensaje;
	Ruta ruta;
	Almacen_Rutas R;

	if(is){
		getline(is,mensaje);
		if(mensaje == "#Rutas"){
			while (is >> ruta) {
	 			R.Insertar(ruta);
			}
		}
	}

	AR = R;

	return is;
}

ostream & operator << (ostream &os, Almacen_Rutas &AR){

	Almacen_Rutas::iterator it = AR.begin();
	Almacen_Rutas::iterator ita = AR.end();

	if(os){
		os << "#Rutas" << endl;
		for (; it != ita; ++it) {
			os << AR.GetRuta((*it).first) <<endl;			
		}

	}
	return os;
}
