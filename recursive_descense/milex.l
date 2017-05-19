

%{
#include "data.h"

void error(char*);
extern int yylex();
%}

%%
[ \t\n]         ;
;		{return PYCOMA;}
=		{return ASIGNACION;}
"+"		{return SUMA;}
"*"		{return MULTIPLICACION;}
"-"		{return RESTA;}
"/"		{return DIVISION;}
declar		{return DECLAR;}
cad		{return CAD;}
ent		{return ENT;}
[-]?[0-9]+          {return NUMERO; }
[a-zA-Z0-9]+	{return IDENTIFICADOR;}
\"[a-zA-Z0-9 \-\.\,\#]+\" {return RISTRA;}
%%
