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
void inicializacionEnteroOLlamaAFuncion();
void body(void);
void bodyFunction();


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


void cond(){
	expect(IDENTIFICADOR);
	if(accept(IGUAL) || accept(MAYORQUE) || accept(MENORQUE) || accept(DIFERENTE)){
		expect(IDENTIFICADOR);
	} else {
		error();
	}
}

void si(){
	expect(ABREPAR);
	cond();
	expect(CIERRAPAR);
	expect(ABRECOR);
	bodyFunction();
	expect(CIERRACOR);
}

void mientras(){
	expect(ABREPAR);
	cond();
	expect(CIERRAPAR);
	expect(ABRECOR);
	bodyFunction();
	expect(CIERRACOR);
}

void funcion(){
	expect(IDENTIFICADOR);
	expect(ABREPAR);
	expect(CIERRAPAR);
	expect(ABRECOR);
	bodyFunction();
	expect(CIERRACOR);
}

void imprimir(){
	expect(ABREPAR);
	expect(IDENTIFICADOR);
	expect(CIERRAPAR);
	expect(PYCOMA);

}


void bodyFunction(){
	while(currentSymbol != 0 && currentSymbol != CIERRACOR){
			if (accept(DECLAR)){
				declaracion();
			} else if(accept(IDENTIFICADOR)){
				inicializacionEnteroOLlamaAFuncion();
			} else if(accept(SI)){
				si();
			} else if(accept(MIENTRAS)){
				mientras();
			} else if(accept(IMPRIMIR)){
				imprimir();
			} else {
				error();
			}
	}
}

void body(void){
	if (accept(DECLAR)){
		declaracion();
	} else if(accept(IDENTIFICADOR)){
		inicializacionEnteroOLlamaAFuncion();
	} else if(accept(SI)){
		si();
	} else if(accept(MIENTRAS)){
		mientras();
	} else if(accept(FUNCION)){
		funcion();
	} else if(accept(IMPRIMIR)){
		imprimir();
	} else {
		error();
	}
	
}

void program(void){
	nextSymbol();
	while(currentSymbol != 0){
		body();
	}

}

void declaracion(void){
	if (accept(CAD)){
		declaracionYInicializacionCadena();
	}
	else if (accept(ENT)){
		declaracionEntero();
	} else {
		error();
	}
}

void declaracionEntero(void){
	expect(IDENTIFICADOR);
	expect(PYCOMA);
	
}

void inicializacionEnteroOLlamaAFuncion(void){
	if(accept(ASIGNACION)){
		if(accept(NUMERO)){
			if(accept(SUMA) || accept(RESTA) || accept(MULTIPLICACION) || accept(DIVISION)){
				expect(NUMERO);
				expect(PYCOMA);

			} else{
				expect(PYCOMA);

			}
		} else if(accept(IDENTIFICADOR)){
				if(accept(SUMA) || accept(RESTA) || accept(MULTIPLICACION) || accept(DIVISION)){
					expect(IDENTIFICADOR);
					expect(PYCOMA);

				} else{
					expect(PYCOMA);

			}		
		} else {
			error();
		}
	} else if(accept(ABREPAR)){
		expect(CIERRAPAR);
		expect(PYCOMA);
	} else {
		error();
	}
}

void declaracionYInicializacionCadena(void){
	expect(IDENTIFICADOR);
	expect(ASIGNACION);
	if(accept(RISTRA)){
		if(accept(CONCATENACION)){
			expect(RISTRA);
		}
		expect(PYCOMA);
	} else if(accept(IDENTIFICADOR)){
			if(accept(CONCATENACION)){
				expect(IDENTIFICADOR);
			}
			expect(PYCOMA);
	} else {
		error();
	}
	
}


int main(int argc, char** argv){

	if(argc > 1) yyin=fopen(argv[1], "r");
	program();
	printf("Finalizado con exito\n");	

	return 0;
}
