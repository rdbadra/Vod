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
STAT(2)
	MEM(0x11ff0, 8);
CODE(2)
	R0=0x11ff0;
	R1=0x11ffc;
	R2=U(R1+0);
	U(R0+0)=R2;
	R2=U(R1+1);
	U(R0+1)=R2;
	R2=U(R1+2);
	U(R0+2)=R2;
	R2=U(R1+3);
	U(R0+3)=R2;
	R1=0x11ff8;
	R2=U(R1+0);
	U(R0+4)=R2;
	R2=U(R1+1);
	U(R0+5)=R2;
	R2=U(R1+2);
	U(R0+6)=R2;
	R2=U(R1+3);
	U(R0+7)=R2;
	R0=11;
	R1=U(0x11ff0+0);
	GT(-12);
L 11:
	R0=12;
	R1=U(0x11ff0+1);
	GT(-12);
L 12:
	R0=13;
	R1=U(0x11ff0+2);
	GT(-12);
L 13:
	R0=14;
	R1=U(0x11ff0+3);
	GT(-12);
L 14:
	R0=15;
	R1=U(0x11ff0+4);
	GT(-12);
L 15:
	R0=16;
	R1=U(0x11ff0+5);
	GT(-12);
L 16:
	R0=17;
	R1=U(0x11ff0+6);
	GT(-12);
L 17:
	R0=18;
	R1=U(0x11ff0+7);
	GT(-12);
L 18:
	R0=19;
	R1=35;
	GT(-12);
	L 19:
	R0=0;
	GT(-2);
END
