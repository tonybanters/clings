// Exercise 068: Simple Memory Pool
//
// Memory pools pre-allocate a block and give out chunks.
// This is faster than repeated malloc/free!
//
// Concept:
//   - Allocate big block upfront
//   - Track current position
//   - "Allocate" by returning pointer and advancing
//
// EXPECTED: Pool created with 1024 bytes
// EXPECTED: Allocated 100 bytes at offset 0
// EXPECTED: Allocated 200 bytes at offset 100
// EXPECTED: Allocated 50 bytes at offset 300
// EXPECTED: Pool freed
// HINT: Track offset, check bounds, return pointer to current position

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *memory;
    size_t size;
    size_t used;
} MemoryPool;

MemoryPool* pool_create(size_t size) {
    MemoryPool *pool = malloc(sizeof(MemoryPool));
    if (pool == NULL) return NULL;

    pool->memory = malloc(size);
    if (pool->memory == NULL) {
        free(pool);
        return NULL;
    }

    pool->size = size;
    pool->used = 0;

    printf("Pool created with %zu bytes\n", size);
    return pool;
}

void* pool_alloc(MemoryPool *pool, size_t size) {
    // TODO: Check if enough space: if (pool->used + size > pool->size) return NULL;

    void *ptr = pool->memory + pool->used;
    printf("Allocated %zu bytes at offset %zu\n", size, pool->used);

    // TODO: Update used: pool->used += size;

    return ptr;
}

void pool_free(MemoryPool *pool) {
    if (pool) {
        free(pool->memory);
        // TODO: Don't forget to free the pool struct itself!
        printf("Pool freed\n");
    }
}

int main(void) {
    MemoryPool *pool = pool_create(1024);

    int *arr1 = pool_alloc(pool, 100);
    int *arr2 = pool_alloc(pool, 200);
    int *arr3 = pool_alloc(pool, 50);

    pool_free(pool);

    return 0;
}
