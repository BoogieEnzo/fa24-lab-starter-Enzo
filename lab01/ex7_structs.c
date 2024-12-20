#include <stdio.h>
#include <stdlib.h>

// Structs allow you to hold data items of different types in a single variable
// Struct definitions can be used to declare a struct variable within your program
// Struct definitions are typically done outside of a function
// struct Student {
//     int id;
//     char* name;
// };

// 定义二
typedef struct {
    int id;
    char* name;
} Student;

int main() {
  // TODO: declare a variable student of type struct Student
  // Note: this struct is stored on the stack
  Student student;
  Student* ptr = & student;

  // TODO: print out the size of a struct Student
  // While this may seem out of place now, it will be useful in the future!
  // Hint: there's an operator that can calculate this for you!
  printf("Size of a struct Student: %lu bytes\n", sizeof(student));

  // TODO: set student's id field to 5
  // Hint: the dot notation accesses a struct's fields
  student.id = 5;
  ptr->name = "Enzo";

  // TODO: print out student's id field
  printf("Student's ID: %d\n", student.id);
  printf("Student's ID using pointer: %d\n", ptr->id);
  printf("Student's Name using pointer: %s\n", ptr->name);

  return 0;
}
