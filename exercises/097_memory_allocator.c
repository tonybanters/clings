// Exercise 097: Simple Memory Allocator
//
// Build a basic memory allocator with first-fit strategy!
//
// Concepts:
//   - Free list: linked list of free blocks
//   - Allocate: find first block that fits
//   - Free: add block back to free list
//
// EXPECTED: Allocator created with 1024 bytes
// EXPECTED: Allocated 100 bytes
// EXPECTED: Allocated 200 bytes
// EXPECTED: Allocated 50 bytes
// EXPECTED: Freed 200 bytes
// EXPECTED: Allocated 150 bytes (reused freed space)
// HINT: Track free blocks in linked list, split blocks if needed

#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    size_t size;
    struct Block *next;
    int free;
} Block;

typedef struct {
    void *memory;
    Block *free_list;
} Allocator;

Allocator* allocator_create(size_t size) {
    Allocator *alloc = malloc(sizeof(Allocator));
    alloc->memory = malloc(size);

    // Initialize free list with one big block
    Block *block = (Block*)alloc->memory;
    block->size = size - sizeof(Block);
    block->next = NULL;
    // TODO: Fix - should set free = 1 (true)!
    block->free = 0;

    alloc->free_list = block;

    printf("Allocator created with %zu bytes\n", size);
    return alloc;
}

void* allocator_alloc(Allocator *alloc, size_t size) {
    Block *current = alloc->free_list;

    while (current != NULL) {
        if (current->free && current->size >= size) {
            // TODO: Fix - should set free = 0 (false)!
            current->free = 1;
            printf("Allocated %zu bytes\n", size);
            // TODO: Fix - return pointer after Block header!
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void allocator_free(Allocator *alloc, void *ptr) {
    // TODO: Implement free!
    // Hint: Get Block* by subtracting sizeof(Block) from ptr
    //       Set free = 1

    printf("Freed bytes\n");
}

int main(void) {
    Allocator *alloc = allocator_create(1024);

    void *p1 = allocator_alloc(alloc, 100);
    void *p2 = allocator_alloc(alloc, 200);
    void *p3 = allocator_alloc(alloc, 50);

    allocator_free(alloc, p2);

    void *p4 = allocator_alloc(alloc, 150);

    return 0;
}
