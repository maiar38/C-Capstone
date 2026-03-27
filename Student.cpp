#include <fstream>
#include "Student.h"

Student::Student(int id, string name, double gpa)
    : Person(name) {
    this->id = id;
    this->gpa = gpa;
}

int Student::getId() const {
    return id;
}

double Student::getGpa() const {
    return gpa;
}

void Student::enrollCourse(string course) {
    courses.insert(course);
}

void Student::showCourses() const {
    if (courses.empty()) {
        cout << "No courses.\n";
        return;
    }

    for (auto c : courses)
        cout << "- " << c << endl;
}

void Student::saveToFile(ofstream& out) const {
    out << id << "," << name << "," << gpa;

    for (const auto& c : courses) {
        out << " " << c;
    }

    out << endl;
}
