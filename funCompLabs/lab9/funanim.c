// Katie Morales
// 4/25/21
// funanim.c 

#include "gfx.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void draw_square(double,double,double);
void draw_triangle(double,double,double);
void draw_diamond(double,double,double);
void draw_polygon(double,double,double,int);

int main() 
{
	int width=600, height=500; //window size
	double px=width/2, py=height/2; //coordinates for point
	double x,y,size=25;//arguments for shape
	double radius=200;//distance of rotation from point
	int pausetime= 10000;//pausetime
	double theta;//for loop
	char shape='c';

	gfx_open(width,height,"funanim.c");//open window
	gfx_color(255,255,255);
	gfx_text(width/3,height/2,"See command window for instructions!");
	gfx_text(width/3,height/2+20,"Click mouse to start!");
	printf("enter\n  'c' for a circle\n  's' for a square\n  't' for a triangle\n  'd' for a diamond\n  'p' for a pentagon\n  'h' for a hexagon\n  'q' to exit\n");
	if (gfx_wait()==1) {
		while(1) {//q quits the program
			for (theta=0; theta<=2*3.1415; theta+=0.02) {
				x= px+(radius)*(cos(theta));//x-coordinate for center of shape
				y=py+(radius)*(sin(theta));//y-coordinate for center of shape
				gfx_clear();//clear window
				if(gfx_event_waiting())
					shape = gfx_wait();
				switch (shape){
					case 'c':
						gfx_color(65,105,225);//blue 
						gfx_circle(x, y, size);//draw circle
						gfx_flush();
						break;
					case 's':
						gfx_color(220,20,60);//red
						draw_square(x,y,size);//draw square
						gfx_flush();
						break;
					case 't':
						gfx_color(255,255,0);//yellow
						draw_triangle(x,y,size);//draw triangle
						gfx_flush();
						break;
					case 'd':
						gfx_color(255,128,0);//orange
						draw_diamond(x,y,size);//draw diamond
						gfx_flush();
						break;
					case 'p':
						gfx_color(102,204,0); //green
						draw_polygon(x,y,size,5);//draw pentagon
						gfx_flush;
						break;
					case 'h':
						gfx_color(153,0,153); //purple
						draw_polygon(x,y,size,6);//draw hexagon;
						break;
					case 'q':
						return 0;
				}
				usleep(pausetime);//wait before moving so the animation will work
			}
			//break;
		}
	
	
	}
}

void draw_square(double x,double y,double size){
	gfx_line((x-size),(y-size),(x+size),(y-size));
	gfx_line((x+size),(y-size),(x+size),(y+size));
	gfx_line((x+size),(y+size),(x-size),(y+size));
	gfx_line((x-size),(y+size),(x-size),(y-size));
}
	
void draw_triangle(double x,double y,double size){
	gfx_line((x-size),(y+size), (x+size), (y+size));
	gfx_line((x-size),(y+size), (x), (y-size));
	gfx_line((x+size),(y+size), (x), (y-size));
}

void draw_diamond(double x,double y,double size){
	gfx_line(x,(y-size),(x+size),y);
	gfx_line((x+size),y,x,(y+size));
	gfx_line(x,(y+size),(x-size),y);
	gfx_line((x-size),y,x,(y-size));
}
	
void draw_polygon(double x,double y,double size,int sides) {
	int i;
	int x1=x+size,x2;//x-ccordinates for when drawing lines
	int y1=y,y2;//y-coordinates for drawing lines
	for (i=1; i<=sides; i++) {//same as code from symbol.c
		x2=x+(size)*cos(0+(i)*6.28/sides);//center + rcos(theta), divide 2pi by number of sides in polygon
		y2=y+(size)*sin(0+(i)*6.28/sides);
		gfx_line(x1,y1,x2,y2);
		gfx_flush();
		x1=x2;//set end of line to beginning of next line
		y1=y2;
	}
}
		
