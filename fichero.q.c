#include "Q.h"
#define INI 0
#define FIN -2
BEGIN
L 0:
STAT(0)
	MEM(0x11ffc, 4);
CODE(0)
	R0=0x11ffc;
	R1=3;
	I(R0)=R1;
STAT(1)
	MEM(0x11ff8, 4);
CODE(1)
	R0=0x11ff8;
	R1=1;
	I(R0)=R1;
STAT(2)
	MEM(0x11ff4, 4);
CODE(2)
	R0=0x11ff4;
	R1=3;
	I(R0)=R1;
STAT(3)
	MEM(0x11ff0, 4);
CODE(3)
	R0=0x11ff0;
	R1=3;
	I(R0)=R1;
	GT(2);
L 1:
	R6=R7;
	R0=I(0x11ffc);
	R1=I(0x11ff8);
	R0=R0>R1;
	IF(!R0) GT(3);
	R0=I(0x11ffc);
	R1=I(0x11ff8);
	R0=R0-R1;
	R1=0x11ffc;
	I(R1)=R0;
	R0=I(0x11ff4);
	R1=I(0x11ff0);
	R0=R0*R1;
	R1=0x11ff4;
	I(R1)=R0;
	R7=R7-8;
	P(R7+4)=R6;
	P(R7)=4;
	GT(1);
L 4:
L 3:
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
	R0=6;
	R1=I(0x11ff4);
	GT(-13);
L 6:
	R0=0;
	GT(-2);
END
