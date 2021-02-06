/**
 * @ file : punto.h
 * @brief: TDA Punto
 * */


#ifndef __PUNTO_H
#define __PUNTO_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/**
  *  @brief T.D.A. Punto
  *
  * Una instancia @e p del tipo de datos @p Punto es un objeto
  * formado por la latitud y la longitud. 
  *
  *
  *
  *
  * @author Irene Muñoz Domingo & Noelia Carrasco Vilar
  * @date Enero 2021
  */

class Punto {
	private:

		double latitud, longitud;

	public:

		/**
		  * @brief  Constructor de punto
		  */
		Punto();

		/**
		  * @brief Constructor por parámetros.
		  * @param l: latitud con la que se desea inicializar el punto.
		  * @param L: longitud con la que se desea inicializar el punto.
		  * @param d 
		  * @return devuelve los puntos de la ruta. 
		  */
		Punto (double l, double L, string d);

		/**
		  * @brief Obtención de la latitud de un punto.
		  * @return devuelve la latitud de un punto. 
		  */
		double GetLatitud() const;

		/**
		  * @brief Obtención de la longitud de un punto.
		  * @return devuelve la longitud de un punto. 
		  */
		double GetLongitud() const;

		/**
		  * @brief Asigna una latitud a un punto.
		  * @param l: valor que se desea asignar a la latitud.
		  */
		void SetLatitud(double l) ;

		/**
		  * @brief Asigna una longitud a un punto.
		  * @param l: valor que se desea asignar a la longitud.
		  */
		void SetLongitud (double l) ;

		/**
		  * @brief Comprueba si un punto es menor que otro.
		  * @param p: punto con el quese desea comparar.
		  * @return devuelve TRUE si es menor, FALSE en caso contrario. 
		  */
		bool operator< (const Punto &p) const;
		
		/**
		  * @brief Comprueba si dos puntos son iguales.
		  * @param p: punto con el quese desea comparar.
		  * @return devuelve TRUE si es igual, FALSE en caso contrario. 
		  */
		bool operator == (const Punto &p) const ;

		/**
		  * @brief operador >>.
		  * @param is: fichero a utilizar.
		  * @param p: punto con el que se desea escribir.
		  * @return devuelve el fichero actualizado (el flujo de entrada).
		  */
		friend istream & operator >> (istream & is, Punto &p);
		
		/**
		  * @brief operador <<.
		  * @param os: fichero a utilizar.
		  * @param p: punto a leer.
		  * @return devuelve el fichero (el flujjo de salida).
		  */
		friend ostream & operator << (ostream & os, const Punto &p);
};

#endif
