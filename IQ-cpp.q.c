#include "Q.h"
# 1 "<stdin>"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "<stdin>"
# 1 "Qlib.h" 1
# 2 "<stdin>" 2


BEGIN
L 0:
STAT(0)
 MEM(0x11ffc, 4);
 MEM(0x11ff8, 4);
 MEM(0x11ff7, 1);
CODE(0)
 R0=0x11ff7;
 R1=35;
 U(R0+0)=R1;
STAT(1)
 MEM(0x11ff4, 3);
CODE(1)
 R0=0x11ff4;
 R1=110;
 U(R0+0)=R1;
 R1=58;
 U(R0+1)=R1;
 R1=32;
 U(R0+2)=R1;
STAT(2)
 MEM(0x11ff1, 3);
CODE(2)
 R0=0x11ff1;
 R1=114;
 U(R0+0)=R1;
 R1=58;
 U(R0+1)=R1;
 R1=32;
 U(R0+2)=R1;
STAT(3)
 MEM(0x11fea, 7);
CODE(3)
 R0=0x11fea;
 R1=100;
 U(R0+0)=R1;
 R1=101;
 U(R0+1)=R1;
 R1=110;
 U(R0+2)=R1;
 R1=116;
 U(R0+3)=R1;
 R1=114;
 U(R0+4)=R1;
 R1=111;
 U(R0+5)=R1;
 R1=32;
 U(R0+6)=R1;
STAT(4)
 MEM(0x11fe6, 4);
CODE(4)
 R0=0x11fe6;
 R1=102;
 U(R0+0)=R1;
 R1=49;
 U(R0+1)=R1;
 R1=58;
 U(R0+2)=R1;
 R1=32;
 U(R0+3)=R1;
STAT(5)
 MEM(0x11fe1, 5);
CODE(5)
 R0=0x11fe1;
 R1=32;
 U(R0+0)=R1;
 R1=102;
 U(R0+1)=R1;
 R1=50;
 U(R0+2)=R1;
 R1=58;
 U(R0+3)=R1;
 R1=32;
 U(R0+4)=R1;
STAT(6)
 MEM(0x11fdd, 4);
CODE(6)
 R0=0x11fdd;
 R1=1;
 I(R0)=R1;
STAT(7)
 MEM(0x11fd9, 4);
CODE(7)
 R0=0x11fd9;
 R1=2;
 I(R0)=R1;
STAT(8)
 MEM(0x11fd5, 4);
CODE(8)
 R0=0x11fd5;
 R1=0;
 I(R0)=R1;
 GT(2);
L 1:
 R6=R7;
 R7=R7-4;
 R7=R7-4;
 R7=R7-4;
 R0=R6-12;
 R1=I(0x11ffc);
 I(R0)=R1;
 R7=R7-4;
 R0=R6-16;
 R1=4;
 I(R0)=R1;
 R0=3;
 R1=I(R6-16);
 GT(-13);
L 3:
 R0=I(R6-12);
 R1=I(0x11fd9);
 R0=R0<R1;
 IF(!R0) GT(4);
 R0=0x11ff8;
 R1=I(R6-12);
 I(R0)=R1;
L 4:
 R0=I(R6-12);
 R1=I(0x11fdd);
 R0=R0>R1;
 IF(!R0) GT(5);
 R0=I(R6-12);
 R1=I(0x11fdd);
 R0=R0-R1;
 R1=0x11ffc;
 I(R1)=R0;
 R7=R7-8;
 P(R7+4)=R6;
 P(R7)=6;
 GT(1);
L 6:
 R0=R6-4;
 R1=I(0x11ff8);
 I(R0)=R1;
 R0=I(R6-12);
 R1=I(0x11fd9);
 R0=R0-R1;
 R1=0x11ffc;
 I(R1)=R0;
 R7=R7-8;
 P(R7+4)=R6;
 P(R7)=7;
 GT(1);
L 7:
 R0=R6-8;
 R1=I(0x11ff8);
 I(R0)=R1;
 R0=I(R6-4);
 R1=I(R6-8);
 R0=R0+R1;
 R1=0x11ff8;
 I(R1)=R0;
L 5:
 R7=R6;
 R6=P(R7+4);
 R5=P(R7);
 GT(R5);
L 2:
STAT(9)
 MEM(0x11fd1, 4);
 MEM(0x11fcd, 4);
CODE(9)
 R0=0x11fd1;
 R1=0;
 I(R0)=R1;
 R0=0x11fcd;
 R1=9;
 I(R0)=R1;
 R7=R7-10;
 R0=102;
 U(R7+0)=R0;
 R0=105;
 U(R7+1)=R0;
 R0=98;
 U(R7+2)=R0;
 R0=111;
 U(R7+3)=R0;
 R0=110;
 U(R7+4)=R0;
 R0=97;
 U(R7+5)=R0;
 R0=99;
 U(R7+6)=R0;
 R0=99;
 U(R7+7)=R0;
 R0=105;
 U(R7+8)=R0;
 R0=35;
 U(R7+9)=R0;
 R0=8;
 R1=U(R7+0);
 GT(-12);
L 8:
 R0=9;
 R1=U(R7+1);
 GT(-12);
L 9:
 R0=10;
 R1=U(R7+2);
 GT(-12);
L 10:
 R0=11;
 R1=U(R7+3);
 GT(-12);
L 11:
 R0=12;
 R1=U(R7+4);
 GT(-12);
L 12:
 R0=13;
 R1=U(R7+5);
 GT(-12);
L 13:
 R0=14;
 R1=U(R7+6);
 GT(-12);
L 14:
 R0=15;
 R1=U(R7+7);
 GT(-12);
L 15:
 R0=16;
 R1=U(R7+8);
 GT(-12);
L 16:
 R0=17;
 R1=U(R7+9);
 GT(-12);
L 17:
 R7=R7+10;
L 18:
 R0=I(0x11fd1);
 R1=I(0x11fcd);
 R0=R0<R1;
 IF(!R0) GT(19);
 R0=0x11ffc;
 R1=I(0x11fd1);
 I(R0)=R1;
 R7=R7-8;
 P(R7+4)=R6;
 P(R7)=20;
 GT(1);
L 20:
 R0=21;
 R1=I(0x11ff8);
 GT(-13);
L 21:
 R0=22;
 R1=U(0x11ff7+0);
 GT(-12);
L 22:
 R0=I(0x11fd1);
 R1=I(0x11fdd);
 R0=R0+R1;
 R1=0x11fd1;
 I(R1)=R0;
 GT(18);
L 19:
 R0=0;
 GT(-2);
END
