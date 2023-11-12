#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
#include "list.h"
#include"fatal.h"
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    List Head;
} QueueRecord;

int IsEmpty( Queue Q ) {
    return Q->Size == 0;
}

int IsFull( Queue Q ) {
    return Q->Size == Q->Capacity;
}

 Queue CreateQueue( int MaxElements ) {
    Queue q =(Queue)malloc(sizeof(QueueRecord));
    q->Capacity = MaxElements;
    q->Size = 0;
    q->Front = 1;
    q->Rear = 0;
    q->Head = NULL;
 }
void DisposeQueue( Queue Q ){
    if (Q != NULL) {
        if (Q->Head != NULL) {
            free(Q->Head);
        }
        free(Q);
    }
}      
void MakeEmpty( Queue Q ) {
    if (Q != NULL) {
        if (Q->Head != NULL) {
            free(Q->Head);
        }
        Q->Head = NULL;
        Q->Size = 0;
        Q->Front = 1;
        Q->Rear = 0;
    }
}        
static int
        Succ( int Value, Queue Q )
        {
            if( ++Value == Q->Capacity )
                Value = 0;
            return Value;
        }

void Enqueue( ElementType X, Queue Q ){
    if (IsFull(Q)) {
        Error("Full queue");
    }
    else {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        if (Q->Head == NULL) {
            Q->Head = (List)malloc(sizeof(Node));
            Q->Head->data = X;
            Q->Head->next = NULL;
        }
        else {
            List p = Q->Head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = (List)malloc(sizeof(Node));
            p->next->data = X;
            p->next->next = NULL;
        }
    }
}        
ElementType Front( Queue Q ){
    if (!IsEmpty(Q)) {
        return Q->Head->data;
    }
    else {
        return 0;
    }
}
        
void Dequeue( Queue Q ) {
    if (!IsEmpty(Q)) {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
        List p = Q->Head;
        Q->Head = Q->Head->next;
        free(p);
    }
}
ElementType FrontAndDequeue( Queue Q ) {
    if (!IsEmpty(Q)) {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
        List p = Q->Head;
        Q->Head = Q->Head->next;
        ElementType data = p->data;
        free(p);
        return data;
    }
    else {
        return 0;
    }
}