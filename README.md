# STUD_MANAGEMENT_SYSTEM
A whole versatile student management system compiled with C language.
# Student Record Management System in C

## Overview
This is a console-based *Student Record Management System* written in C, designed to perform basic CRUD (Create, Read, Update, Delete) operations on student records stored in a file. It features a user-friendly menu and persistent file storage.

This project was developed as a part of my programming practice in *B.Tech(Electronics Engineering) - 2nd year* to explore the applications of file handling and structured data in C.

---

## Features
- Add a new student record
- View all stored student records
- Search for a student by ID
- Edit student details
- Delete a student record
- Data is stored in a text file (Studentrec.txt) for persistence

---

## Technologies Used
- *Language*: C
- *Concepts*: File I/O, Structures, Loops, Conditional Logic, Functions
- *Compiler*: GCC / Code::Blocks / Turbo C (or any standard C compiler)
- *Platform*: Windows/Linux terminal

---

## Data Structure
Each student record includes:
- int id – Unique student ID
- char name[20] – Student name
- int age – Age of the student
- float score – Score/marks of the student

Data is stored in plain text using:
```text
ID NAME AGE SCORE
