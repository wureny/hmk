#include <stdio.h>
typedef struct {
    int data[1000]; 
    int last_position; 
} 
LIST;

void Delete(int x, LIST *L) {
    for (int i = 0; i <= L->last_position; i++) 
    {
        if (L->data[i] == x) 
        {
            for (int j = i; j < L->last_position; j++) 
            {
                L->data[j] = L->data[j + 1];
            }
            L->last_position--;
            i--;
        }
    }
}