#include "Q.h"
#define INI 0
#define FIN -2
BEGIN
L 0:
STAT(0)
	MEM(0x11ffc, 4);
CODE(0)
	GT(2);
L 1:
	R6=R7;
	R7=R7-4; //declaramos variables locales pila: 4
	R0=R7+0;
	R1=3;
	I(R0)=R1;
	R7=R7-4; //declaramos variables locales pila: 8
	R7=R7-4; //declaramos variables locales pila: 12
	R7=R7-4; //declaramos variables locales pila: 16
	R0=R7+0;
	R1=9;
	I(R0)=R1;
	R0=R7+4;
	R1=6;
	I(R0)=R1;
	R0=R7+8;
	R1=7;
	I(R0)=R1;
	R0=3;
	R1=I(R7+12);
	GT(-13);
L 3:
	R0=4;
	R1=I(R7+8);
	GT(-13);
L 4:
	R7=R6;
	R6=P(R7+4);
	R5=P(R7);
	GT(R5);
L 2: 
	R7=R7-8;
	P(R7+4)=R6;
	P(R7)=5;
	GT(1);
L 5:
	R0=0;
	GT(-2);
END
