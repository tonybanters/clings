// Exercise 096: Hash Map Implementation
//
// Build a complete hash map with chaining!
//
// This combines concepts from earlier exercises:
//   - Hash function
//   - Linked list for chaining
//   - Dynamic memory
//
// EXPECTED: Set: apple = 5
// EXPECTED: Set: banana = 3
// EXPECTED: Set: cherry = 8
// EXPECTED: Get apple: 5
// EXPECTED: Get banana: 3
// EXPECTED: Delete cherry
// EXPECTED: Get cherry: not found
// HINT: Use linked list at each bucket, hash to find bucket

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Entry {
    char *key;
    int value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry *buckets[TABLE_SIZE];
} HashMap;

unsigned int hash(const char *key) {
    unsigned int h = 0;
    while (*key) {
        h = h * 31 + *key++;
    }
    return h % TABLE_SIZE;
}

void map_init(HashMap *map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->buckets[i] = NULL;
    }
}

void map_set(HashMap *map, const char *key, int value) {
    unsigned int index = hash(key);

    // Check if key exists
    Entry *current = map->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->value = value;
            printf("Set: %s = %d\n", key, value);
            return;
        }
        current = current->next;
    }

    // Create new entry
    Entry *new_entry = malloc(sizeof(Entry));
    new_entry->key = strdup(key);
    new_entry->value = value;
    // TODO: Fix - should link to existing bucket!
    new_entry->next = NULL;
    map->buckets[index] = new_entry;

    printf("Set: %s = %d\n", key, value);
}

int map_get(HashMap *map, const char *key, int *value) {
    unsigned int index = hash(key);
    Entry *current = map->buckets[index];

    while (current != NULL) {
        // TODO: Fix - should use strcmp, not ==!
        if (current->key == key) {
            *value = current->value;
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void map_delete(HashMap *map, const char *key) {
    // TODO: Implement deletion!
    // Hint: Track previous entry to update next pointer
    printf("Delete %s\n", key);
}

int main(void) {
    HashMap map;
    map_init(&map);

    map_set(&map, "apple", 5);
    map_set(&map, "banana", 3);
    map_set(&map, "cherry", 8);

    int value;
    if (map_get(&map, "apple", &value)) {
        printf("Get apple: %d\n", value);
    }

    if (map_get(&map, "banana", &value)) {
        printf("Get banana: %d\n", value);
    }

    map_delete(&map, "cherry");

    if (!map_get(&map, "cherry", &value)) {
        printf("Get cherry: not found\n");
    }

    return 0;
}
