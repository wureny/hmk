#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"

typedef int ElementType;

void PrintArray(ElementType A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    ElementType arr[] = {12, 2, 16, 30, 28, 10, 16, 20, 6, 18};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    PrintArray(arr, arrSize);
    Heapsort(arr, arrSize);
    PrintArray(arr, arrSize);
    Heapsort(arr, arrSize);
    PrintArray(arr, arrSize);
    return 0;
}
