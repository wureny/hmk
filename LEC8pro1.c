#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct BTNode {
    ElementType data;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

int leaf(BTNode* t) {
    if(t == NULL) {
        return 0;
    }
    if(t->left == NULL && t->right == NULL) 
    return 1;
    return leaf(t->left) + leaf(t->right);
}