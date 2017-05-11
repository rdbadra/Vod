#include "stackElement.h"
#include <iostream>
#include <cstring>
#include <vector> 
#include <sstream>

using namespace std;
//variable
Variable::Variable(const char* n, const char* t, const char* c, int d){
	strcpy(name, n);
	strcpy(tipo, t);
	strcpy(context, c);
	direccion = d;
}

char* Variable::getName(){
	return name;
}

char* Variable::getTipo(){
	return tipo;
}

char* Variable::getContext(){
	return context;
}

int Variable::getDireccion(){
	return direccion;
}

//funcion
Funcion::Funcion(const char* n, int etiq){
	strcpy(name, n);
	etiqueta=etiq;
	espacioParaLasVariables=0;
}

char* Funcion::getName(){
	return name;
}

int Funcion::getEtiqueta(){
	return etiqueta;
}

int Funcion::getEspacioParaLasVariables(){
	return espacioParaLasVariables;
}

void Funcion::setEspacioParaLasVariables(int espacio){
	espacioParaLasVariables=espacio;
}
