#include "binheap.h"
#include<stdio.h>
#include"fatal.h"
#include<stdlib.h>
    struct HeapStruct
        {
            int Capacity;
            int Size;
            ElementType *Elements;
        };

void PercUp(int i, PriorityQueue H) {
    ElementType X = H->Elements[i];
    int parent;

    for (; i > 1; i = parent) {
        parent = i / 2;
        if (H->Elements[parent] > X) {
            H->Elements[i] = H->Elements[parent];
        } else {
            break;
        }
    }
    H->Elements[i] = X;
}

void PercDown(int i, PriorityQueue H) {
    int child;
    ElementType X = H->Elements[i];

    for (; i * 2 <= H->Size; i = child) {
        child = i * 2;
        if (child != H->Size && H->Elements[child + 1] < H->Elements[child]) {
            child++;
        }
        if (X > H->Elements[child]) {
            H->Elements[i] = H->Elements[child];
        } else {
            break;
        }
    }
    H->Elements[i] = X;
}

void Insert(ElementType X, PriorityQueue H) {
    if (IsFull(H)) {
        Error("full");
        return;
    }

    H->Elements[++H->Size] = X;
    PercUp(H->Size, H);
}

ElementType DeleteMin(PriorityQueue H) {
    if (IsEmpty(H)) {
        Error("empty");
        return H->Elements[0];
    }

    ElementType MinElement = H->Elements[1];
    ElementType LastElement = H->Elements[H->Size--];

    H->Elements[1] = LastElement;
    PercDown(1, H);

    return MinElement;
}


