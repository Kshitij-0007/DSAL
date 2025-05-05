#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student { int rollNumber; string name, division, address; };

void addStudent() {
    Student student;
    fstream file("students.dat", ios::out | ios::app | ios::binary);
    cout << "Enter Roll No: "; cin >> student.rollNumber; cin.ignore();
    cout << "Enter Name: "; getline(cin, student.name);
    cout << "Enter Division: "; getline(cin, student.division);
    cout << "Enter Address: "; getline(cin, student.address);
    file.write(reinterpret_cast<char*>(&student), sizeof(student));
}

void deleteStudent(int rollNumber) {
    Student student;
    fstream file("students.dat", ios::in | ios::binary);
    fstream tempFile("temp.dat", ios::out | ios::binary);
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        if (student.rollNumber != rollNumber) tempFile.write(reinterpret_cast<char*>(&student), sizeof(student));
        else found = true;
    }
    file.close(); tempFile.close();
    remove("students.dat"); rename("temp.dat", "students.dat");
    cout << (found ? "Deleted successfully." : "Student not found.") << endl;
}

void displayStudent(int rollNumber) {
    Student student;
    fstream file("students.dat", ios::in | ios::binary);
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        if (student.rollNumber == rollNumber) {
            cout << "Roll No: " << student.rollNumber << "\nName: " << student.name
                 << "\nDivision: " << student.division << "\nAddress: " << student.address << endl;
            found = true; break;
        }
    }
    if (!found) cout << "Record not found." << endl;
}

int main() {
    int choice, rollNumber;
    while (true) {
        cout << "1. Add 2. Delete 3. Display 4. Exit\nChoice: "; cin >> choice;
        if (choice == 1) addStudent();
        else if (choice == 2) { cout << "Enter Roll No: "; cin >> rollNumber; deleteStudent(rollNumber); }
        else if (choice == 3) { cout << "Enter Roll No: "; cin >> rollNumber; displayStudent(rollNumber); }
        else return 0;
    }
}
