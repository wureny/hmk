#include<stdio.h>
#include<stdlib.h>
double addfirstn(int n) {
    if (n==1) return 1;
    return 1.0/n + addfirstn(n-1);
}
int main() {
    int n=3;
    printf("%lf",addfirstn(n));
}
