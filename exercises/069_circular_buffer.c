// Exercise 069: Circular Buffer (Ring Buffer)
//
// A circular buffer is a fixed-size buffer that wraps around.
// Used in: audio, network buffers, producer-consumer patterns
//
// Uses modulo to wrap indices!
//
// EXPECTED: Wrote: 10
// EXPECTED: Wrote: 20
// EXPECTED: Wrote: 30
// EXPECTED: Read: 10
// EXPECTED: Wrote: 40
// EXPECTED: Read: 20
// EXPECTED: Read: 30
// HINT: Use modulo for wrap-around, track read/write positions

#include <stdio.h>

#define BUFFER_SIZE 3

typedef struct {
    int data[BUFFER_SIZE];
    int read_pos;
    int write_pos;
    int count;  // Number of items in buffer
} CircularBuffer;

void cb_init(CircularBuffer *cb) {
    cb->read_pos = 0;
    cb->write_pos = 0;
    cb->count = 0;
}

int cb_write(CircularBuffer *cb, int value) {
    if (cb->count == BUFFER_SIZE) {
        return 0;  // Buffer full
    }

    cb->data[cb->write_pos] = value;
    // TODO: Fix - use modulo: cb->write_pos = (cb->write_pos + 1) % BUFFER_SIZE;
    cb->write_pos = cb->write_pos + 1;
    cb->count++;

    printf("Wrote: %d\n", value);
    return 1;
}

int cb_read(CircularBuffer *cb, int *value) {
    // TODO: Check if buffer is empty: if (cb->count == 0) return 0;

    *value = cb->data[cb->read_pos];
    cb->read_pos = (cb->read_pos + 1) % BUFFER_SIZE;
    // TODO: Decrement count: cb->count--;

    printf("Read: %d\n", *value);
    return 1;
}

int main(void) {
    CircularBuffer cb;
    cb_init(&cb);

    cb_write(&cb, 10);
    cb_write(&cb, 20);
    cb_write(&cb, 30);

    int value;
    cb_read(&cb, &value);

    cb_write(&cb, 40);  // Reuses slot from first read

    cb_read(&cb, &value);
    cb_read(&cb, &value);

    return 0;
}
