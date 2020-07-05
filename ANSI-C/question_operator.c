//question operator

#include <stdio.h>

int main()
{
  int foo = 10;
  int bar = 50;
  int bas;

  bas = (foo > bar) ? foo : bar;

  printf("bas = %d\n\n", bas);

  return 0;
}
