// prog3.c
#include <stdio.h>
#include <string.h>

void print_reverse(char *);

int main()
{
  char *str = "University of Notre Dame";

  printf("%s\n", str);

  print_reverse(str);

  return 0;
}

void print_reverse(char *s)
{
  char *p = s + strlen(s);

  while (1) {
    printf("%c", *p);
    if (p == s) break;
    p--;
  } 
  printf("\n");
}

