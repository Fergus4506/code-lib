#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 // Maximum size of the stack
// Define the stack structure
struct Stack {
    int top; // Index of the top element in the stack
    int arr[MAX_SIZE]; // Array to store the elements in the stack
};
// Function to initialize the stack
void initialize(struct Stack *s) {
    s->top = -1;
}
// Function to check if the stack is empty
int is_empty(struct Stack *s) {
    return s->top == -1;
}
// Function to check if the stack is full
int is_full(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}
// Function to push an element onto the stack
void push(struct Stack *s, int element) {
    if (is_full(s)) {
        printf("Stack overflow error!\n");
        exit(EXIT_FAILURE);
    }
    s->top++;
    s->arr[s->top] = element;
}
// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow error!\n");
        exit(EXIT_FAILURE);
    }
    int element = s->arr[s->top];
    s->top--;
    return element;
}
// Function to peek at the top element in the stack
int peek(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    return s->arr[s->top];
}
// Function to print the elements in the stack
void print_stack(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Elements in the stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
int main() {
    struct Stack s;
    initialize(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    print_stack(&s); // Output: Elements in the stack: 1 2 3
    pop(&s);
    print_stack(&s); // Output: Elements in the stack: 1 2
    printf("Top element in the stack: %d\n", peek(&s)); // Output: Top element in the stack: 2
    return 0;
}
 