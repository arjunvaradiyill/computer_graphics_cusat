#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#define pi 3.1415

void plotcircle(int xxc,int yyc,int xx,int yy)
{
putpixel(xxc+xx,yyc+yy,15);
putpixel(xxc+xx,yyc-yy,15);
putpixel(xxc-xx,yyc+yy,15);
putpixel(xxc-xx,yyc-yy,15);
putpixel(xxc+yy,yyc+xx,15);
putpixel(xxc+yy,yyc-xx,15);
putpixel(xxc-yy,yyc+xx,15);
putpixel(xxc-yy,yyc-xx,15);
}

void dc(int xc,int yc,int r)
{
int e=3-2*r,x=0,y=r;
while(x<=y)
{plotcircle(xc,yc,x,y);
if(e<0)
{
e=e+4*x+6;
}
else
{
e=e+4*(x-y)+10;
y=y-1;
}
x=x+1;
}
}
void main()
{
int gd=DETECT,gm,sec,min,hr;
struct time t;
initgraph(&gd,&gm,"C:\TURBOC3\BGI");
while(1)
{
gettime(&t);
sec=t.ti_sec;
min=t.ti_min;
hr=t.ti_hour;
setcolor(RED);
dc(300,200,200);
outtextxy(300+180*sin(pi/6),200-180*cos(pi/6),"1");
outtextxy(300+180*sin(2*pi/6),200-180*cos(2*pi/6),"2");
outtextxy(300+180*sin(3*pi/6),200-180*cos(3*pi/6),"3");
outtextxy(300+180*sin(4*pi/6),200-180*cos(4*pi/6),"4");
outtextxy(300+180*sin(5*pi/6),200-180*cos(5*pi/6),"5");
outtextxy(300+180*sin(6*pi/6),200-180*cos(6*pi/6),"6");
outtextxy(300+180*sin(7*pi/6),200-180*cos(7*pi/6),"7");
outtextxy(300+180*sin(8*pi/6),200-180*cos(8*pi/6),"8");
outtextxy(300+180*sin(9*pi/6),200-180*cos(9*pi/6),"9");
outtextxy(300+180*sin(10*pi/6),200-180*cos(10*pi/6),"10");
outtextxy(300+180*sin(11*pi/6),200-180*cos(11*pi/6),"11");
outtextxy(300+180*sin(12*pi/6),200-180*cos(12*pi/6),"12");
setcolor(CYAN);
dc(300,200,10);
setcolor(RED);
line(300,200,300+80*sin(hr*pi/6),200-80*(hr*pi/6));
setcolor(WHITE);
line(300,200,300+120*sin(sec*pi/30),200-120*cos(sec*pi/30));
setcolor(YELLOW);
line(300,200,300+160*sin(min*pi/30),200-120*cos(min*pi/30));
delay(1000);
cleardevice();
}
}