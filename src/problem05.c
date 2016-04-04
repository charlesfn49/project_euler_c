#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * Project Euler Problem 5:
 *   2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *   What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 *
 *   Answer: 232792560
 */   

// DEPRECATED
// brute force check for divisibilty
bool isDivisible(unsigned int n, unsigned char m)
{
  while(m > 0)
  {
    if(n % m-- != 0) return false;
  }
  return true;
}

// The solultion involving the insertion of the missing prime factors of
// each factor under the max_factor_value to the factors of n without the
// usage of logarithms to figure out each power of the nth prime.
unsigned long smallest_divisible_number(unsigned char max_factor_value)
{
  unsigned long n = 1;
  for(unsigned char i = 2; i <= max_factor_value; i++)
  {
    unsigned char m = i; // stash the current factor being added
    unsigned int k = n; // stash the current product
    for(unsigned char j = 2; j < i; j++)
    {
      // extract the component of the prime factorization of j from i
      // as the leftovers in m
      while (m % j == 0 && k % j == 0)
      {
	m /= j;
	k /= j;
      }
    }
    // append the missing prime factorization component to n
    n *= m;
  }
  return n;
}

// prime number test (n > 2)
// is a prime: true
// else: false
bool is_prime_over_2(int n)
{
  for(int i = 2; i <= sqrt(n); i++)
  {
    if(n % i == 0) return false;
  }
  return true;
}

// prime number test
// is a prime: true
// else: false
bool is_prime(int n)
{
  if (n < 2) return false;
  else if (n == 2) return true;
  else return is_prime_over_2(n);
}

// The magic of logarithms applied to the previous solution
//   * note the heavy reliance on library functions
unsigned long smallest_divisible_number_logarithms(unsigned char k)
{
  unsigned long n = 1;
  unsigned short limit = sqrt(k);
  for(unsigned char i = 0; i <= k; i++)
  {
    if(is_prime(i))
    {
      unsigned char a = 1;
      if (i <= limit)
      {
	a = (unsigned char) (log(k) / log(i));
      }
      n *= pow(i, a);
    }
  }
  return n;
}

int main()
{
  printf("%lu\n", smallest_divisible_number(20));
}
