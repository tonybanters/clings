// Exercise 090: Quiz 9 - Data Structures and Algorithms
//
// This quiz tests your understanding of:
//   - Dynamic memory management
//   - Generic programming with void*
//   - Data structure implementation
//
// Implement a simple stack that can store any type!
//
// EXPECTED: Pushed: 10
// EXPECTED: Pushed: 20
// EXPECTED: Pushed: 30
// EXPECTED: Popped: 30
// EXPECTED: Popped: 20
// EXPECTED: Top: 10
// HINT: Use void* for data, malloc for nodes, track top pointer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    void *data;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
    size_t elem_size;
} Stack;

void stack_init(Stack *s, size_t elem_size) {
    // TODO: Initialize stack!
}

void stack_push(Stack *s, void *data) {
    // TODO: Create new node, copy data, link to top!
    // Hint: malloc(sizeof(StackNode))
    //       node->data = malloc(s->elem_size)
    //       memcpy(node->data, data, s->elem_size)

    printf("Pushed: %d\n", *(int*)data);
}

int stack_pop(Stack *s, void *data) {
    // TODO: Check if empty, copy data, free node, return 1
    // Return 0 if empty
    return 0;
}

int stack_peek(Stack *s, void *data) {
    // TODO: Copy top data without removing
    // Return 1 if success, 0 if empty
    return 0;
}

int main(void) {
    Stack s;
    stack_init(&s, sizeof(int));

    int values[] = {10, 20, 30};
    for (int i = 0; i < 3; i++) {
        stack_push(&s, &values[i]);
    }

    int popped;
    if (stack_pop(&s, &popped)) {
        printf("Popped: %d\n", popped);
    }

    if (stack_pop(&s, &popped)) {
        printf("Popped: %d\n", popped);
    }

    int top;
    if (stack_peek(&s, &top)) {
        printf("Top: %d\n", top);
    }

    return 0;
}
