// Katie Morales
// 4/25/21
// bounce.c 

#include "gfx.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

int main() 
{
	srand(time(NULL));//reset random
	int width=600, height=500; //window size
	float xc = 50, yc=50, radius= 25;//arguments for gfx_circle
	float vx=rand() %7 + 1;//velocity of x
	float vy=rand() %7 + 1;//velocity of y
	char c = 0; //gfx wait
	int pausetime= 10000;//pausetime

	gfx_open(width,height,"bounce.c");//open window
	gfx_color(255,255,255);//color is white

	while(c !='q') {//q quits the program
		gfx_clear();//clear window
		gfx_circle(xc, yc, radius);//draw circle
		gfx_flush();//flush output
		usleep(pausetime);//wait before moving so the animation will work

		xc +=vx;//change x position by velocity
		yc+=vy;//change y position by velocity

		if (yc + radius>=height) {//bottom wall
			vy=-vy;
			yc=height-radius-1;
		}
		else if (yc-radius<=0) {//top wall
			vy=-vy;
			yc=radius+1;
		}
		else if (xc + radius>=width) {//right wall
			vx=-vx;
			xc=width-radius-1;
		}
		else if (xc-radius<=0) {//left wall
			vx=-vx;
			xc=radius+1;
		}

		if(gfx_event_waiting()) {//see if user pressed key
			c = gfx_wait();
		}
	}

	return 0;
}

