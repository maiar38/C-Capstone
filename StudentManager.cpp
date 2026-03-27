#include "StudentManager.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

void StudentManager::addStudent(int id, string name, double gpa) {
    if (gpa < 0.0 || gpa > 4.0) {
        cout << "Invalid GPA!\n";
        return;
    }

    for (auto& s : students) {
        if (s.getId() == id) {
            cout << "ID exists!\n";
            return;
        }
    }

    students.push_back(Student(id, name, gpa));
    cout << "Student added.\n";
}

void StudentManager::removeStudent(int id) {
    auto it = remove_if(students.begin(), students.end(),
        [id](Student& s) { return s.getId() == id; });

    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Removed.\n";
    }
    else {
        cout << "Not found.\n";
    }
}

Student* StudentManager::findStudent(int id) {
    for (auto& s : students) {
        if (s.getId() == id)
            return &s;
    }
    return nullptr;
}

void StudentManager::displayAll() {

    if (students.empty()) {
        cout << "No students.\n";
        return;
    }
    for (auto& s : students) {
        cout << "ID: " << s.getId()
            << ", Name: " << s.getName()
            << ", GPA: " << s.getGpa() << endl;
    }
}

void StudentManager::enrollCourse(int id, string course) {
    Student* s = findStudent(id);
    if (s) {
        s->enrollCourse(course);
    }
    else {
        cout << "Student not found.\n";
    }
}

void StudentManager::showCourses(int id) {
    Student* s = findStudent(id);
    if (s) {
        s->showCourses();
    }
    else {
        cout << "Student not found.\n";
    }
}

void StudentManager::sortByGPA() {
    sort(students.begin(), students.end(),
        [](Student& a, Student& b) {
            return a.getGpa() > b.getGpa();
        });
}


void StudentManager::saveToFile(string filename) {
    ofstream out(filename);

    if (!out) {
        cout << "Error opening file!\n";
        return;
    }

    for (const auto& s : students) {
        s.saveToFile(out);
    }

    cout << "Data saved successfully.\n";
}

void StudentManager::loadFromFile(string filename) {
    ifstream in(filename);

    if (!in) {
        cout << "File not found!\n";
        return;
    }

    students.clear(); 

    string line;
    while (getline(in, line)) {
        stringstream ss(line);

        int id;
        string name;
        double gpa;

        ss >> id >> name >> gpa;

        Student s(id, name, gpa);

        string course;
        while (ss >> course) {
            s.enrollCourse(course);
        }

        students.push_back(s);
    }

    cout << "Data loaded successfully.\n";
    displayAll();
}

void StudentManager::searchByName(string name) {
    bool found = false;

    for (auto& s : students) {
        if (s.getName() == name) {
            cout << "ID: " << s.getId()
                << ", Name: " << s.getName()
                << ", GPA: " << s.getGpa() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No student found with this name.\n";
    }
}