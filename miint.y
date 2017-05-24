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
char global[7] = "global";
GestorDeMemoria mem;
Stack stack;
int pila = 0;
int etiqueta = 0;
int etiqFunc = 0;
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
%token <ent> MIENTRAS SI
%token MAYORQUE MENORQUE IGUAL DIFERENTE
%token IMPRIMIR
%token <ent> DECLAR ASIGNACION PYCOMA FUNCION ABREPAR CIERRAPAR ABRECOR CIERRACOR COMILLAS
%token SUMA RESTA MULTIPLICACION DIVISION CONCATENACION
%token <cad> IDENTIFICADOR RISTRA
%token CAD ENT
%token <ent> NUMERO
%type <cad> identi
%type <ent> suma resta division multiplicacion operacionent cond sentencias declare declareent declarecad
%type <ent> mientras declarefunc

%%
// this is the actual grammar that bison will parse, but for right now it's just
// something silly to echo to the screen what bison gets from flex.  We'll
// make a real one shortly:
vod:
	{gc("#include \"Q.h\"\n");
	gc("#define INI 0\n");
	gc("#define FIN -2\n");
	gc("BEGIN\n");
	gc("L %d:\n", etiqueta);
	etiqueta++;
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

sentenciassi:
	| sentenciassi inicializar PYCOMA
	| sentenciassi callfunc PYCOMA
	| sentenciassi imprime PYCOMA
	| sentenciassi si
	| sentenciassi mientras 
	| sentenciassi PYCOMA
	;

sentencias:
	sentencias declare PYCOMA
	{
	// Para saber el numero de bytes que hay que reservar en memoria
	$$ = $$ + $2;
	}
	| sentencias inicializar PYCOMA
	| sentencias callfunc PYCOMA
	| sentencias imprime PYCOMA
	| sentencias si
	| sentencias mientras 
	| sentencias PYCOMA
	|
	{
	$$ = 0;
	}
	;

si:
	SI
	{
	
	}
	ABREPAR cond CIERRAPAR
	{
	$3=etiqueta;
	gc("\tIF(!R%d) GT(%d);\n", $4, $3);
	etiqueta++;
	mem.liberaRegistro($4);
	}
	ABRECOR sentenciassi CIERRACOR 
	{
	gc("L %d:\n",$3);
	}
	;

mientras:
	MIENTRAS 
	{
	$1 = etiqueta;
	gc("L %d:\n", $1);
	etiqueta++;
	}
	ABREPAR cond CIERRAPAR
	{
	$3=etiqueta;
	gc("\tIF(!R%d) GT(%d);\n", $4, $3);
	etiqueta++;
	mem.liberaRegistro($4);
	}
	ABRECOR sentenciassi CIERRACOR 
	{
	gc("\tGT(%d);\nL %d:\n", $1, $3);
	}
	;

cond:	
	identi MAYORQUE identi 
	{
	if(strcmp(stack.getVariable($1).getTipo(), "ent")==0 && strcmp(stack.getVariable($3).getTipo(), "ent")==0){
		if(strcmp(stack.getVariable($1).getContext(), global)==0){
			if(strcmp(stack.getVariable($3).getContext(), global)==0){
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(0x%x);  // global mayor que global\n", res, stack.getVariable($1).getDireccion());
				gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d>R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			} else {
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(0x%x); // global mayor que local\n", res, stack.getVariable($1).getDireccion());
				gc("\tR%d=I(R7+%d);\n", add, pila-stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d>R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			}
		} else {
			if(strcmp(stack.getVariable($3).getContext(), global)==0){
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(R7+%d);  // local mayor que global\n", res, pila-stack.getVariable($1).getDireccion());
				gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d>R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			} else {
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(R7+%d); // local mayor que local\n", res, pila-stack.getVariable($1).getDireccion());
				gc("\tR%d=I(R7+%d);\n", add, pila-stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d>R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			}
	}
	}
	}
	| identi MENORQUE identi 
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
		gc("\tR%d=R%d<R%d;\n", res, res, add);
		$$ = res;
		mem.liberaRegistro(add);
	} else {
		yyerror("syntax error");
	}
	}
	| identi IGUAL identi 
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
		gc("\tR%d=R%d==R%d;\n", res, res, add);
		$$ = res;
		mem.liberaRegistro(add);
	} else {
		yyerror("syntax error");
	}
	}
	| identi DIFERENTE identi 
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
		gc("\tR%d=R%d!=R%d;\n", res, res, add);
		$$ = res;
		mem.liberaRegistro(add);
	} else {
		yyerror("syntax error");
	}
	}
	;
