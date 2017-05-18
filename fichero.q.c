#include "Q.h"
#define INI 0
#define FIN -2
BEGIN
L 0:
STAT(0)
	MEM(0x11ffc, 4);
CODE(0)
	R0=1;
	R1=2;
	R0=R0+R1;
	R1=0x11ffc;
	I(R1)=R0;
	R0=1;
	R1=I(0x11ffc);
	GT(-13);
L 1:
	R0=0;
	GT(-2);
END
