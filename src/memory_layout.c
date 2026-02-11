#include <stdio.h>
#include <stdlib.h>

int global_init = 10;
int global_uninit;

void func() {
    int local = 5;
    printf("func local addr: %p\n", &local);
}

int main() {
    int local = 20;
    int *heap = malloc(sizeof(int));

    printf("Text (func):      %p\n", func);
    printf("Global init:      %p\n", &global_init);
    printf("Global uninit:    %p\n", &global_uninit);
    printf("Heap malloc:      %p\n", heap);
    printf("Stack local:      %p\n", &local);

    func();
    free(heap);
    return 0;
}
