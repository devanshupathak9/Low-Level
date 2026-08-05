# 02 — Data Structures in C

Implementing data structures by hand is really pointer practice with a purpose.
No library helps you here — you allocate every node and you free every node.

## Folders

| Folder | What goes in it |
| --- | --- |
| `linked-list/` | Singly, doubly and circular lists; insert, delete, reverse (iterative + recursive) |
| `stack-and-queue/` | Array-backed and list-backed versions, circular buffer |
| `trees/` | Binary tree, BST, traversals, height/depth |
| `hash-table/` | Hash functions, buckets, collision handling with chaining |
| `sorting-and-searching/` | Bubble/insertion/merge/quick sort, linear and binary search |

## Things to hold yourself to

- Every `malloc` has a matching `free`. Check with `valgrind`.
- Always check the return of `malloc` for `NULL`.
- Handle the empty structure and the single-element structure as explicit cases —
  that is where almost every bug lives.

## Build

```bash
make FILE=02-data-structures/linked-list/reverse_linked_list.c run
```
