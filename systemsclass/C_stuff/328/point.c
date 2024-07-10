/* point.c */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {    // TODO: s/struct/union
    int x;
    int y;
} Point;

void point_format(Point *p, FILE *stream) {
    // TODO: Print point to stream
    fprintf(stream, "Point{x: %d, y: %d}\n", p->x, p->y);
}

int main(int argc, char *argv[]) {
    // TODO: Define some points
    Point p0 = {0};
    Point p1 = {1,2};
    
    // TODO: Print size and locations of point structure
    printf("sizeof(Point) = %ld\n", sizeof(Point)); //the size of the location is 4
    printf("&p0           = 0x%lx\n", (intptr_t)&p0);
    printf("&p0.x         = 0x%lx\n", (intptr_t)&p0.x);
    printf("&p0.y         = 0x%lx\n", (intptr_t)&p0.y);
    // TODO: Use print_format to print point structure
    //you already have p0, take the address of to pass as a pointer
    point_format(&p0, stdout); 
    point_format(&p1, stdout);

    // TODO: Define array of points
    Point pa[] = {
        {3,4}, //union will change these to be 3,3 (one memory location )
        {5,6}, //union will change to be 5,5 
        {0} //sentinel
    };

    // TODO: Loop through array with pointers and print each point
    //goes through until wither px and py is 0 (we used a sentinel)
    for (Point *p = pa; p->x && p->y; p++) {
        point_format(p, stdout);
    }
    
    return EXIT_SUCCESS;
}