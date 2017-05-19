

%{
#include "data.h"

void error(char*);
extern int yylex();
int numlin = 1;
%}

%%
[ \t]         ;
[\n]		{numlin++;}
"conc" 		{return CONCATENACION;}
"+"		{return SUMA;}
"-"		{return RESTA;}
"*"		{return MULTIPLICACION;}
"/"		{return DIVISION;}
"{"		{return ABRECOR;}
"}"		{return CIERRACOR;}
"("		{return ABREPAR;}
")"		{return CIERRAPAR;}
;		{return PYCOMA;}
=		{return ASIGNACION;}
">"		{return MAYORQUE;}
"<"		{return MENORQUE;}
"=="		{return IGUAL;}
"!="		{return DIFERENTE;}
si		{return SI;}
mientras	{return MIENTRAS;}
imprimir	{return IMPRIMIR;}
funcion		{return FUNCION;}
declar		{return DECLAR;}
cad		{return CAD;}
ent 		{return ENT;}
[-]?[0-9]+          {return NUMERO; }
[a-zA-Z0-9]+	{return IDENTIFICADOR;}
\"[a-zA-Z0-9 \-\.\,\#]*\" {return RISTRA;}
%%
