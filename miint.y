%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "stackElement.h"
#include "stack.h"
#include "GestorDeMemoria.h"
#include <typeinfo>
#include <cstdarg>


// stuff from flex that bison needs to know about:
extern int yylex();
extern int yyparse();
extern FILE *yyin;
GestorDeMemoria mem;
Stack stack;
void yyerror(const char *s);
FILE *qFile = fopen ( "fichero.q.c", "w+");
void gc(const char* code, ...);
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
%token SUMA RESTA MULTIPLICACION DIVISION CONCATENACION
%token <cad> IDENTIFICADOR
%token CAD ENT
%token <ent> NUMERO
%token <cad> RISTRA
%type <cad> identi operacioncad
%type <ent> suma resta division multiplicacion operacionent cond

%%
// this is the actual grammar that bison will parse, but for right now it's just
// something silly to echo to the screen what bison gets from flex.  We'll
// make a real one shortly:
vod:
	{gc("BEGIN\n");}
	body   
	{gc("END\n");}
	;

body:
	body declarefunc
	| declarefunc
	| sentencias
	| body sentencias
	;
//los conflictos empezaron despues de añadir sentencias
//la ultima regla genero muchos conflictos
sentencias:
	sentencias declare PYCOMA
	| sentencias inicializar PYCOMA
	| sentencias callfunc PYCOMA
	| sentencias operacionent PYCOMA
	| sentencias operacioncad PYCOMA
	| sentencias escaneo PYCOMA
	| sentencias imprime PYCOMA
	| sentencias si
	| sentencias mientras 
	|
	;

si:
	SI ABREPAR cond CIERRAPAR ABRECOR sentencias CIERRACOR {printf("%d\n", $3);}
	;

mientras:
	MIENTRAS ABREPAR cond CIERRAPAR ABRECOR sentencias CIERRACOR {printf("%d\n", $3);}
	;

cond:	
	identi MAYORQUE identi 
	{
	if(strcmp(stack.getStackElement($1).getType(), "ent")==0 && strcmp(stack.getStackElement($3).getType(), "ent")==0){
		if(stack.getEntValue($1)>stack.getEntValue($3)){
			$$ = 1;
		} else {
			$$ = 0;
		}
	}
	}
	| identi MENORQUE identi 
	{
	if(strcmp(stack.getStackElement($1).getType(), "ent")==0 && strcmp(stack.getStackElement($3).getType(), "ent")==0){
		if(stack.getEntValue($1)<stack.getEntValue($3)){
			$$ = 1;
		} else {
			$$ = 0;
		}
	}
	}
	| identi IGUAL identi 
	{
	if(strcmp(stack.getStackElement($1).getType(), "ent")==0 && strcmp(stack.getStackElement($3).getType(), "ent")==0){
		if(stack.getEntValue($1)==stack.getEntValue($3)){
			$$ = 1;
		} else {
			$$ = 0;
		}
	}
	}
	| identi DIFERENTE identi 
	{
	if(strcmp(stack.getStackElement($1).getType(), "ent")==0 && strcmp(stack.getStackElement($3).getType(), "ent")==0){
		if(stack.getEntValue($1)!=stack.getEntValue($3)){
			$$ = 1;
		} else {
			$$ = 0;
		}
	}
	}
	;

//completar funciones escanear e imprimir
escaneo:
	ESCANEAR ABREPAR CIERRAPAR {}
	;

imprime:
	IMPRIMIR ABREPAR IDENTIFICADOR CIERRAPAR 
	{
	if(!stack.exists($3)){
		printf("la variable no existe\n");
	} else {
	if(strcmp(stack.getStackElement($3).getType(), "cad")==0){
		printf("%s\n",stack.getCadValue($3));
	}	
	}
	}
	;

callfunc:
	IDENTIFICADOR ABREPAR CIERRAPAR {}
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

operacioncad:
	RISTRA CONCATENACION RISTRA
	{
		char* j= strcat($1, $3);
		printf("%s\n", j);
	}
	
	
	| identi CONCATENACION identi
	{
	if(strcmp(stack.getStackElement($1).getType(), "cad")==0 && strcmp(stack.getStackElement($3).getType(), "cad")==0){
		$$ = strcat(stack.getCadValue($1), stack.getCadValue($3));
	}
	;
	}
	;

suma:
	identi SUMA identi 
	{
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
		gc("\tMEM(0x%s, %d);\n", mem.cogerDireccionDeMemoria(), 4);
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
		stack.addStackElement($3, "cad");	
	}
	}
	;
//hay que saber si se escanea cadena o enteros
inicializar:
	inicializar inicializarent
	| inicializar inicializarcad
	| IDENTIFICADOR ASIGNACION escaneo {}
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
			gc("\tR%d=%d;\n", stack.getEntValue($3), $1);
			stack.addEntValue(stack.getEntValue($3), $1);
	}
	}
	}
	|IDENTIFICADOR ASIGNACION NUMERO {
	
	if(!stack.exists($1)){
		printf("la variable no existe\n");
	} else {
		gc("\tR%d=%d;\n", mem.devuelveRegistroLibre(), $3);
		stack.addEntValue($3, $1);
	}	
	
	}
	| IDENTIFICADOR ASIGNACION operacionent 
	{
	if(!stack.exists($1)){
		printf("la variable no existe\n");
	} else {
		printf("ha\n");
		gc("\tR%d=%d;\n", mem.devuelveRegistroLibre(), $3);
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
	|
	IDENTIFICADOR ASIGNACION operacioncad
	{
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

void gc(const char* code, ...){
	printf("dentro\n");
	va_list args;
	va_start (args, code);
	vfprintf(qFile, code, args);
	va_end (args);
}

void yyerror(const char *s) {
	printf("error sintactico: %s\n", s);
}
