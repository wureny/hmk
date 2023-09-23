#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 

struct List {
    int data[MAX_SIZE];
    int size;
};

// Initialize an empty list
void InitializeList(struct List* L) {
    L->size = 0;
}

// Insert an element at the front of the list
void Insert(int x, struct List* L) {
    if (L->size < MAX_SIZE) {
        // Shift existing elements to the right
        for (int i = L->size; i > 0; i--) {
            L->data[i] = L->data[i - 1];
        }

        // Insert the new element at the front
        L->data[0] = x;
        L->size++;
    } else {
        printf("List is full. Cannot insert.\n");
    }
}

// Delete a node with a specific value x from the list
void Delete(int x, struct List* L) {
    for (int i = 0; i < L->size; i++) {
        if (L->data[i] == x) {
            // Shift elements to the left to fill the gap
            for (int j = i; j < L->size - 1; j++) {
                L->data[j] = L->data[j + 1];
            }
            L->size--;
            return; // Element found and deleted
        }
    }
}

// Find an element and move it to the front of the list
void FindAndMoveToFront(int x, struct List* L) {
    for (int i = 0; i < L->size; i++) {
        if (L->data[i] == x) {
            // Shift elements to the right to move the element to the front
            for (int j = i; j > 0; j--) {
                L->data[j] = L->data[j - 1];
            }
            L->data[0] = x;
            return; 
        }
    }
}


