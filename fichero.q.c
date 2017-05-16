#include "Q.h"
#define INI 0
#define FIN -2
BEGIN
L 0:
STAT(0)
	MEM(0x11ffc, 4);
CODE(0)
	R0=0x11ffc;
	R1=2;
	I(R0)=R1;
STAT(1)
	MEM(0x11ff8, 4);
CODE(1)
	R0=0x11ff8;
	R1=6;
	I(R0)=R1;
L 1:
	R0=I(0x11ffc);
	R1=I(0x11ff8);
	R0=R0<R1;
	IF(!R0) GT(2);
	R0=3;
	R1=I(0x11ff8);
	GT(-13);
L 3:
	R0=0x11ff8;
	R1=1;
	I(R0)=R1;
	GT(1);
L 2:
	R0=0;
	GT(-2);
END
