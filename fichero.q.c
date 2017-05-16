#include "Q.h"
#define INI 0
#define FIN -2
BEGIN
L 0:
STAT(0)
	MEM(0x11ffc, 4);
	MEM(0x11ff8, 4);
CODE(0)
	GT(3);
L 1:
	R6=R7;
	R0=0x11ffc;
	R1=2;
	I(R0)=R1;
	R0=2;
	R1=I(0x11ffc);
	GT(-13);
L 2:
	R7=R6;
	R6=P(R7+0);
	R5=P(R7);
	GT(R5);
L 3: 
	R7=R7-4;
	P(R7+4)=R6;
	P(R7)=4;
	GT(1);
L 4:
	R0=0;
	GT(-2);
END
