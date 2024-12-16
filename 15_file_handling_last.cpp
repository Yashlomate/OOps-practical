#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Structure to store student information
struct Student {
    int rollNumber;
    string name;
    char division;
    string address;
};

// Function to add a student record
void addStudent() {
    ofstream outFile("students.dat", ios::app | ios::binary);
    if (!outFile) {
        cerr << "File could not be opened!" << endl;
        return;
    }

    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.rollNumber;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Division: ";
    cin >> s.division;
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, s.address);

    outFile.write(reinterpret_cast<char*>(&s), sizeof(Student));
    outFile.close();
    cout << "Student added successfully!" << endl;
}

// Function to display a student record
void displayStudent(int rollNumber) {
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cerr << "File could not be opened!" << endl;
        return;
    }

    Student s;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.rollNumber == rollNumber) {
            found = true;
            cout << "Roll Number: " << s.rollNumber << endl;
            cout << "Name: " << s.name << endl;
            cout << "Division: " << s.division << endl;
            cout << "Address: " << s.address << endl;
            break;
        }
    }
    inFile.close();

    if (!found) {
        cout << "Student record not found!" << endl;
    }
}

int main() {
    int choice, rollNumber;
    do {
        cout << "1. Add Student" << endl;
        cout << "2. Display Student" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            cout << "Enter Roll Number to display: ";
            cin >> rollNumber;
            displayStudent(rollNumber);
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}

