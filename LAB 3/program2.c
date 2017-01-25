#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.14159
#define sign(x) ((x > 0)? 1 : ((x < 0)? -1: 0))
int midpoint_line(int x1, int y1, int x2, int y2, int color)
{
	int x = x1; 
	int i = 0, temp = 0, D = 0;
	int y = y1;
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int s1 = sign(x2 - x1);
	int s2 = sign(y2 - y1);
	int swap = 0;
	if (dy > dx)
	{
		temp = dx; 
		dx = dy; 
		dy = temp; 
		swap = 1;
	}
	D = 2*dy - dx;
	for (i = 0; i < dx; i++) 
	{
	    putpixel(x, y,color); 
	    while (D >= 0) 
	    {
	    	D = D - 2*dx; 
	    	if (swap) 
	    		x += s1; 
	    	else 
	    		y += s2; 
	    } 
		D = D + 2*dy; 
		if (swap) 
			y += s2; 
		else 
			x += s1; 
	} 	
}

void circleBres(int xc, int yc, int r, int color)
{
	int d,x,y;
	d=3-2*r;
	x=0;
	y=r;
	while(x<=y)
	{
		putpixel(xc+x,yc+y,color);
		putpixel(xc-y,yc-x,color);
		putpixel(xc+y,yc-x,color);
		putpixel(xc-y,yc+x,color);
		putpixel(xc+y,yc+x,color);
		putpixel(xc-x,yc-y,color);
		putpixel(xc+x,yc-y,color);
		putpixel(xc-x,yc+y,color);
		if(d<=0)
		{
			d=d+4*x+6;
		}
		else
		{
			d=d+4*x-4*y+10;
			y=y-1;
		}
		x=x+1;
	}
}




int main()
{
	int gdriver = DETECT , gmode;
	initgraph(&gdriver,&gmode," ");
	int x0=0,y0=0,x1=0,y1=0,j=0;
	int dx=0,dy=0;
	float i=0;
	//Draw a pentagon
	for(i=0;i< 4*PI -1 ; i += (18*PI)/45)
	{
		x1 = 80*cos(i);
		y1 = 80*sin(i);
		i += (18*PI)/45;
		x0 = 80*cos(i);
		y0 = 80*sin(i);
		midpoint_line(100+x1,100+y1,100+x0,100+y0,WHITE);
	}
	//Rotate it by PI/3 rad
	for(i=0;i< 4*PI -1 ; i += (18*PI)/45)
	{
		x1 = 80*cos(i+PI/3);
		y1 = 80*sin(i+PI/3);
		i += (18*PI)/45;
		x0 = 80*cos(i+PI/3);
		y0 = 80*sin(i+PI/3);
		midpoint_line(250+x1,250+y1,250+x0,250+y0,WHITE);
	}
	//Tanslation
	for(i=0;i< 4*PI -1 ; i += (18*PI)/45)
	{
		x1 = 80*cos(i);
		y1 = 80*sin(i);
		i += (18*PI)/45;
		x0 = 80*cos(i);
		y0 = 80*sin(i);
		midpoint_line(375+x1,375+y1,375+x0,375+y0,WHITE);
	}
	
	
		
	getch();
	closegraph();
	return 0;
}
