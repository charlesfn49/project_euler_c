#include <stdio.h>
#include "euler_math.c"

int main()
{
  unsigned char i = 1;
  unsigned long n = 1;
  unsigned long sum = 0;
  while(n < 4000000)
  {
    if(n % 2 == 0) sum += n;
    n = fibonacci(++i);
  }   
  printf("%lu\n", sum);
}
