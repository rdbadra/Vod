#include "Q.h"
#define INI 0
#define FIN -2
BEGIN
L 0:
STAT(0)
	MEM(0x11ffc, 4);
CODE(0)
	R0=0x11ffc;
	R1=104;
	U(R0+0)=R1;
	R1=111;
	U(R0+1)=R1;
	R1=108;
	U(R0+2)=R1;
	R1=97;
	U(R0+3)=R1;
	R0=1;
	R1=U(0x11ffc+0);
	GT(-12);
L 1:
	R0=2;
	R1=U(0x11ffc+1);
	GT(-12);
L 2:
	R0=3;
	R1=U(0x11ffc+2);
	GT(-12);
L 3:
	R0=4;
	R1=U(0x11ffc+3);
	GT(-12);
L 4:
	R0=5;
	R1=35;
	GT(-12);
	L 5:
STAT(1)
	STR(0x11ff8, "nose");
CODE(1)
	R0=0x11ff8;
	R1=110;
	U(R0+0)=R1;
	R1=111;
	U(R0+1)=R1;
	R1=115;
	U(R0+2)=R1;
	R1=101;
	U(R0+3)=R1;
	R0=6;
	R1=U(0x11ff8+0);
	GT(-12);
L 6:
	R0=7;
	R1=U(0x11ff8+1);
	GT(-12);
L 7:
	R0=8;
	R1=U(0x11ff8+2);
	GT(-12);
L 8:
	R0=9;
	R1=U(0x11ff8+3);
	GT(-12);
L 9:
	R0=10;
	R1=35;
	GT(-12);
	L 10:
	R0=0;
	GT(-2);
END
