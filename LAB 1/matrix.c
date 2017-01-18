#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.14159

float max(float x, float y)
{
	if(x>=y)
		return x;
	else
		return y;
}

void dda_line(int x1,int y1,int x2,int y2, int color)
{
	float x,y, dx, dy, pix;
	dx = x2-x1;
	dy = y2-y1;
	pix = max(abs(dx), abs(dy));
	dx = dx/pix;
	dy = dy/pix;
	x = x1;
	y = y1;
	int i = 1;
	while(i<=pix)
	{
		putpixel(x,y,color);
		x = x+dx;
		y = y + dy;
		i=i+1;
	}
	return;
}

void draw_rect(int x1,int y1,int x2,int y2, int color)
{  
	int i;
	for( i = y1;i<=y2;i++)
	{
		dda_line(x1, i, x2, i, color);
	}
	return;
}

int main()
{
	int gdriver = DETECT , gmode;
	initgraph(&gdriver,&gmode," ");
	int i = 0;
	for(i = 1;i<5;i++)
	{
		draw_rect(50*i,50,250,100,i);
		draw_rect(50*i,100,250,150,(i+1)%16);
		draw_rect(50*i,150,250,200,(i+2)%16);
		draw_rect(50*i,200,250,250,(i+3)%16);
		
	}
	
	
	getch();
	closegraph();
	return 0;
}
	

