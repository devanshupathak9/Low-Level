## C Basics
## Header Files
- <stdio.h> – Standard Input Output
- <stdlib.h> – Standard Library
- <string.h> - String Handling functions
<hr>

## Pointers
<hr>

## Structures (struct)
Used to group related data.
```c
struct Student{
    int id;
    char name[50];
    fload marks;
}
struct Student s1;
s1.id = 5;
s1.name = "xyz";
```
## Self Refrentials Structure


## Memory Management in C
### Stack Memory
- Automatic
- Local variables
- Freed autlmatically

### Heap Memory
- Dynamic
- Allocate and Free manually
- Uses Pointers

##### 1. malloc() - allocates memory (uninitialized)
```c
int *ptr = (int *)malloc(10*sizeof(int));
Node *ptr = (Node *)malloc(sizeof(Node));
```
##### 2. realloc() - Resizes allocated memory
```c
ptr = realloc(ptr, 10*sizeof(int)));
```

#### 3. calloc() - llocates and initializes to zero
```c
int *ptr = (int*) calloc(5, sizeof(int));
```
#### 3. free() - free memory
```c
free(ptr);
```
<hr>