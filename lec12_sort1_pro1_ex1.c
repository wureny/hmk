#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"

typedef int ElementType;

void PrintPass(ElementType A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Swap(ElementType *lhs, ElementType *rhs)
{
    ElementType Tmp = *lhs;
    *lhs = *rhs;
    *rhs = Tmp;
}

void InsertionSort(ElementType A[], int N)
{
    int j, P;
    ElementType Tmp;

    for (P = 1; P < N; P++)
    {
        Tmp = A[P];
        for (j = P; j > 0 && A[j - 1] > Tmp; j--)
            A[j] = A[j - 1];
        A[j] = Tmp;
        printf(" %d: ", P);
        PrintPass(A, N);
    }
}
