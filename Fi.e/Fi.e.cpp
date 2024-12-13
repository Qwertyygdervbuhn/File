#include <iostream>
#include <fstream>
using namespace std;

class Student {
    string name;
    string surname;
    int age;

public:
    Student() {
        name = "";
        surname = "";
        age = 0;
    }

    Student(const char* n, const char* sur, int a) {
        name = n;
        surname = sur;
        age = a;
    }

    void Print() {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Age: " << age << endl;
    }

    void SaveFile() {
        ofstream file;
        file.open("student.txt");
        if (file.is_open()) {
            file << name << endl;
            file << surname << endl;
            file << age << endl;
            file.close();
            cout << "Saved!" << endl;
        }
        else {
            cout << "Failed to open file!" << endl;
        }
    }

    void ReadFile() {
        ifstream file;
        file.open("student.txt");
        if (file.is_open()) {
            file >> age;
            file.close();
            cout << "Read from file!" << endl;
        }
        else {
            cout << "Failed to open file!" << endl;
        }
    }
};

int main() {
    Student s("Alice", "Smith", 18);
    s.Print();

    s.SaveFile();

    Student newStudent;
    newStudent.ReadFile();
    newStudent.Print();
}
