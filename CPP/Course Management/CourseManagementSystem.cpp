#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Student {
public:
    int id;
    string name;

    Student(int id, string name) : id(id), name(name) {}
};

class Course {
public:
    int id;
    string name;
    vector<Student> students;

    Course(int id, string name) : id(id), name(name) {}

    void enrollStudent(int studentId, const string& studentName) {
        students.push_back(Student(studentId, studentName));
    }

    void unenrollStudent(int studentId) {
        auto it = remove_if(students.begin(), students.end(), [studentId](const Student& student) {
            return student.id == studentId;
        });
        if (it != students.end()) {
            students.erase(it, students.end());
        }
    }

    void displayStudents() const {
        if (students.empty()) {
            cout << "No students enrolled in this course.\n";
        } else {
            for (const auto& student : students) {
                cout << "Student ID: " << student.id << ", Name: " << student.name << endl;
            }
        }
    }

    bool hasStudent(int studentId) const {
        return any_of(students.begin(), students.end(), [studentId](const Student& student) {
            return student.id == studentId;
        });
    }

    const Student* getStudent(int studentId) const {
        auto it = find_if(students.begin(), students.end(), [studentId](const Student& student) {
            return student.id == studentId;
        });
        return it != students.end() ? &(*it) : nullptr;
    }
};

class CourseManagementSystem {
private:
    vector<Course> courses;

public:
    void addCourses() {
        int numCourses;
        cout << "Enter number of courses to add (up to 10): ";
        cin >> numCourses;

        if (numCourses > 10) {
            cout << "You can add up to 10 courses only.\n";
            return;
        }

        for (int i = 0; i < numCourses; ++i) {
            int courseId;
            string courseName;
            cout << "Enter course ID: ";
            cin >> courseId;
            cout << "Enter course name: ";
            cin.ignore();
            getline(cin, courseName);

            // Check if the course ID is already in use
            for (const auto& course : courses) {
                if (course.id == courseId) {
                    cout << "Course ID already exists. Please choose a different ID.\n";
                    --i;  // To repeat the loop for the same course
                    continue;
                }
            }

            courses.push_back(Course(courseId, courseName));
            cout << "Course added successfully.\n";
        }
    }

    void enrollStudent() {
        int courseId;
        int studentId;
        string studentName;
        cout << "Enter course ID to enroll student: ";
        cin >> courseId;
        cout << "Enter student ID: ";
        cin >> studentId;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, studentName);

        for (auto& course : courses) {
            if (course.id == courseId) {
                course.enrollStudent(studentId, studentName);
                cout << "Student enrolled successfully.\n";
                return;
            }
        }
        cout << "Course not found.\n";
    }

    void unenrollStudent() {
        int courseId;
        int studentId;
        cout << "Enter course ID to unenroll student: ";
        cin >> courseId;
        cout << "Enter student ID: ";
        cin >> studentId;

        for (auto& course : courses) {
            if (course.id == courseId) {
                course.unenrollStudent(studentId);
                cout << "Student unenrolled successfully.\n";
                return;
            }
        }
        cout << "Course not found.\n";
    }

    void viewAllCourses() const {
        if (courses.empty()) {
            cout << "No courses available.\n";
            return;
        }

        for (const auto& course : courses) {
            cout << "Course ID: " << course.id << ", Course Name: " << course.name << endl;
        }
    }

    void viewStudentsInCourse() const {
        int courseId;
        cout << "Enter course ID to view students: ";
        cin >> courseId;

        for (const auto& course : courses) {
            if (course.id == courseId) {
                cout << "Students enrolled in " << course.name << ":\n";
                course.displayStudents();
                return;
            }
        }
        cout << "Course not found.\n";
    }

    void searchStudentInCourses() const {
        int studentId;
        cout << "Enter student ID to search: ";
        cin >> studentId;

        bool found = false;
        for (const auto& course : courses) {
            if (course.hasStudent(studentId)) {
                const Student* student = course.getStudent(studentId);
                cout << "Student ID: " << student->id << ", Name: " << student->name
                     << ", Course: " << course.name << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Student not found in any course.\n";
        }
    }
};

int main() {
    CourseManagementSystem cms;
    int choice;

    do {
        cout << "\nCourse Management System\n";
        cout << "1. Add Courses\n";
        cout << "2. Enroll Student\n";
        cout << "3. Unenroll Student\n";
        cout << "4. View All Courses\n";
        cout << "5. View Students in a Course\n";
        cout << "6. Search Student in Courses\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cms.addCourses();
                break;
            case 2:
                cms.enrollStudent();
                break;
            case 3:
                cms.unenrollStudent();
                break;
            case 4:
                cms.viewAllCourses();
                break;
            case 5:
                cms.viewStudentsInCourse();
                break;
            case 6:
                cms.searchStudentInCourses();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
