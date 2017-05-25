

%{
#include "miint.tab.h"
int numlin = 1;

void error(char*);
extern int yylex();
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
ent		{return ENT;}
[-]?[0-9]+          { yylval.ent = atoi(yytext);return NUMERO; }
[a-zA-Z0-9]+	{yylval.cad = strdup(yytext);return IDENTIFICADOR;}
\"[a-zA-Z0-9 \-\.\,\#\¿\?\¡\!\_\;\*\']*\" {yylval.cad = strdup(yytext);return RISTRA;}
%%

void error(char* mens) {
printf("Error lexico en linea %i: %s\n",numlin , mens);
}
