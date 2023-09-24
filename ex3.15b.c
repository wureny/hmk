#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct List {
    struct Node* head;
};

void Delete(int x, struct List* L) {
    struct Node* cur = L->head;
    struct Node* prev = NULL;
    while (cur != NULL) 
    {
        if (cur->data == x)
         {
            if (prev != NULL) 
            {
                prev->next = cur->next;
            } else
             {
                L->head = cur->next;
            }
            free(cur);
            break; 
        }
        prev = cur;
        cur = cur->next;
        continue;
    }
}

void FindAndMove(int x, struct List* L) {
    struct Node* cur = L->head;
    struct Node* prev = NULL;
    while (cur != NULL)
     {
        if (cur->data == x)
         {
            if (prev != NULL) 
            {
                prev->next = cur->next;
                cur->next = L->head;
                L->head = cur;
            }
            break; 
        }
        prev = cur;
        cur = cur->next;
    }
}