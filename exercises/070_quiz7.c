// Exercise 070: Quiz 7 - Advanced Patterns
//
// This quiz tests your understanding of:
//   - Memory management patterns
//   - Data structure implementation
//   - Algorithm application
//
// Implement a simple hash table!
//
// EXPECTED: Inserted: apple -> 5
// EXPECTED: Inserted: banana -> 6
// EXPECTED: Inserted: cherry -> 6
// EXPECTED: Found apple: 5
// EXPECTED: Found banana: 6
// EXPECTED: cherry not found (deleted)
// HINT: Implement hash function, collision handling, insertion, deletion

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Entry {
    char *key;
    int value;
    struct Entry *next;  // For collision handling (chaining)
} Entry;

typedef struct {
    Entry *buckets[TABLE_SIZE];
} HashTable;

// Simple hash function
unsigned int hash(const char *key) {
    unsigned int hash = 0;
    // TODO: Implement hash function!
    // Hint: for each char, hash = hash * 31 + *key;
    return hash % TABLE_SIZE;
}

void ht_insert(HashTable *ht, const char *key, int value) {
    unsigned int index = hash(key);

    // TODO: Create new entry and insert at head of bucket!
    // Hint: malloc Entry, set fields, link to ht->buckets[index]

    printf("Inserted: %s -> %d\n", key, value);
}

int ht_get(HashTable *ht, const char *key, int *value) {
    unsigned int index = hash(key);
    Entry *current = ht->buckets[index];

    // TODO: Search linked list for key!
    // Return 1 if found, 0 if not found

    return 0;
}

void ht_delete(HashTable *ht, const char *key) {
    // TODO: Implement deletion!
    // Find entry and remove from linked list
}

int main(void) {
    HashTable ht = {0};  // Zero-initialize

    ht_insert(&ht, "apple", 5);
    ht_insert(&ht, "banana", 6);
    ht_insert(&ht, "cherry", 6);

    int value;
    if (ht_get(&ht, "apple", &value)) {
        printf("Found apple: %d\n", value);
    }

    if (ht_get(&ht, "banana", &value)) {
        printf("Found banana: %d\n", value);
    }

    ht_delete(&ht, "cherry");

    if (!ht_get(&ht, "cherry", &value)) {
        printf("cherry not found (deleted)\n");
    }

    return 0;
}
