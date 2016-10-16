#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>
#include <process.h>
#include <alloc.h>
#include <stdlib.h>
#include <iostream.h>

void CHECK3_1TO2();
void CHECK3_2TO3();
void CHECK3_3TO4();

int anda3=380;
int basket3=1;

void lvl3()
{
    setcolor(1);
    settextstyle(2,0,7);
    outtextxy(500,10,"LEVEL 2");
    setcolor(15);
    settextstyle(2,0,7);
    outtextxy(500,10,"LEVEL 3");

    setcolor(2);
    setfillstyle(9,4);
    floodfill(350,200,15);
    setfillstyle(9,2);
    floodfill(350,200,15);
    delay(200);

}

void CHECK3_1TO2()
{
   if(xr1>330&&xr1<380||xl1>330&&xl1<380)
   {
       ::anda3=280;
       basket3=2;
       score+=10;

       move1r=0;
       move1l=0;
       move2r=1;
       move2l=1;

       delay(200);
   }
   else
   {
       fall++;
       FALL();
       score-=5;
       delay(200);
   }

}

void CHECK3_2TO3()
{
   if(xr2>330&&xr2<380||xl2>330&&xl2<380)
   {
       ::anda3=180;
       basket3=3;
       score+=10;

       move2r=0;
       move2l=0;
       move3r=1;
       move3l=1;

       delay(200);
   }
   else
   {
       fall++;
       score-=5;
       FALL();
       delay(200);
   }

}

void CHECK3_3TO4()
{

   if(xr3>330&&xr3<380||xl3>330&&xl3<380)
   {
       ::anda3=80;
       basket3=4;
       score+=10;

       move3r=0;
       move3l=0;
       move4r=1;
       move4l=1;


       delay(200);
   }
   else
   {
       fall++;
       score-=5;
       FALL();
       delay(200);
   }
  lvl_stat++;
}