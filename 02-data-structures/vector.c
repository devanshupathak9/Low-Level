#include <stdio.h>
#include <stdlib.h>
# define MAX_CAPACITY 10

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;


void vector_init(vector *vect) {
    vect->size = 0;
    vect->capacity = MAX_CAPACITY;
    vect->data = calloc(vect->capacity, sizeof(int));
}


void push_back(vector *vect, int value) {
    if (vect->size == vect->capacity) {
        size_t new_capacity = 2*vect->capacity;
        int *temp = realloc(vect->data, new_capacity*sizeof(int));
        if (temp == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        vect->data = temp;
        vect->capacity = new_capacity;
    }
    vect->data[vect->size] = value;
    vect->size++;
}


size_t size(vector *vect) {
    return vect->size;
}

void pop_back(vector *vect) {
    if (vect->size > 0) {
        vect->size--;
    }
}


int get(vector *vect, size_t index) {
    if (index >= vect->size) {
        fprintf(stderr, "Index out of range!!\n");
        exit(EXIT_FAILURE);
    }
    return vect->data[index];
}

int main() {
    vector vect;
    vector_init(&vect);

    push_back(&vect, 3);
    push_back(&vect, 12);
    push_back(&vect, 31);
    push_back(&vect, 19);
    push_back(&vect, 45);
    pop_back(&vect);

    printf("%zu\n", size(&vect));
    printf("%d\n", get(&vect, 2));
    printf("%d\n", get(&vect, 4));
    printf("%d\n", get(&vect, 12));
    free(vect.data);
    return 0;
}