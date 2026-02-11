## C Program Memory Layout
When a C program runs, its virtual memory is split into regions:
```c
High Address
+----------------------+
|        Stack         |  ← grows DOWN
|  (local variables,   |
|   function calls)    |
+----------------------+
|        Heap          |  ← grows UP
|  (malloc / free)     |
+----------------------+
|   BSS Segment        |
|  (uninitialized      |
|   globals/statics)   |
+----------------------+
|   Data Segment       |
|  (initialized        |
|   globals/statics)   |
+----------------------+
|   Text Segment       |
|  (machine code,      |
|   read-only data)    |
+----------------------+
Low Address
```