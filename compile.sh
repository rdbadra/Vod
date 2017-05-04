#!/bin/bash

bison -d miint.y
flex milex.l
g++ lex.yy.c miint.tab.c stack.cpp -lfl -o v
