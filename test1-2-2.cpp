#include <stdio.h>
class Actor
{
    int left, right;

public:
    Actor(int);
    Actor(int, int);
    Actor(Actor &);
    Actor &operator+(Actor);
    int operator!();
    ~Actor(){
        printf("delet\n");
    };
};
Actor::Actor(int n) : left(n), right(-n) {}
Actor::Actor(int m, int n)
{
    left = -m;
    right = m - n;
}
Actor::Actor(Actor &actor) : left(actor.right), right(actor.left) {}
/*Actor& actor 和 Actor actor不一樣，因為物件傳值使用記憶體位址的方式運作
所以今天當你使用的方式不為指標傳值時就會被判定為新建一個物件來暫時替代他的位置
也就是會造成這題在加號的部分呼叫建構值的原因*/
Actor &Actor::operator+(Actor actor)
{
    left += actor.left;
    right = actor.right;
    actor.left = actor.right = 0;
    return *this;
}
int Actor::operator!()
{
    if (left > right)
        printf("%d%d\n", left, right); 
    else
        printf("%d\n", right - left);
    return left + right;
}
int main()
{
    Actor joe(32 % 5);//left=2 right=-2
    Actor mary(32 % 10, 32 % 2);//left=-2 right=2
    Actor peter(mary);//left=2 right=-2
    !joe;                        // (1)2-2
    !!mary;                      // (2)4
    printf("%d\n", !peter + 11); // (3)2-2 \n 11
    !(joe + mary); 
    /* (4)+ => 建構(l=2,r=-2) 
    => 繼續運行+的部分 
    => joe l=4 r=-2
    => 解構暫時物件
    => !的運行
    => 輸出 4-2\n
    =>結束
    */
    printf("\n");            
    return 0;
}