imprime:
	IMPRIMIR ABREPAR IDENTIFICADOR CIERRAPAR 
	{
	if(!stack.existsVariable($3)){
		printf("la variable %s no existe\n", $3);
		yyerror("syntax error");
	} else {
		if (mem.getStat()==mem.getCode()+1){
				gc("CODE(%d)\n", mem.getCode());
				mem.incrementCode();
		}		
		if(strcmp(stack.getVariable($3).getTipo(), "cad")==0){
			//imprimir cadena
			int ret, ristra;
			ret = mem.devuelveRegistroLibre();
			ristra = mem.devuelveRegistroLibre();
			int size = stack.getVariable($3).getSize();
			for(int i = 0; i < size; i++){
				gc("\tR%d=%d;\n", ret, etiqueta);
				gc("\tR%d=U(0x%x+%d);\n", ristra, stack.getVariable($3).getDireccion(), i);
				gc("\tGT(-12);\nL %d:\n", etiqueta);
				etiqueta++;	
			}
			mem.liberaRegistro(ret);
			mem.liberaRegistro(ristra);
		}
		else{
			//imprimir numero
			if(strcmp(stack.getVariable($3).getContext(), global)==0){
				int ret, numero;
				ret = mem.devuelveRegistroLibre();
				numero = mem.devuelveRegistroLibre();
				gc("\tR%d=%d;\n", ret, etiqueta);
				gc("\tR%d=I(0x%x);\n", numero, stack.getVariable($3).getDireccion());
				gc("\tGT(-13);\nL %d:\n", etiqueta);
				etiqueta++;
				mem.liberaRegistro(ret);
				mem.liberaRegistro(numero);
			} else {
				int ret, numero;
				ret = mem.devuelveRegistroLibre();
				numero = mem.devuelveRegistroLibre();
				gc("\tR%d=%d;\n", ret, etiqueta);
				gc("\tR%d=I(R7+%d);\n", numero, pila-stack.getVariable($3).getDireccion());
				gc("\tGT(-13);\nL %d:\n", etiqueta);
				etiqueta++;
				mem.liberaRegistro(ret);
				mem.liberaRegistro(numero);
			}
		}	
	}
	}
	;

callfunc:
	IDENTIFICADOR ABREPAR CIERRAPAR 
	{
	if (mem.getStat()==mem.getCode()+1){
				gc("CODE(%d)\n", mem.getCode());
				mem.incrementCode();
	}
	gc("\tR7=R7-8;\n");
	gc("\tP(R7+4)=R6;\n");	
	gc("\tP(R7)=%d;\n", etiqueta);
	gc("\tGT(%d);\n", stack.getFuncion($1).getEtiqueta());
	gc("L %d:\n", etiqueta);
	etiqueta++;
	}
	;

operacionent:
	ABREPAR operacionent CIERRAPAR
	{
	$$ = $2;
	}
	| suma
	| resta
	| multiplicacion
	| division
	;

