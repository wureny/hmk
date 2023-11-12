#include<stdio.h>
#include<stdlib.h>
#include"list.h"
#include<math.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

int getMaxDigits(Node *head) {
    int max = 0;
    while (head != NULL) {
        int len = snprintf(NULL, 0, "%d", head->data);
        if (len > max) max = len;
        head = head->next;
    }
    return max;
}

void radixSort(Node **head) {
    int i, j, m, maxDigits;
    Node *temp, *rear, *front;
    Node *bins[10];

    maxDigits = getMaxDigits(*head);

    for (i = 0; i < 10; i++) {
        bins[i] = NULL;
    }

    for (i = 0; i < maxDigits; i++) {
        while (*head != NULL) {
            temp = *head;
            *head = (*head)->next;
            temp->next = NULL;

            if (temp == NULL) {
                continue;
            }

            m = (temp->data / ((int)pow(10, i))) % 10;

            if (bins[m] == NULL) {
                bins[m] = temp;
            } else {
                rear = bins[m];
                while (rear->next != NULL) {
                    rear = rear->next;
                }
                rear->next = temp;
            }
        }
        j = 0;
        while (bins[j] == NULL) {
            j++;
        }
        *head = bins[j];
        rear = bins[j];
        for (j++; j < 10; j++) {
            if (bins[j] != NULL) {
                rear->next = bins[j];
                while (rear->next != NULL) {
                    rear = rear->next;
                }
            }
            bins[j] = NULL;
        }
    }
}

int main() {
    Node *head = (Node*)malloc(sizeof(Node));
    int i, n, data;
    n=3;
    Node* cur=head;
    head->next=(Node*)malloc(sizeof(Node));
    cur=head->next;
    cur->data=2;
    cur->next=(Node*)malloc(sizeof(Node));
    cur=cur->next;
    cur->data=1;
    cur->next=(Node*)malloc(sizeof(Node));
    cur=cur->next;
    cur->data=3;
    radixSort(&head);
    cur=head->next;
    while(cur!=NULL) {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    return 0;
}
