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

void InitializeList(struct List* L) {
    L->head = NULL;
}

void Insert(int x, struct List* L) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = L->head;
    L->head = newNode;
}

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
            return; 
        }
        prev = current;
        current = current->next;
    }
}

void FindAndMoveToFront(int x, struct List* L) {
    struct Node* current = L->head;
    struct Node* prev = NULL;
    while (current != NULL) {
        if (current->data == x) {
            if (prev != NULL) {
                prev->next = current->next;
                current->next = L->head;
                L->head = current;
            }
            return; 
        }
        prev = current;
        current = current->next;
    }
}