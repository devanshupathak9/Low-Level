## C Basics
## Header Files
- <stdio.h> – Standard Input Output
- <stdlib.h> – Standard Library
- <string.h> - String Handling functions
<hr>

## Pointers
<hr>

## typedef
typedef is a keyword that is used to provide existing data type with a new name.<br>
typedef existing_type new_type;<br>
After the declaration, we can use alias name as if it was the real existing name in the program.
```c
typedef long long ll;
ll x = 10*9;

typedef int * ip;
ip ptr = &a;

typedef struct Node{
    int data; 
    struct Node* next;
} Node;
Node* ptr = NULL;
```
<hr>

## Structures (struct)
structs are user-defined data type that is used to group items of different data types into a single type.
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
<hr>

## Self-Referential Structures
The self-referential structures are those structures that contain references to the same type as themselves i.e. they contain a member of the type pointer pointing to the same structure type.
<hr>

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