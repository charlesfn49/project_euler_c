#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

// gets the factorial of n as an array of values
// representative of a big integer
int* factorial(int * arr, int n)
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
