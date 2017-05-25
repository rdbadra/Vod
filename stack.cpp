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
		cout << " ambito: " << el.getAmbito();
		cout << " address: " << el.getDireccion();
		cout << endl;
	}

	int size1 = funcionStack.size();
	for(int i = 0; i < size1; i++){
		Funcion el = funcionStack.at(i);
		cout << "name: " << el.getName();
		cout << " label: " << el.getEtiqueta();
		cout << " stack: " << el.getPila();
		cout << endl;
	}
	cout << "END" << endl;
}

int Stack::getLastPosition(){
	int size = variableStack.size();
	return variableStack.at(size-1).getDireccion();

}


int Stack::size(void){
	return (variableStack.size() + funcionStack.size());
}

void Stack::cleanDinamicStack(int context){
	int size = variableStack.size();
	for(int i = 0; i < size; i++){
		if(variableStack.at(i).getAmbito()==context){
			size--;
			variableStack.erase(variableStack.begin()+i);
			i--;
		}
	}

}

void Stack::setPila(int p, int eti, char *n){
	int pil;
	int size = funcionStack.size();
	for(int i = 0; i < size; i++){
		if(funcionStack.at(i).getEtiqueta()==eti){
			size--;
			pil = funcionStack.at(i).getPila();
			funcionStack.erase(funcionStack.begin()+i);
			i--;
		}
	}
	
	p = p + pil;
	funcionStack.push_back(Funcion(n, eti, p));
}

void Stack::addVariable(const char *name, const char *type, const char* c, int amb, int direc, int s){
	//hay que comprobar si ya esta en la tabla
	variableStack.push_back(Variable(name, type, c, amb, direc, s));
}

void Stack::addFuncion(const char *name, int etiqueta, int pila){
	//hay que comprobar si ya esta en la tabla
	funcionStack.push_back(Funcion(name, etiqueta, pila));
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
Variable Stack::getVariableWithContext(const char *name, int context){
	int size = variableStack.size();
	for(int i = 0; i < size; i++){
		if(strcmp(variableStack.at(i).getName(), name)==0 && variableStack.at(i).getAmbito()==context) return variableStack.at(i);
	}

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
