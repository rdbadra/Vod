#include "Q.h"
#define INI 0
#define FIN -2
BEGIN
L 0:	STAT(0)
	MEM(0x11ffc, 4);
	MEM(0x11ff8, 4);
CODE(0)
	R0=0x11ffc;
	R1=7;
	I(R0)=R1;
	R0=0x11ff8;
	R1=8;
	I(R0)=R1;
	R0=I(0x11ffc);
	R1=I(0x11ff8);
	R0=R0<R1;
	IF(!R0) GT(1);
STAT(1)
	MEM(0x11ff4, 4);
CODE(1)
	R1=0x11ff4;
	R2=5;
	I(R1)=R2;
	R1=I(0x11ff4);
	R2=I(0x11ff8);
	R1=R1<R2;
	IF(!R1) GT(2);
	R2=I(0x11ffc);
	R3=I(0x11ff8);
	R2=R2+R3;
	R3=0x11ff4;
	I(R3)=R2;
L 2:
L 1:
	R0=0;
	GT(-2);
END
