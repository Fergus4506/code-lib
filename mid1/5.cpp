#include<stdio.h>
#define abs(a) (a<0?a*-1:a)
int main(){
    int a=220;
    a=abs(a);
    printf("%d",a);
    return 0;
}