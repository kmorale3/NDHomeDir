#include <stdio.h>

int main()
{
	char name[20]= "Chris Smith"; //C string
	
	printf("the name is %s\n", name);
	printf("%c\n", name[3]);
	name[1] = 'a';
	printf("the name is %s\n", name);

	char str1[]= {'p', 'a', 't'};
	char str2[]= "pat";

	printf("%d\n", sizeof(str1));
	printf("%d\n", sizeof(str2));

	return 0;
}
