// Exercise 098: Introduction to Multithreading
//
// Use pthreads to run code in parallel!
//
// Basic pattern:
//   1. pthread_create(&thread, NULL, function, arg)
//   2. pthread_join(thread, NULL)
//
// EXPECTED: Thread 1: Count 0
// EXPECTED: Thread 2: Count 0
// EXPECTED: Thread 1: Count 1
// EXPECTED: Thread 2: Count 1
// EXPECTED: Thread 1: Count 2
// EXPECTED: Thread 2: Count 2
// EXPECTED: Both threads finished
// HINT: Use pthread_create and pthread_join, pass data to threads

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void *arg) {
    int thread_id = *(int*)arg;

    for (int i = 0; i < 3; i++) {
        printf("Thread %d: Count %d\n", thread_id, i);
        // TODO: Uncomment to add small delay
        // usleep(100000);  // 100ms
    }

    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;

    // TODO: Fix - should pass &id1, not id1!
    pthread_create(&thread1, NULL, thread_function, id1);
    pthread_create(&thread2, NULL, thread_function, &id2);

    // TODO: Add pthread_join for thread1!
    pthread_join(thread2, NULL);

    printf("Both threads finished\n");

    return 0;
}

// Compile with: gcc -pthread 098_multithreading.c -o 098_multithreading
