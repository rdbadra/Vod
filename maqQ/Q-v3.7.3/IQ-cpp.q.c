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
STAT(0)
 STR(0x11ff9, "a =%d\n");
 MEM(0x11ff5, 4);
CODE(0)
L 0: R0=0x11ff5;
 R1=6;
 I(R0)=R1;

 R0=1;
 R1=0x11ff9;
 R2=I(0x11ff5);
 GT(-12);
L 1:
 GT(-2);
END
