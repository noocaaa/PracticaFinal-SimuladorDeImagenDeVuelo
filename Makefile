SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
TDA = $(OBJ)/almacen_rutas.o $(OBJ)/punto.o $(OBJ)/ruta.o
IMG = $(OBJ)/imagen.o $(OBJ)/imagenES.o
TBN = $(BIN)/rutas_aereas $(BIN)/pruebarutas $(BIN)/pruebaimagen $(BIN)/pruebapegado $(BIN)/pruebarotacion
CPPFLAGS = -Wall -g  -I$(INC) -c

#cuando hacemos make, limpia lo que teniamos con anterioridad y construimos el ejecutable de rutas_aereas y los de las pruebas
all: clean $(TBN)

#--------------------------------------------------------------------------------------------- RUTAS AEREAS ---------------------------------------------------------------------------------------------

$(BIN)/rutas_aereas: $(IMG) $(TDA) $(OBJ)/rutas_aereas.o
	$(CXX) -o $(BIN)/rutas_aereas $(IMG) $(TDA) $(OBJ)/rutas_aereas.o

$(OBJ)/rutas_aereas.o: $(SRC)/rutas_aereas.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/rutas_aereas.cpp  -o $(OBJ)/rutas_aereas.o

#--------------------------------------------------------------------------------------------- PRUEBA RUTAS ---------------------------------------------------------------------------------------------

$(BIN)/pruebarutas: $(IMG) $(TDA) $(OBJ)/pruebarutas.o
	$(CXX) -o $(BIN)/pruebarutas $(IMG) $(TDA) $(OBJ)/pruebarutas.o

$(OBJ)/pruebarutas.o: $(SRC)/pruebarutas.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/pruebarutas.cpp  -o $(OBJ)/pruebarutas.o 

#--------------------------------------------------------------------------------------------- PRUEBA IMAGEN --------------------------------------------------------------------------------------------

$(BIN)/pruebaimagen: $(IMG) $(TDA) $(OBJ)/pruebaimagen.o
	$(CXX) -o $(BIN)/pruebaimagen $(IMG) $(TDA) $(OBJ)/pruebaimagen.o

$(OBJ)/pruebaimagen.o: $(SRC)/pruebaimagen.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/pruebaimagen.cpp  -o $(OBJ)/pruebaimagen.o 

#----------------------------------------------------------------------------------------- PRUEBA PEGADO IMAGEN -----------------------------------------------------------------------------------------

$(BIN)/pruebapegado: $(IMG) $(TDA) $(OBJ)/pruebapegado.o 
	$(CXX) -o $(BIN)/pruebapegado $(IMG) $(TDA) $(OBJ)/pruebapegado.o

$(OBJ)/pruebapegado.o: $(SRC)/pruebapegado.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/pruebapegado.cpp  -o $(OBJ)/pruebapegado.o 

#-------------------------------------------------------------------------------------------- PRUEBA ROTACIÓN -------------------------------------------------------------------------------------------

$(BIN)/pruebarotacion: $(IMG) $(TDA) $(OBJ)/pruebarotacion.o 
	$(CXX) -o $(BIN)/pruebarotacion $(IMG) $(TDA) $(OBJ)/pruebarotacion.o

$(OBJ)/pruebarotacion.o: $(SRC)/pruebarotacion.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/pruebarotacion.cpp  -o $(OBJ)/pruebarotacion.o 

#------------------------------------------------------------------------------------------------ IMAGEN ------------------------------------------------------------------------------------------------

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS)  $(SRC)/imagen.cpp  -o $(OBJ)/imagen.o	

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS)  $(SRC)/imagenES.cpp  -o $(OBJ)/imagenES.o		

#------------------------------------------------------------------------------------------- OBJETOS DEL TDA --------------------------------------------------------------------------------------------

$(OBJ)/punto.o: $(SRC)/punto.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/punto.cpp  -o $(OBJ)/punto.o		

$(OBJ)/ruta.o: $(SRC)/ruta.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/ruta.cpp  -o $(OBJ)/ruta.o		

$(OBJ)/almacen_rutas.o: $(SRC)/almacen_rutas.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/almacen_rutas.cpp  -o $(OBJ)/almacen_rutas.o		

#------------------------------------------------------------------------------------------------ PAISES ------------------------------------------------------------------------------------------------

$(OBJ)/pais.o: $(SRC)/pais.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/pais.cpp  -o $(OBJ)/pais.o	

$(OBJ)/paises.o: $(SRC)/paises.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/paises.cpp  -o $(OBJ)/paises.o	

#--------------------------------------------------------------------------------------------- DOCUMENTACION --------------------------------------------------------------------------------------------

documentacion:
	doxygen doc/doxys/Doxyfile

#----------------------------------------------------------------------------------------------- LIMPIEZA -----------------------------------------------------------------------------------------------

clean :
	echo Limpiando ficheros en obj, src y include.
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	echo Limpiando la documclentación y ficheros en bin.
	-rm $(BIN)/* doc/html/*

#---------------------------------------------------------------------------------- INSTRUCCIONES PARA PROBAR LOS BIN -----------------------------------------------------------------------------------

# Para el fichero rutas_aereas

#./bin/rutas_aereas datos/paises.txt datos/imagenes/mapas/mapa1.ppm datos/imagenes/banderas/ datos/almacen_rutas.txt datos/imagenes/aviones/avion1.ppm datos/imagenes/aviones/mascara_avion1.pgm

# Para el fichero pruebapegado

# ./bin/pruebapegado datos/imagenes/mapas/mapa1.ppm datos/imagenes/aviones/avion1.ppm datos/imagenes/aviones/mascara_avion1.pgm imagensalida 50 50 0

# Para el fichero pruebarotacion

#./bin/pruebarotacion datos/imagenes/aviones/avion1.ppm 45 salidaimagen

