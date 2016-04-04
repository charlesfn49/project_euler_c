#include <stdio.h>

/**
 * Project Euler Problem 1:
 *   If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *   Find the sum of all the multiples of 3 or 5 below 1000.
 * 
 *   Answer: 233168
 */
int main()
{
  unsigned short n = 1000, sum = 0;
  // iterate over all natural numbers less than 1000
  // if n is divisible by 3 or 5 add it to the sum
  for(; n > 0 ; n--)
  {
    if(n % 3 == 0 || n % 5 == 0) sum += n;
  }
  printf("%d\n", sum);
  return 0;
}
