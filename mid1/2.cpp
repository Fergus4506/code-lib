#include <stdlib.h> 
#include<stdio.h>
struct Boo
{
    int data;
    Boo *ptr;
};
int main(){
    Boo *p=(Boo*)malloc(sizeof(Boo));
    p->ptr=(Boo*)malloc(sizeof(Boo));
    p->data=-1;
    p->ptr->data=-3;
    p->ptr->ptr=0;
    /*頭部插入節點*/
    Boo *temp=(Boo*)malloc(sizeof(Boo));
    temp->ptr=p;
    p=temp;
    temp=0;
    /*刪除頭部*/
    temp=p;
    p=p->ptr;
    free(temp);
    return 0;
}