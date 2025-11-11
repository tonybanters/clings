// Exercise 040: Linked Lists - Introduction
//
// A linked list is a dynamic data structure where each node
// contains data and a pointer to the next node.
//
// Node structure:
//   struct Node {
//       int data;
//       struct Node *next;
//   };
//
// Operations:
//   - Insert at head: O(1)
//   - Insert at tail: O(n)
//   - Search: O(n)
//   - Delete: O(n)
//
// Advantages:
//   - Dynamic size
//   - Easy insertion/deletion
//
// Disadvantages:
//   - No random access
//   - Extra memory for pointers
//
// Fix THREE linked list bugs!
//
// EXPECTED: List: 3 -> 2 -> 1 -> NULL
// EXPECTED: Found 2: Yes
// EXPECTED: After delete: 3 -> 1 -> NULL
// HINT: Fix pointer operations, malloc, free, and list traversal

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert at the beginning
struct Node* insert_head(struct Node *head, int data) {
    struct Node *new_node = malloc(sizeof(struct Node));
    if (new_node == NULL) {
        return head;
    }

    new_node->data = data;
    // TODO: Fix this!
    new_node->next = NULL;
    return new_node;
}

// Search for a value
int search(struct Node *head, int target) {
    struct Node *current = head;
    // TODO: Fix this!= NULL, not current->next!
    while (current->next != NULL) {
        if (current->data == target) {
            return 1;  // Found
        }
        current = current->next;
    }
    return 0;  // Not found
}

// Delete a node with given value
struct Node* delete_node(struct Node *head, int target) {
    if (head == NULL) {
        return NULL;
    }

    // If head needs to be deleted
    if (head->data == target) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Search for the node to delete
    struct Node *current = head;
    while (current->next != NULL && current->next->data != target) {
        current = current->next;
    }

    // Delete the node
    if (current->next != NULL) {
        struct Node *temp = current->next;
        current->next = current->next->next;
        // TODO: Fix memory leak!
    }

    return head;
}

// Print list
void print_list(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Free entire list
void free_list(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main(void) {
    struct Node *head = NULL;

    // Insert elements
    head = insert_head(head, 1);
    head = insert_head(head, 2);
    head = insert_head(head, 3);

    printf("List: ");
    print_list(head);

    // Search
    printf("Found 2: %s\n", search(head, 2) ? "Yes" : "No");

    // Delete
    head = delete_node(head, 2);
    printf("After delete: ");
    print_list(head);

    free_list(head);
    return 0;
}
