#include <stdlib.h>
#include <stdio.h>
#define TABLE_SIZE 21

typedef struct Map {
    char *name;
    int age;
    struct Map *next;
} Map;

Map *table[TABLE_SIZE];

void init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

int hash_value(char *name) {
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }
    return sum % TABLE_SIZE;
}

void insert(Map *person) {
    int hash = hash_value(person->name);

    Map *curr = (Map*)malloc(sizeof(Map));
    curr->name = person->name;
    curr->age = person->age;

    Map *node = table[hash];
    if (node == NULL) {
        table[hash] = curr;
    } else {
        Map *head = table[hash];
        while (head->next) {
            head = head->next;
        }
        head->next = curr;
    }
}

Map *search(char *name) {
    int hash = hash_value(name);
    Map *node = table[hash];
    while (node) {
        if (node->name == name) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void printMap(Map *map) {
    if (map == NULL) {
        printf("Nothing found\n");
        return;
    }
    printf("%s\n", map->name);
    printf("%d\n", map->age);
}

int main() {
    init();
    Map p1 = {.name = "aman", .age = 12};
    insert(&p1);
    Map p2 = {.name = "nama", .age = 21};
    insert(&p2);

    Map *res = search("nma");
    printMap(res);
    return 0;
}