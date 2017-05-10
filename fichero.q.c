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
	R0=0;
	GT(-2);
END
