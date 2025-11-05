// Exercise 042: Queue Data Structure
//
// A queue is a FIFO (First In, First Out) data structure.
//
// Operations:
//   - enqueue: add to rear
//   - dequeue: remove from front
//   - peek: look at front
//   - isEmpty: check if empty
//
// Can be implemented with:
//   - Array (circular queue)
//   - Linked list
//
// Uses:
//   - Task scheduling
//   - BFS algorithm
//   - Print spooler
//   - Message queues
//
// Fix THREE queue implementation bugs!
//
// EXPECTED: Enqueued: 10
// EXPECTED: Enqueued: 20
// EXPECTED: Enqueued: 30
// EXPECTED: Front: 10
// EXPECTED: Dequeued: 10
// EXPECTED: Dequeued: 20
// EXPECTED: Final front: 30
// HINT: Fix circular queue logic, indices, and boundary conditions

#include <stdio.h>

#define MAX_SIZE 5

struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
};

void init_queue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int is_empty(struct Queue *q) {
    return q->size == 0;
}

int is_full(struct Queue *q) {
    return q->size == MAX_SIZE;
}

void enqueue(struct Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue overflow!\n");
        return;
    }

    // TODO: Fix - need modulo for circular queue!
    q->rear = q->rear + 1;
    q->data[q->rear] = value;
    q->size++;
    printf("Enqueued: %d\n", value);
}

int dequeue(struct Queue *q) {
    if (is_empty(q)) {
        printf("Queue underflow!\n");
        return -1;
    }

    int value = q->data[q->front];
    // TODO: Fix - need modulo for circular queue!
    q->front = q->front + 1;
    q->size--;
    return value;
}

int peek(struct Queue *q) {
    if (is_empty(q)) {
        return -1;
    }
    return q->data[q->front];
}

int main(void) {
    struct Queue q;
    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    // TODO: Fix - missing third enqueue!

    printf("Front: %d\n", peek(&q));

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    printf("Final front: %d\n", peek(&q));

    return 0;
}
