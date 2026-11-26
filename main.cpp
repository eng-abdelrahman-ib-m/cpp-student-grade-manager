// Student Grade Manager
// A simple console app to manage students and their grades.
// Features: add students, record grades, compute averages, save/load from a file.

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

struct Student {
    std::string name;
    std::vector<double> grades;

    double average() const {
        if (grades.empty()) return 0.0;
        double sum = 0.0;
        for (double g : grades) sum += g;
        return sum / grades.size();
    }
};

const char* FILE_NAME = "students.txt";

void saveToFile(const std::vector<Student>& students) {
    std::ofstream out(FILE_NAME);
    for (const Student& s : students) {
        out << s.name;
        for (double g : s.grades) out << ' ' << g;
        out << '\n';
    }
}

std::vector<Student> loadFromFile() {
    std::vector<Student> students;
    std::ifstream in(FILE_NAME);
    std::string name;
    while (in >> name) {
        Student s;
        s.name = name;
        double g;
        while (in.peek() != '\n' && in >> g) s.grades.push_back(g);
        students.push_back(s);
    }
    return students;
}

void listStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students yet.\n";
        return;
    }
    std::cout << "\n#  Name            Grades              Average\n";
    std::cout << "--  --------------  ------------------  -------\n";
    for (size_t i = 0; i < students.size(); i++) {
        const Student& s = students[i];
        std::cout << i + 1 << ". " << s.name << "\t";
        for (double g : s.grades) std::cout << g << ' ';
        std::cout << "\tavg: " << s.average() << '\n';
    }
}

int main() {
    std::vector<Student> students = loadFromFile();

    while (true) {
        std::cout << "\n=== Student Grade Manager ===\n"
                  << "1. Add student\n"
                  << "2. Add grade to student\n"
                  << "3. List students\n"
                  << "4. Save and exit\n"
                  << "Choice: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            std::cout << "Student name (one word): ";
            std::string name;
            std::cin >> name;
            students.push_back({name, {}});
            std::cout << "Added " << name << ".\n";
        } else if (choice == 2) {
            listStudents(students);
            if (students.empty()) continue;
            std::cout << "Student number: ";
            size_t idx;
            std::cin >> idx;
            if (idx < 1 || idx > students.size()) {
                std::cout << "Invalid number.\n";
                continue;
            }
            std::cout << "Grade (0-100): ";
            double g;
            std::cin >> g;
            if (g < 0 || g > 100) {
                std::cout << "Grade must be between 0 and 100.\n";
                continue;
            }
            students[idx - 1].grades.push_back(g);
            std::cout << "Grade added.\n";
        } else if (choice == 3) {
            listStudents(students);
        } else if (choice == 4) {
            saveToFile(students);
            std::cout << "Saved to " << FILE_NAME << ". Bye!\n";
            break;
        }
    }
    return 0;
}
