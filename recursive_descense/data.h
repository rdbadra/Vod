typedef enum
  {
    DECLAR = 265,
    ASIGNACION = 266,
    PYCOMA = 267,
    SUMA = 274,
    RESTA = 275,
    MULTIPLICACION = 276,
    DIVISION = 277,
    IDENTIFICADOR = 279,
    RISTRA = 280,
    CAD = 281,
    ENT = 282,
    NUMERO = 283
} Symbol;
extern int yylex();
extern int yyparse();
extern FILE *yyin;

