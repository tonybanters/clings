// Exercise 093: Simple Text Editor Buffer
//
// Implement basic text editor operations!
//
// Operations:
//   - Insert text at position
//   - Delete text
//   - Get current text
//
// EXPECTED: Inserted: Hello
// EXPECTED: Inserted at 5:  World
// EXPECTED: Current: Hello World
// EXPECTED: Deleted 6 chars from pos 5
// EXPECTED: Final: Hello
// HINT: Use memmove to shift characters, track length

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1000

typedef struct {
    char data[BUFFER_SIZE];
    size_t length;
} TextBuffer;

void tb_init(TextBuffer *tb) {
    tb->data[0] = '\0';
    tb->length = 0;
}

void tb_insert(TextBuffer *tb, size_t pos, const char *text) {
    size_t text_len = strlen(text);

    // TODO: Fix - should be memmove, not memcpy (overlapping memory)!
    // Move existing text to make room
    memcpy(tb->data + pos + text_len, tb->data + pos, tb->length - pos);

    // Insert new text
    memcpy(tb->data + pos, text, text_len);

    tb->length += text_len;
    tb->data[tb->length] = '\0';

    printf("Inserted at %zu: %s\n", pos, text);
}

void tb_delete(TextBuffer *tb, size_t pos, size_t count) {
    // TODO: Implement delete by moving text!
    // Hint: memmove(tb->data + pos, tb->data + pos + count, ...)

    printf("Deleted %zu chars from pos %zu\n", count, pos);
}

int main(void) {
    TextBuffer tb;
    tb_init(&tb);

    tb_insert(&tb, 0, "Hello");
    tb_insert(&tb, 5, " World");

    printf("Current: %s\n", tb.data);

    tb_delete(&tb, 5, 6);

    printf("Final: %s\n", tb.data);

    return 0;
}
