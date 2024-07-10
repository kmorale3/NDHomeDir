#include <stdio.h>
#include <string.h>

int main()
{
	char str[20];

	strcpy(str, "notre dame");

	strcat(str, " irish");

	puts(str);
	printf("%d\n", strlen(str));

	char s2[] = "hello";
	printf("%d\n", strlen(s2));
	printf("%d\n", sizeof(s2));

	return 0;
}
