#include "stackElement.h"
#include "stack.h"
#include <iostream>
#include <cstring>
#include <vector> 
 
using namespace std;


StackElement::StackElement(const char nombre[], const char tipo[]){
	strcpy(name, nombre);
	strcpy(type, tipo); 
	//cout << "Object is being created" << endl;
	//cout << name << endl;
}

char* StackElement::getName(void){
	return name;
}

char* StackElement::getType(void){
	return type;
}

void Stack::printStack(void){
	cout << "printing stack" << endl;
	int size = stack.size();
	for(int i = 0; i < size; i++){
		cout << "name: " << stack.at(i).getName();
		cout << " type: " << stack.at(i).getType() << endl;
	}
}

int Stack::size(void){
	return stack.size();
}

void Stack::addStackElement(const char *name, const char *type){
	//hay que comprobar si ya esta en la tabla
	stack.push_back(StackElement(name, type));
}

bool Stack::exists(const char *name){
	int size = stack.size();
	for(int i = 0; i < size; i++){
		if(strcmp(stack.at(i).getName(), name)==0) return true;
	}
	return false;
}

StackElement Stack::getStackElement(const char *name){
	int size = stack.size();
	for(int i = 0; i < size; i++){
		if(strcmp(stack.at(i).getName(), name)==0) return stack.at(i);
	}
}


// Main function for the program

