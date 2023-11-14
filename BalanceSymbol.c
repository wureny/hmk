#include "stackli.h"
#include <stdio.h>
#include <stdlib.h>

int IsBalancedSymbols(char *expr) {
    Stack S = CreateStack();
    int balanced = 1;
    int index = 0;
    char symbol;

    while (expr[index] != '\0' && balanced) {
        symbol = expr[index];
        switch (symbol) {
            case '(': case '[': case '{':
                Push(symbol, S);
                break;
            case ')': case ']': case '}':
                if (IsEmpty(S)) {
                    balanced = 0; 
                } else {
                    char topSymbol = Top(S);
                    Pop(S);
                    if ((topSymbol == '(' && symbol != ')') ||
                        (topSymbol == '[' && symbol != ']') ||
                        (topSymbol == '{' && symbol != '}')) {
                        balanced = 0; 
                    }
                }
                break;
            default: 
                break;
        }
        index++;
    }

    if (balanced && !IsEmpty(S)) {
        balanced = 0; 
    }
    DisposeStack(S); 
    return balanced;
}

int main() {
    char *expression = "{[(2 + 3) * (5 / 1)] - (4 * 6)}";
    if (IsBalancedSymbols(expression)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }
    return 0;
}
