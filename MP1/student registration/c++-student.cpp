#include <iostream>
#include <vector>

using namespace std;

class student {
  public:
  student(string studentName, int age, float gpa, string gradeLevel);
    string studentName;
    int age;
    float gpa;
    string gradeLevel;
};

student::student(string studentName, int age, float gpa, string gradeLevel)
  : studentName(studentName), age(age), gpa(gpa), gradeLevel(gradeLevel) {}

void display(student s) {
  cout << "Name: " << s.studentName << endl;
  cout << "Age: " << s.age << endl;
  cout << "GPA: " << s.gpa << endl;
  cout << "Grade Level: " << s.gradeLevel << endl;
}

int main() {
  int num;
  cout << "Input number of students to be registered: ";
  cin >> num;
  cout << endl;
  vector<student> students;

  for(int i = 0; i < num; i++) {
    string tempName;
    int tempAge;
    float tempGPA;
    string tempGradeLevel;

    cout << "Name: ";
    cin >> tempName;
    cout << "Age: ";
    cin >> tempAge;
    cout << "GPA: ";
    cin >> tempGPA;
    cout << "Grade Level: ";
    cin >> tempGradeLevel;
    cout << endl;

    student s(tempName, tempAge, tempGPA, tempGradeLevel);
    students.push_back(s);
  }

  cout << "\n STUDENT REGISTRATION SYSTEM \n" << endl;
  for(int i = 0; i < num; i++) {
    display((students[i]));
  }
  return 0;
}
