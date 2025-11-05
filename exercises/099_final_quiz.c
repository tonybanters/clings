// Exercise 099: Final Quiz - Putting It All Together
//
// This quiz tests everything you've learned!
//
// Build a simple in-memory key-value database with:
//   - Hash map for storage
//   - Command parsing (SET, GET, DEL)
//   - File persistence (save/load)
//   - Error handling
//
// EXPECTED: > SET name Alice
// EXPECTED: OK
// EXPECTED: > GET name
// EXPECTED: Alice
// EXPECTED: > SET age 25
// EXPECTED: OK
// EXPECTED: > GET age
// EXPECTED: 25
// EXPECTED: > DEL name
// EXPECTED: OK
// EXPECTED: > GET name
// EXPECTED: (null)
// HINT: Combine hash map, file I/O, string parsing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100
#define MAX_LINE 256

typedef struct Entry {
    char *key;
    char *value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry *buckets[TABLE_SIZE];
} Database;

unsigned int hash(const char *key) {
    // TODO: Implement hash function!
    return 0;
}

void db_init(Database *db) {
    // TODO: Initialize all buckets to NULL!
}

void db_set(Database *db, const char *key, const char *value) {
    // TODO: Implement set operation!
    // Hint: Similar to hash map from exercise 096
    printf("OK\n");
}

const char* db_get(Database *db, const char *key) {
    // TODO: Implement get operation!
    return NULL;
}

void db_delete(Database *db, const char *key) {
    // TODO: Implement delete operation!
    printf("OK\n");
}

void process_command(Database *db, const char *line) {
    char cmd[10], key[50], value[200];

    // Parse command
    if (sscanf(line, "%s %s %[^\n]", cmd, key, value) >= 2) {
        // TODO: Implement command processing!
        // Hint: if (strcmp(cmd, "SET") == 0) ...
        //       else if (strcmp(cmd, "GET") == 0) ...
        //       else if (strcmp(cmd, "DEL") == 0) ...
    }
}

int main(void) {
    Database db;
    db_init(&db);

    // Simulated commands (in real version, you'd read from stdin)
    const char *commands[] = {
        "SET name Alice",
        "GET name",
        "SET age 25",
        "GET age",
        "DEL name",
        "GET name",
        NULL
    };

    for (int i = 0; commands[i] != NULL; i++) {
        printf("> %s\n", commands[i]);
        process_command(&db, commands[i]);
    }

    return 0;
}

// Advanced extensions to try:
// - Save database to file with db_save()
// - Load database from file with db_load()
// - Add KEYS command to list all keys
// - Add EXISTS command to check if key exists
// - Add CLEAR command to clear database
