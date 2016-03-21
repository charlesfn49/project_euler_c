#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "int_arrays.c"

int * factorial(int * arr, int n)
{
  while(n > 1)
  {
    for(int i = 1; i < arr[0]; i++)
    {
      arr[i] *= n;
    }
    arr = carry_array_values(arr, 10);
    n--;
  }
  return arr;
}

int main()
{
  int arr[] = {2,1};
  printf("%d\n", sum_array(factorial(arr, 100)));
  return 0;
}
