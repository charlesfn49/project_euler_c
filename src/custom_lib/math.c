#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "int_arrays.c"

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

// finds the largest prime factor
// of an integer n
unsigned int largest_prime_factor(unsigned int n)
{
  for(unsigned int m = sqrt(n); m > 1; m--)
  {
    if(n % m == 0 && is_prime(m)) return m;
  }
  return n;
}


// returns anew array representing the prime
// factorization of a number 
int* prime_factorization(int n)
{
  int* arr = calloc(n, sizeof(int));
  int i = 1;
  int p = n;

  // handle prime factors of 2
  while(n % 2 == 0)
  {
    n /= 2;
    arr[i]++;
  }
  i++;
  
  // get all other prime factors
  for(int m = 3; m <= p; m += 2)
  {
    if(is_prime_over_2(m))
    {
      while(n % m == 0)
      {
	printf("%d\n", m);
	n /= m;
	arr[i]++;
      }
      i++;
    }
  } 

  // put size of arr in first index
  // (effectively drop unused indices)
  arr[0] = i;
  return arr;
}

// returns the prime factorization of a factorial
// as an int array representing the powers of
// consecutive primes (index 0 is length)
int* prime_factorization_factorial(int* arr, int n)
{
  while(n > 1)
  {
    int* arr_aux = calloc(n, sizeof(int));
    arr_aux = prime_factorization(n);
    for(int i = 0; i < arr_aux[0]; i++)
      printf("%d, ", arr[i]);
    printf("\n");
    arr = sum_arrays(arr, arr_aux);
    n--;
  }
  return arr;
}

// factorial function
unsigned long factorial(unsigned char n)
{
  if(n == 0) return 1;
  else return n * factorial(n-1);
}

unsigned long fibonacci(unsigned char n)
{
  if(n == 0 || n == 1) return 1ul;
  else return fibonacci(n - 1) + fibonacci(n - 2);
}

// sigmoid function
double sigmoid(double n)
{
  return 1 / (1 + exp(-n));
}

// 1 iteration of newton's approximation method
double approx_zero(double function(double), double derivative(double), double n)
{
  return n - function(n) / derivative(n);
}



