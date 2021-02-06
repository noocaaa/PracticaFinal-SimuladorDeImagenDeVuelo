/**
 * @ file : almacen_rutas.h
 * @brief: TDA Almacen_Rutas
 */


#ifndef __ALMACENRUTAS_H
#define __ALMACENRUTAS_H

#include "ruta.h"

#include <string>
#include <map>
#include <iostream>

using namespace std;

/**
  *  @brief T.D.A. Almacen_Rutas
  *
  * Una instancia @e a del tipo de datos abstracto @a Almacen_Rutas es un objeto
  * formado por diversos puntos que construyen unas rutas. 
  *
  *
  *
  * @author Irene Muñoz Domingo & Noelia Carrasco Vilar
  * @date Enero 2021
  */

class Almacen_Rutas{
	private:
		map<string,Ruta> rutas;
	public:

		/**
		  * @brief Constructor del almacen de rutas. 
		  */
		Almacen_Rutas(){}

		/**
		  * @brief Insertar una ruta en nuestro conjunto de rutas. 
		  * @param r: ruta que se desea insertar en el conjunto de rutas.
		  */
		void Insertar(const Ruta &r);

		/**
		  * @brief Borrar una ruta de nuestro conjunto de rutas.
		  * @param r: ruta que se desea eliminar del conjunto de rutas.
		  */
		void Borrar(const Ruta &r);

		/**
		  * @brief Obtención de una ruta. 
		  * @param ruta: ruta que se desea obtener del conjunto de rutas.
		  * @return devuelve la ruta pasada por parametro, con su código, numero de puntos y todos los puntos que contiene. 
		  */
		Ruta GetRuta(const string &ruta);


		/**
		  * @brief clase para iterar sobre el almacen de rutas
		  */
		class iterator{
		private:
			map<string,Ruta>::iterator it;
		public:
			/**
			 * @brief Operador de incremento
			 * @return devuelve el puntero a iterador que contiene el valor incrementado en uno
			 */
			iterator &operator++(){
				++it;
				return *this;
			}

			/**
			 * @brief Operador de decremento
			 * @return devuelve el puntero a iterador que contiene el valor decrementado en uno
			 */
			iterator &operator--(){
				--it;
				return *this;
			}

			/**
			 * @brief Operador de intersección
			 * @return devuelve el puntero a iterador que contiene la intersección 
			 */
			const pair<const string,Ruta> &operator*(){
				return *it;
			}

			/**
			 * @brief Operador de igualdad
			 * @return devuelve true si son iguales, false si son diferentes
			 */
			bool operator==(const iterator &i){
				return it==i.it;
			}

			/**
			 * @brief Operador de disigualdad
			 * @return devuelve true si son diferentes, false si son iguales
			 */
			bool operator!=(const iterator &i){
				return it!=i.it;
			}

			friend class Almacen_Rutas;
		};

		/**
		  * @brief clase para iterar sobre el almacen de rutas
		  */
		class const_iterator{
		private:
			map<string,Ruta>::const_iterator it;
		public:

			/**
			 * @brief Operador de incremento
			 * @return devuelve el puntero a iterador que contiene el valor incrementado en uno
			 */
			const_iterator &operator++(){
				++it;
				return *this;
			}

			/**
			 * @brief Operador de decremento
			 * @return devuelve el puntero a iterador que contiene el valor decrementado en uno
			 */
			const_iterator &operator--(){
				--it;
				return *this;
			}

			/**
			 * @brief Operador de intersección
			 * @return devuelve el puntero a iterador que contiene la intersección 
			 */
			const pair<const string,Ruta> &operator*(){
				return *it;
			}

			/**
			 * @brief Operador de igualdad
			 * @return devuelve true si son iguales, false si son diferentes
			 */
			bool operator==(const const_iterator &i){
				return it==i.it;
			}

			/**
			 * @brief Operador de disigualdad
			 * @return devuelve true si son diferentes, false si son iguales
			 */
			bool operator!=(const const_iterator &i){
				return it!=i.it;
			}

			friend class Almacen_Rutas;
		};

		/**
		  * @brief Inicializa un iterator al comienzo del almacen
		  * @return devuelve un iterator que apunta al inicio del alamcen
		  */
		iterator begin(){
			iterator i;
			i.it = rutas.begin();
			return i;
		}

		/**
		  *  @brief Inicializa un iterator al final del almacen
		  * @return devuelve un iterator que apunta al final del alamcen
		  */
		iterator end(){
			iterator i;
			i.it = rutas.end();
			return i;
		}

		/**
		  * @brief Inicializa un const_iterator al comienzo del almacen
		  * @return devuelve un const_iterator que apunta al inicio del alamcen
		  */
		const_iterator begin() const{
			const_iterator i;
			i.it = rutas.begin();
			return i;
		}

		/**
		  * @brief Inicializa un const_iterator al final del almacen
		  * @return devuelve un const_iterator que apunta al final del alamcen
		  */
		const_iterator end() const{
			const_iterator i;
			i.it = rutas.end();
			return i;
		}

		/**
		 * @brief Operador <<
		 * @param is, istream que nos servira para captar la información del fichero
		 * @param AR, almacen de rutas donde almacenaremos la información captada
		 * @return devuelve el flujo de entrada (is). 
		 */
		friend istream & operator >> (istream &is, Almacen_Rutas &AR);
		
		/**
		 * @brief Operador <<
		 * @param os, istream que nos servira para enviar la información al fichero
		 * @param AR, almacen de rutas que se introducirá en el fichero
		 * @return devuelve el flujo de salida (os). 
		 */
		friend ostream & operator << (ostream &os, Almacen_Rutas &AR);
};

#endif
