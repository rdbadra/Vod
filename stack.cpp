#include "stackElement.h"
#include "stack.h"
#include <iostream>
#include <cstring>
#include <vector> 
 
using namespace std;

EntValue::EntValue(int val, const char* n){
	value = val;
	strcpy(name, n);
}

int EntValue::getValue(){
	return value;
}

char* EntValue::getName(){
	return name;
}

void Stack::printStack(void){
	//cout << "printing stack" << endl;
	int size = stack.size();
	for(int i = 0; i < size; i++){
		StackElement el = stack.at(i);
		cout << "name: " << el.getName();
		cout << " type: " << el.getType();
		cout << " value ent: " << getEntValue(el.getName()) << endl;
		//cout << " value cad: " << el.getCadValue() << endl;
	}
	/*int size1 = entStack.size();
	for(int i = 0; i < size1; i++){
		cout << "name: " << entStack.at(i).getName();
		cout << " value ent: " << entStack.at(i).getValue() << endl;
		//cout << " value cad: " << el.getCadValue() << endl;
	}*/
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

int Stack::getEntValue(const char *name){
	int size = entStack.size();
	//cout << "size: " << size << endl;
	for(int i = 0; i < size; i++){
		//cout << "nombre: " << entStack.at(i).getName() << endl;
		if(strcmp(entStack.at(i).getName(), name)==0) return entStack.at(i).getValue();
	}
}

void Stack::addEntValue(int x, const char *name){
	cout << x << " add " << name << endl;
	entStack.push_back(EntValue(x, name));
}

