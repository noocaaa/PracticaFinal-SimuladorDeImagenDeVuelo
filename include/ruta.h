/**
 * @ file : ruta.h
 * @brief: TDA Rutas
 * */


#ifndef __RUTAS_H
#define __RUTAS_H

#include <string>
#include <list>
#include <iostream> 

#include "punto.h"

/**
  *  @brief T.D.A. Ruta
  *
  * Una instancia @e r del tipo de datos abstracto @r Rutas es un objeto
  * formado por diversos puntos y un codigo de ruta. 
  *
  *
  *
  *
  * @author Irene Muñoz Domingo & Noelia Carrasco Vilar
  * @date Enero 2021
  */

class Ruta{
private:
	list<Punto> puntos; //lista de puntos de la ruta (latitud-longitud) 
	string code;//codigo de la ruta

public:

	/**
	  * @brief Constructor de una ruta. 
	  */
	Ruta(){}

	/**
	  * @brief Insertar un nuevo punto a una ruta. 
	  * @param p: punto que se desea insertar. 
	  */
	void Insertar(const Punto &p);

	/**
	  * @brief Borrar un punto de una ruta. 
	  * @param p: punto que se desea eliminar de la ruta.
	  */
	void Borrar(const Punto &p);

	/**
	  * @brief Obtención de un código de una ruta. 
	  * @return devuelve el código asociado a una ruta. 
	  */
	string GetCode() const;
	
	/**
	  * @brief Obtención de los puntos de una ruta.
	  * @param ruta: ruta que se desea obtener del conjunto de rutas.
	  * @return devuelve los puntos de la ruta. 
	  */
	list<Punto> GetPuntos() const;

	/**
	  * @brief Asigna un código a una ruta.
	  * @param newcode: código que se desea poner a la ruta.
	  */
	void SetCode(const string &newcode);

	/**
	  * @brief Comprueba si dos rutas son iguales.
	  * @param r: ruta con la que se desea comparar.
	  * @return devuelve TRUE si son iguales, FALSE en caso contrario. 
	  */
	bool operator == (const Ruta &r)const;

	/**
	  * @brief Comprueba si una ruta es menor que otra.
	  * @param r: ruta con la que se desea comparar.
	  * @return devuelve TRUE si es menor, FALSE en caso contrario. 
	  */
	bool operator < (const Ruta &r) const;

	/** 
	  * @brief  Tamaño de la ruta. 
	  * @return el numero de rutas. 
	  */
	int size() const;

	/**
	  * @brief clase para iterar sobre el almacen de rutas
	  */
	class iterator{
		private:
			typename list<Punto > :: iterator it;
		public:
			iterator(){}

			iterator & operator++() {
				++it;
				return *this;
			}

			iterator & operator--() {
				--it;
				return *this;
			}

			const Punto & operator*() {
				return *it;
			}

			bool operator==(const iterator &i) const{
				return it==i.it;
			}

			bool operator!=(const iterator &i) const{
				return it!=i.it;
			}

		friend class Ruta;
	};

	/**
	  * @brief clase para iterar sobre el almacen de rutas
	  */
	class const_iterator{
		private:
			typename list<Punto > :: const_iterator it;
		public:

			const_iterator() {}

			const_iterator & operator++() {
				++it;
				return *this;
			}

			const_iterator & operator--() {
				--it;
				return *this;
			}

			const Punto & operator*() {
				return *it;
			}

			bool operator==(const const_iterator &i) const{
				return it==i.it;
			}

			bool operator!=(const const_iterator &i) const{
				return it!=i.it;
			}

		friend class Ruta;
	};

	/**
	  * @brief Inicializa un iterator al comienzo de la ruta
 	  * @return devuelve un iterator que apunta al inicio de la ruta
	  */
	iterator begin(){
		iterator i;
		i.it = puntos.begin();
		return i;
	}

	/**
	  * @brief Inicializa un iterator al final de la ruta
 	  * @return devuelve un iterator que apunta al final de la ruta
	  */
	iterator end(){
		iterator i;
		i.it = puntos.end();
		return i;
	}

	/**
	  * @brief Inicializa un const_iterator al comienzo de la ruta
 	  * @return devuelve un const_iterator que apunta al inicio de la ruta
	  */
	const_iterator begin() const {
		const_iterator i;
		i.it = puntos.begin();
		return i;
	}

	/**
	  * @brief Inicializa un const_iterator al final de la ruta
 	  * @return devuelve un const_iterator que apunta al final de la ruta
	  */
	const_iterator end() const{
		const_iterator i;
		i.it = puntos.end();
		return i;
	}

	/**
	  * @brief Buscar un punto.
	  * @param p: punto que se desea buscar.
	  * @return iterator apuntando a dicho punto. 
	  */
	iterator find(const Punto &p){
		iterator it2;
		list<Punto>::iterator i;
		for (i=puntos.begin(); i!=puntos.end() && !((*i)==p);++i);
		it2.it=i;
		return it2;
	}

	/**
	  * @brief Operador >>.
	  * @param is: fichero a utilizar.
	  * @param r: ruta que se desea escribir.
	  * @return devuelve el fichero actualizado (el flujo de entrada).
	  */
	friend istream & operator >> (istream &is, Ruta &r);

	/**
	  * @brief Operador <<.
	  * @param os: fichero a utilizar.
	  * @param r: ruta que se desea leer.
	  * @return devuelve el fichero (el flujo de salida). 
	  */
	friend ostream & operator << (ostream &os, const Ruta &r);
};

#endif
