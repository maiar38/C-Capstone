#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <set>
#include <iostream>
using namespace std;

class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses;

public:
    Student(int id, string name, double gpa);

    int getId() const;
    double getGpa() const;

    void enrollCourse(string course);
    void showCourses() const;
    void saveToFile(ofstream& out) const;
};

#endif
