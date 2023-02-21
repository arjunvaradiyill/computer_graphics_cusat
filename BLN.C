#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
void dc(int xc,int yc,int x,int y)
{
	putpixel(xc+x,yc+y,YELLOW);
	putpixel(x+xc,yc-y,YELLOW);
	putpixel(xc-x,yc+y,YELLOW);
	putpixel(xc-x,yc-y,YELLOW);
	putpixel(xc+y,yc+x,YELLOW);
	putpixel(xc+y,yc-x,YELLOW);
	putpixel(xc-y,yc+x,YELLOW);
	putpixel(xc-y,yc-x,YELLOW);
}
void bcircle(int xc,int yc,int r)
{
	int x=0,y=r,e=3-(2*r);
	dc(xc,yc,x,y);
	while(x<=y)
	{
		if(e<=0)
		e=e+(4*x)+6;
		else
		{
			e=e+(4*x)-(4*y)+10;
			y--;
		}
		x++;
		dc(xc,yc,x,y);

	}
}
void main()
{
	int i,j,xc,yc,r;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\TC\BGI");
	printf("ENTER VALUES OF XC,YC,R : ");
	scanf("%d%d%d",&xc,&yc,&r);
	for(i=xc,j=yc;i<=i&&j<=i;i++,j++)
	{
		if(i<480)
		{
			setcolor(YELLOW);
			bcircle(0+(i+20),400-j-5,r);
			floodfill(0+(i+20),400-j-5,YELLOW);
			setfillstyle(SOLID_FILL,YELLOW);
			setcolor(10);
			line(0+(i+20),448-j-5,0+(i+20),520-j-5);
		}
		if(i==480)
		{
			break;
		}
		delay(50);
		cleardevice();

	}
	getch();
	closegraph();
}