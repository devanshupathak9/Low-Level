#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 100


typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;


typedef struct Queue {
    TreeNode *data[QUEUE_SIZE];
    int front;
    int back;
} Queue;


void init(Queue *queue) {
    queue->front = -1;
    queue->back = -1;
}

void insert(Queue *queue, TreeNode *node) {
    queue->data[queue->back + 1] = node;
    if (queue->front == -1) {
        queue->front++;
    }
    queue->back++;
}

TreeNode *pop(Queue *queue) {
    TreeNode *node = queue->data[queue->front];
    queue->front++;
    return node;
}

int size(Queue *queue) {
    return queue->back - queue->front + 1;
}

void levelOrderTraversal(TreeNode *head) {
    Queue queue;
    init(&queue);

    insert(&queue, head);

    printf("%d\n", head->data);
    while (size(&queue)) {
        int n = size(&queue);
        while (n) {
            TreeNode *node = pop(&queue);
            if (node->left) {
                printf("%d ", node->left->data);
                insert(&queue, node->left);
            }
            if (node->right) {
                printf("%d ", node->right->data);
                insert(&queue, node->right);
            }
            n--;
        }
        printf("\n");
    }
    return;
}


void insertTreeNode(TreeNode **head, int data) {
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


void freeTree(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    TreeNode *head = NULL;

    insertTreeNode(&head, 15);
    insertTreeNode(&head, 7);
    insertTreeNode(&head, 18);
    insertTreeNode(&head, 12);
    insertTreeNode(&head, 45);
    insertTreeNode(&head, 3);
    insertTreeNode(&head, 16);

    levelOrderTraversal(head);
    freeTree(head);
}