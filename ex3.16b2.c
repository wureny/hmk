#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}
 Node;

typedef struct {
    Node* head;
} 
LIST;


void Delete(int x, LIST* L) {
    Node* cur = L->head;
    Node* prev = NULL;
    while (cur != NULL) {
        if (cur->data == x) 
        {
            if (prev == NULL) 
            {
                Node* temp = cur;
                cur = cur->next;
                L->head = cur;
                free(temp);
            } 
            else {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        } 
        else {
            prev = cur;
            cur = cur->next;
        }
    }
}