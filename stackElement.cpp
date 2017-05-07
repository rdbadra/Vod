#include "stackElement.h"
#include <iostream>
#include <cstring>
#include <vector> 
#include <sstream>

using namespace std;

int y = 0;

StackElement::StackElement(const char nombre[], const char tipo[]){
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

char* StackElement::getCadValue(){
	return cadValue;
}

int StackElement::getEntValue(){
	return entValue;
}

void StackElement::addEntValue(int x){
	y = x;
	entValue = y;
}

void StackElement::addCadValue(const char *val){
	strcpy(cadValue, val);
}
