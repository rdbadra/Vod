#include "Q.h"
#define INI 0
#define FIN -2
BEGIN
L 0:
STAT(0)
	MEM(0x11ffc, 4);
CODE(0)
	R0=0x11ffc;
	R1=5;
	I(R0)=R1;
	R0=1;
	R1=I(0x11ffc);
	GT(-13);
L 1:
STAT(1)
	MEM(0x11ffa, 2);
CODE(1)
	R0=0x11ffa;
	R1=115;
	U(R0+0)=R1;
	R1=105;
	U(R0+1)=R1;
STAT(2)
	MEM(0x11ff8, 2);
CODE(2)
	R0=0x11ff8;
	R1=110;
	U(R0+0)=R1;
	R1=111;
	U(R0+1)=R1;
STAT(3)
	MEM(0x11ff4, 4);
CODE(3)
	R0=0x11ff4;
	R1=0x11ffa;
	R2=U(R1+0);
	U(R0+0)=R2;
	R2=U(R1+1);
	U(R0+1)=R2;
	R1=0x11ff8;
	R2=U(R1+0);
	U(R0+2)=R2;
	R2=U(R1+1);
	U(R0+3)=R2;
	R0=2;
	R1=U(0x11ff4+0);
	GT(-12);
L 2:
	R0=3;
	R1=U(0x11ff4+1);
	GT(-12);
L 3:
	R0=4;
	R1=U(0x11ff4+2);
	GT(-12);
L 4:
	R0=5;
	R1=U(0x11ff4+3);
	GT(-12);
L 5:
	R0=I(0x11ffc);
	R1=I(0x11ffc);
	R0=R0>R1;
	IF(!R0) GT(6);
L 6:
	R0=0;
	GT(-2);
END
