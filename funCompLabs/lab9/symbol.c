// Katie Morales
// 4/25/21
// symbol.c 

#include "gfx.h"
#include <math.h>

const int size=50;

void draw_square(void);
void draw_triangle(void);
void draw_polygon(int);

int main()
{
	int xsize=500, ysize=400;//window size

   // Open a new window for drawing.
   gfx_open(xsize, ysize, "symbol.c");

   while (1) {
		int xm,ym;
		int c=gfx_wait();	
		if (c== 1) //left mouse click
			draw_square();	

		else if (c==99) {// character c
			xm = gfx_xpos();
			ym = gfx_ypos();
			gfx_color(255,255,255);//white
			gfx_circle(xm,ym,size/2);//draw circle with diameter size
		}
		
		else if (c==116) //character t
			draw_triangle();

		else if (c==51) //character 3
			draw_polygon(3);

		else if (c==52) //character 4
			draw_polygon(4);
		
		else if (c==53) //character 5
			draw_polygon(5);

		else if (c==54) //character 6
			draw_polygon(6);

		else if (c==55) //character 7
			draw_polygon(7);

		else if (c==56) //character 8
			draw_polygon(8);

		else if (c==57) //character 9
			draw_polygon(9);

		else if (c==27) // esc character
			gfx_clear();

		else if (c==113)//character q
			break;

   }


  return 0;
}

void draw_square() {
	int xm,ym;
	xm = gfx_xpos();
	ym = gfx_ypos();
	gfx_color(30,144,255); //blue
	//draw a square centered at xm,ym,with side size
	gfx_line((xm-size/2), (ym-size/2),(xm+size/2), (ym-size/2));
	gfx_line((xm+size/2), (ym-size/2),(xm+size/2), (ym+size/2));
	gfx_line((xm+size/2), (ym+size/2),(xm-size/2),(ym+size/2));
	gfx_line((xm-size/2),(ym+size/2),(xm-size/2),(ym-size/2));
}
	
void draw_triangle() {
	int xm,ym;
	xm = gfx_xpos();
	ym = gfx_ypos();
	gfx_color(124,252,0);//white
	//draw isosceles triangle with base "size" and height "size"
	gfx_line((xm-size/2),(ym+size/2),(xm+size/2),(ym+size/2));//base
	gfx_line((xm-size/2),(ym+size/2),xm,(ym-size/2));//"left" line
	gfx_line((xm+size/2),(ym+size/2),xm,(ym-size/2));//"right" line
}

void draw_polygon(int sides){
	int xm,ym,x1,x2,y1,y2;
	xm = gfx_xpos();
	ym = gfx_ypos();
	gfx_color(148,0,211);//purple
	gfx_circle(xm,ym,size/2);
	int i;
	x1=xm+size/2;
	y1=ym;
	//coordiantes for 0 degrees in polar
	for (i=1; i<=sides; i++) {
		x2=xm+(size/2)*cos(0+(i)*6.28/sides);
		y2=ym+(size/2)*sin(0+(i)*6.28/sides);
		gfx_line(x1,y1,x2,y2);
		x1=x2;
		y1=y2;
	}
}
