import java.util.Scanner;

class Student {
	String studentName;
	int age;
  float gpa;
  String gradeLevel;
	public Student() {
		this(" ", 0, 0, " ");
	}
	public Student(String tempStudentName, int tempAge, float tempGPA, String tempGradeLevel) {
		studentName = tempStudentName;
		age = tempAge;
		gpa = tempGPA;
    gradeLevel = tempGradeLevel;
	}
  void Display(){ 
    System.out.println("Student Name: "+studentName); 
    System.out.println("Age: "+age); 
    System.out.println("GPA: "+gpa); 
    System.out.println("Grade Level: "+gradeLevel); 
  }  
}

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Input number of students:");
		int n = Integer.parseInt(in.nextLine().trim());
		System.out.println("Input Student Name, Age, GPA, Grade Level:");
		Student stu = new Student();
		for (int i = 0; i < n; i ++) {
			stu.studentName = in.next();
			stu.age = in.nextInt();
			stu.gpa = in.nextFloat();
      stu.gradeLevel = in.next();
		}
		in.close();
    stu.Display();
	}
}
