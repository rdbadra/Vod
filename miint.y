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

%%
// this is the actual grammar that bison will parse, but for right now it's just
// something silly to echo to the screen what bison gets from flex.  We'll
// make a real one shortly:
vod:
	body      
	| vod RISTRA { printf("ristra %s\n", $2);}
	| NUMERO            { printf("numero %d\n", $1);}
	| RISTRA         { printf("ristra %s\n", $1);}
	| ABREPAR	{printf("par\n");}
	| ABRECOR	{printf("cor\n");}
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
	| sentencias operacioncadosuma PYCOMA
	| callfunc PYCOMA
	| declarefunc
	| declare PYCOMA
	| inicializar PYCOMA
	| operacionent PYCOMA
	| operacioncadosuma PYCOMA
	| sentencias escaneo PYCOMA
	| sentencias imprime PYCOMA
	| escaneo PYCOMA
	| imprime PYCOMA
	| sentencias si
	| sentencias mientras 
	| si
	| mientras
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

operacioncadosuma:
	operacioncadosuma suma
	| operacioncadosuma ABREPAR operacioncadosuma CIERRAPAR
	| ABREPAR operacioncadosuma CIERRAPAR
	| suma	
	| operacioncadosuma SUMA suma
	| identi SUMA suma
	;

operacionent:
	operacionent resta
	| operacionent multiplicacion
	| operacionent division
	| operacionent ABREPAR operacionent CIERRAPAR
	| ABREPAR operacionent CIERRAPAR
	| resta
	| multiplicacion
	| division
	;

suma:
	identi SUMA identi 
	{
	//hay que comprobar si la variable es ent o cad para ver si es suma o concatenacion
	if(strcmp(stack.getStackElement($1).getType(), "ent")==0) printf("ent\n");
	if(strcmp(stack.getStackElement($3).getType(), "ent")==0) printf("ent\n");
	printf("suma\n");
	}
	;

identi:
	identi IDENTIFICADOR	{$$=$2;}
	| IDENTIFICADOR		{$$=$1;}
	| identi ABREPAR identi CIERRAPAR {$$ = $3;}
	| ABREPAR identi CIERRAPAR {$$ = $2;}
	;

resta:
	identi RESTA identi {printf("resta\n");}
	;

multiplicacion:
	identi MULTIPLICACION identi {printf("multiplicacion\n");}
	;

division:
	identi DIVISION identi {printf("division\n");}
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
		printf("adding %s\n", $2);
		stack.addStackElement($2, "func");	
	}
	
	printf("funcion\n");
	
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
	IDENTIFICADOR ASIGNACION identi {printf("esta\n");}
	|IDENTIFICADOR ASIGNACION NUMERO {
	
	if(!stack.exists($1)){
		printf("la variable no existe\n");
	} else {
		//printf("var: %s, num: %d\n", $1, $3);
		//stack.addEntValue($1, $3);
			
		StackElement el = stack.getStackElement($1);
		//el.addEntValue($3);
		stack.addEntValue($3, $1);
		//printf("value: %d name:%s\n",el.getEntValue(),el.getName());
	}	
	
	}
	| IDENTIFICADOR ASIGNACION operacioncadosuma {printf("se inicializa con suma\n");}
	| IDENTIFICADOR ASIGNACION operacionent {printf("se inicializa con operacion de enteros\n");}
	;

inicializarcad:
	IDENTIFICADOR ASIGNACION RISTRA {
	
	if(!stack.exists($1)){
		printf("la variable no existe\n");
	} else {
		printf("var: %s, value: %s\n", $1, $3);
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
