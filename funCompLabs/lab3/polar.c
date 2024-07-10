//Katie Morales
//2/28/20
//polar.c
//This program takes in an input for x and y coordinates and displays the polar coordinates as well as the quadrant of the point

#include <stdio.h>
#include <math.h>

int get_quadrant(double, double);
double get_radius(double, double);
double get_angle(double, double);
void show_info(int, double, double);

int main() {

	double x,y; //coordinates
	printf("please enter your x and y coordinates: ");
	scanf("%lf %lf", &x, &y);

	int quad; //quadrant number
	quad= get_quadrant(x,y);

	double rad; //radius
	rad= get_radius(x,y);

	double angle;
	angle= get_angle(x,y);
	
	show_info(quad, rad, angle);

	return 0;
}

int get_quadrant(double x, double y) {

	int quad;
	if (x>0 && y>0) quad=1; //quadrant 1
	else if (x<0 && y>0) quad=2; //quadrant 2
	else if (x<0 && y<0) quad=3; //quadrant 3
	else if (x>0 && y<0) quad=4; //quadrant 4

	return quad;
}

double get_radius(double x, double y) {

	double rad;
	rad= sqrt( x*x + y*y);

	return rad;
}

double get_angle(double x, double y) {
	
	double angle;
	angle= atan2 (y, x) * 180/(M_PI); //use inverse tangent to find angle (finds angle in correct quadrant)... result is in radians, but then converted to degrees
	
	return angle;
}

void show_info(int quad, double rad, double angle) {

	printf("the point is in quadrant %d\n", quad);
	printf("the point's polar coordinates are: \n");
	printf("    r = %.4lf", rad);
	printf("    theta= %.2lf degrees\n", angle);

}
