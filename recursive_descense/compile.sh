#!/bin/bash

flex milex.l
g++ lex.yy.c parser.cpp -lfl -o v
