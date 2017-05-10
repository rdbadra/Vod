#include "stackElement.h"
#include <iostream>
#include <cstring>
#include <vector> 
#include <sstream>

using namespace std;

StackElement::StackElement(const char nombre[], const char tipo[], int direc){
	direccion = direc;
	strcpy(name, nombre);
	strcpy(type, tipo); 
}

char* StackElement::getName(){
	//addEntValue(8);
	return name;
}

char* StackElement::getType(void){
	return type;
}

int StackElement::getAddress(void){
	return direccion;
}

