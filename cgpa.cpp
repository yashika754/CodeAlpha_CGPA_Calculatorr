#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Subject {
public:
    string subjectName;
    int credits;
    float gradePoint;

    Subject(string name, int cr, float gp) {
        subjectName = name;
        credits = cr;
        gradePoint = gp;
    }


    void displaySubject() const {
        cout << "Subject: " << subjectName << ", Credits: " << credits
             << ", Grade Point: " << gradePoint << endl;
    }
};

class Student {
public:
    string name;
    vector<Subject> subjects;

    Student(string studentName) {
        name = studentName;
    }

    void addSubject(string subjectName, int credits, float gradepoint) {
        Subject newSubject(subjectName, credits, gradepoint);
        subjects.push_back(newSubject);
    }


    void calculateAndDisplayCGPA() {
        int totalCredits = 0;
        float weightedGradePoints = 0;


        
        for (const Subject &subject : subjects) {
          
            totalCredits += subject.credits;
            weightedGradePoints += subject.credits * subject.gradePoint; 
        }

       
        float semesterGPA = (totalCredits > 0) ? (weightedGradePoints / totalCredits) : 0;
        
        
        cout << "\nTotal Credits: " << totalCredits << endl;
        cout << "Total Grade Points: " << weightedGradePoints << endl;
        cout << "Semester GPA: " << semesterGPA << endl;

      
        cout << "CGPA: " << semesterGPA << endl;
    }
};

float gradeToPoint(string grade) {
    if (grade == "A") return 4.0;
    else if (grade == "B") return 3.0;
    else if (grade == "C") return 2.0;
    else if (grade == "D") return 1.0;
    else if (grade == "F") return 0.0;
    else return -1.0;  
}


int getPositiveInt() {
    int value;
    while (true) {
        cin >> value;
        if (value > 0) {
            return value;
        } else {
            cout << "Please enter a positive number: ";
        }
    }
}

int main() {
    string studentName;
    int numSubjects;


    cout << "Enter student name: ";
    getline(cin, studentName);

    cout << "Enter the number of subjects: ";
    numSubjects = getPositiveInt();

    Student student(studentName);

    
    for (int i = 0; i < numSubjects; i++) {
        string subjectName, grade;
        int credit;
        float gradePoints;

        cout << "\nEnter the subject name: ";
        cin.ignore(); 
        getline(cin, subjectName);

        cout << "Enter the credits: ";
        credit = getPositiveInt();

        cout << "Enter the grade (A, B, C, D, F): ";
        cin >> grade;

     
        gradePoints = gradeToPoint(grade);

        if (gradePoints == -1.0) {
            cout << "Invalid grade entered! Exiting program." << endl;
            return 1;
        }

      
        student.addSubject(subjectName, credit, gradePoints);
    }

    
    student.calculateAndDisplayCGPA();

    return 0;
}
