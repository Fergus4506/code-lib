#include<stdio.h>
struct Boo
{
    int data;
    struct Boo *ptr;
};
int main(){
    struct Boo *p=(struct Boo*)malloc(sizeof(struct Boo));
    p->ptr=(struct Boo*)malloc(sizeof(struct Boo));
    p->data=-1;
    p->ptr->data=-3;
    p->ptr->ptr=0;
    /*頭部插入節點*/
    struct Boo *temp=(struct Boo*)malloc(sizeof(struct Boo));
    temp->ptr=p;
    p=temp;
    temp=0;
    /*刪除頭部*/
    temp=p;
    p=p->ptr;
    free(temp);
    return 0;
}