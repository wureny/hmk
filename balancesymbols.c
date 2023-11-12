#include<stdio.h>
#include<stdlib.h>
#include"stackli.h"
int Balancesymbols(char *s){
    Stack S;
    S = CreateStack();
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            Push(s[i],S);
        }
        else if(s[i] == ')'){
            if(Top(S) == '('){
                Pop(S);
            }
            else{
                return 0;
            }
        }
        else if(s[i] == ']'){
            if(Top(S) == '['){
                Pop(S);
            }
            else{
                return 0;
            }
        }
        else if(s[i] == '}'){
            if(Top(S) == '{'){
                Pop(S);
            }
            else{
                return 0;
            }
        }
        i++;
    }
    if(IsEmpty(S)){
        return 1;
    }
    return 0;
}