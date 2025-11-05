// Exercise 094: Expression Evaluator (RPN)
//
// Evaluate expressions in Reverse Polish Notation!
//
// RPN: 3 4 + means 3 + 4 = 7
//      5 1 2 + 4 * + means 5 + ((1 + 2) * 4) = 17
//
// Algorithm: Use a stack!
//   - If number: push
//   - If operator: pop two, apply operation, push result
//
// EXPECTED: 3 4 + = 7
// EXPECTED: 5 1 2 + 4 * + = 17
// EXPECTED: 15 7 1 1 + - / 3 * 2 1 1 + + - = 5
// HINT: Use stack, push numbers, pop for operators

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STACK_SIZE 100

typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

void stack_init(Stack *s) {
    s->top = -1;
}

void stack_push(Stack *s, int value) {
    s->data[++s->top] = value;
}

int stack_pop(Stack *s) {
    return s->data[s->top--];
}

int evaluate_rpn(const char *expr) {
    Stack s;
    stack_init(&s);

    char *expr_copy = strdup(expr);
    char *token = strtok(expr_copy, " ");

    while (token != NULL) {
        if (isdigit(token[0])) {
            // TODO: Fix - should use atoi to convert string to int!
            stack_push(&s, token[0]);
        } else {
            // Operator
            int b = stack_pop(&s);
            int a = stack_pop(&s);

            // TODO: Implement operator logic!
            // Hint: switch(token[0]) {
            //         case '+': stack_push(&s, a + b); break;
            //         case '-': stack_push(&s, a - b); break;
            //         ...
            //       }
        }

        token = strtok(NULL, " ");
    }

    free(expr_copy);
    return stack_pop(&s);
}

int main(void) {
    printf("3 4 + = %d\n", evaluate_rpn("3 4 +"));
    printf("5 1 2 + 4 * + = %d\n", evaluate_rpn("5 1 2 + 4 * +"));
    printf("15 7 1 1 + - / 3 * 2 1 1 + + - = %d\n",
           evaluate_rpn("15 7 1 1 + - / 3 * 2 1 1 + + -"));

    return 0;
}
