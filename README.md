# Student Grade Manager (C++)

A simple console application to manage students and their grades, written in C++.

## Features

- Add students
- Record grades for each student (0-100)
- Show each student's average
- Save everything to a file and load it again next time

## How to build and run

You need a C++ compiler such as g++ (comes with MinGW on Windows, or build-essential on Linux).

```bash
g++ -std=c++17 -o grade_manager main.cpp
./grade_manager        # on Linux/macOS
grade_manager.exe      # on Windows
```

## Example

```
=== Student Grade Manager ===
1. Add student
2. Add grade to student
3. List students
4. Save and exit
Choice: 1
Student name (one word): Ahmed
Added Ahmed.
```

## Concepts used in this project

- Structs and vectors
- Loops and input validation
- Reading and writing files with fstream

## Notes

A learning example prepared for me by my AI assistant to study and extend as
I learn C++ at the Faculty of Computers and Artificial Intelligence, Minya
University.
