#include"list.h"
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

List reverse(List L) {
    if (L->next==NULL) return NULL;
    List cur=(Node*)malloc(sizeof(Node));
    cur=L;
    List pre=L;
    while(cur!=NULL) {
        List tmp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=tmp;
    }
    L->next=NULL;
    return pre;
}

//Test reverse funciton
int main() {
    List L=(Node*)malloc(sizeof(Node));
    L->data=0;
    L->next=(Node*)malloc(sizeof(Node));
    L->next->data=1;
    L->next->next=(Node*)malloc(sizeof(Node));
    L->next->next->data=2;
    printf("Before reverse:\n");
    List cur=L;
    while(cur!=NULL) {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    printf("\n");
    L=reverse(L);
    printf("After reverse:\n");
    cur=L;
    while(cur!=NULL) {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    printf("\n");
}