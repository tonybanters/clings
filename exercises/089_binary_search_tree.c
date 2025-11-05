// Exercise 089: Binary Search Tree
//
// A tree where left < parent < right!
//
// Operations:
//   - Insert: recursively find correct position
//   - Search: compare and go left or right
//
// EXPECTED: Inserted: 50
// EXPECTED: Inserted: 30
// EXPECTED: Inserted: 70
// EXPECTED: Inserted: 20
// EXPECTED: Inserted: 40
// EXPECTED: Found 30: Yes
// EXPECTED: Found 100: No
// HINT: Use recursion, compare values to decide left or right

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* create_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node *root, int data) {
    if (root == NULL) {
        printf("Inserted: %d\n", data);
        return create_node(data);
    }

    // TODO: Fix condition - should be data < root->data!
    if (data > root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

int search(Node *root, int data) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == data) {
        return 1;
    }

    // TODO: Implement search logic!
    // Hint: if (data < root->data) return search(root->left, data);
    //       else return search(root->right, data);
    return 0;
}

int main(void) {
    Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    printf("Found 30: %s\n", search(root, 30) ? "Yes" : "No");
    printf("Found 100: %s\n", search(root, 100) ? "Yes" : "No");

    return 0;
}
