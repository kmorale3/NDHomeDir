//project.c
//5/11/21
//Katie Morales
//for my project, I will be creating a pac-man simulation

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
	int x;
	int y;
	int speed;
	int direction;//1 up, 2 right, 3 down, 4 left
	int directionLength;
	int color[4];
} Ghost;

typedef struct {
	int x;
	int y;
	int speed;
	int direction;//1 up, 2 right, 3 down, 4 left
	int directionLength;
} PacMan;

void initializeGhosts(Ghost []);
void drawGhost(Ghost [],int n);
void drawPartialCircle(float theta1, float theta2, float radius, float  x, float y);

int main() 
{
	srand(time(NULL)); //reset random
	int width=700, int height=700;//window size
	int numGhosts;
	numGhosts=gfx_wait();
	gfx_open(width,height,"project.c");
	gfx_text(width/3, height/2,"Please enter a number between 1 and 6 for the number of ghosts!");
	gfx_event_waiting(); 
	Ghost ghost[numGhosts];
	ghost1[0].x=350;
	ghost1[0].y=350;
	ghost1[0].color[0]=255;
	ghost1[0].color[1]=255;
	ghost1[0].color[2]=0;
	drawGhost(ghost1,1);
	usleep(1000000);
	return 0;
}

void drawGhost(Ghost ghost[], int n) {
	int i;
	for (i=0; i<n; i++) {
		gfx_color(ghost[i].color[0],ghost[i].color[1], ghost[i].color[2]);
		//gfx_point(350,350);
		int ghostRad=13;
		while (ghostRad>=1) {
			gfx_circle(350,350,ghostRad);
			gfx_flush();
		int j;
		for (j=0; j<=2*ghostRad; j++) {
			gfx_line(350-ghostRad+j, 350, 350-ghostRad+j, 350+2*ghostRad);
			gfx_flush();
		}
			usleep(10000);
			ghostRad--;		
			printf("%d", ghostRad);
		}
	}
}

void drawPartialCircle(float theta1, float theta2, float radius, float x, float y) 
{
	if (radius<1) return;
		
	gfx_color(255,255,0);
	drawPartialCircle(theta1, theta2, radius-0.5, x, y);

	float i;
	for (i=theta1; i<theta2; i+=.1) {
		gfx_point(x+radius*cos(i), y+radius*sin(i));
		gfx_flush();
		usleep(10000);
		printf("%f hello\n",i);
	}

}

