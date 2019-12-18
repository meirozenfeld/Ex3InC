#include "isort.h"
#include <stdio.h>
#define size 50
void printarr(int *arr)
{
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            printf("%d,", *(arr + i));
        }
        else
        {
            printf("%d", *(arr + i));
        }
    }
}
int main()
{
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        int num;
        scanf("%d", &num);
        *(arr + i) = num;
    }
    insertion_sort(arr, 50);
    printarr(arr); //print arr method
    return 0;
}