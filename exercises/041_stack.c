// Exercise 041: Stack Data Structure
//
// A stack is a LIFO (Last In, First Out) data structure.
//
// Operations:
//   - push: add to top
//   - pop: remove from top
//   - peek: look at top
//   - isEmpty: check if empty
//
// Can be implemented with:
//   - Array (fixed size)
//   - Linked list (dynamic)
//
// Uses:
//   - Function call stack
//   - Undo/redo
//   - Expression evaluation
//   - Backtracking algorithms
//
// Fix THREE stack implementation bugs!
//
// EXPECTED: Pushed: 10
// EXPECTED: Pushed: 20
// EXPECTED: Pushed: 30
// EXPECTED: Top: 30
// EXPECTED: Popped: 30
// EXPECTED: Popped: 20
// EXPECTED: Final top: 10
// HINT: Fix array index logic, boundary checks, and push/pop operations

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void init_stack(struct Stack *s) {
    // TODO: Fix this!
    s->top = 0;
}

int is_empty(struct Stack *s) {
    return s->top == -1;
}

int is_full(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, int value) {
    if (is_full(s)) {
        printf("Stack overflow!\n");
        return;
    }
    // TODO: Fix this!
    s->data[s->top] = value;
    printf("Pushed: %d\n", value);
}

int pop(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    // TODO: Fix this!
    s->top--;
    return s->data[s->top];
}

int peek(struct Stack *s) {
    if (is_empty(s)) {
        return -1;
    }
    return s->data[s->top];
}

int main(void) {
    struct Stack s;
    init_stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top: %d\n", peek(&s));

    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    printf("Final top: %d\n", peek(&s));

    return 0;
}
