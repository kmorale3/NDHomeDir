// rectangle2.c
#include <stdio.h>

int find_perim(float, float);
int find_area(float, float);
int display(float, float);

int main()
{
  float len, wid;
  float perim, area;

  printf("enter the length: ");
  scanf("%f", &len);
  printf("enter the width: ");
  scanf("%f", &wid);

  perim = find_perim(len, wid);  // call the find_perim function
  area = find_area(len, wid);    // call the find_area function

  display(perim, area);          // call the display function

  return 0;
}

int find_perim(float len, float wid)
{
	float perim;
	perim= 2*len +2*wid;

	return perim;
}

int find_area(float len, float wid)
{
	float area;
	area= len*wid;

	return area;
}

int display(float perim, float area)
{
	printf("the perimeter is: %.2f\n", perim);
	printf("the area is: %.2f\n", area);

	return 0;
}
