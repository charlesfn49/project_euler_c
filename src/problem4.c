#include <stdbool.h>
#include <math.h>
#include <stdio.h>

bool isPalindrome(unsigned int n)
{
  // find value used to start decimal digit extraction
  unsigned int m = pow(10, (int) (log(n) / log(10)));

  // branch outwards from center digit and compare digits
  int start = m; // stash the starting value of m to calc future values for right digit isolation
  while(m > 1)
  {
    if(n / m % 10 != n / (start / m) % 10) return false;
    m /= 10;
  }
  return true;
}

unsigned long max_palindrome_product(unsigned int max_digits)
{
  unsigned long max_product = 0;
  unsigned short sqrt_product = 0;

  unsigned long max_value = pow(10, max_digits); // stash max_value to avoid 10^max_digits calls to pow
  for(unsigned int i = max_value - 1; i > 0; i--)
  {
    for(unsigned int j = i - 1; j > 1; j--)
    {
      unsigned int product = i * j; // stash product to avoid 3x multiplication
      
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
}
