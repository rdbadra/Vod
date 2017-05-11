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
%token DECLAR ASIGNACION PYCOMA FUNCION ABREPAR CIERRAPAR ABRECOR CIERRACOR COMILLAS
%token SUMA RESTA MULTIPLICACION DIVISION CONCATENACION
%token <cad> IDENTIFICADOR RISTRA
%token CAD ENT
%token <ent> NUMERO
%type <cad> identi operacioncad ristra
%type <ent> suma resta division multiplicacion operacionent cond

%%
// this is the actual grammar that bison will parse, but for right now it's just
// something silly to echo to the screen what bison gets from flex.  We'll
// make a real one shortly:
vod:
	{gc("#include \"Q.h\"\n");
	gc("#define INI 0\n");
	gc("#define FIN -2\n");
	gc("BEGIN\n");
	}
	body  
	{gc("\tR0=0;\n");
	{gc("\tGT(-2);\n");
	gc("END\n");}
	}
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
	if(strcmp(stack.getVariable($1).getTipo(), "ent")==0 && strcmp(stack.getVariable($3).getTipo(), "ent")==0){

	}
	}
	| identi MENORQUE identi 
	{
		if(strcmp(stack.getVariable($1).getTipo(), "ent")==0 && strcmp(stack.getVariable($3).getTipo(), "ent")==0){

		}
	
	}
	| identi IGUAL identi 
	{
	if(strcmp(stack.getVariable($1).getTipo(), "ent")==0 && strcmp(stack.getVariable($3).getTipo(), "ent")==0){

	}
	
	}
	| identi DIFERENTE identi 
	{
	if(strcmp(stack.getVariable($1).getTipo(), "ent")==0 && strcmp(stack.getVariable($3).getTipo(), "ent")==0){

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
	if(!stack.existsVariable($3)){
		printf("la variable no existe\n");
	} else {
		if(strcmp(stack.getVariable($3).getTipo(), "cad")==0){
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
	ristra CONCATENACION ristra
	{
		char* j= strcat($1, $3);
		printf("%s\n", j);
	}
	
	
	| identi CONCATENACION identi
	{
	if(strcmp(stack.getVariable($1).getTipo(), "cad")==0 && strcmp(stack.getVariable($3).getTipo(), "cad")==0){
	}
	;
	}
	;

suma:
	identi SUMA identi 
	{
	if(strcmp(stack.getVariable($1).getTipo(), "ent")==0 && strcmp(stack.getVariable($3).getTipo(), "ent")==0){
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=I(0x%x);\n", res, stack.getVariable($1).getDireccion());
		gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
		gc("\tR%d=R%d+R%d;\n", res, res, add);
		$$ = res;
		mem.liberaRegistro(add);
		
	}
	;
	}
	| NUMERO SUMA NUMERO 
	{
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=%d;\n", res, $1);
		gc("\tR%d=%d;\n", add, $3);
		gc("\tR%d=R%d+R%d;\n", res, res, add);
		$$ = res;
		mem.liberaRegistro(add);
	}
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
	if(strcmp(stack.getVariable($1).getTipo(), "ent")==0 && strcmp(stack.getVariable($3).getTipo(), "ent")==0){
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=I(0x%x);\n", res, stack.getVariable($1).getDireccion());
		gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
		gc("\tR%d=R%d-R%d;\n", res, res, add);
		$$ = res;
		mem.liberaRegistro(add);
	}
	;
	}
	| NUMERO RESTA NUMERO 
	{
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=%d;\n", res, $1);
		gc("\tR%d=%d;\n", add, $3);
		gc("\tR%d=R%d-R%d;\n", res, res, add);
		$$ = res;
		mem.liberaRegistro(add);	
	}
	;

multiplicacion:
	identi MULTIPLICACION identi 
	{
	if(strcmp(stack.getVariable($1).getTipo(), "ent")==0 && strcmp(stack.getVariable($3).getTipo(), "ent")==0){
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=I(0x%x);\n", res, stack.getVariable($1).getDireccion());
		gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
		gc("\tR%d=R%d*R%d;\n", res, res, add);
		$$ = res;
		mem.liberaRegistro(add);
	}
	;
	}
	| NUMERO MULTIPLICACION NUMERO 
	{
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=%d;\n", res, $1);
		gc("\tR%d=%d;\n", add, $3);
		gc("\tR%d=R%d*R%d;\n", res, res, add);
		$$ = res;
		mem.liberaRegistro(add);

	}
	;

division:
	identi DIVISION identi 
	{
	if(strcmp(stack.getVariable($1).getTipo(), "ent")==0 && strcmp(stack.getVariable($3).getTipo(), "ent")==0){
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=I(0x%x);\n", res, stack.getVariable($1).getDireccion());
		gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
		gc("\tR%d=R%d/R%d;\n", res, res, add);
		$$ = res;
		mem.liberaRegistro(add);
	}
	;
	}
	| NUMERO DIVISION NUMERO 
	{
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int res, add;
		res = mem.devuelveRegistroLibre();
		add = mem.devuelveRegistroLibre();
		gc("\tR%d=%d;\n", res, $1);
		gc("\tR%d=%d;\n", add, $3);
		gc("\tR%d=R%d/R%d;\n", res, res, add);
		$$ = res;
		mem.liberaRegistro(add);

	}
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
	if(stack.existsFuncion($2)){
		printf("ya existe\n");
	} else {
		//stack.addStackElement($2, "func");	
	}
	}

	;

declareent:
	DECLAR ENT IDENTIFICADOR	
	{
	if(stack.existsVariable($3)){
		printf("ya existe\n");
	} else {
		//printf("adding %s\n", $3);
		int dir = mem.cogerDireccionDeMemoriaEnt();
		if (mem.getStat()==mem.getCode()){
			gc("STAT(%d)\n", mem.getStat());
			mem.incrementStat();
		}
		gc("\tMEM(0x%x, %d);\n", dir, 4);
		stack.addVariable($3, "ent", "global", dir);	
	}
	}
	;

declarecad:
	DECLAR CAD IDENTIFICADOR	
	{
	if(stack.existsVariable($3)){
		printf("ya existe\n");
	} else {
		int dir = mem.cogerDireccionDeMemoriaCad();
		if (mem.getStat()==mem.getCode()){
			gc("STAT(%d)\n", mem.getStat());
			mem.incrementStat();
		}
		gc("\tMEM(0x%x, %d);\n", dir, 20);
		stack.addVariable($3, "cad", "global", dir);	
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
	if(!stack.existsVariable($1)){
		printf("la variable no existe\n");
	} else {
		if(!stack.existsVariable($3)){
			printf("la variable no existe\n");
		} else {
			
	}
	}
	}
	|IDENTIFICADOR ASIGNACION NUMERO {
	
	if(!stack.existsVariable($1)){
		printf("la variable no existe\n");
	} else {
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		

		int id=mem.devuelveRegistroLibre();
		gc("\tR%d=0x%x;\n", id, stack.getVariable($1).getDireccion(), $3);
		int val = mem.devuelveRegistroLibre();
		gc("\tR%d=%d;\n", val, $3);
		gc("\tI(R%d)=R%d;\n", id, val);
		mem.liberaRegistro(id);
		mem.liberaRegistro(val);
	}	
	
	}
	| IDENTIFICADOR ASIGNACION operacionent 
	{
	if(!stack.existsVariable($1)){
		printf("la variable no existe\n");
	} else {
		int reg = mem.devuelveRegistroLibre();
		gc("\tR%d=0x%x;\n", reg, stack.getVariable($1).getDireccion() );
		gc("\tI(R%d)=R%d;\n", reg, $3);
		mem.liberaRegistro(reg);
		mem.liberaRegistro($3);
	}
	}
	;

ristra:
	COMILLAS IDENTIFICADOR COMILLAS
	{$$ = $2;}
	;

inicializarcad:
	IDENTIFICADOR ASIGNACION ristra {
	
	if(!stack.existsVariable($1)){
		printf("la variable no existe\n");
	} else {
		
	}	
	
	}
	|
	IDENTIFICADOR ASIGNACION operacioncad
	{
	if(!stack.existsVariable($1)){
		printf("la variable no existe\n");
	} else {
		printf("3\n");
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
	//printf("dentro\n");
	va_list args;
	va_start (args, code);
	vfprintf(qFile, code, args);
	va_end (args);
}

void yyerror(const char *s) {
	printf("error sintactico: %s\n", s);
}
