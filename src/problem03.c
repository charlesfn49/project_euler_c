#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * Project Euler Problem 3:
 *   The prime factors of 13195 are 5, 7, 13 and 29.
 *   What is the largest prime factor of the number 600,851,475,143 ?
 * 
 *   Answer: 6,857
 */

// prime number test (for n > 2)
// is a prime: true
// else: false
bool is_prime_over_2(unsigned long n)
{
  // sqrt(2^64 - 1) == 2^32 - 1 => i can be 4 bytes
  for(unsigned int i = 2; i <= sqrt(n); i++)
  {
    if(n % i == 0) return false;
  }
  return true;
}

// prime number test (for all n >= 0)
// is a prime: true
// else: false
bool is_prime(int n)
{
  if (n < 2) return false;
  else if (n == 2) return true;
  else return is_prime_over_2(n);
}

// finds the largest prime factor
// of an integer n
unsigned int largest_prime_factor(unsigned long n)
{
  for(unsigned int m = sqrt(n); m > 1; m--)
  {
    if(n % m == 0 && is_prime(m)) return m;
  }
  return n;
}

int main()
{
  printf("%d\n", largest_prime_factor(600851475143lu));
}
