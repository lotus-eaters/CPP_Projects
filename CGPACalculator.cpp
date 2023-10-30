#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a course with grade and credit hours
struct Course {
    string courseName;
    char grade;
    int creditHours;
};

// Function to calculate grade points based on the grade obtained
float calculateGradePoints(char grade) {
    switch (grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return -1.0; // Invalid grade
    }
}

// Function to calculate CGPA
float calculateCGPA(const vector<Course>& courses) {
    float totalGradePoints = 0.0;
    int totalCreditHours = 0;
    
    for (const Course& course : courses) {
        float gradePoints = calculateGradePoints(course.grade);
        if (gradePoints == -1.0) {
            cout << "Invalid grade in course: " << course.courseName << endl;
            return -1.0;
        }
        
        totalGradePoints += gradePoints * course.creditHours;
        totalCreditHours += course.creditHours;
    }
    
    return totalGradePoints / totalCreditHours;
}

// Function to compare courses by credit hours in descending order
bool compareByCreditHours(const Course& a, const Course& b) {
    return a.creditHours > b.creditHours;
}
// Function to display the course list and save it to a file
void displayCourseList(const vector<Course>& courses, ofstream& outputFile) {
    cout << "Course List:" << endl;
    outputFile << "Course List:" << endl;
    
    for (const Course& course : courses) {
        cout << "Course Name: " << course.courseName << endl;
        cout << "Grade: " << course.grade << endl;
        cout << "Credit Hours: " << course.creditHours << endl;
        cout << "---------------------------" << endl;
        
        // Save to the file as well
        outputFile << "Course Name: " << course.courseName << endl;
        outputFile << "Grade: " << course.grade << endl;
        outputFile << "Credit Hours: " << course.creditHours << endl;
        outputFile << "---------------------------" << endl;
    }
}

int main() {
    vector<Course> courses;
    int numCourses;
    
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    
    for (int i = 0; i < numCourses; i++) {
        Course course;
        cout << "Enter course name: ";
        cin.ignore();
        getline(cin, course.courseName);
        cout << "Enter grade (A, B, C, D, F): ";
        cin >> course.grade;
        cout << "Enter credit hours: ";
        cin >> course.creditHours;
        courses.push_back(course);
    }
    

    // Sort the courses by credit hours in descending order before calculating CGPA
    sort(courses.begin(), courses.end(), compareByCreditHours);

        
    float cgpa = calculateCGPA(courses);
    
    if (cgpa != -1.0) {
        cout << "Your CGPA is: " << cgpa << endl;
        
        // Save the CGPA and course list in a file
        ofstream outputFile("cgpa.txt");
        outputFile << "CGPA: " << cgpa << endl;
        displayCourseList(courses, outputFile);
        outputFile.close();
    }
    
    return 0;
}

