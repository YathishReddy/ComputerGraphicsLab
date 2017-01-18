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
	draw_rect(100,100,550,200,12);
	draw_rect(100,200,550,300,15);
	draw_rect(100,300,550,400,2);
	int rx = 325, ry = 250;
	int rad = 50;
	float angle = 1.0/rad;
	float Dtheta = PI/12.0;
	int i = 0;
	float radian = 0.0;
	float x,y;
	while (radian <= 2*PI)
	{
		x = rx + rad*cos(radian);
		y = ry + rad*sin(radian);
		putpixel(x,y,1);
		radian += angle;
	}
	radian = 0.0;
	float ang = 0.0;
	while(i<24)
	{
		x = rx + rad*cos(radian);
		y = ry + rad*sin(radian);
		dda_line(rx,ry,x,y,1);
		radian += Dtheta;
		i++;
	}
	getch();
	closegraph();
	return 0;
}
	

