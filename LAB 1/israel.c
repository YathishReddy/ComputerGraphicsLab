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

void draw_triangle(int x1,int y1,int x2,int y2, int x3, int y3, int color)
{
	dda_line(x1,y1,x2,y2,BLUE);
	dda_line(x1,y1,x3,y3,BLUE);
	dda_line(x2,y2,x3,y3,BLUE);	
}
int main()
{
	int gdriver = DETECT , gmode;
	initgraph(&gdriver,&gmode," ");
	draw_rect(50,50,250,65,WHITE);
	draw_rect(50,65,250,90,BLUE);
	draw_rect(50,90,250,170,WHITE);
	draw_rect(50,170,250,195,BLUE);
	draw_rect(50,195,250,220,WHITE);
	int a[0], b[0];
	int i = 0;
	float deg = PI/3;
	for(i=0;i<3;i++)
	{
		a[i] = 160 + 33*cos(PI/6 + i*deg);
		b[i] = 130 + 33*sin(PI/6 + i*deg);
	}
	draw_triangle(a[0],b[0],a[1],b[1],a[2],b[2],BLUE);
	getch();
	closegraph();
	return 0;
}
	

