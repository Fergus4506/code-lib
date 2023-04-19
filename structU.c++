#include<stdio.h>
struct Y
{
    int date;
    Y(int _d){date=_d;printf("%d user hello\n",date);}
    ~Y(){printf("%d user bye\n",date);}
};
int main(){
    Y y1(-1);
}
Y y1(1),*p =new Y(2);

