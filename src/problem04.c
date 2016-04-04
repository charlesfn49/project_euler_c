#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

/**
 * Project Euler Problem 4:
 *   A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *   Find the largest palindrome made from the product of two 3-digit numbers.
 *   
 *   Answer: 906609
 */


unsigned long reverse(unsigned long n)
{
  // get the number required to grab the left most digit of n
  unsigned long i = pow(10, (long) (log(n) / log(10))), j = 1, m = 0;
  // get the digits of n in reverse order
  // and put them in m
  while(j <= i)
  {
    m += n / j % 10 * (i / j);
    j *= 10;
  }
  return m;
}

// checks if a number is palindromic
bool isPalindrome(unsigned long n)
{
  return n == reverse(n);
}

// finds the maximum palindromic product of integers with no more than
// max digits digits
// some notes:
//   - relies on the idea that the product of any 2 numbers < a number n
//     that are also less than sqrt(n) cannot be > n to make an optimized
//     early return (this has allowed computation of similar problems
//     allotting up to 6 digits in the factors in reasonable time)
//   - the objective was to be heavy on memory and light on computation
//     the following optimizations worked around the preceding arithmetic
//       * saving the product: 3x multiplication for comparisons
//       * saving the sqrt of the product: 2x calc of sqrt
//             and allows for early return
//       * saving max_value: avoids 10^n calls to pow
unsigned long max_palindrome_product(unsigned char max_digits)
{
  unsigned long product, max_product = 0, max_value = pow(10, max_digits);
  unsigned int sqrt_product = 0;

  for(unsigned long i = max_value - 1; i > 0; i--)
  {
    for(unsigned long j = i - 1; j > 1; j--)
    {
      product = i * j; // stash product to avoid 3x multiplication
      
      // check if the number is the next largest palindrome
      if(product > max_product && isPalindrome(product)) 
      {
	max_product = product;
	sqrt_product = sqrt(max_product);
      }
      // if it is impossible for future products to be greater, return
      else if(i < sqrt_product && j < sqrt_product) return max_product;
    }
  }
  return max_product;
}

int main()
{
  printf("%lu\n", max_palindrome_product(3));
  return 0;
}
