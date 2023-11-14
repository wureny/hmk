#include<stdio.h>
#include<stdlib.h>
int ackerman(int m,int n) {
    if (m==0) return n+1;
    if (m>0 && n==0) return ackerman(m-1,1);
    if (m>0 && n>0) return ackerman(m-1,ackerman(m,n-1));
}

int main() {
    int result1=ackerman(2,3);
    int result2=ackerman(2,5);
    int result3=ackerman(0,3);
    int result4=ackerman(3,0);
    printf("%d . ",result1);
    printf("%d . ",result2);
    printf("%d . ",result3);
    printf("%d . ",result4);
}