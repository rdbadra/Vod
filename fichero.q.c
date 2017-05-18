#include "Q.h"
#define INI 0
#define FIN -2
BEGIN
L 0:
STAT(0)
	MEM(0x11ffc, 4);
	MEM(0x11ff8, 4);
	MEM(0x11ff4, 4);
	MEM(0x11ff0, 4);
	MEM(0x11fec, 4);
	MEM(0x11fe8, 4);
	MEM(0x11fe7, 1);
CODE(0)
	R0=0x11fe7;
	R1=35;
	U(R0+0)=R1;
	R0=0x11fe8;
	R1=1;
	I(R0)=R1;
	R0=0x11fec;
	R1=0;
	I(R0)=R1;
	R0=0x11ff8;
	R1=5;
	I(R0)=R1;
	R0=0x11ffc;
	R1=1;
	I(R0)=R1;
	R0=0x11ff4;
	R1=0;
	I(R0)=R1;
	R0=I(0x11ff8);
	R1=I(0x11ff4);
	R0=R0-R1;
	R1=0x11ff0;
	I(R1)=R0;
L 1:
	R0=I(0x11ff0);
	R1=I(0x11fec);
	R0=R0>R1;
	IF(!R0) GT(2);
	R0=I(0x11ffc);
	R1=I(0x11ff0);
	R0=R0*R1;
	R1=0x11ffc;
	I(R1)=R0;
	R0=I(0x11ff4);
	R1=I(0x11fe8);
	R0=R0+R1;
	R1=0x11ff4;
	I(R1)=R0;
	R0=I(0x11ff8);
	R1=I(0x11ff4);
	R0=R0-R1;
	R1=0x11ff0;
	I(R1)=R0;
	GT(1);
L 2:
STAT(1)
	MEM(0x11fd2, 21);
CODE(1)
	R0=0x11fd2;
	R1=69;
	U(R0+0)=R1;
	R1=108;
	U(R0+1)=R1;
	R1=32;
	U(R0+2)=R1;
	R1=102;
	U(R0+3)=R1;
	R1=97;
	U(R0+4)=R1;
	R1=99;
	U(R0+5)=R1;
	R1=116;
	U(R0+6)=R1;
	R1=111;
	U(R0+7)=R1;
	R1=114;
	U(R0+8)=R1;
	R1=105;
	U(R0+9)=R1;
	R1=97;
	U(R0+10)=R1;
	R1=108;
	U(R0+11)=R1;
	R1=32;
	U(R0+12)=R1;
	R1=100;
	U(R0+13)=R1;
	R1=101;
	U(R0+14)=R1;
	R1=32;
	U(R0+15)=R1;
	R1=53;
	U(R0+16)=R1;
	R1=32;
	U(R0+17)=R1;
	R1=101;
	U(R0+18)=R1;
	R1=115;
	U(R0+19)=R1;
	R1=32;
	U(R0+20)=R1;
STAT(2)
	MEM(0x11fd0, 2);
CODE(2)
	R0=0x11fd0;
	R1=46;
	U(R0+0)=R1;
	R1=32;
	U(R0+1)=R1;
	R0=3;
	R1=U(0x11fd2+0);
	GT(-12);
L 3:
	R0=4;
	R1=U(0x11fd2+1);
	GT(-12);
L 4:
	R0=5;
	R1=U(0x11fd2+2);
	GT(-12);
L 5:
	R0=6;
	R1=U(0x11fd2+3);
	GT(-12);
L 6:
	R0=7;
	R1=U(0x11fd2+4);
	GT(-12);
L 7:
	R0=8;
	R1=U(0x11fd2+5);
	GT(-12);
L 8:
	R0=9;
	R1=U(0x11fd2+6);
	GT(-12);
L 9:
	R0=10;
	R1=U(0x11fd2+7);
	GT(-12);
L 10:
	R0=11;
	R1=U(0x11fd2+8);
	GT(-12);
L 11:
	R0=12;
	R1=U(0x11fd2+9);
	GT(-12);
L 12:
	R0=13;
	R1=U(0x11fd2+10);
	GT(-12);
L 13:
	R0=14;
	R1=U(0x11fd2+11);
	GT(-12);
L 14:
	R0=15;
	R1=U(0x11fd2+12);
	GT(-12);
L 15:
	R0=16;
	R1=U(0x11fd2+13);
	GT(-12);
L 16:
	R0=17;
	R1=U(0x11fd2+14);
	GT(-12);
L 17:
	R0=18;
	R1=U(0x11fd2+15);
	GT(-12);
L 18:
	R0=19;
	R1=U(0x11fd2+16);
	GT(-12);
L 19:
	R0=20;
	R1=U(0x11fd2+17);
	GT(-12);
L 20:
	R0=21;
	R1=U(0x11fd2+18);
	GT(-12);
L 21:
	R0=22;
	R1=U(0x11fd2+19);
	GT(-12);
L 22:
	R0=23;
	R1=U(0x11fd2+20);
	GT(-12);
L 23:
	R0=24;
	R1=I(0x11ffc);
	GT(-13);
L 24:
	R0=25;
	R1=U(0x11fd0+0);
	GT(-12);
L 25:
	R0=26;
	R1=U(0x11fd0+1);
	GT(-12);
L 26:
	R0=27;
	R1=U(0x11fe7+0);
	GT(-12);
L 27:
	R0=0;
	GT(-2);
END
