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

int x[20], y[20];
int points()
{	int i;
	x[1] = 100, y[1] = 100;
	x[2] = 300, y[2] = 100;
	x[3] = 50, y[3] = 200;
	x[4] = 100, y[4] = 200;
	x[5] = 300, y[5] = 200;
	x[6] = 350, y[6] = 200;
	x[7] = 175, y[7] = 325;
	x[8] = 225, y[8] = 325;
	x[9] = 100, y[9] = 400;
	x[10] = 175, y[10] = 400;
	x[11] = 225, y[11] = 400;
	x[12] = 300, y[12] = 400;
	x[13] = 225, y[13] = 215;
	x[14] = 250, y[14] = 215;
	x[15] = 225, y[15] = 240;
	x[16] = 250, y[16] = 240;
	for(i=1;i<=16;i++)
	{
		x[i] = x[i]/2;
		y[i] = y[i]/2;
	}
}

int draw()
{
	midpoint_line(x[1],y[1],x[2],y[2],WHITE);
	midpoint_line(x[3],y[3],x[6],y[6],WHITE);
	midpoint_line(x[4],y[4],x[9],y[9],WHITE);
	midpoint_line(x[5],y[5],x[12],y[12],WHITE);
	midpoint_line(x[9],y[9],x[12],y[12],WHITE);
	midpoint_line(x[1],y[1],x[3],y[3],WHITE);
	midpoint_line(x[2],y[2],x[6],y[6],WHITE);
	midpoint_line(x[7],y[7],x[8],y[8],WHITE);
	midpoint_line(x[7],y[7],x[10],y[10],WHITE);
	midpoint_line(x[8],y[8],x[11],y[11],WHITE);
	midpoint_line(x[13],y[13],x[14],y[14],WHITE);
	midpoint_line(x[15],y[15],x[16],y[16],WHITE);
	midpoint_line(x[13],y[13],x[15],y[15],WHITE);
	midpoint_line(x[14],y[14],x[16],y[16],WHITE);
}	
int main()
{
	int gdriver = DETECT , gmode;
	initgraph(&gdriver,&gmode," ");
	int x0=0,y0=0,x1=0,y1=0,j=0;
	int dx=0,dy=0;
	int i=0;
	points();
	draw();
	
	printf("Enter 1. For X-Axis Shear 2. For Y-Axis Shear\n");
	scanf("%d",&j);
	switch(j)
	{
		case 1:
			for(i=1;(i<=16)&&((i!=9)||(i!=10)||(i!=11)||(i!=12));i++)
				x[i] = tan(PI/6)*(200-y[i])+x[i];
			draw();
			break;
		case 2:
			for(i=1;(i<=16);i++)
			{
				if(i==6)
					continue;
				y[i] = tan(PI/6)*(175-x[i])+y[i];
			}
			draw();
			break;
	}
			
				
	
	getch();
	closegraph();
	return 0;
}
