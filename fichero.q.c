#include "Q.h"
#define INI 0
#define FIN -2
BEGIN
L 0:
STAT(0)
	MEM(0x11ffc, 4);		// declaramos variables ent globales a
CODE(0)
	R0=0x11ffc;		// Se asigna valor ent a variable global
	R1=1;
	I(R0)=R1;
	R7=R7-5;		// declaramos cad dinamico 
	R1=102;
	U(R7+0)=R1;
	R1=97;
	U(R7+1)=R1;
	R1=98;
	U(R7+2)=R1;
	R1=105;
	U(R7+3)=R1;
	R1=111;
	U(R7+4)=R1;
	R0=1;		// imprimimimos cad dinamico
	R1=U(R7+0);
	GT(-12);
L 1:
	R0=2;		// imprimimimos cad dinamico
	R1=U(R7+1);
	GT(-12);
L 2:
	R0=3;		// imprimimimos cad dinamico
	R1=U(R7+2);
	GT(-12);
L 3:
	R0=4;		// imprimimimos cad dinamico
	R1=U(R7+3);
	GT(-12);
L 4:
	R0=5;		// imprimimimos cad dinamico
	R1=U(R7+4);
	GT(-12);
L 5:
	R0=0;
	GT(-2);
END
