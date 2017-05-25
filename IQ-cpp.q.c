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
 MEM(0x11ff3, 4);
CODE(1)
 R0=0x11ff3;
 R1=110;
 U(R0+0)=R1;
 R1=45;
 U(R0+1)=R1;
 R1=32;
 U(R0+2)=R1;
 R1=35;
 U(R0+3)=R1;
STAT(2)
 MEM(0x11fee, 5);
CODE(2)
 R0=0x11fee;
 R1=114;
 U(R0+0)=R1;
 R1=45;
 U(R0+1)=R1;
 R1=45;
 U(R0+2)=R1;
 R1=32;
 U(R0+3)=R1;
 R1=35;
 U(R0+4)=R1;
STAT(3)
 MEM(0x11fe6, 8);
CODE(3)
 R0=0x11fe6;
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
 R1=35;
 U(R0+7)=R1;
STAT(4)
 MEM(0x11fe1, 5);
CODE(4)
 R0=0x11fe1;
 R1=102;
 U(R0+0)=R1;
 R1=49;
 U(R0+1)=R1;
 R1=45;
 U(R0+2)=R1;
 R1=45;
 U(R0+3)=R1;
 R1=32;
 U(R0+4)=R1;
STAT(5)
 MEM(0x11fdb, 6);
CODE(5)
 R0=0x11fdb;
 R1=32;
 U(R0+0)=R1;
 R1=102;
 U(R0+1)=R1;
 R1=50;
 U(R0+2)=R1;
 R1=45;
 U(R0+3)=R1;
 R1=45;
 U(R0+4)=R1;
 R1=32;
 U(R0+5)=R1;
STAT(6)
 MEM(0x11fd7, 4);
CODE(6)
 R0=0x11fd7;
 R1=1;
 I(R0)=R1;
STAT(7)
 MEM(0x11fd3, 4);
CODE(7)
 R0=0x11fd3;
 R1=2;
 I(R0)=R1;
STAT(8)
 MEM(0x11fcf, 4);
CODE(8)
 R0=0x11fcf;
 R1=0;
 I(R0)=R1;
 GT(2);
L 1:
 R6=R7;
 R7=R7-4;
 R7=R7-4;
 R7=R7-4;
 R0=R7+0;
 R1=I(0x11ffc);
 I(R0)=R1;
 R0=I(R7+0);
 R1=I(0x11fd3);
 R0=R0<R1;
 IF(!R0) GT(3);
 R0=0x11ff8;
 R1=I(R7+0);
 I(R0)=R1;
 R0=4;
 R1=U(0x11fee+0);
 GT(-12);
L 4:
 R0=5;
 R1=U(0x11fee+1);
 GT(-12);
L 5:
 R0=6;
 R1=U(0x11fee+2);
 GT(-12);
L 6:
 R0=7;
 R1=U(0x11fee+3);
 GT(-12);
L 7:
 R0=8;
 R1=U(0x11fee+4);
 GT(-12);
L 8:
 R0=9;
 R1=I(0x11ff8);
 GT(-13);
L 9:
 R0=10;
 R1=U(0x11ff7+0);
 GT(-12);
L 10:
L 3:
 R0=I(R7+0);
 R1=I(0x11fcf);
 R0=R0<R1;
 IF(!R0) GT(11);
 R0=0x11ff8;
 R1=I(0x11fcf);
 I(R0)=R1;
L 11:
 R0=I(R7+0);
 R1=I(0x11fd7);
 R0=R0>R1;
 IF(!R0) GT(12);
 R0=I(R7+0);
 R1=I(0x11fd7);
 R0=R0-R1;
 R1=0x11ffc;
 I(R1)=R0;
 R7=R7-8;
 P(R7+4)=R6;
 P(R7)=13;
 GT(1);
L 13:
 R0=R7+-4;
 R1=I(0x11ff8);
 I(R0)=R1;
 R0=I(R7+-12);
 R1=I(0x11fd3);
 R0=R0-R1;
 R1=0x11ffc;
 I(R1)=R0;
 R7=R7-8;
 P(R7+4)=R6;
 P(R7)=14;
 GT(1);
L 14:
 R0=R7+-8;
 R1=I(0x11ff8);
 I(R0)=R1;
 R0=I(R7+-4);
 R1=I(R7+-8);
 R0=R0+R1;
 R1=0x11ff8;
 I(R1)=R0;
 R0=15;
 R1=U(0x11fe1+0);
 GT(-12);
L 15:
 R0=16;
 R1=U(0x11fe1+1);
 GT(-12);
L 16:
 R0=17;
 R1=U(0x11fe1+2);
 GT(-12);
L 17:
 R0=18;
 R1=U(0x11fe1+3);
 GT(-12);
L 18:
 R0=19;
 R1=U(0x11fe1+4);
 GT(-12);
L 19:
 R0=20;
 R1=U(0x11fee+0);
 GT(-12);
L 20:
 R0=21;
 R1=U(0x11fee+1);
 GT(-12);
L 21:
 R0=22;
 R1=U(0x11fee+2);
 GT(-12);
L 22:
 R0=23;
 R1=U(0x11fee+3);
 GT(-12);
L 23:
 R0=24;
 R1=U(0x11fee+4);
 GT(-12);
L 24:
 R0=25;
 R1=I(0x11ff8);
 GT(-13);
L 25:
 R0=26;
 R1=U(0x11ff7+0);
 GT(-12);
L 26:
L 12:
 R7=R6;
 R6=P(R7+4);
 R5=P(R7);
 GT(R5);
L 2:
STAT(9)
 MEM(0x11fcb, 4);
 MEM(0x11fc7, 4);
CODE(9)
 R0=0x11fcb;
 R1=0;
 I(R0)=R1;
 R0=0x11fc7;
 R1=8;
 I(R0)=R1;
L 27:
 R0=I(0x11fcb);
 R1=I(0x11fc7);
 R0=R0<R1;
 IF(!R0) GT(28);
 R0=0x11ffc;
 R1=I(0x11fcb);
 I(R0)=R1;
 R7=R7-8;
 P(R7+4)=R6;
 P(R7)=29;
 GT(1);
L 29:
 R0=30;
 R1=I(0x11ff8);
 GT(-13);
L 30:
 R0=31;
 R1=U(0x11ff7+0);
 GT(-12);
L 31:
 R0=I(0x11fcb);
 R1=I(0x11fd7);
 R0=R0+R1;
 R1=0x11fcb;
 I(R1)=R0;
 GT(27);
L 28:
 R0=0;
 GT(-2);
END
