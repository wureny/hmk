#include <stdio.h>

#define MAX_SIZE 100

// Define the structure for the list
typedef struct {
    int data[MAX_SIZE]; // The array to store elements
    int last_position;  // The index of the last element
} LIST;

void Delete(int x, LIST *L) {
    int i, j;

    // Loop through the list from left to right
    for (i = 0; i <= L->last_position; i++) {
        if (L->data[i] == x) {
            for (j = i; j < L->last_position; j++) {
                L->data[j] = L->data[j + 1];
            }
            L->last_position--;
            i--;
        }
    }
}