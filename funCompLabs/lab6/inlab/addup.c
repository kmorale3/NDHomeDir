#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
	if (argc ==1) {
		printf("Please enter 2 numbers\n");
		return 1;
	} else if (argc==3) {
		printf("the sum is %d\n", (atoi(argv[1])+atoi(argv[2])));
		return 0;
	} else {
		printf("error: wrong number of arguments\n");
		return 0;
	}
}

