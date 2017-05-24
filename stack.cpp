#include "stackElement.h"
#include "stack.h"
#include <iostream>
#include <cstring>
#include <vector> 
 
using namespace std;

void Stack::printStack(void){
	cout << "printing stack" << endl;
	cout << "BEGIN" << endl;

	int size = variableStack.size();
	for(int i = 0; i < size; i++){
		Variable el = variableStack.at(i);
		cout << "name: " << el.getName();
		cout << " type: " << el.getTipo();
		cout << " context: " << el.getContext();
		cout << " address: " << el.getDireccion();
		cout << endl;
	}

	int size1 = funcionStack.size();
	for(int i = 0; i < size1; i++){
		Funcion el = funcionStack.at(i);
		cout << "name: " << el.getName();
		cout << " label: " << el.getEtiqueta();
		cout << " used space: " << el.getEspacioParaLasVariables();
		cout << endl;
	}
	cout << "END" << endl;
}


int Stack::size(void){
	return (variableStack.size() + funcionStack.size());
}

void Stack::cleanDinamicStack(const char * name){
	int size = variableStack.size();
	for(int i = 0; i < size; i++){
		if(strcmp(variableStack.at(i).getContext(), name)==0){
			size--;
			variableStack.erase(variableStack.begin()+i);
			i--;
		}
	}

}

void Stack::addVariable(const char *name, const char *type, const char* c, int direc, int s){
	//hay que comprobar si ya esta en la tabla
	variableStack.push_back(Variable(name, type, c, direc, s));
}

void Stack::setDirection(const char *name, const char *type, const char* c, int direc, int s){
	int size = variableStack.size();
	for(int i = 0; i < size; i++){
		if(strcmp(variableStack.at(i).getName(), name)==0){
			variableStack.erase(variableStack.begin()+i);
		}
	}
	variableStack.push_back(Variable(name, type, c, direc, s));
}

void Stack::addFuncion(const char *name, int etiqueta){
	//hay que comprobar si ya esta en la tabla
	funcionStack.push_back(Funcion(name, etiqueta));
}

bool Stack::existsVariable(const char *name){
	int size = variableStack.size();
	for(int i = 0; i < size; i++){
		if(strcmp(variableStack.at(i).getName(), name)==0){
			return true;
		}
	}
	return false;
}

bool Stack::existsFuncion(const char *name){
	int size = funcionStack.size();
	for(int i = 0; i < size; i++){
		if(strcmp(funcionStack.at(i).getName(), name)==0) return true;
	}
	return false;
}

Variable Stack::getVariable(const char *name){
	int size = variableStack.size();
	for(int i = 0; i < size; i++){
		if(strcmp(variableStack.at(i).getName(), name)==0) return variableStack.at(i);
	}
}

Funcion Stack::getFuncion(const char *name){
	int size = funcionStack.size();
	for(int i = 0; i < size; i++){
		if(strcmp(funcionStack.at(i).getName(), name)==0) return funcionStack.at(i);
	}
}
