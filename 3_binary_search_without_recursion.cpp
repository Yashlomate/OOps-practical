#include <iostream>
#include <algorithm> // For sort()
#include <string>   // For string
using namespace std;

// Structure to hold student details
struct Student {
    int rollNo;         // Roll Number of the student
    string name;        // Name of the student
    float sgpa;         // SGPA of the student
};

// Function to display student details
void displayStudent(const Student& student) {
    cout << "Roll No: " << student.rollNo << ", Name: " << student.name << ", SGPA: " << student.sgpa << endl;
}

// Binary Search Function to find students by name
void binarySearchByName(Student students[], int n, string key) {
    int left = 0, right = n - 1; // Initialize search range
    bool found = false;         // To check if any student is found

    while (left <= right) { // Loop until search range is valid
        int mid = (left + right) / 2; // Find the middle index

        if (students[mid].name == key) { // Check if the middle student matches the key
            found = true;

            // Display all matching students
            cout << "\nStudents with name '" << key << "':\n";

            // Check students with the same name on the left
            int i = mid;
            while (i >= 0 && students[i].name == key) {
                displayStudent(students[i]);
                i--;
            }

            // Check students with the same name on the right
            i = mid + 1;
            while (i < n && students[i].name == key) {
                displayStudent(students[i]);
                i++;
            }
            break;
        } else if (students[mid].name < key) {
            left = mid + 1; // Search the right half
        } else {
            right = mid - 1; // Search the left half
        }
    }

    if (!found) {
        cout << "\nNo student found with the name '" << key << "'.\n";
    }
}

int main() {
    // Array of 15 student records
    Student students[15] = {
        {1, "Alice", 8.5}, {2, "Bob", 9.0}, {3, "Charlie", 7.8}, {4, "Alice", 8.2},
        {5, "Eve", 9.1}, {6, "David", 7.5}, {7, "Alice", 8.3}, {8, "Frank", 6.9},
        {9, "Grace", 9.2}, {10, "Heidi", 7.6}, {11, "Ivan", 8.0}, {12, "Judy", 8.4},
        {13, "Mallory", 7.9}, {14, "Oscar", 8.6}, {15, "Peggy", 9.3}
    };

    // Sort the array of students by name (required for binary search)
    sort(students, students + 15, [](const Student& a, const Student& b) {
        return a.name < b.name;
    });

    // Input the name to search
    string searchName;
    cout << "Enter the name of the student to search: ";
    cin >> searchName;

    // Call the binary search function
    binarySearchByName(students, 15, searchName);

    return 0;
}
