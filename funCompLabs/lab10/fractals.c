// fractals.c
// contains 8 fractals

#include "gfx.h"
#include <math.h>

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 );
void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 );
void shrinkingSquares( int x, int y, int side);
void drawSquare( int x, int y, int side);
void spiralSquares(float radius, float theta, float side, float xc, float yc);
void circularLace(float x, float y, float radius);
void snowflake(float x, float y, float length);
void tree(float x,float y, float length, float theta);
void fern(float x, float y, float length, float theta);
void spiralSpiral(float radius, float theta, float xc, float yc);

int main()
{
	int width = 700, height = 700, mrgn = 20;//window size
	gfx_open(width, height, "fractals.c");

	while(1) {
		char c=gfx_wait();//used in switch case
		gfx_clear();//clear window
				float side=140;//side length of largest square for spiralSquares
				float radius = sqrt(pow((width/2-mrgn-side/2),2)+pow((height/2-mrgn-side/2),2));//for spirals, to start at bottom right corner
				float theta = M_PI/4;//for spirals, to start at bottom right corner and go inward
				float circleRadius= 0.75*height/2;//for circular lace, radius of initial circle
				float snowflakeLength=(width/3);//length of initial line for snowflake
		switch (c) {
			case '1': //sierpinkski triangle
				sierpinski(mrgn, mrgn, width-mrgn, mrgn, width/2, height-mrgn);
				break;
			case '2'://shrinking squares
				shrinkingSquares(width/2,height/2,((width-2*mrgn)/2));//side length should be half of the window minus 2 margins on each side
				break;
			case '3': //spiral squares
				spiralSquares(radius,theta,side,width/2,height/2);
				break;
			case '4'://circular lace
				circularLace(width/2,height/2,circleRadius);
				break;
			case '5'://snowflake
				snowflake(width/2,height/2,snowflakeLength);
				break;
			case '6': //tree
				tree(width/2,height, height/3,-M_PI/2);
				break;
			case '7': //fern
				fern(width/2,height,height*2/3,-M_PI/2);
				break;
			case '8'://spiral of spirals
				spiralSpiral(radius,theta, width/2,height/2);
				break;
			case 'q'://end program
				return 0;
			default:
				break;
			
		}
	}
}

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 )
{
	// Base case. 
	if( abs(x2-x1) < 5 ) return;

	// Draw a triangle
	drawTriangle( x1, y1, x2, y2, x3, y3 );//3 points to have lines draw between

	// Recursive calls
	sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );//3 recursive calss because three new triangles come from each triangle
	sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
	sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}

void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 )
{
	gfx_line(x1,y1,x2,y2);//draw three lines for triangle, based upon three given points
	gfx_line(x2,y2,x3,y3);
	gfx_line(x3,y3,x1,y1);
}

void shrinkingSquares( int x, int y, int side) // x and y are the center of the square and side is the side length of the square
{
	//Base Case
	if (side<2) return;

	//draw the square
	drawSquare(x,y,side);//center of square and side length of square

	//recursive calls
	//4 squares are produced from each square, so 4 recursive calls are needed
	shrinkingSquares((x-side/2),(y-side/2),side*0.48);//top left
	shrinkingSquares((x+side/2),(y-side/2),side*0.48);//top right
	shrinkingSquares((x+side/2),(y+side/2),side*0.48);//bottom right
	shrinkingSquares((x-side/2),(y+side/2),side*0.48);//bottom left

}

void drawSquare( int x, int y, int side) {
	gfx_line((x-side/2),(y-side/2),(x+side/2),(y-side/2));//top
	gfx_line((x+side/2),(y-side/2),(x+side/2),(y+side/2));//right
	gfx_line((x+side/2),(y+side/2),(x-side/2),(y+side/2));//bottom
	gfx_line((x-side/2),(y+side/2),(x-side/2),(y-side/2));//left
}

void spiralSquares(float radius, float theta, float side, float xc, float yc)
{
	//Base Case
	if (radius<5) return;//the radius is the distance from the center of the window to the center of the square

	//draw square
	drawSquare(xc+radius*cos(theta),yc+radius*sin(theta),side);//polar coordinates for center of square

	//recursive call
	spiralSquares(radius*0.95, theta+0.5, side*0.9, xc, yc);//decrease the radius of the circle in order to make a spiral and change theta to go around the circle, make the square smaller
}

void circularLace(float x, float y, float radius)
{
	//Base Case
	if (radius<3) return;//once the circle's radius is less than 3, stop

	//draw circle
	gfx_circle(x,y,radius);//draw circle with center points of circle and radius

	float i; //for loop countere

	//recursive call (6 times)
	for (i=0; i<2*M_PI; i+=M_PI/3) {//go from 0 to 2pi, increasing by 2pi/6
		circularLace(x+radius*cos(i), y+radius*sin(i), radius/3);//change the center of the circle and make the circle smaller
	}
}

void snowflake(float x, float y, float length)
{

	//Base case
	if (length<5) return;//once the length gets too small

	//draw shape and recursive call
	float i;//for loop counter, 5 recursive calls, polar coordinates (similar to a circle
	for(i=M_PI/2;i<2*M_PI+M_PI/2;i+=2*M_PI/5) {
		gfx_line(x,y,x+length*cos(i), y+length*sin(i));//draw the line 
		snowflake(x+length*cos(i), y+length*sin(i), 0.4*length);//recurse
	}
}

void tree(float x, float y, float length, float theta)
{
	//Base Casd
	if (length<3) return;//once the length is too small

	//Draw Line
	gfx_line(x,y,x+length*cos(theta),y+length*sin(theta));//draw new line
	
	//recursive call
	//2 calls because 2 lines come from each line
	tree(x+length*cos(theta), y+length*sin(theta), 0.68*length,theta-M_PI/6); 
	tree(x+length*cos(theta), y+length*sin(theta), 0.68*length,theta+M_PI/6);
}
 
void fern(float x, float y, float length, float theta)
{
	//Base Case
	if (length<3) return;//once length is too small
	
	//Draw Line
	gfx_line(x,y,x+length*cos(theta), y+length*sin(theta));//draw the line

	//recursive calls
	float i; //for loop counter,
	//8 lines come from each line, 4 pairs of lines at different heights
	//the for loop goes by height at 2 different angles
	for(i=length/4; i<=length; i+=length/4) {
		fern(x+i*cos(theta), y+i*sin(theta),length/3,theta-M_PI/6);
		fern(x+i*cos(theta), y+i*sin(theta),length/3,theta+M_PI/6);
	}
}

void spiralSpiral(float radius, float theta, float xc, float yc) 
{
	//Base Case
	if (radius<1) return;//once the radius of the circle of the spiral is too small

	//Draw Point
	gfx_point(xc+radius*cos(theta), yc+radius*sin(theta));

	//recursive call, 2 recursive calls, the second one makes the basic spiral shape while the first one makes the individual spirals within the overall spiral 
		
	spiralSpiral(radius*0.3,theta, xc+radius*cos(theta),yc+radius*sin(theta));
	spiralSpiral(radius*0.93, theta+0.5,xc,yc);
}
