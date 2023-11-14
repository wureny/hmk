#include"list.h"
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

List Reverse(List L) {
    if (L->next==NULL) 
    {
    return NULL;
    }
    List curr=(Node*)malloc(sizeof(Node));
    curr=L;
    List pre=L;
    while(curr!=NULL) {
        List tmp=curr->next;
        curr->next=pre;
        pre=curr;
        curr=tmp;
    }
    L->next=NULL;
    return pre;
}

int main() {
    List L=(Node*)malloc(sizeof(Node));
    L->data=2;
    L->next=(Node*)malloc(sizeof(Node));
    L->next->data=7;
    L->next->next=(Node*)malloc(sizeof(Node));
    L->next->next->data=9;
    printf("Before:\n");
    List cur=L;
    while(cur!=NULL) {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    L=Reverse(L);
    printf("After:\n");
    cur=L;
    while(cur!=NULL) {
        printf("%d ",cur->data);
        cur=cur->next;
    }
}