// Exercise 095: Graph Traversal (BFS)
//
// Implement Breadth-First Search on a graph!
//
// BFS uses a queue:
//   1. Start at node, mark visited
//   2. Add to queue
//   3. While queue not empty:
//      - Dequeue node
//      - For each neighbor: if not visited, mark and enqueue
//
// EXPECTED: BFS from node 0:
// EXPECTED: Visited: 0
// EXPECTED: Visited: 1
// EXPECTED: Visited: 2
// EXPECTED: Visited: 3
// EXPECTED: Visited: 4
// HINT: Use queue, track visited array

#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10

typedef struct {
    int items[MAX_NODES];
    int front, rear;
} Queue;

void queue_init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q, int value) {
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    int item = q->items[q->front];
    // TODO: Fix - should increment front, not decrement!
    q->front--;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

bool queue_is_empty(Queue *q) {
    return q->front == -1;
}

void bfs(int graph[][MAX_NODES], int num_nodes, int start) {
    bool visited[MAX_NODES] = {false};
    Queue q;
    queue_init(&q);

    visited[start] = true;
    enqueue(&q, start);

    printf("BFS from node %d:\n", start);

    while (!queue_is_empty(&q)) {
        int node = dequeue(&q);
        printf("Visited: %d\n", node);

        for (int i = 0; i < num_nodes; i++) {
            // TODO: Fix - should check graph[node][i] == 1!
            if (graph[i][node] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main(void) {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    bfs(graph, 5, 0);

    return 0;
}
