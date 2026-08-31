#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int id; 
    char *name;
    double marks;
} Student;

Student create(int id, char* name, double marks) {
    Student s1;
    s1.id = id;
    s1.name = name;
    s1.marks = marks;
    return s1;
}

void printStudent(Student *s) {
    printf("%d\n", s->id);
    printf("%s\n", s->name);
    printf("%f\n", s->marks);
}

void replaceMarks2(Student *s1, Student *s2) {
    char* name1 = s1->name;
    s1->name = s2->name;
    s2->name = name1;
}

int main() {
    Student s = create(1, "Dev", 65.65);
    Student s2 = {4, "Man", 65.87};
    replaceMarks2(&s, &s2);
    printStudent(&s2);
    return 1;
}