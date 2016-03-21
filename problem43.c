#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int sum_array(int* arr)
{
  int sum = 0;
  for(int i = 1; i < arr[0]; i++)
  {
    sum += arr[i];
  }
  return sum;
}

void print_array(int * arr)
{
  for(int i = 0; i < arr[0]; i++)
    printf("%d, ", arr[i]);
  printf("\n");
}

int * carry_array_values(int* arr, int base)
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

  // reallocate array 
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

int * sum_arrays(int * arr1, int * arr2)
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

// comparison of integers
int cmpfunc(const void * a, const void * b)
{
  return (*(int*)a - *(int*)b );
}

// check if the number is a solution
bool check(int* values)
{ 
  // get numbers along the way
  int * numbers = calloc(8, sizeof(int));
  numbers[0] = 8;
  for(int i = 1; i < 8; i++)
  {
    numbers[i] = 100*values[i+1] + 10*values[i+2] + values[i+3];
  }

  // sort the values
  qsort(values+1, 10, sizeof(int), cmpfunc);

  // check for duplicate values
  for(int i = 0; i < 10; i++)
  {
    // search for value
    int * item = (int *) bsearch(&i, values+1, 10, sizeof(int), cmpfunc);
    //printf("%d\n", item);
    //printf("%lu\n", item-values-1);

    // detect duplicate
    if(item != NULL) 
    {
      if((int) (item-values) >= 2)
	if(values[(int) (item-values)-1] == *item) return false;
      if((int) (item-values) <= 10)
	if(values[(int) (item-values)+1] == *item) return false;
    }
  }

  // check for divisibility
  int primes[] = {2,3,5,7,11,13,17};
  for(int i = 1; i < numbers[0]; i++)
  {
    if(numbers[i] % primes[i-1] != 0) return false; 
  }

  return true;
}

int main()
{  
  int qwer[] = {11,1,4,0,6,3,5,7,2,8,9};
  printf("%d\n", check(qwer));
  
  int * arr = calloc(11, sizeof(int));
  // generate all possibilities
  for(int a = 0; a < 10; a++)
  {
    for(int b = 0; b < 10; b++)
    {
      for(int c = 0; c < 10; c++)
      {
	for(int d = 0; d < 10; d++)
	{
	  for(int e = 0; e < 10; e++)
	  {
	    for(int f = 0; f < 10; f++)
	    {
	      for(int g = 0; g < 10; g++)
	      {
	        for(int h = 0; h < 10; h++)
	        {
		  for(int i = 0; i < 10; i++)
		  {
		    for(int j = 0; j < 10; j++)
		    {
		      // check the number for requirements
		      int values[] = {11,a,b,c,d,e,f,g,h,i,j};
                      if(check(values))
		      {
			arr = sum_arrays(values, arr);
			print_array(arr);
			printf("%lu\n", a*1000000000ul + b*100000000ul +
			       c*10000000ul + d*1000000ul + e*100000ul +
			       f*10000ul + g*1000ul + h*100ul + i*10ul + j);
		      }
		    }
		  }
	        }
	      }
	    }
	  }
	}
      }
    }
    }
  return 0;
}
