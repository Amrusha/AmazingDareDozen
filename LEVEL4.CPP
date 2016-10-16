#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>
#include <process.h>
#include <alloc.h>
#include <stdlib.h>
#include <iostream.h>

void CHECK4_1TO2();
void CHECK4_2TO3();

int anda4=360;
int basket4=1;

void lvl4()
{
    setcolor(1);
    settextstyle(2,0,7);
    outtextxy(500,10,"LEVEL 3");
    setcolor(15);
    settextstyle(2,0,7);
    outtextxy(500,10,"LEVEL 4");

    setcolor(2);
    setfillstyle(9,4);
    floodfill(350,200,15);
    setfillstyle(9,2);
    floodfill(350,200,15);
    delay(200);

}

void CHECK4_1TO2()
{

   if(xl1>330&&xl1<380||xr1>330&&xr1<380)
   {
       ::anda4=230;
       basket4=2;
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
       score-=5;
       FALL();
       delay(200);
   }

}

void CHECK4_2TO3()
{
   if(xl2>330&&xl2<=380||xr2>330&&xr2<380)
   {
       ::anda4=180;
       basket4=3;
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
 lvl_stat++;
}
