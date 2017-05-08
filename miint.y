%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "stackElement.h"
#include "stack.h"
#include <typeinfo>


// stuff from flex that bison needs to know about:
extern int yylex();
extern int yyparse();
extern FILE *yyin;
Stack stack;
void yyerror(const char *s);
%}

// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  But tokens could be of any
// arbitrary data type!  So we deal with that in Bison by defining a C union
// holding each of the types of tokens that Flex could return, and have Bison
// use that union instead of "int" for the definition of "yystype":
%union {
	int ent;
	char *cad;
}

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token SI MIENTRAS
%token MAYORQUE MENORQUE IGUAL DIFERENTE
%token ESCANEAR IMPRIMIR
%token DECLAR ASIGNACION PYCOMA FUNCION ABREPAR CIERRAPAR ABRECOR CIERRACOR
%token SUMA RESTA MULTIPLICACION DIVISION
%token <cad> IDENTIFICADOR
%token CAD ENT
%token <ent> NUMERO
%token <cad> RISTRA
%type <cad> identi
%type <ent> suma resta division multiplicacion operacionent

%%
// this is the actual grammar that bison will parse, but for right now it's just
// something silly to echo to the screen what bison gets from flex.  We'll
// make a real one shortly:
vod:
	body      
	;

body:
	sentencias
	;
//los conflictos empezaron despues de añadir sentencias
//la ultima regla genero muchos conflictos
sentencias:
	sentencias declare PYCOMA
	| sentencias inicializar PYCOMA
	| sentencias declarefunc
	| sentencias callfunc PYCOMA
	| sentencias operacionent PYCOMA
	| sentencias escaneo PYCOMA
	| sentencias imprime PYCOMA
	| sentencias si
	| sentencias mientras 
	|
	;

si:
	SI ABREPAR cond CIERRAPAR ABRECOR sentencias CIERRACOR {printf("si\n");}
	;

mientras:
	MIENTRAS ABREPAR cond CIERRAPAR ABRECOR sentencias CIERRACOR {printf("mientras\n");}
	;

cond:	
	identi MAYORQUE identi {printf("MAYORQUE\n");}
	| identi MENORQUE identi {printf("MENORQUE\n");}
	| identi IGUAL identi {printf("IGUAL\n");}
	| identi DIFERENTE identi {printf("DIFERENTE\n");}
	;

//completar funciones escanear e imprimir
escaneo:
	ESCANEAR ABREPAR CIERRAPAR {printf("escanear\n");}
	;

imprime:
	IMPRIMIR ABREPAR IDENTIFICADOR CIERRAPAR {printf("imprimir\n");}
	;

callfunc:
	IDENTIFICADOR ABREPAR CIERRAPAR {printf("llamada a funcion\n");}
	;

operacionent:
	operacionent resta
	| operacionent multiplicacion
	| operacionent division
	| operacionent suma
	| operacionent ABREPAR operacionent CIERRAPAR
	| suma
	| resta
	| multiplicacion
	| division
	;

suma:
	identi SUMA identi 
	{
	//hay que comprobar si la variable es ent o cad para ver si es suma o concatenacion
	if(strcmp(stack.getStackElement($1).getType(), "ent")==0 && strcmp(stack.getStackElement($3).getType(), "ent")==0){
		$$ = stack.getEntValue($1) + stack.getEntValue($3);
	}
	;
	}
	| NUMERO SUMA NUMERO {$$=$1+$3;}
	;

identi:
	identi IDENTIFICADOR	{$$=$2;}
	| IDENTIFICADOR		{$$=$1;}
	| identi ABREPAR identi CIERRAPAR {$$ = $3;}
	| ABREPAR identi CIERRAPAR {$$ = $2;}
	;

resta:
	identi RESTA identi 
	{
	if(strcmp(stack.getStackElement($1).getType(), "ent")==0 && strcmp(stack.getStackElement($3).getType(), "ent")==0){
		$$ = stack.getEntValue($1) - stack.getEntValue($3);
	}
	;
	}
	| NUMERO RESTA NUMERO {$$=$1-$3;}
	;

multiplicacion:
	identi MULTIPLICACION identi 
	{
	if(strcmp(stack.getStackElement($1).getType(), "ent")==0 && strcmp(stack.getStackElement($3).getType(), "ent")==0){
		$$ = stack.getEntValue($1) * stack.getEntValue($3);
	}
	;
	}
	| NUMERO MULTIPLICACION NUMERO {$$=$1*$3;}
	;

division:
	identi DIVISION identi 
	{
	if(strcmp(stack.getStackElement($1).getType(), "ent")==0 && strcmp(stack.getStackElement($3).getType(), "ent")==0){
		$$ = stack.getEntValue($1) / stack.getEntValue($3);
	}
	;
	}
	| NUMERO DIVISION NUMERO {$$=$1-$3;}
	;
	

declare:
	declare declareent
	| declare declarecad
	| declarecad
	| declareent
	;

declarefunc:
	FUNCION IDENTIFICADOR ABREPAR CIERRAPAR ABRECOR sentencias CIERRACOR 
	{
	if(stack.exists($2)){
		printf("ya existe\n");
	} else {
		stack.addStackElement($2, "func");	
	}
	}
	;

declareent:
	DECLAR ENT IDENTIFICADOR	
	{
	if(stack.exists($3)){
		printf("ya existe\n");
	} else {
		//printf("adding %s\n", $3);
		stack.addStackElement($3, "ent");	
	}
	}
	;

declarecad:
	DECLAR CAD IDENTIFICADOR	
	{
	if(stack.exists($3)){
		printf("ya existe\n");
	} else {
		printf("adding %s\n", $3);
		stack.addStackElement($3, "cad");	
	}
	}
	;
//hay que saber si se escanea cadena o enteros
inicializar:
	inicializar inicializarent
	| inicializar inicializarcad
	| IDENTIFICADOR ASIGNACION escaneo {printf("escaneando\n");}
	| inicializarent
	| inicializarcad
	;

inicializarent:
	IDENTIFICADOR ASIGNACION identi 
	{
	if(!stack.exists($1)){
		printf("la variable no existe\n");
	} else {
		if(!stack.exists($3)){
			printf("la variable no existe\n");
		} else {
			stack.addEntValue(stack.getEntValue($3), $1);
	}
	}
	}
	|IDENTIFICADOR ASIGNACION NUMERO {
	
	if(!stack.exists($1)){
		printf("la variable no existe\n");
	} else {
		stack.addEntValue($3, $1);
	}	
	
	}
	| IDENTIFICADOR ASIGNACION operacionent 
	{
	if(!stack.exists($1)){
		printf("la variable no existe\n");
	} else {
		stack.addEntValue($3, $1);
	}
	}
	;

inicializarcad:
	IDENTIFICADOR ASIGNACION RISTRA {
	
	if(!stack.exists($1)){
		printf("la variable no existe\n");
	} else {
		stack.addCadValue($3, $1);
	}	
	
	}
	;
%%

int main(int argc, char** argv) {
	// open a file handle to a particular file:
	if(argc>1) yyin=fopen(argv[1], "r");
	yyparse();
	stack.printStack();
	
	
}

void yyerror(const char *s) {
	printf("error sintactico: %s\n", s);
}
