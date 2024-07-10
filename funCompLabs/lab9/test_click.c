// test_click.c
// example to test how to get the position of the mouse click
// a small circle will be drawn wherever the mouse is clicked
//
#include <stdio.h>
#include "gfx.h"

int main()
{
  int wd = 500, ht = 400;  // window width, height
  int xm, ym;

  // Open a new window for drawing (default fg color is white)
  gfx_open(wd, ht, "My window");

  while(1) {
    xm = gfx_xpos();        // get mouse click's x coordinate
    ym = gfx_ypos();        // get mouse click's y coordinate
    gfx_circle(xm, ym, 5);  // draw a small circle at click location
    printf("(%d,%d)\n", xm, ym);  // display the center's coord. at the monitor

    if (gfx_wait() == 'q')  // quit when a 'q' is pressed
      break;
  }

  return 0;
}

