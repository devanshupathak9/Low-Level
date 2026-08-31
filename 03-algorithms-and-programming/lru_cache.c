#include <stdio.h>
#include <stblib.h>
#define MAXSIZE 100

typedef struct Node {
    char *data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct HashTable {
    Node *HTable[MAXSIZE];
} HashTable;

typedef struct LRUCache {
    HashTable *htable;
    int capacity;
    
} LRUCache;

int main() {

}