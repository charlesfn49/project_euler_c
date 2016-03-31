#include <stdio.h>


/**
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

int main()
{
  int n = 3;
  int m = 5;
  int max = 1000;

  // get natural numbers divisible by n or m
  int sum = 0;
  for(int i = 1; i < max; i++)
  {
    if(i % n == 0 || i % m == 0)
    {
      sum += i;
    }
  }

  printf("%d\n", sum);
}
