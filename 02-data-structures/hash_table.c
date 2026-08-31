#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define MAX_SIZE 100

typedef struct Node {
    char *key;
    int value;
    struct Node* next;
} Node;

typedef struct HashTable{
    Node *table[MAX_SIZE];
    int size;
} HashTable;


void init(HashTable *hTable) {
    for (int i = 0; i < MAX_SIZE; i++) {
        hTable->table[i] = NULL;
    }
    hTable->size = 0;
}

int hashValue(char *key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0' ;i++) {
        sum += key[i];
    }
    return sum%MAX_SIZE;
}

void insert(HashTable *hTable, char *key, int value) {
    int hash = hashValue(key);
    Node *curr = hTable->table[hash];
    if (curr == NULL) {
        Node *node = malloc(sizeof(Node));
        node->key = key;
        node->value = value;
        node->next = NULL;
        hTable->table[hash] = node;
        hTable->size += 1;
        return;
    } 
    Node *prev = NULL;
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            curr->value = value;
            return ;
        }
        prev = curr;
        curr = curr->next;
    }
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    prev->next = node;
    hTable->size += 1;
}

int find(HashTable *hTable, char *key) {
    int hash = hashValue(key);
    Node *node = hTable->table[hash];
    if (node == NULL) {
        fprintf(stderr, "Key error!");
        return -1;
    }
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
        fprintf(stderr, "Key error!");
        return -1;
}

void removeKey(HashTable *hTable, char *key) {
    int hash = hashValue(key);
    Node *node = hTable->table[hash];
    if (node == NULL) {
        fprintf(stderr, "key not found!!");
        return;
    }
    Node *prev = NULL;
    while (node) {
        if (strcmp(node->key, key) == 0) {
            break;
        }
        prev = node;
        node = node->next;
    }
    if (node) {
        if (prev) {
            prev->next = node->next;
        } else {
            hTable->table[hash] = node->next;
        }
        free(node);
        hTable->size -= 1;
        return;
    }
    fprintf(stderr, "key not found!!");
}

int size(HashTable *hTable) {
    return hTable->size;
}

int main() {
    HashTable hTable;
    init(&hTable);
    insert(&hTable, "dev", 54);
    insert(&hTable, "ved", 63);
    insert(&hTable, "dove", 6);
    insert(&hTable, "rishab", 54);
    insert(&hTable, "ved", 154);
    removeKey(&hTable, "dove");

    printf("%d\n", size(&hTable));
    printf("%d\n", find(&hTable, "ved"));
}