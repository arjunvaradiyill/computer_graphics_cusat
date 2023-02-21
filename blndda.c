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

	while(x<=y)
	{       dc(xc,yc,x,y);
		if(e<=0)
		e=e+(4*x)+6;
		else
		{
			e=e+(4*x)-(4*y)+10;
			y--;
		}
		x++;

	}

}

void dda(int x1,int y1,int x2,int y2)
{
	int i;
	int dx=x2-x1;
	int dy=y2-y1;
	int steps=abs(dx)>abs(dy) ? abs(dx):abs(dy);
	float xinc=dx/(float)steps;
	float yinc=dy/(float)steps;
	float x=x1;
	float y=y1;
	for(i=0;i<=steps;i++)
	{
		putpixel(x,y,YELLOW);
		x+=xinc;
		y+=yinc;

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
			bcircle((i+20),400-j-5,r);
			floodfill((i+20),400-j-5,YELLOW);
			setfillstyle(SOLID_FILL,YELLOW);
			setcolor(10);
			dda((i+20),448-j-5,(i+20),520-j-5);
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