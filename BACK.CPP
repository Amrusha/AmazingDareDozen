#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>
#include <process.h>
#include <alloc.h>
#include <stdlib.h>
#include <iostream.h>
void bye()
{
setlinestyle(4,1,1);
for(float co=0;co<650;co++)
{
setcolor(co);
delay(5);
line(co,0,co,500);
line(0,co,700,co);
}
for(co=0;co<500;co++)
{
 setcolor(0);
 circle(300,250,co);
}
setcolor(15);
settextstyle(4,0,7);
outtextxy(130,250,"THANK YOU");
getch();
}