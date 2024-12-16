#include <iostream>
#include <string>
using namespace std;

// Structure to store student details
struct Student {
    int rollNo;       // Roll Number
    string name;      // Name of the student
    float sgpa;       // SGPA
};

// Bubble Sort to sort by Roll Number
void bubbleSortByRollNo(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                // Swap if current roll number is greater
                swap(students[j], students[j + 1]);
            }
        }
    }
}

// Insertion Sort to sort by Name
void insertionSortByName(Student students[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = students[i]; // Take the current student as key
        int j = i - 1;
        // Move students with names greater than key.name forward
        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key; // Insert key at the correct position
    }
}

// Function to display the student database
void displayStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Roll No: " << students[i].rollNo 
             << ", Name: " << students[i].name 
             << ", SGPA: " << students[i].sgpa << endl;
    }
}

int main() {
    // Create an array of students (SEIT class with 10 records)
    Student students[10] = {
        {3, "Alice", 8.7}, {1, "Bob", 9.1}, {10, "Charlie", 7.8}, {5, "David", 8.3},
        {2, "Eve", 9.0}, {8, "Frank", 7.5}, {6, "Grace", 8.0}, {4, "Hannah", 8.2},
        {9, "Ivy", 7.9}, {7, "Jack", 8.6}
    };

    int n = 10; // Number of students

    // a. Sort students by Roll Number
    cout << "Sorting by Roll Number (Ascending Order):" << endl;
    bubbleSortByRollNo(students, n);
    displayStudents(students, n);

    // b. Sort students by Name
    cout << "\nSorting by Name (Alphabetical Order):" << endl;
    insertionSortByName(students, n);
    displayStudents(students, n);

    return 0;
}
