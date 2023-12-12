#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"

typedef int ElementType;

void Swap(ElementType *Lhs, ElementType *Rhs)
{
    ElementType Tmp = *Lhs;
    *Lhs = *Rhs;
    *Rhs = Tmp;
}

void PrintPass(ElementType A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
}
void Shellsort(ElementType A[], int N, int increments[], int numIncrements)
{
    int i;
    int j;
    int Increment;
    ElementType Tmp;
    for (int incIndex = 0; incIndex < numIncrements; incIndex++)
    {
        Increment = increments[incIndex];
        for (i = Increment; i < N; i++)
        {
            Tmp = A[i];
            for (j = i; j >= Increment && A[j - Increment] > Tmp; j -= Increment)
                A[j] = A[j - Increment];
            A[j] = Tmp;

            printf("%d (%d): ", i, Increment);
            PrintPass(A, N);
        }
    }
}