suma:
	identi SUMA identi 
	{
	if(strcmp(stack.getVariable($1).getTipo(), "ent")==0 && strcmp(stack.getVariable($3).getTipo(), "ent")==0){
		if(strcmp(stack.getVariable($1).getContext(), global)==0){
			if(strcmp(stack.getVariable($3).getContext(), global)==0){
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(0x%x);  // suma de globales\n", res, stack.getVariable($1).getDireccion());
				gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d+R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			} else {
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(0x%x); // global mas local\n", res, stack.getVariable($1).getDireccion());
				gc("\tR%d=I(R7+%d);\n", add, pila-stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d+R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			}
		} else {
			if(strcmp(stack.getVariable($3).getContext(), global)==0){
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(R7+%d);  // local mas global\n", res, pila-stack.getVariable($1).getDireccion());
				gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d+R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			} else {
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(R7+%d); // local mas local\n", res, pila-stack.getVariable($1).getDireccion());
				gc("\tR%d=I(R7+%d);\n", add, pila-stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d+R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			}
	}
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
			if(strcmp(stack.getVariable($1).getContext(), global)==0){
			if(strcmp(stack.getVariable($3).getContext(), global)==0){
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(0x%x);  // resta de globales\n", res, stack.getVariable($1).getDireccion());
				gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d-R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			} else {
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(0x%x); // global menos local\n", res, stack.getVariable($1).getDireccion());
				gc("\tR%d=I(R7+%d);\n", add, pila-stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d-R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			}
		} else {
			if(strcmp(stack.getVariable($3).getContext(), global)==0){
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(R7+%d);  // local menos global\n", res, pila-stack.getVariable($1).getDireccion());
				gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d-R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			} else {
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(R7+%d); // local menos local\n", res, pila-stack.getVariable($1).getDireccion());
				gc("\tR%d=I(R7+%d);\n", add, pila-stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d-R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			}
	}
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
		if(strcmp(stack.getVariable($1).getContext(), global)==0){
			if(strcmp(stack.getVariable($3).getContext(), global)==0){
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(0x%x);  // multiplicacion de globales\n", res, stack.getVariable($1).getDireccion());
				gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d*R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			} else {
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(0x%x); // global por local\n", res, stack.getVariable($1).getDireccion());
				gc("\tR%d=I(R7+%d);\n", add, pila-stack.getVariable($3).getDireccion());
				gc("\tR%d=R%*R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			}
		} else {
			if(strcmp(stack.getVariable($3).getContext(), global)==0){
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(R7+%d);  // local por global\n", res, pila-stack.getVariable($1).getDireccion());
				gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d*R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			} else {
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(R7+%d); // local por local\n", res, pila-stack.getVariable($1).getDireccion());
				gc("\tR%d=I(R7+%d);\n", add, pila-stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d*R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			}
	}
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
		if(strcmp(stack.getVariable($1).getContext(), global)==0){
			if(strcmp(stack.getVariable($3).getContext(), global)==0){
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(0x%x);  // division de globales\n", res, stack.getVariable($1).getDireccion());
				gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d/R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			} else {
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(0x%x); // global dividido por local\n", res, stack.getVariable($1).getDireccion());
				gc("\tR%d=I(R7+%d);\n", add, pila-stack.getVariable($3).getDireccion());
				gc("\tR%d=R%/R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			}
		} else {
			if(strcmp(stack.getVariable($3).getContext(), global)==0){
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(R7+%d);  // local dividido por global\n", res, pila-stack.getVariable($1).getDireccion());
				gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d/R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			} else {
				if (mem.getStat()==mem.getCode()+1){
					gc("CODE(%d)\n", mem.getCode());
					mem.incrementCode();
				}
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=I(R7+%d); // local dividido por local\n", res, pila-stack.getVariable($1).getDireccion());
				gc("\tR%d=I(R7+%d);\n", add, pila-stack.getVariable($3).getDireccion());
				gc("\tR%d=R%d/R%d;\n", res, res, add);
				$$ = res;
				mem.liberaRegistro(add);
			}
	}
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
	{
	$$ += $2;
	}
	| declare declarecad
	{
	$$ += $2;
	}
	| declarecad
	{
	$$ = $1;
	}
	| declareent
	{
	$$ = $1;
	}
	;

declarefunc:
	FUNCION IDENTIFICADOR ABREPAR CIERRAPAR
	{
	if(stack.existsFuncion($2)){
		printf("ya existe %s\n", $2);
		yyerror("syntax error");
	} else {
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		mem.setAmbito($2);
		int etiq = etiqueta;
		etiqueta++;
		stack.addFuncion($2, etiq);
		etiqFunc = etiqueta;
		gc("\tGT(%d);\n", etiqueta);
		gc("L %d:\n", etiq);
		gc("\tR6=R7;\n");	
		etiqueta++;
	}
	}
	ABRECOR sentencias CIERRACOR
	{
	if (mem.getStat()==mem.getCode()+1){
				gc("CODE(%d)\n", mem.getCode());
				mem.incrementCode();
	}
	gc("\tR7=R6;\n");
	gc("\tR6=P(R7+4);\n");
	gc("\tR5=P(R7);\n");
	gc("\tGT(R5);\n");
	gc("L %d: \n", etiqFunc);
	stack.cleanDinamicStack($2);
	mem.setAmbito(global);
	}	
	;

declareent:
	DECLAR ENT IDENTIFICADOR	
	{
	$$ = 4;
	if(stack.existsVariable($3)){
		printf("ya existe %s\n", $3);
		yyerror("syntax error");
	} else {
		if(strcmp(mem.getAmbito(), global)==0){
			if (mem.getStat()==mem.getCode()){
			gc("STAT(%d)\n", mem.getStat());
			mem.incrementStat();
			}
			int dir = mem.cogerDireccionDeMemoriaEnt();
			stack.addVariable($3, "ent", mem.getAmbito(), dir, 4);	
			gc("\tMEM(0x%x, %d);\n", dir, 4);
		} else {
			pila += 4;
			gc("\tR7=R7-%d; //declaramos variables locales pila: %d\n", 4, pila);
			stack.addVariable($3, "ent", mem.getAmbito(), pila, 4);	
			//pila += 4;
		}
		
			
	}
	}
	;

declarecad:
	DECLAR CAD IDENTIFICADOR ASIGNACION RISTRA	
	{
	if(stack.existsVariable($3)){
		printf("ya existe %s\n", $3);
		yyerror("syntax error");
	} else {
		int size = strlen($5);
		char h[size-2];
		for(int i = 0; i < size-2; i++){
			h[i] = $5[i+1];
		}
		h[size-2] = '\0';
		$$ = strlen(h);
		int dir = mem.cogerDireccionDeMemoriaCad(strlen(h));
		if (mem.getStat()==mem.getCode()){
			gc("STAT(%d)\n", mem.getStat());
			mem.incrementStat();
		}
		gc("\tMEM(0x%x, %d);\n", dir, strlen(h));
		stack.addVariable($3, "cad", mem.getAmbito(), dir, strlen(h));
				if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		int id=mem.devuelveRegistroLibre();
		gc("\tR%d=0x%x;\n", id, stack.getVariable($3).getDireccion());
		int val = mem.devuelveRegistroLibre();
		for(int i = 0; i < strlen(h); i++){
			gc("\tR%d=%d;\n", val, h[i]);
			gc("\tU(R%d+%d)=R%d;\n", id,i, val);
		}
		mem.liberaRegistro(id);
		mem.liberaRegistro(val);
	}
	}
	|
	DECLAR CAD IDENTIFICADOR ASIGNACION identi CONCATENACION identi
	{
		if(strcmp(stack.getVariable($5).getTipo(), "cad")==0 && strcmp(stack.getVariable($7).getTipo(), "cad")==0){
		
			int size = stack.getVariable($5).getSize() + stack.getVariable($7).getSize();
			$$ = size;
			int dir = mem.cogerDireccionDeMemoriaCad(size);
			if (mem.getStat()==mem.getCode()){
				gc("STAT(%d)\n", mem.getStat());
				mem.incrementStat();
			}
			gc("\tMEM(0x%x, %d);\n", dir, size);
			stack.addVariable($3, "cad", mem.getAmbito(), dir, size);
					if (mem.getStat()==mem.getCode()+1){
				gc("CODE(%d)\n", mem.getCode());
				mem.incrementCode();
			}
			int reg0 = mem.devuelveRegistroLibre();
			int reg1 = mem.devuelveRegistroLibre();
			int reg2 = mem.devuelveRegistroLibre();
			gc("\tR%d=0x%x;\n", reg0, stack.getVariable($3).getDireccion());
			gc("\tR%d=0x%x;\n", reg1, stack.getVariable($5).getDireccion());
			int i;
			for(i = 0; i < stack.getVariable($5).getSize(); i++){
				gc("\tR%d=U(R%d+%d);\n", reg2, reg1, i );
				gc("\tU(R%d+%d)=R%d;\n", reg0, i, reg2 );
			}
			gc("\tR%d=0x%x;\n", reg1, stack.getVariable($7).getDireccion());
			for(i = 0; i < stack.getVariable($7).getSize(); i++){
				gc("\tR%d=U(R%d+%d);\n", reg2, reg1, i );
				gc("\tU(R%d+%d)=R%d;\n", reg0, i+stack.getVariable($5).getSize(), reg2 );
			}
			mem.liberaRegistro(reg0);
			mem.liberaRegistro(reg1);
			mem.liberaRegistro(reg2);
		}
		
	}
	;

inicializar:
	inicializarent
	;

inicializarent:
	IDENTIFICADOR ASIGNACION identi 
	{
	if(!stack.existsVariable($1)){
		printf("la variable %s no existe\n", $1);
		yyerror("syntax error");
	} else {
		if(!stack.existsVariable($3)){
			printf("la variable %s no existe\n", $3);
			yyerror("syntax error");
		} else {
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		if(strcmp(stack.getVariable($1).getContext(), global)==0){
			if(strcmp(stack.getVariable($3).getContext(), global)==0){
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=0x%x; //global gets global value\n", res, stack.getVariable($1).getDireccion());
				gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
				gc("\tI(R%d)=R%d;\n", res, add);
				mem.liberaRegistro(add);
				mem.liberaRegistro(res);
			} else {
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=0x%x; //global gets local value\n", res, stack.getVariable($1).getDireccion());
				gc("\tR%d=I(R7+%d);\n", add, pila-stack.getVariable($3).getDireccion());
				gc("\tI(R%d)=R%d;\n", res, add);
				mem.liberaRegistro(add);
				mem.liberaRegistro(res);
			}
		} else {
			if(strcmp(stack.getVariable($3).getContext(), global)==0){
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=R7+%d; //local gets global value \n", res, pila-stack.getVariable($1).getDireccion());
				gc("\tR%d=I(0x%x);\n", add, stack.getVariable($3).getDireccion());
				gc("\tI(R%d)=R%d;\n", res, add);
				mem.liberaRegistro(add);
				mem.liberaRegistro(res);
			} else {
				int res, add;
				res = mem.devuelveRegistroLibre();
				add = mem.devuelveRegistroLibre();
				gc("\tR%d=R7+%d; //local gets local value\n", res, pila-stack.getVariable($1).getDireccion());
				gc("\tR%d=I(R7+%d);\n", add, pila-stack.getVariable($3).getDireccion());
				gc("\tI(R%d)=R%d;\n", res, add);
				mem.liberaRegistro(add);
				mem.liberaRegistro(res);
			}
		}
	
	}
	}
	}
	|IDENTIFICADOR ASIGNACION NUMERO {
	
	if(!stack.existsVariable($1)){
		printf("la variable %s no existe\n", $1);
		yyerror("syntax error");
	} else {
		if (mem.getStat()==mem.getCode()+1){
			gc("CODE(%d)\n", mem.getCode());
			mem.incrementCode();
		}
		if(strcmp(stack.getVariable($1).getContext(), global)==0){
			int id=mem.devuelveRegistroLibre();
			gc("\tR%d=0x%x;\n", id, stack.getVariable($1).getDireccion());
			int val = mem.devuelveRegistroLibre();
			gc("\tR%d=%d;\n", val, $3);
			gc("\tI(R%d)=R%d;\n", id, val);
			mem.liberaRegistro(id);
			mem.liberaRegistro(val);
		} else {
			int id=mem.devuelveRegistroLibre();
			gc("\tR%d=R7+%d;\n", id, pila-stack.getVariable($1).getDireccion());
			int val = mem.devuelveRegistroLibre();
			gc("\tR%d=%d;\n", val, $3);
			gc("\tI(R%d)=R%d;\n", id, val);
			mem.liberaRegistro(id);
			mem.liberaRegistro(val);
		}
	}	
	
	}
	| IDENTIFICADOR ASIGNACION operacionent 
	{
	if(!stack.existsVariable($1)){
		printf("la variable %s no existe\n", $1);
		yyerror("syntax error");
	} else {
		if(strcmp(stack.getVariable($1).getContext(), global)==0){
			int reg = mem.devuelveRegistroLibre();
			gc("\tR%d=0x%x;\n", reg, stack.getVariable($1).getDireccion() );
			gc("\tI(R%d)=R%d;\n", reg, $3);
			mem.liberaRegistro(reg);
			mem.liberaRegistro($3);
		} else {
			int reg = mem.devuelveRegistroLibre();
			gc("\tR%d=R7+%d;\n", reg, pila-stack.getVariable($1).getDireccion() );
			gc("\tI(R%d)=R%d;\n", reg, $3);
			mem.liberaRegistro(reg);
			mem.liberaRegistro($3);
		}
	}
	}
	;
%%

int main(int argc, char** argv) {
	// open a file handle to a particular file:
	if(argc>1) yyin=fopen(argv[1], "r");
	//yydebug = 1;
	yyparse();
	stack.printStack();
	
	
	
}

void gc(const char* code, ...){
	va_list args;
	va_start (args, code);
	vfprintf(qFile, code, args);
	va_end (args);
}

void yyerror(const char *s) {
	printf("error sintactico: %s\n", s);
	exit(0);
}
