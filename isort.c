#include "isort.h"
#include <stdio.h>

void shift_element(int *arr, int i)
{
    for ( int j=i-1 ; j>= 0; j--)
    {
      *(arr+j+1) = *(arr+j); 
    }    
}

void insertion_sort (int* arr, int len)
{
  int temp;
  for ( int i = 0; i < len; i++)
  {
    for (int j = 0; j<i; j++)
    {
      if(*(arr+j)>*(arr+i))
      {
        temp = *(arr+i);
        shift_element(arr+j , i-j);
        *(arr+j) = temp;
      }
    }
  }
}