#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * The int_arrays library is the by product of solutions in project euler. All functions
 * take an int* arr as an argument wherein the value held at *arr = the length of the
 * array that is the number of elements int the array including *arr or arr[0]
 * number of elements: i.e {5, 1, 2, 3, 4} has a length of 5; thus, arr[0] == 5.
 *
 * The library is written to work with arrays of 32 bit signed integers in order to not
 * place excessive restrictions on the byte size of values.
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
  for(int i = 1; i < arr[0]; i++)
    printf("%d, ", arr[i]);
  printf("\b\b  \n");
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
  int* new_arr = calloc(extension + arr[0], sizeof(int));
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
int* add_arrays(int* arr1, int* arr2)
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
