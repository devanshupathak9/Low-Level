#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;


void insert(TreeNode **head, int data) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    TreeNode *curr = *head;
    if (curr) {
        while (curr) {
            if (curr->data < data) {
                if (curr->right == NULL) {
                    curr->right = node; break;
                }
                curr = curr->right;
            } else {
                if (curr->left == NULL) {
                    curr->left = node; break;
                }
                curr = curr->left;
            }
        }
    } else {
        *head = node;
    }
}

int main() {
    TreeNode *head = NULL;
    insert(&head, 15);
    insert(&head, 7);
    insert(&head, 18);
    insert(&head, 12);
    insert(&head, 45);

    printf("head->%d\n", head->data);
    printf("head->left->%d\n", head->left->data);
    printf("head->right->%d\n", head->right->data);
}