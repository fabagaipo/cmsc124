class Student:
  def __init__(self, studentName, age, gpa, gradeLevel):
    self.studentName = studentName
    self.age = age;
    self.gpa = gpa;
    self.gradeLevel = gradeLevel

  def __str__(self):
    return "Name: " + self.studentName + "\n" + "Age: " + str(self.age) + "\n" + "GPA: " + str(self.gpa) + "\n" + "Grade Level: " + str(self.gradeLevel) + "\n"
    print()

num = int(input("Input number of students to be registered: "))
print()

studentList = []

for i in range(num):
  tempName = input("Name: ")
  tempAge = int(input("Age: "))
  tempGPA = float(input("GPA: "))
  tempGradeLevel = input("Grade Level: ")

  s = Student(tempName, tempAge, tempGPA, tempGradeLevel)
  studentList.append(s)

print("\n STUDENT REGISTRATION SYSTEM \n")
for student in studentList:
  print(student)
