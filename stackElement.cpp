#include "stackElement.h"
#include <iostream>
#include <cstring>
#include <vector> 
#include <sstream>

using namespace std;
//variable
Variable::Variable(const char* n, const char* t, const char* c, int amb, int d, int s){
	strcpy(name, n);
	strcpy(tipo, t);
	strcpy(context, c);
	direccion = d;
	ambito = amb;
	size = s;
}

int Variable::getAmbito(){
	return ambito;
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

int Variable::getSize(){
	return size;
}

//funcion
Funcion::Funcion(const char* n, int etiq, int p){
	strcpy(name, n);
	etiqueta=etiq;
	pila=p;
}

char* Funcion::getName(){
	return name;
}

int Funcion::getEtiqueta(){
	return etiqueta;
}

int Funcion::getPila(){
	return pila;
}
