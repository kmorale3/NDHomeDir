#include <stdio.h>
#include <string.h>

int main()
{
	char s1[]= "notre dame";
	char s2[]= "notre dame";

	if (!strcmp(s1, s2))//!strcmp means they are the same... references
		puts("yes");
	else
		puts("no");

	return 0;
}
