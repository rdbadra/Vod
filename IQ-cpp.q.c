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
CODE(0)
 R0=0x11ffc;
 R1=1;
 I(R0)=R1;
 R7=R7-5;
 R1=102;
 U(R7+0)=R1;
 R1=97;
 U(R7+1)=R1;
 R1=98;
 U(R7+2)=R1;
 R1=105;
 U(R7+3)=R1;
 R1=111;
 U(R7+4)=R1;
 R0=1;
 R1=U(R7+0);
 GT(-12);
L 1:
 R0=2;
 R1=U(R7+1);
 GT(-12);
L 2:
 R0=3;
 R1=U(R7+2);
 GT(-12);
L 3:
 R0=4;
 R1=U(R7+3);
 GT(-12);
L 4:
 R0=5;
 R1=U(R7+4);
 GT(-12);
L 5:
 R0=0;
 GT(-2);
END
