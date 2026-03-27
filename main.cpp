#include <iostream>
#include "StudentManager.h"

using namespace std;

int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n1.Add\n2.Remove\n3.Search\n4.Display\n5.Enroll\n6.Show Courses\n7.Sort\n8.Save to File\n9.Load from File\n10.Search By Name\n11.Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice!\n";
            continue;
        }

        int id;
        string name, course;
        double gpa;

        switch (choice) {

        case 1:
            cout << "Enter ID: ";
            cin >> id;

            cin.ignore(); 

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter GPA: ";
            cin >> gpa;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid GPA!\n";
                break;
            }

            manager.addStudent(id, name, gpa);
            manager.saveToFile("students.txt");
            break;

        case 2:
            cout << "Enter ID: ";
            cin >> id;
            manager.removeStudent(id);
            break;

        case 3: {
            cout << "Enter ID: ";
            cin >> id;

            Student* s = manager.findStudent(id);

            if (s) {
                cout << "ID: " << s->getId()
                    << ", Name: " << s->getName()
                    << ", GPA: " << s->getGpa() << endl;
            }
            else {
                cout << "Student Not Found\n";
            }

            break;
        }
        case 4:
            manager.displayAll();
            break;

        case 5:
            cout << "Enter ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Course: ";
            getline(cin, course);
            if (course.empty()) {
                cout << "Invalid course!\n";
                break;
            }
            manager.enrollCourse(id, course);
            break;

        case 6:
            cout << "Enter ID: ";
            cin >> id;
            manager.showCourses(id);
            break;

        case 7:
            manager.sortByGPA();
            cout << "Sorted successfully.\n";
            break;

        case 8:
            manager.saveToFile("students.txt");
            break;

        case 9:
            manager.loadFromFile("students.txt");
            break;

        case 10:
            cin.ignore();
            cout << "Enter name: ";
            getline(cin, name);
            manager.searchByName(name);
            break;

        case 11:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option!\n";
        }

    } while (choice != 11);

    return 0;
}
