#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the self-adjusting list
struct List {
    struct Node* head;
};

// Initialize an empty list
void InitializeList(struct List* L) {
    L->head = NULL;
}

// Insert an element at the front of the list
void Insert(int x, struct List* L) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = L->head;
    L->head = newNode;
}

// Delete a node with a specific value x from the list
void Delete(int x, struct List* L) {
    struct Node* current = L->head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == x) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                L->head = current->next;
            }
            free(current);
            return; // Element found and deleted
        }
        prev = current;
        current = current->next;
    }
}

// Find an element and move it to the front of the list
void FindAndMoveToFront(int x, struct List* L) {
    struct Node* current = L->head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == x) {
            // Move the found element to the front of the list
            if (prev != NULL) {
                prev->next = current->next;
                current->next = L->head;
                L->head = current;
            }
            return; // Element found and moved to the front
        }
        prev = current;
        current = current->next;
    }
}