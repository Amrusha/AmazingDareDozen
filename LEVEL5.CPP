#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>
#include <process.h>
#include <alloc.h>
#include <stdlib.h>
#include <iostream.h>

void CHECK5_1TO2();
void CHECK5_1TO3();
void CHECK5_1TO4();


     int egg1=0,egg2=0,egg3=0;
     int xy=0,flag=0;
     int yl1=0,yl2=0,yl3=0;
     int X1,Y1,Z1;
     int X2,Y2,Z2;
     int X3,Y3,Z3;
     int X4,Y4,Z4;
     int X5,Y5,Z5;
     int X6,Y6,Z6;


void lvl5()
{
    setcolor(1);
    settextstyle(2,0,7);
    outtextxy(500,10,"LEVEL 4");
    setcolor(15);
    settextstyle(2,0,7);
    outtextxy(500,10,"LEVEL 5");

    setcolor(2);
    setfillstyle(9,4);
    floodfill(350,200,15);
    setfillstyle(9,2);
    floodfill(350,200,15);

    setlinestyle(0,0,0);

//lowest basket
setcolor(6);
arc(350,400,182,0,25);
line(375,400,325,400);
setfillstyle(6,6);
floodfill(355,405,6);

setlinestyle(4,0,0);

delay(200);
}
void CHECK5_1TO2()
{

   if(xl1>=330&&xl1<=360)
   {
       egg1=1;
       score+=20;
       setfillstyle( SOLID_FILL, WHITE ) ;
       sector( 350,400, 0, 180, 10.7, 15 ) ;
       move1l=1;

       delay(200);
   }
   else
   {
       if(!flag)
       {
       fall++;
       score-=10;
       move1l=0;
       move2l=0;
       move3l=0;
       egg1=0;
       egg2=0;
       egg3=0;
       xy=0;
       flag=1;
       FALL();
       }
       delay(200);
   }
  }
void CHECK5_1TO3()
{
   if(xl2>=330&&xl2<=360)
   {
       egg2=1;
       score+=20;
       setfillstyle( SOLID_FILL, WHITE ) ;
       sector( 350,400, 0, 180, 10.7, 15 ) ;
       move2l=1;

       delay(200);
   }
   else
   {
       if(!flag)
       {
       fall++;
       score-=10;
       move1l=0;
       move2l=0;
       move3l=0;
       xy=0;
       flag=1;
       egg1=0;egg2=0;egg3=0;
       FALL();
       }
       delay(200);
   }
}

void CHECK5_1TO4()
{
   if(xl3>=340&&xl3<=360)
       {
       egg3=1;
       score+=20;
       move3l=1;

       delay(200);
       }

   else
   {
       if(!flag)
       {
       fall++;
       score-=10;
       move1l=0;
       move2l=0;
       move3l=0;
       xy=0;
       flag=1;
       egg1=0;egg2=0;egg3=0;
       FALL();
       }
       delay(200);
   }
 }

