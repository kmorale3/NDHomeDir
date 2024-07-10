#include <stdio.h>
#include <string.h>

int main()
{
	int a, b;
	FILE *ifp
	ifp= fopen("nums.dat","r");
	fscanf(ifp, "%d %d", &a, &b);

	printf("%d %d\n", a, b);

	return 0;
}
