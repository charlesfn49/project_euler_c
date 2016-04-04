#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * Formal Documentation Here.
 *
 */

// sums the data of an int array
int sum_array(int* arr)
{
  int sum = 0;
  for(int i = 1; i < arr[0]; i++)
  {
    sum += arr[i];
  }
  return sum;
}

// prints the contents of an int array, including
// the size parameter considered in the first index (0)
void print_array(int* arr)
{
  for(int i = 0; i < arr[0]; i++)
    printf("%d, ", arr[i]);
  printf("\b\b\n");
}

// converts the array data into the given base (with
// decimal representation in each number place) and
// returns a new array of that data
int* carry_array_values(int* arr, int base)
{
  // carry over values in array
  for(int i = arr[0] - 1; i > 1; i--)
  {
    int carry = arr[i] / base;
    arr[i] %= base;
    arr[i-1] += carry;
  }
 
  // get info required for array resizing
  int extension = 0;
  int n = arr[1];
  while(n / base > 0)
  {
    n /= base;
    extension++;
  }

  // resize array 
  int * new_arr = calloc(extension + arr[0], sizeof(int));
  new_arr[0] = extension + arr[0];
 
  // copy old data into new allocation
  for(int i = 1; i < arr[0]; i++)
  {
    new_arr[i + extension] = arr[i];
  }

  // carry data in updated array over
  for(int i = 1 + extension; i > 1; i--)
  {
    int carry = new_arr[i] / base;
    new_arr[i] %= base;
    new_arr[i-1] += carry;
  }

  return new_arr;
}

// adds 2 arrays like a human; returns the resulting array;
// however, does not manage carrying out of number places
// and destroys the larger (length-wise) array's data
// (see carry_array_values)
int* sum_arrays(int* arr1, int* arr2)
{
  if(arr1[0] > arr2[0])
  {
    for(int i = 1; i < arr2[0]; i++)
    {
      arr1[i] += arr2[i];
    }
    return arr1;
  }
  else
  {
    for(int i = 1; i < arr1[0]; i++)
    {
      arr2[i] += arr1[i];
    }
    return arr2;
  }
}
