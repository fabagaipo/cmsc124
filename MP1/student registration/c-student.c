#include <stdio.h>

typedef struct {
  char studentName[50];
  int age;
  float gpa;
  char gradeLevel[10];
} student;

void display(student s) {
  printf("Name: %s\n", s.studentName);
  printf("Age: %d\n", s.age);
  printf("GPA: %f\n", s.gpa);
  printf("Grade Level: %s\n", s.gradeLevel);
}

int main() {
  int num;
  printf("Input number of students to be registered: ");
  scanf("%d", &num);

  student students[num];
  for(int i = 0; i < num; i++) {
    student s;
    printf("Name: ");
    scanf("%s", &s.studentName);
    printf("Age: ");
    scanf("%d", &s.age);
    printf("GPA: ");
    scanf("%f", &s.gpa);
    printf("Grade Level: ");
    scanf("%s", &s.gradeLevel);

    students[i] = s;
  }

  printf("\n STUDENT REGISTRATION SYSTEM \n");

  for(int i = 0; i < num; i++) {
    display(students[i]);
  }
  return 0;
}
