#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>
#include <process.h>
#include <alloc.h>
#include <stdlib.h>
#include <iostream.h>

int lvl_stat=0;
int fall=0;
int score=0;
int move1l=0,move1r=0,move2l=0,move3l=0;
int move2r=0,move3r=0,move4l=0,move4r=0;
int xl1,xr1,xl2,xr2,xl3,xl4,xr4,xr3;
int count=0;
void FALL();
void gam_ovr();
void spiral();
void disp_score();
int b=0;

#include"C:\TC\BIN\PROJECT\LEVEL1.cpp"
#include"C:\TC\BIN\PROJECT\LEVEL2.cpp"
#include"C:\TC\BIN\PROJECT\LEVEL3.cpp"
#include"C:\TC\BIN\PROJECT\LEVEL4.cpp"
#include"C:\TC\BIN\PROJECT\LEVEL5.cpp"
#include"C:\TC\BIN\PROJECT\FRONT.cpp"
#include"C:\TC\BIN\PROJECT\BACK.cpp"

//Declaration for  i/o Registers
 union REGS i,o ;


// INITIALISES MOUSE
interrupt initmouse()
 {
  i.x.ax = 0 ;
  int86(0x33, &i, &o) ;
  return ( o.x.ax == 0 ? -1:0 ) ;

 }


 //DISPLAY MOUSE POINTER
  showmouseptr()
  {
    i.x.ax = 1 ;
    int86( 0x33, &i, &o );
  }

 //RESTRICTS MOUSE POINTER
     restrictmouseptr(int x1, int y1, int x2, int y2 )
     {
     i.x.ax = 7 ;
     i.x.cx = x1 ;
     i.x.dx = x2 ;
     int86(0x33, &i, &o ) ;

     i.x.ax = 8 ;
     i.x.cx = y1 ;
     i.x.dx = y2 ;
     int86(0x33, &i, &o) ;

   }
  //GETS MOUSE COORDINATES AND BUTTON STATUS

  getmousepos(int *button, int *x, int *y )
  {
   i.x.ax = 3 ;
   int86(0x33, &i, &o ) ;

   *button = o.x.bx ;
   *x = o.x.cx ;
   *y = o.x.dx ;
  }

  main ()
  {
  int gd = DETECT, gm , maxx, maxy, x, y , button ;
  int init ;
  initgraph(&gd, &gm, "\\tc\\bgi ") ;

welcome();

for( int doz=0;doz<30;doz++)
{

setfillstyle(1,15);
fillellipse(600,30+doz*20,13,20);

setfillstyle(1,0);
fillellipse(585,23+doz*20,2,6);
floodfill(585,23+doz*20,0);
setfillstyle(1,15);
fillellipse(585,25+doz*20,1.7,3.5);
floodfill(585,25+doz*20,15);
setcolor(15);
arc(585,15+doz*20,20,145,2);
arc(615,15+doz*20,20,145,2);

setfillstyle(1,0);
fillellipse(615,23+doz*20,2,6);
floodfill(615,23+doz*20,0);
setfillstyle(1,15);
fillellipse(615,25+doz*20,1.7,3.5);
floodfill(615,25+doz*20,15);

setcolor(4);
setfillstyle(9,4);
sector(582,15+doz*20,180,0,6,4);
sector(600,15+doz*20,180,0,11,11);
floodfill(605,20+doz*20,15);
setcolor(4);
line(585,6+doz*20,590,16+doz*20);
line(585,7+doz*20,590,16+doz*20);

setcolor(0);
line(595,39+doz*20,606,39+doz*20);
rectangle(597,39+doz*20,599,42+doz*20);
rectangle(603,39+doz*50,605,41+doz*50);
circle(608,34+doz*20,1);
floodfill(608,34+doz*20,0);

ellipse(593,24+doz*20,0,360,1,2);
ellipse(593,24+doz*20,0,360,1.5,3);
line(587,20+doz*20,612,20);
setfillstyle(1,0);
ellipse(605,24+doz*20,127,40,4,5);//blak i
floodfill(605,24+doz*20,0);
}
for(  doz=0;doz<30;doz++)
{

setfillstyle(1,15);
fillellipse(30,10+doz*20,13,20);

setfillstyle(1,0);
fillellipse(15,23+doz*20,2,6);
floodfill(15,23+doz*20,0);
setfillstyle(1,15);
fillellipse(15,25+doz*20,1.7,3.5);
floodfill(15,25+doz*20,15);
setcolor(15);
arc(15,15+doz*20,20,145,2);
arc(45,15+doz*20,20,145,2);

setfillstyle(1,0);
fillellipse(45,23+doz*20,2,6);
floodfill(45,23+doz*20,0);
setfillstyle(1,15);
fillellipse(45,25+doz*20,1.7,3.5);
floodfill(45,25+doz*20,15);

setcolor(4);
setfillstyle(9,4);
sector(12,15+doz*20,180,0,6,4);
sector(30,15+doz*20,180,0,11,11);
floodfill(35,20+doz*20,15);
setcolor(4);
line(15,6+doz*20,590,16+doz*20);
line(15,7+doz*20,590,16+doz*20);

setcolor(0);
line(25,39+doz*20,606,39+doz*20);
rectangle(27,39+doz*20,29,42+doz*20);
rectangle(33,39+doz*50,35,41+doz*50);
circle(38,34+doz*20,1);
floodfill(38,34+doz*20,0);

ellipse(23,24+doz*20,0,360,1,2);
ellipse(23,24+doz*20,0,360,1.5,3);
line(17,20+doz*20,612,20);
setfillstyle(1,0);
ellipse(35,24+doz*20,127,40,4,5);//blak i
floodfill(35,24+doz*20,0);
}

delay(100);
settextstyle(4,0,7);
spiral();

 initmouse() ;
 showmouseptr() ;
 while(lvl_stat==0)
 {
	getmousepos(&button, &x, &y);
	if(x>=190&&x<=450&&y>=200&&y<=250)//diff in y->50
	{
	setcolor(15);
	settextstyle(3,0,5);
	outtextxy(365,200,"HELP");
	setcolor(8);
	settextstyle(3,0,5);
	outtextxy(368,203,"HELP");
	if(button==1)
	{
	setcolor(0);
	for(int page=0;page<650;page++)
	rectangle(700-page,0,800,700);
	delay(500);
	count=1;
	spiral();
	setcolor(15);
    settextstyle(2,0,5);
    outtextxy(80,50,"* This game is played with the help of a mouse.");
    outtextxy(80,70,"* The player needs to get the basket to the next ");
    outtextxy(80,90,"  by clicking anywhere on the screen.");
    outtextxy(80,110,"* Player needs to pass through 20 baskets in 5");
    outtextxy(80,130,"  levels with the highest scores to win this game .");
    outtextxy(80,150,"* With success in getting to the higher basket");
    outtextxy(80,170,"  the player is awarded +10 or +15(level 5).");
    outtextxy(80,190,"* if the player fails to put the egg to the next ");
    outtextxy(80,210,"  basket,he/she gets -5 or -10(level5)score as well ");
    outtextxy(80,230,"  as an egg less from the dozen and so on....");
    outtextxy(80,250,"* When the player loses all the eggs from the egg box");
    outtextxy(80,270,"  the game gets over.");
    getch();
    cleardevice();
    welcome();
    count=0;
    spiral();
	}
	}
	else
	{
	setcolor(8);
	settextstyle(3,0,5);
	outtextxy(365,200,"HELP");
	setcolor(3);
	settextstyle(3,0,5);
	outtextxy(368,203,"HELP");

	}
	if(x>=265&&x<=450&&y>=100&&y<=150)
	{
	setcolor(8);
	settextstyle(3,0,5);
	outtextxy(268,103,"PLAY");
	setcolor(15);
	settextstyle(3,0,5);
	outtextxy(265,100,"PLAY");
	if(button==1)
	b=1;
	}
	else
	{
	setcolor(8);
	settextstyle(3,0,5);
	outtextxy(265,100,"PLAY");
	setcolor(3);
	settextstyle(3,0,5);
	outtextxy(268,103,"PLAY");
	}
	if(x>=370&&x<=550&&y>=300&&y<=350)
	{
	setcolor(15);
	settextstyle(3,0,5);
	outtextxy(470,300,"QUIT");
	setcolor(8);
	settextstyle(3,0,5);
	outtextxy(473,303,"QUIT");
	}
	else
	{
	setcolor(8);
	settextstyle(3,0,5);
	outtextxy(470,300,"QUIT");
	setcolor(3);
	settextstyle(3,0,5);
	outtextxy(473,303,"QUIT");
	}

	//click detection
	if(button==1)
	{
	if(x>=370&&x<=550&&y>=300&&y<=350)
	exit(0);
	}
	if( (button & 2)==2)
		outtextxy(100, 100, "dfsd");
		if(b)
		lvl_stat=1;
 }
  cleardevice();
  setcolor(15);
  settextstyle(2,0,5);
  setfillstyle(9,1);
  floodfill(0,0,1);

  //2nd circle
  circle(70,200,40);
  setfillstyle(9,1);
  floodfill(70,200,15);

  circle(70,200,35);
  setfillstyle(9,3);
  floodfill(70,200,15);

  circle(70,200,25);
  setfillstyle(9,5);
  floodfill(70,200,15);

  circle(70,200,20);
  setfillstyle(9,10);
  floodfill(70,200,15);

  circle(70,200,10);
  setfillstyle(9,2);
  floodfill(70,200,15);

  //1st circle

  circle(10,300,104);
  setfillstyle(9,1);
  floodfill(10,300,15);

  circle(10,300,100);
  setfillstyle(9,10);
  floodfill(10,300,15);

  circle(10,300,80);
  setfillstyle(9,5);
  floodfill(10,300,15);

  circle(10,300,73);
  setfillstyle(9,3);
  floodfill(10,300,15);

  circle(10,300,55);
  setfillstyle(9,1);
  floodfill(10,300,15);

  circle(10,300,50);
  setfillstyle(9,2);
  floodfill(10,300,15);

  //3rd circle
  circle(100,400,50);
  setfillstyle(9,1);
  floodfill(100,400,15);

  circle(100,400,45);
  setfillstyle(9,3);
  floodfill(100,400,15);

  circle(100,400,25);
  setfillstyle(9,5);
  floodfill(100,400,15);

  circle(100,400,20);
  setfillstyle(9,10);
  floodfill(100,400,15);

  circle(100,400,5);
  setfillstyle(9,2);
  floodfill(100,400,15);

  //4th

  circle(150,250,35);
  setfillstyle(9,1);
  floodfill(150,250,15);

  circle(150,250,30);
  setfillstyle(9,10);
  floodfill(150,250,15);

  circle(150,250,15);
  setfillstyle(9,2);
  floodfill(150,250,15);

  circle(150,250,7);
  setfillstyle(9,5);
  floodfill(150,250,15);

  //eggbox
  setcolor(15);
  rectangle(10,30,50,150);
  line(30,30,30,150);
  line(10,50,50,50);
  line(10,90,50,90);
  line(10,70,50,70);
  line(10,110,50,110);
  line(10,130,50,130);
  for(int egg=0;egg<=100;egg+=20)
  {
  setfillstyle(1,15);
  sector(20,40+egg,10,360,6,7);
  setfillstyle(1,1);
  floodfill(25,45+egg,15);
  }
  for( egg=0;egg<=100;egg+=20)
  {
  setfillstyle(1,15);
  sector(40,40+egg,10,360,6,7);
  setfillstyle(1,1);
  floodfill(45,45+egg,15);
  }

  //outer board
  setcolor(15);
  setfillstyle(10,1);
  ellipse(350,240,0,360,180,235);
  ellipse(350,240,0,360,160,230);
  floodfill(180,300,15);
  setfillstyle(9,MAGENTA);
  ellipse(350,240,0,360,160,220);
  floodfill(310,20,15);
  floodfill(310,460,15);
  setlinestyle(3,1,2);
  setfillstyle(9,2);
  floodfill(350,200,15);
  outtextxy(500,455,"press esc to quit ");

  initmouse() ;
  showmouseptr() ;

  if(lvl_stat==1)
  {
  move3r=0;
  move3l=0;
  move4r=0;
  move4l=0;

  lvl1();

  do
  {
  for( int i=0,k=0;i<220&&k<200;i++,k++)
	{
	getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=600)
	     {
	     if(basket==1||::anda==400)
	     CHECK1_1TO2();
	     else if(basket==2||::anda==320)
	     CHECK1_2TO3();
	     else if(basket==3||::anda==240)
	     CHECK1_3TO4();
	     else if(basket==4||::anda==160)
	     CHECK1_4TO5();
	     }

	     if(kbhit())
	     exit(0);

	       //moving low3 basket frm lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 235+k, 240, 180, 360, 26 ) ;
		delay( 5 ) ;
		setcolor( 6 );
		setfillstyle(  9 , 2 );
		pieslice( 235+k, 240, 180, 360, 26 ) ;
		xr3=235+k;

		//moving low4 basket frm r8 2 left
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 450-i, 160, 180, 360, 26 ) ;
		delay( 5 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( 450-i, 160, 180, 360, 26 ) ;
		xl4=450-i;

		if(move3r)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector( 235+k,240,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector( 235+k,240,0,180,10.7,15);
		move3l=1;
		}
		if(move4l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(450-i,160,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(450-i,160,0,180,10.7,15);
		move4r=1;
		}
	}
	for(int j=0,l=0;j<250&&l<200;j++,l++)
	{
	getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=400)
	     {
	     if(basket==1||::anda==400)
	     CHECK1_1TO2();
	     else if(basket==2||::anda==320)
	     CHECK1_2TO3();
	     else if(basket==3||::anda==240)
	     CHECK1_3TO4();
	     else if(basket==4||::anda==160)
	     CHECK1_4TO5();
	     }

	     if(kbhit())
	     exit(0);

		//movin low3 baskt frm r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 460-j, 240, 180, 360, 26 ) ;
		delay( 5 ) ;
		setcolor( 6 );
		setfillstyle(  9 , 2 );
		pieslice( 460-j, 240, 180, 360, 26 ) ;
		xl3=480-j;

		//movin low4 basket frm lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 235+j, 160, 180, 360, 26 ) ;
		delay( 5 ) ;
		setcolor( 6 );
		setfillstyle(  9 , 2 );
		pieslice( 235+j, 160, 180, 360, 26 ) ;
		xr4=225+j;

		if(move3l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector( 460-j,240,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector( 460-j,240,0,180,10.7,15);
		move3r=1;
		}
		if(move4r)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(235+j,160,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(235+j,160,0,180,10.7,15);
		move4l=1;
		}
	}
	}while(lvl_stat==1);
  }

  if(lvl_stat==2)
  {

  move2r=0;
  move2l=0;
  move4l=0;
  move4r=0;

  lvl2();
  do
  {
  for(int i=0;i<190;i++)
  {
	 getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=600)
	     {
	     if(basket2==1||::anda2==400)
	     CHECK2_1TO2();
	     else if(basket2==2||::anda2==300)
	     CHECK2_2TO3();
	     else if(basket2==3||::anda2==200)
	     CHECK2_3TO4();
	     }

	     if(kbhit())
	     exit(0);

		//moving low2 basket frm r8 2 left
		setcolor(6);
		setfillstyle(6,6);
		pieslice(450-i,300,180,360,26  ) ;
		delay( 5 ) ;
		setcolor( 2);
		setfillstyle(  9 , 2);
		pieslice( 450-i, 300, 180, 360, 26 ) ;
		xl2=450-i;

		//moving low4 basket frm r8 2 left
		setcolor(6);
		setfillstyle(6,6);
		pieslice(447-i,100,  180, 360, 26 ) ;
		delay( 5 ) ;
		setcolor( 2);
		setfillstyle(  9 , 2 );
		pieslice( 447-i, 100, 180, 360, 26 ) ;
		xl4=447-i;

		if(move2l)
		{

		setcolor(15);
		setfillstyle(1,15);
		sector(451-i,300,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(451-i,300,0,180,10.7,15);
		move2r=1;
		}
		if(move4l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(447-i,100,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(447-i,100,0,180,10.7,15);
		}
 }//for

 for(int j=0;j<193;j++)
 {
	getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=600)
	     {
	     if(basket2==1||::anda2==400)
	     CHECK2_1TO2();
	     else if(basket2==2||::anda2==300)
	     CHECK2_2TO3();
	     else if(basket2==3||::anda2==200)
	     CHECK2_3TO4();
	     }

	     if(kbhit())
	     exit(0);

		//movin low2 basket frm lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 250+j, 300, 180, 360, 26 ) ;
		delay( 5 ) ;
		setcolor( 2 );
		setfillstyle(  9 , 2 );
		pieslice( 250+j, 300, 180, 360, 26 ) ;
		xr2=250+j;

		//movin low4 frm lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 255+j, 100, 180, 360, 26 ) ;
		delay( 5 ) ;
		setcolor( 2 );
		setfillstyle(  9 , 2 );
		pieslice( 255+j, 100, 180, 360, 26 ) ;
		xr4=255+j;

		if(move2r)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(251+j,300,0,180,10.7,15);
		delay(1);
		setcolor(1);
		setfillstyle(9,2);
		sector(251+j,300,0,180,10.7,15);
		move2l=1;
		}
		if(move4r)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(253+j,100,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(253+j,100,0,180,10.7,15);
		}
 }//for
}while(::anda2!=100||lvl_stat==2);
  }

  if(lvl_stat==3)
  {
    move1r=1;
    move1l=1;
    move2l=0;
    move2r=0;
    move3r=0;
    move3l=0;
    move4l=0;
    move4r=0;

    lvl3();

    do
    {
      for(int a=0;a<201;a++)
      {
	getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=600)
	     {
	     if(basket3==1||::anda3==380)
	     CHECK3_1TO2();
	     else if(basket3==2||::anda3==280)
	     CHECK3_2TO3();
	     else if(basket3==3||::anda3==180)
	     CHECK3_3TO4();
	     }

	     if(a<180)
	     {
		//move low1 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 260+a, 380, 180, 360, 26 ) ;
	     }
	     if(a<200)
	     {
	     //move low2 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(448-a,280,180,360,26  ) ;
		//move low3 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 250+a, 180, 180, 360, 26 ) ;
	     }
	     if(a<165)
	     {
	     //move low4 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(435-a,80,180,360,26  ) ;
	     }

	     if(a<180)
	     {
		//move low1 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 260+a, 380, 180, 360, 26 ) ;
		//delay( 1 ) ;
		setcolor( 2 );
		setfillstyle(  9 , 2 );
		pieslice( 260+a, 380, 180, 360, 26 ) ;
		xr1=260+a;

		if(move1r)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(260+a,380,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(260+a,380,0,180,10.7,15);
		move1l=1;
		}
	     }
	     if(a<200)
	     {
	     //move low2 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(448-a,280,180,360,26  ) ;
		//delay( 1 ) ;
		setcolor( 2);
		setfillstyle(  9 , 2);
		pieslice( 448-a, 280, 180, 360, 26 ) ;
		xl2=448-a;

		if(move2l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(448-a,280,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(448-a,280,0,180,10.7,15);
		move2r=1;
		}

	     }

	     if(a<200)
	     {
	     //move low3 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 250+a, 180, 180, 360, 26 ) ;
		//delay( 1 ) ;
		setcolor( 2 );
		setfillstyle(  9 , 2 );
		pieslice( 250+a, 180, 180, 360, 26 ) ;
		xr3=250+a;

		if(move3r)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(250+a,180,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(250+a,180,0,180,10.7,15);
		move3l=1;
		}
	     }
	     if(a<165)
	     {
	     //move low4 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(435-a,80,180,360,26  ) ;
		//delay( 1 ) ;
		setcolor( 2);
		setfillstyle(  9 , 2);
		pieslice( 435-a, 80, 180, 360, 26 ) ;
		xl4=435-a;

		if(move4l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(435-a,80,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(435-a,80,0,180,10.7,15);
		move4r=1;
		}

	     }

	     if(kbhit())
	     exit(0);
      }//for

      for(a=0;a<201;a++)
      {
	getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=600)
	     {
	     if(basket3==1||::anda3==380)
	     CHECK3_1TO2();
	     else if(basket3==2||::anda3==280)
	     CHECK3_2TO3();
	     else if(basket3==3||::anda3==180)
	     CHECK3_3TO4();
	     }

	     if(a<160)
	     {
	     //move low4 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 267+a, 80, 180, 360, 26 ) ;
	     }
	     if(a<200)
	      {
	     //move low3 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(450-a,180,180,360,26  ) ;
		//move low2 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 250+a, 280, 180, 360, 26 ) ;
	     }
	     if(a<180)
	     {
	     //move low1 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(440-a,380,180,360,26  ) ;
	     }
	     if(a<160)
	     {
	     //move low4 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 267+a, 80, 180, 360, 26 ) ;
		//delay( 1 ) ;
		setcolor( 2 );
		setfillstyle(  9 , 2 );
		pieslice( 267+a, 80, 180, 360, 26 ) ;
		xr4=267+a;

		if(move4r)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(267+a,80,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(267+a,80,0,180,10.7,15);
		move4l=1;
		}
	      }

	      if(a<200)
	      {
	     //move low3 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(450-a,180,180,360,26  ) ;
		//delay( 1 ) ;
		setcolor( 2);
		setfillstyle(  9 , 2);
		pieslice( 450-a, 180, 180, 360, 26 ) ;
		xl3=450-a;

		if(move3l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(450-a,180,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(450-a,180,0,180,10.7,15);
		move3r=1;
		}
	      }

	      if(a<200)
	      {
	     //move low2 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 250+a, 280, 180, 360, 26 ) ;
		//delay( 1 ) ;
		setcolor( 2 );
		setfillstyle(  9 , 2 );
		pieslice( 250+a, 280, 180, 360, 26 ) ;
		xr2=250+a;

		if(move2r)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(250+a,280,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(250+a,280,0,180,10.7,15);
		move2l=1;
		}
	     }

	     if(a<180)
	     {
	     //move low1 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(440-a,380,180,360,26  ) ;
		//delay( 1 ) ;
		setcolor( 2);
		setfillstyle(  9 , 2);
		pieslice( 440-a, 380, 180, 360, 26 ) ;
		xr1=440-a;

		if(move1l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(440-a,380,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(440-a,380,0,180,10.7,15);
		move1r=1;
		}
	     }

	     if(kbhit())
	     exit(0);
      }//for
    }while(anda3!=80||lvl_stat==3);
  }

  if(lvl_stat==4)
  {
    lvl4();

    move1r=1;
    move1l=1;
    move2l=0;
    move2r=0;
    move3r=0;
    move3l=0;

    do
    {
      for(int a=0;a<191;a++)
      {
	getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=600)
	     {
	     if(basket4==1||::anda4==360)
	     CHECK4_1TO2();
	     else if(basket4==2||::anda4==230)
	     CHECK4_2TO3();
	     }
	     if(a<180)
	     {
	     //move low1 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 260+a, 360, 180, 360, 26 ) ;
	     }
	     if(a<200)
	     {
	     //move low2 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(448-a,230,180,360,26  ) ;
	     }
	     if(a<190)
	     {
	     //move low3 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 250+a, 100, 180, 360, 26 ) ;
	     }
	     if(a<180)
	     {
	     //move low1 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 260+a, 360, 180, 360, 26 ) ;
		//delay( 1 ) ;
		setcolor( 2 );
		setfillstyle(  9 , 2 );
		pieslice( 260+a, 360, 180, 360, 26 ) ;
		xr1=260+a;

		if(move1r)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(260+a,360,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(260+a,360,0,180,10.7,15);
		move1l=1;
		}
	     }
	     if(a<200)
	     {
	     //move low2 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(448-a,230,180,360,26  ) ;
		//delay( 1 ) ;
		setcolor( 2);
		setfillstyle(  9 , 2);
		pieslice( 448-a, 230, 180, 360, 26 ) ;
		xl2=448-a;

		if(move2l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(448-a,230,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(448-a,230,0,180,10.7,15);
		move2r=1;
		}

	     }

	     if(a<190)
	     {
	     //move low3 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 250+a, 100, 180, 360, 26 ) ;
		//delay( 1 ) ;
		setcolor( 2 );
		setfillstyle(  9 , 2 );
		pieslice( 250+a, 100, 180, 360, 26 ) ;
		xr3=250+a;

		if(move3r)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(250+a,100,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(250+a,100,0,180,10.7,15);
		move3l=1;
		}
	     }

	     if(kbhit())
	     exit(0);
      }//for

      for(a=0;a<191;a++)
      {
	getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=600)
	     {
	     if(basket3==1||::anda3==360)
	     CHECK4_1TO2();
	     else if(basket3==2||::anda3==230)
	     CHECK4_2TO3();
	     }
		if(kbhit())
	     exit(0);

	      if(a<190)
	      {
	     //move low3 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(450-a,100,180,360,26  ) ;
	     }
	     if(a<200)
	      {
	     //move low2 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 250+a, 230, 180, 360, 26 ) ;
	     }
	     if(a<180)
	     {
	     //move low1 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(440-a,360,180,360,26  ) ;
	     }
	      if(a<190)
	      {
	     //move low3 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(450-a,100,180,360,26  ) ;
		//delay( 1 ) ;
		setcolor( 2);
		setfillstyle(  9 , 2);
		pieslice( 450-a, 100, 180, 360, 26 ) ;
		xl3=450-a;

		if(move3l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(450-a,100,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(450-a,100,0,180,10.7,15);
		move3r=1;
		}
	      }
	      if(a<200)
	      {
	     //move low2 lft 2 r8
		setcolor(6);
		setfillstyle(6,6);
		pieslice( 250+a, 230, 180, 360, 26 ) ;
		//delay( 1 ) ;
		setcolor( 2 );
		setfillstyle(  9 , 2 );
		pieslice( 250+a, 230, 180, 360, 26 ) ;
		xr2=250+a;

		if(move2r)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(250+a,230,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(250+a,230,0,180,10.7,15);
		move2l=1;
		}
	     }
	     if(a<180)
	     {
	     //move low1 r8 2 lft
		setcolor(6);
		setfillstyle(6,6);
		pieslice(440-a,360,180,360,26  ) ;
		//delay( 1 ) ;
		setcolor( 2);
		setfillstyle(  9 , 2);
		pieslice( 440-a, 360, 180, 360, 26 ) ;
		xr1=440-a;

		if(move1l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(440-a,360,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(440-a,360,0,180,10.7,15);
		move1r=1;
		}
	     }

      }//for
    }while(anda4!=80&&lvl_stat==4);
  }
  if(lvl_stat==5)
  {
     lvl5();
     move1l=0;
     move2l=0;
     move3l=0;

setfillstyle( SOLID_FILL, WHITE ) ;
sector( 350,400, 0, 180, 10.7, 15 ) ;

do
{
for(int i=0;i<90;i++)
{
	     getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=600)
	     {
	     if(egg1==0&&yl1>=180)
	     {
	     CHECK5_1TO2();
	     }
	     if(egg2==0&&yl2>=180)
	     {
	     CHECK5_1TO3();
	     }
	     if(egg3==0&&yl3>=180)
	     {
	     CHECK5_1TO4();
	     }
	     flag=0;
	     }
	     if(kbhit())
	     exit(0);

		setcolor(6);
		setfillstyle(6,6);
		pieslice( 250+i, 200, 180, 360, 26 ) ;
		pieslice( 450, 200-i, 180, 360, 26 ) ;
		pieslice( 350-i, 100, 180, 360, 26 ) ;

		setcolor(6);
		setfillstyle(6,6);
		pieslice( 250+i, 200, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( 250+i, 200, 180, 360, 26 ) ;
		X1=250+i;
		xl1=X1;
		yl1=200;
		if(move1l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(X1,200,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(X1,200,0,180,10.7,15);
		}

		setcolor(6);
		setfillstyle(6,6);
		pieslice( 450, 200-i, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( 450, 200-i, 180, 360, 26 ) ;
		Y1=200-i;
		xl2=450;
		yl2=200-i;
		if(move2l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(450,Y1,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(450,Y1,0,180,10.7,15);
		}

		setcolor(6);
		setfillstyle(6,6);
		pieslice( 350-i, 100, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( 350-i, 100, 180, 360, 26 ) ;
		Z1=350-i;
		xl3=Z1;
		yl3=100;
		if(move3l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(Z1,100,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(Z1,100,0,180,10.7,15);
		}
 xy=1;
}
X1++;
Y1--;
Z1--;
for(i=0;i<90;i++)
{
setlinestyle(4,0,0);

	     getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=600)
	     {
	     if(egg1==0&&yl1>=180)
	     {
	     CHECK5_1TO2();
	     }
	     if(egg2==0&&yl2>=180)
	     {
	     CHECK5_1TO3();
	     }
	     if(egg3==0&&yl3>=180)
	     {
	     CHECK5_1TO4();
	     }
	     flag=0;
	     }
	     if(kbhit())
	     exit(0);

		setcolor(6);
		setfillstyle(6,6);
		pieslice( X1+i, 200, 180, 360, 26 ) ;
		pieslice( 450-i, Y1, 180, 360, 26 ) ;
		pieslice( Z1, 100+i, 180, 360, 26 ) ;

		setcolor(6);
		setfillstyle(6,6);
		pieslice( X1+i, 200, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( X1+i, 200, 180, 360, 26 ) ;
		X2=X1+i;
		xl1=X2;
		yl1=200;
		if(move1l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(X2,200,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(X2,200,0,180,10.7,15);
		}

		setcolor(6);
		setfillstyle(6,6);
		pieslice( 450-i, Y1, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( 450-i, Y1, 180, 360, 26 ) ;
		Y2=450-i;
		xl2=Y2;
		yl2=Y1;
		if(move2l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(Y2,Y1,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(Y2,Y1,0,180,10.7,15);
		}

		setcolor(6);
		setfillstyle(6,6);
		pieslice( Z1, 100+i, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( Z1, 100+i, 180, 360, 26 ) ;
		Z2=100+i;
		xl3=Z1;
		yl3=Z2;
		if(move3l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(Z1,Z2,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(Z1,Z2,0,180,10.7,15);
		}
  xy=2;
}
X2++;
Y2--;
Z2++;

for(i=0;i<90;i++)
{
setlinestyle(4,0,0);

	     getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=600)
	     {
	     if(egg1==0&&yl1>=180)
	     {
	     CHECK5_1TO2();
	     }
	     if(egg2==0&&yl2>=180)
	     {
	     CHECK5_1TO3();
	     }
	     if(egg3==0&&yl3>=180)
	     {
	     CHECK5_1TO4();
	     }
	     flag=0;
	     }
	     if(kbhit())
	     exit(0);

		setcolor(6);
		setfillstyle(6,6);
		pieslice( X2, 200-i, 180, 360, 26 ) ;
		pieslice( Y2-i, Y1, 180, 360, 26 ) ;
		pieslice( Z1+i, Z2, 180, 360, 26 ) ;

		setcolor(6);
		setfillstyle(6,6);
		pieslice( X2, 200-i, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( X2, 200-i, 180, 360, 26 ) ;
		X3=200-i;
		xl1=X2;
		yl1=X3;
		if(move1l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(X2,200-i,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(X2,200-i,0,180,10.7,15);
		}

		setcolor(6);
		setfillstyle(6,6);
		pieslice( Y2-i, Y1, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( Y2-i, Y1, 180, 360, 26 ) ;
		Y3=Y2-i;
		xl2=Y3;
		yl2=Y1;
		if(move2l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(Y3,Y1,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(Y3,Y1,0,180,10.7,15);
		}

		setcolor(6);
		setfillstyle(6,6);
		pieslice( Z1+i, Z2, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( Z1+i, Z2, 180, 360, 26 ) ;
		Z3=Z1+i;
		xl3=Z3;
		yl3=Z2;
		if(move3l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(Z3,Z2,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(Z3,Z2,0,180,10.7,15);
		}
   xy=3;
}
X3--;
Y3--;
Z3++;

for(i=0;i<90;i++)
{
setlinestyle(4,0,0);

	     getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=600)
	     {
	     if(egg1==0&&yl1>=180)
	     {
	     CHECK5_1TO2();
	     }
	     if(egg2==0&&yl2>=180)
	     {
	     CHECK5_1TO3();
	     }
	     if(egg3==0&&yl3>=180)
	     {
	     CHECK5_1TO4();
	     }
	     flag=0;
	     }
	     if(kbhit())
	     exit(0);
		setcolor(6);
		setfillstyle(6,6);
		pieslice( X2-i, X3, 180, 360, 26 ) ;
		pieslice( Y3, Y1+i, 180, 360, 26 ) ;
		pieslice( Z3+i, Z2, 180, 360, 26 ) ;

		setcolor(6);
		setfillstyle(6,6);
		pieslice( X2-i, X3, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( X2-i, X3, 180, 360, 26 ) ;
		X4=X2-i;
		xl1=X4;
		yl1=X3;
		if(move1l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(X4,X3,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(X4,X3,0,180,10.7,15);
		}

		setcolor(6);
		setfillstyle(6,6);
		pieslice( Y3, Y1+i, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( Y3, Y1+i, 180, 360, 26 ) ;
		Y4=Y1+i;
		xl2=Y3;
		yl2=Y4;
		if(move2l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(Y3,Y4,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(Y3,Y4,0,180,10.7,15);
		}

		setcolor(6);
		setfillstyle(6,6);
		pieslice( Z3+i, Z2, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( Z3+i, Z2, 180, 360, 26 ) ;
		Z4=Z3+i;
		xl3=Z4;
		yl3=Z2;
		if(move3l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(Z4,Z2,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(Z4,Z2,0,180,10.7,15);
		}
  xy=4;
}
X4--;
Y4++;
Z4++;

for(i=0;i<90;i++)
{
setlinestyle(4,0,0);

	     getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=600)
	     {
	     if(egg1==0&&yl1>=180)
	     {
	     CHECK5_1TO2();
	     }
	     if(egg2==0&&yl2>=180)
	     {
	     CHECK5_1TO3();
	     }
	     if(egg3==0&&yl3>=180)
	     {
	     CHECK5_1TO4();
	     }
	     flag=0;
	     }
	     if(kbhit())
	     exit(0);

		setcolor(6);
		setfillstyle(6,6);
		pieslice( X4-i, X3, 180, 360, 26 ) ;
		pieslice( Y3+i, Y4, 180, 360, 26 ) ;
		pieslice( Z4, Z2-i, 180, 360, 26 ) ;

		setcolor(6);
		setfillstyle(6,6);
		pieslice( X4-i, X3, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( X4-i, X3, 180, 360, 26 ) ;
		X5=X4-i;
		xl1=X5;
		yl1=X3;
		if(move1l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(X5,X3,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(X5,X3,0,180,10.7,15);
		}

		setcolor(6);
		setfillstyle(6,6);
		pieslice( Y3+i, Y4, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( Y3+i, Y4, 180, 360, 26 ) ;
		Y5=Y3+i;
		xl2=Y5;
		yl2=Y4;
		if(move2l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(Y5,Y4,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(Y5,Y4,0,180,10.7,15);
		}

		setcolor(6);
		setfillstyle(6,6);
		pieslice( Z4, Z2-i, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6 );
		setfillstyle(  9 , 2 );
		pieslice( Z4, Z2-i, 180, 360, 26 ) ;
		Z5=Z2-i;
		xl3=Z4;
		yl3=Z5;
		if(move3l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(Z4,Z5,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(Z4,Z5,0,180,10.7,15);
		}
  xy=5;
}
X5++;
Y5--;
Z5--;

for(i=0;i<90;i++)
{
setlinestyle(4,0,0);
	     getmousepos(&button, &x, &y);

	     if(button==1)
	     if(x>=0&&x<=700&&y>=0&&y<=600)
	     {
	     if(egg1==0&&yl1>=180)
	     {
	     CHECK5_1TO2();
	     }
	     if(egg2==0&&yl2>=180)
	     {
	     CHECK5_1TO3();
	     }
	     if(egg3==0&&yl3>=180)
	     {
	     CHECK5_1TO4();
	     }
	     flag=0;
	     }
	     if(kbhit())
	     exit(0);

		setcolor(6);
		setfillstyle(6,6);
		pieslice( X5, X3+i, 180, 360, 26 ) ;
		pieslice( Y5+i, Y4, 180, 360, 26 ) ;
		pieslice( Z4-i, Z5, 180, 360, 26 ) ;

		setcolor(6);
		setfillstyle(6,6);
		pieslice( X5, X3+i, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( X5, X3+i, 180, 360, 26 ) ;
		X6=X3+i;
		xl1=X5;
		yl1=X6;
		if(move1l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(X5,X6,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(X5,X6,0,180,10.7,15);
		}

		setcolor(6);
		setfillstyle(6,6);
		pieslice( Y5+i, Y4, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( Y5+i, Y4, 180, 360, 26 ) ;
		Y6=Y5+i;
		xl2=Y6;
		yl2=Y4;
		if(move2l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(Y6,Y4,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(Y6,Y4,0,180,10.7,15);
		}

		setcolor(6);
		setfillstyle(6,6);
		pieslice( Z4-i, Z5, 180, 360, 26 ) ;
		delay( 1 ) ;
		setcolor( 6);
		setfillstyle(  9 , 2 );
		pieslice( Z4-i, Z5, 180, 360, 26 ) ;
		Z6=Z4-i;
		xl3=Z6;
		yl3=Z5;
		if(move3l)
		{
		setcolor(15);
		setfillstyle(1,15);
		sector(Z6,Z5,0,180,10.7,15);
		delay(1);
		setcolor(2);
		setfillstyle(9,2);
		sector(Z6,Z5,0,180,10.7,15);
		}
  xy=6;
}
if(egg1==1)
if(egg2==1)
if(egg3==1)
lvl_stat=0;
}while(lvl_stat==5);
bye();
  }
  getch();
}
void FALL()
{
setcolor(1);
int y;
switch(fall)
{
case 1:y=40;
       break;
case 2:y=60;
       break;
case 3:y=80;
       break;
case 4:y=100;
       break;
case 5:y=120;
       break;
case 6:y=140;
       break;
case 7:y=40;
       break;
case 8:y=60;
       break;
case 9:y=80;
       break;
case 10:y=100;
       break;
case 11:y=120;
       break;
case 12:y=140;
	gam_ovr();
	break;
default:exit(0);
}
if(fall<=6)
{
setfillstyle(1,1);
sector(20,y,0,360,6,9);
setfillstyle(1,1);
floodfill(25,y+5,15);
}
if(fall>=7)
{
setfillstyle(1,1);
sector(40,y,0,360,6,8);
setfillstyle(1,1);
floodfill(45,y+5,15);
}
}

void gam_ovr()
{
cleardevice();
setcolor(1);
circle(250,250,30);
floodfill(250,250,1);
setlinestyle(1,0,0);
for(int i=0;i<700;i++)
{
int x=random(500);
int y=random(500);
line(y,x,800,y);
}
for(i=0;i<700;i++)
{
int x=random(500);
int y=random(500);
line(0,x,800,y);
}
for( i=0;i<100;i++)
{
if(i<60)
{
setcolor(15);
settextstyle(4,0,7);
outtextxy(300,500-i*2.5,"OvEr");
outtextxy(10,500-i*4,"O");
outtextxy(100,(500-i*5),"iii");
outtextxy(165,(500-i*4),"2");
outtextxy(195,(500-i*3),"**__");
}
if(i>=60)
{
setcolor(15);
settextstyle(4,0,7);
outtextxy(300,500-i*2.5,"oVeR");
}
if(i<99)
{
setcolor(0);
settextstyle(4,0,7);
outtextxy(300,500-i*2.5,"Dozen");
outtextxy(10,(500-i*4)+120,"a.");
outtextxy(40,(500-i*4)+120,"a.");
outtextxy(100,(500-i*6)+300,"a.");
outtextxy(160,(500-i*4)+170,"a.");
outtextxy(165,(500-i*4)+170,".7");
outtextxy(195,(500-i*3)+200,"&!");
outtextxy(365,(500-i*4)+170,"22");
outtextxy(380,(500-i*3)+170,"***");
}
}
for(i=0;i<750;i++)
{
setcolor(15);
outtextxy(600-i,40,"Game over");
delay(1);
setcolor(0);
outtextxy(600-i,40,"Game over");
}
exit(0);
}

void spiral()
{
//cleardevice();
for( int doz=0;doz<30;doz++)
{

setfillstyle(1,15);
fillellipse(600,30+doz*20,13,20);

setfillstyle(1,0);
fillellipse(585,23+doz*20,2,6);
floodfill(585,23+doz*20,0);
setfillstyle(1,15);
fillellipse(585,25+doz*20,1.7,3.5);
floodfill(585,25+doz*20,15);
setcolor(15);
arc(585,15+doz*20,20,145,2);
arc(615,15+doz*20,20,145,2);

setfillstyle(1,0);
fillellipse(615,23+doz*20,2,6);
floodfill(615,23+doz*20,0);
setfillstyle(1,15);
fillellipse(615,25+doz*20,1.7,3.5);
floodfill(615,25+doz*20,15);

setcolor(4);
setfillstyle(9,4);
sector(582,15+doz*20,180,0,6,4);
sector(600,15+doz*20,180,0,11,11);
floodfill(605,20+doz*20,15);
setcolor(4);
line(585,6+doz*20,590,16+doz*20);
line(585,7+doz*20,590,16+doz*20);

setcolor(0);
line(595,39+doz*20,606,39+doz*20);
rectangle(597,39+doz*20,599,42+doz*20);
rectangle(603,39+doz*50,605,41+doz*50);
circle(608,34+doz*20,1);
floodfill(608,34+doz*20,0);

ellipse(593,24+doz*20,0,360,1,2);
ellipse(593,24+doz*20,0,360,1.5,3);
line(587,20+doz*20,612,20);
setfillstyle(1,0);
ellipse(605,24+doz*20,127,40,4,5);//blak i
floodfill(605,24+doz*20,0);
}
for(  doz=0;doz<30;doz++)
{

setfillstyle(1,15);
fillellipse(30,10+doz*20,13,20);

setfillstyle(1,0);
fillellipse(15,23+doz*20,2,6);
floodfill(15,23+doz*20,0);
setfillstyle(1,15);
fillellipse(15,25+doz*20,1.7,3.5);
floodfill(15,25+doz*20,15);
setcolor(15);
arc(15,15+doz*20,20,145,2);
arc(45,15+doz*20,20,145,2);

setfillstyle(1,0);
fillellipse(45,23+doz*20,2,6);
floodfill(45,23+doz*20,0);
setfillstyle(1,15);
fillellipse(45,25+doz*20,1.7,3.5);
floodfill(45,25+doz*20,15);

setcolor(4);
setfillstyle(9,4);
sector(12,15+doz*20,180,0,6,4);
sector(30,15+doz*20,180,0,11,11);
floodfill(35,20+doz*20,15);
setcolor(4);
line(15,6+doz*20,590,16+doz*20);
line(15,7+doz*20,590,16+doz*20);

setcolor(0);
line(25,39+doz*20,606,39+doz*20);
rectangle(27,39+doz*20,29,42+doz*20);
rectangle(33,39+doz*50,35,41+doz*50);
circle(38,34+doz*20,1);
floodfill(38,34+doz*20,0);

ellipse(23,24+doz*20,0,360,1,2);
ellipse(23,24+doz*20,0,360,1.5,3);
line(17,20+doz*20,612,20);
setfillstyle(1,0);
ellipse(35,24+doz*20,127,40,4,5);//blak i
floodfill(35,24+doz*20,0);

if(count==1)
{
setcolor(1);
setlinestyle(1,0,1);

for(int i=0;i<70;i++)
{
int x=random(500);
int y=random(500);
line(y,x,800,y);
}
for(i=0;i<70;i++)
{
int x=random(500);
int y=random(500);
line(0,x,800,y);
}
setcolor(0);
setlinestyle(0,0,0);
}
}
}
void disp_sco()
{

}