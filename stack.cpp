#include <iostream>
using namespace std;
#define DEFAULT_STACK_SIZE 10
class Stack
{
private:
    int top;
    int *arr;
public:
    int len=DEFAULT_STACK_SIZE;
    Stack()
    {
        arr = new int[DEFAULT_STACK_SIZE];
        top = -1;
    }
    Stack(int size)
    {
        arr = new int[size];
        top=-1;
        len=size;
    }
    Stack(Stack&s){
        top=s.top;
        arr=new int[DEFAULT_STACK_SIZE];
        for(int i=0;i<top+1;i++){
            if(is_full()){
                cout << "Stack overflow error!\n";
                break;
            }
            arr[i]=s.arr[i];
        }
    }
    bool is_empty()
    { // function member, operation, method
        return top == -1;
    }
    // Function to check if the stack is full
    bool is_full()
    {
        return top == len - 1;
    }
    // Function to push an element onto the stack
    void push(int element)
    {
        if (is_full())
        {
            cout << "Stack overflow error!\n";
            exit(EXIT_FAILURE);
        }
        arr[++top] = element;
    }
    // Function to pop an element from the stack
    int pop()
    {
        if (is_empty())
        {
            cout << "Stack underflow error!\n";
            exit(EXIT_FAILURE);
        }
        return arr[top--];
    }
    // Function to peek at the top element in the stack
    int peek()
    {
        if (is_empty())
        {
            cout << "Stack is empty!\n";
            exit(EXIT_FAILURE);
        }
        return arr[top];
    }
    // Function to print the elements in the stack
    void print_stack()
    {
        if (is_empty())
        {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Elements in the stack: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    Stack& operator<<(int data){
        push(data);
        return *this;
    }
    Stack& operator<<(Stack&is){
        for(int i=0;i<is.top+1;i++){
            if(is_full()){
                break;
            }
            push(is.arr[is.top-i]);
        }
        return *this;
    }
    Stack& operator+=(Stack&is){
        for(int i=0;i<is.top+1;i++){
            if(is_full()){
                break;
            }
            push(is.arr[i]);
        }
        return *this;
    }
    Stack& operator=(Stack&is){
        for(int i=0;i<is.top+1;i++){
            arr[i]=is.arr[i];
            top++;
        }
        return *this;
    }
    int operator-(){
        return pop();
    }
    int operator~(){
         return peek();;
    }
    void operator!(){
        arr=new int[len];
        top=-1;
    }
};

ostream& operator<<(ostream&os,Stack&s){
    s.print_stack();
    return os;
}
/*Stack& operator<<(Stack&s,int data){
    s.push(data);
    return s;
}*/
int main()
{
    int m=5;
    Stack s1,s2(m),s3(s1);  //overloading constructors
    cout<<s1<<s2<<s3;       //display the stack content
    s1<<1<<2<<3;            // << : push element
    cout<<s1<<s2<<s3;       //overloading <<
    s2<<8<<9;               //s1:123 s2:89
    s3=s2+=s1<<4;           // +=: copy content to other stack 複製的概念跟推入推出是不一樣的，複製是陣列的概念而推入是stack的概念
//    s3=(s2+s1)<<4;
    cout<<s1<<s2<<s3;       
    cout<<-s1<<-s2<<-s3;    // -: pop 將pop出來的資料丟出並且輸出
    cout<<s1<<s2<<s3;       
    cout<<~s1<<~s2<<5;      // ~:peek
    !s1;                    // empty stack  
    s1<<0<<s2;              //overloading <<  // 我將 "<<" 設定為 s1原本的資料保留，然後將s2裡的資料由top丟進s1，
    cout<<s1<<(s2<<-1)<<s3; //在輸出前將s2中推入-1
    return 0;
}