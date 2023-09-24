#include <stdio.h>
#include <stdlib.h>
int Max=200;
struct List {
    int data[200];
    int size;
};
void Delete(int x, struct List* L) 
{
    for (int i = 0; i < L->size; i++) 
    {
        if (L->data[i] == x) 
        {
            for (int j = i; j < L->size - 1; j++) 
            {
                L->data[j] = L->data[j + 1];
            }
            L->size--;
            return; 
    }
}
}
void FindAndMove(int x, struct List* L) 
{
    for (int i = 0; i < L->size; i++)
     {
        if (L->data[i] == x) {
            for (int j = i; j > 0; j--) 
            {
                L->data[j] = L->data[j - 1];
            }
            L->data[0] = x;
            return; 
     }
}
}