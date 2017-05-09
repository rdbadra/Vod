#!/bin/bash

bison -d miint.y
flex milex.l
g++ lex.yy.c miint.tab.c stack.cpp stackElement.cpp GestorDeMemoria.cpp -lfl -o v
