typedef enum
  {
    MIENTRAS = 258,
    SI = 259,
    MAYORQUE = 260,
    MENORQUE = 261,
    IGUAL = 262,
    DIFERENTE = 263,
    IMPRIMIR = 264,
    DECLAR = 265,
    ASIGNACION = 266,
    PYCOMA = 267,
    FUNCION = 268,
    ABREPAR = 269,
    CIERRAPAR = 270,
    ABRECOR = 271,
    CIERRACOR = 272,
    COMILLAS = 273,
    SUMA = 274,
    RESTA = 275,
    MULTIPLICACION = 276,
    DIVISION = 277,
    CONCATENACION = 278,
    IDENTIFICADOR = 279,
    RISTRA = 280,
    CAD = 281,
    ENT = 282,
    NUMERO = 283
} Symbol;

extern int numlin;
extern int yylex();
extern int yyparse();
extern FILE *yyin;

