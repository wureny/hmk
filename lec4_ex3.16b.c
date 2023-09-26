#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure for the list
typedef struct {
    Node* head;
} LIST;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}


void insertFront(LIST* L, int data) {
    Node* newNode = createNode(data);
    if (newNode) {
        newNode->next = L->head;
        L->head = newNode;
    }
}
void Delete(int x, LIST* L) {
    Node* current = L->head;
    Node* prev = NULL;
    while (current != NULL) {
        if (current->data == x) {
            if (prev == NULL) {
                Node* temp = current;
                current = current->next;
                L->head = current;
                free(temp);
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void freeList(LIST* L) {
    Node* current = L->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(L);
}