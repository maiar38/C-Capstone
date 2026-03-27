# 🎓 Student Course Management System (C++)

## 📌 Overview

This project is a **console-based application** developed using C++ to manage students and their enrolled courses.
It demonstrates core programming concepts including **Object-Oriented Programming (OOP)**, **Standard Template Library (STL)**, and **file handling**.

---

## 🚀 Features

### 🔹 Core Features

* Add a new student (ID, Name, GPA)
* Remove a student by ID
* Search for a student by ID
* Display all students
* Enroll a student in a course
* Show student courses
* Sort students by GPA
* Save student data to file (students.txt)
* Load student data from file

---

### 🔹 Bonus Features Implemented

* ✅ Prevent duplicate courses using `set`
* ✅ Additional search functionality
* ✅ Save data to file (`students.txt`)
* ✅ Load data from file

---

## 🧱 Technologies Used

* **C++**
* **OOP Concepts**

  * Classes & Objects
  * Inheritance
  * Encapsulation
* **STL (Standard Template Library)**

  * `vector` (for storing students)
  * `set` (for storing unique courses)
* **Algorithms**

  * `sort`
  * `remove_if`
* **File Handling**

  * `fstream`
  * `stringstream`

---

## 📂 Project Structure

```
/project
│
├── Person.h
├── Student.h
├── StudentManager.h
│
├── Person.cpp
├── Student.cpp
├── StudentManager.cpp
│
└── main.cpp
```

---

## 🧠 System Design

### 🔹 Class Relationships

* `Student` inherits from `Person`
* `StudentManager` manages a collection of students

---



## 💾 File Storage

* Data is saved in:

```
students.txt
```

### Example Format:

```
1001 Ali 3.5 Math Physics
1002 Sara 3.8 AI ML
```

---

## ⚙️ How to Run

1. Compile the project:

```
g++ main.cpp Student.cpp StudentManager.cpp Person.cpp -o app
```

2. Run:

```
./app
```

---

## 🖥️ Sample Menu

```
1. Add Student
2. Remove Student
3. Search Student by ID
4. Display All Students
5. Enroll Student in Course
6. Show Student Courses
7. Sort Students by GPA
8. Save to File
9. Load from File
10. Search Student by Name
11. Exit
```

---

## ⚠️ Constraints Handled

* Student ID must be unique
* GPA must be between 0.0 and 4.0
* Duplicate courses are prevented
* Invalid input is handled

---

## 💡 Future Improvements

* Save data in JSON format
* Use a database (SQLite)
* Add GUI interface
* Advanced search (by name, GPA range)

---

## 👨‍💻 Author

Maiar Emam
