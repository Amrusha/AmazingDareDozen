#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>
#include <process.h>
#include <alloc.h>
#include <stdlib.h>
#include <iostream.h>

  void CHECK1_1TO2();
  void CHECK1_2TO3();
  void CHECK1_3TO4();
  void CHECK1_4TO5();

  int anda=400;
  int basket=1;

void lvl1()
{

settextstyle(2,0,7);
outtextxy(500,10,"LEVEL 1");


//The ANDA
setfillstyle( SOLID_FILL, WHITE ) ;
sector( 350,400, 0, 180, 10.7, 15 ) ;

setlinestyle(0,0,0);

//lowest basket
setcolor(6);
arc(350,400,182,0,25);
line(375,400,325,400);
setfillstyle(6,6);
floodfill(355,405,6);

//lowest basket 2
setcolor(6);
arc(350,320,182,0,25);
line(375,320,325,320);
setfillstyle(6,6);
floodfill(355,325,6);

// middlemost basket
setcolor(6);
arc(235,240,182,0,25);
line(260,240,210,240);
setfillstyle(6,6);
floodfill(240,245,6);

setcolor(0);
setcolor(15);
settextstyle(2,0,5);
outtextxy(323,400," START");

//4th basket frm below
setcolor(6);
arc(450,160,182,0,25);
line(475,160,425,160);
setfillstyle(6,6);
floodfill(455,165,6);

//top basket
arc(350,80,182,0,25);
line(375,80,325,80);
setfillstyle(6,6);
floodfill(330,85,6);

setlinestyle(3,1,2);
setcolor(2);
  setfillstyle(9,4);

}

void CHECK1_1TO2()
{
       :: anda=320;
	basket=2;
	setfillstyle(9,2) ;
	sector( 350,400, 0, 180, 10.7, 15 ) ;
	setfillstyle(1,15) ;
	sector( 350,320, 0, 180, 10.7, 15 ) ;
	score+=10;
	delay(200);

}
void CHECK1_2TO3()
{
  if(xr3>330&&xr3<380||xl3>330&&xl3<380)
  {
  ::anda=240;
  basket=3;
  setfillstyle(9,2);
  sector(350,320,0,180,10.7,15);
  score+=10;
  move3r=1;
  move3l=1;
  delay(200);
  }
  else
  {
  fall++;
  score-=5;
  setfillstyle(1,15);
  sector(350,320,0,180,10.7,15);
  FALL();
  delay(200);
  }
}
void CHECK1_3TO4()
{
if(xl4>330&&xl4<380||xr4>330&&xr4<330)
  {
  ::anda=160;
  basket=4;
  move3r=0;
  move3l=0;
  move4r=1;
  move4l=1;
  score+=10;
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
void CHECK1_4TO5()
{
if(xl4>330&&xl4<380||xr4>330&&xr4<380)
  {
  ::anda=160;
  basket=5;
  setfillstyle(1,15);
  sector(350,80,0,180,10.7,15);
  move4r=0;
  move4l=0;
  score+=10;
  delay(200);
  lvl_stat=2;
  }
  else
  {
  fall++;
  score-=5;
  FALL();
  delay(200);
  }
}

