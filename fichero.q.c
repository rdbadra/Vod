#include "Q.h"
#define INI 0
#define FIN -2
BEGIN
STAT(0)
	MEM(0x11ffc, 4);
	MEM(0x11ff8, 4);
CODE(0)
	R0=0x11ffc;
	R1=7;
	I(R0)=R1;
	R0=0x11ff8;
	R1=8;
	I(R0)=R1;
STAT(1)
	MEM(0x11fe4, 20);
CODE(1)
	R0=2;
	R1=2;
	R0=R0+R1;
	R1=0x11ff8;
	I(R1)=R0;
	R0=I(0x11ffc);
	R1=I(0x11ff8);
	R0=R0+R1;
	R1=0x11ffc;
	I(R1)=R0;
	R0=0;
	GT(-2);
END
