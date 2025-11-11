// Exercise 091: Simple JSON Parser
//
// Parse a simple JSON object!
//
// We'll just handle {"key": "value"} format.
// Real JSON parsers are much more complex!
//
// EXPECTED: Parsing: {"name": "Alice"}
// EXPECTED: Key: name
// EXPECTED: Value: Alice
// HINT: Find quotes, extract strings between them

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void parse_simple_json(const char *json) {
    printf("Parsing: %s\n", json);

    // Find first quoted string (key)
    const char *key_start = strchr(json, '"');
    if (key_start == NULL) return;
    key_start++;  // Skip opening quote

    // TODO: Fix this!
    const char *key_end = strrchr(key_start, '"');

    char key[50];
    // TODO: Fix this!
    int key_len = key_start - key_end;
    strncpy(key, key_start, key_len);
    key[key_len] = '\0';

    printf("Key: %s\n", key);

    // Find second quoted string (value)
    const char *value_start = strchr(key_end + 1, '"');
    if (value_start == NULL) return;
    value_start++;

    const char *value_end = strchr(value_start, '"');

    char value[50];
    int value_len = value_end - value_start;
    strncpy(value, value_start, value_len);
    value[value_len] = '\0';

    printf("Value: %s\n", value);
}

int main(void) {
    parse_simple_json("{\"name\": \"Alice\"}");
    return 0;
}
