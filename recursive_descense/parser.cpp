#include <iostream>
#include "data.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int currentSymbol;
void nextSymbol(void);
void error();
void declaracion();
void declaracionYInicializacionCadena();
void declaracionEntero();
void inicializacionEntero();
int numlin = 1;


void nextSymbol(void){
	currentSymbol = yylex();
}

int accept(Symbol s){
	if(currentSymbol == s){
		nextSymbol();
		return 1;
	}
	return 0;
}

int expect(Symbol s){
	if(accept(s)){
		return 1;
	}
	error();
	return 0;
}

void error() {
	printf("unexpected symbol: %d en linea: %d\n", currentSymbol, numlin);
	exit(0);
}

void program(void){
	nextSymbol();
	while(currentSymbol != 0){
		if (accept(DECLAR)){
			declaracion();
		} else if(accept(IDENTIFICADOR)){
			inicializacionEntero();

		} else {
			error();
		}
	}
}

void declaracion(void){
	if (accept(CAD)){
		declaracionYInicializacionCadena();
	}
	else if (accept(ENT)){
		declaracionEntero();
	}
}

void declaracionEntero(void){
	if (accept(IDENTIFICADOR)){
		expect(PYCOMA);
		numlin++;
	}
}

void inicializacionEntero(void){
	if(accept(ASIGNACION)){
		if(accept(NUMERO)){
			if(accept(SUMA) || accept(RESTA) || accept(MULTIPLICACION) || accept(DIVISION)){
				expect(NUMERO);
				expect(PYCOMA);
				numlin++;
			} else{
				expect(PYCOMA);
				numlin++;
			}
		}
		else if(accept(IDENTIFICADOR)){
				if(accept(SUMA) || accept(RESTA) || accept(MULTIPLICACION) || accept(DIVISION)){
					expect(IDENTIFICADOR);
					expect(PYCOMA);
					numlin++;
				} else{
					expect(PYCOMA);
					numlin++;
			}		
		}
	}
}

void declaracionYInicializacionCadena(void){
	if (accept(IDENTIFICADOR)){
		expect(ASIGNACION);
		expect(RISTRA);
		expect(PYCOMA);
		numlin++;
	}
}


int main(int argc, char** argv){

	if(argc > 1) yyin=fopen(argv[1], "r");
	program();	

	//do printf("%i \n", s = yylex()); while(s!= 0);
	//cout << ASIGNACION << endl;
	return 0;
}
