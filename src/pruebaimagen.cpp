#include "../include/imagen.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc != 2) {
	cout << "Numero de argumentos introducidos erronenos. Debe introducir una imagen." << endl;
	exit(0);
  }

  Imagen I;

  I.LeerImagen(argv[1]);

  
  I.EscribirImagen("prueba.ppm");
}
  
  
