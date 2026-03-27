#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student.h"
#include <vector>

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent(int id, string name, double gpa);
    void removeStudent(int id);
    Student* findStudent(int id);
    void displayAll();
    void enrollCourse(int id, string course);
    void showCourses(int id);
    void sortByGPA();

    void saveToFile(string filename);
    void loadFromFile(string filename);
    void searchByName(string name);
};

#endif
