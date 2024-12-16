#include <iostream>
#include <string>
using namespace std;

// Define a structure to represent a Student with roll number, name, and SGPA
struct Student {
    int rollNo;       // Roll Number
    string name;      // Name of the student
    float sgpa;       // SGPA (Semester Grade Point Average)
};

// Partition function for Quick Sort: organizes elements around a pivot
int partition(Student s[], int low, int high) {
    float pivot = s[high].sgpa; // Select the last element's SGPA as the pivot
    int i = low - 1;            // Index for smaller elements
    
    for (int j = low; j < high; j++) {
        // If current element's SGPA is greater than pivot (for descending order)
        if (s[j].sgpa > pivot) 
            swap(s[++i], s[j]); // Move it to the left side
    }
    swap(s[i + 1], s[high]);    // Place pivot in its correct position
    return i + 1;               // Return the partition index
}

// Quick Sort function to sort the array by SGPA in descending order
void quickSort(Student s[], int low, int high) {
    if (low < high) {
        int pi = partition(s, low, high); // Partition the array
        
        // Recursively sort the sub-arrays on either side of the pivot
        quickSort(s, low, pi - 1); // Sort elements to the left of pivot
        quickSort(s, pi + 1, high); // Sort elements to the right of pivot
    }
}

// Function to display details of students in the array
void display(Student s[], int n) {
    for (int i = 0; i < n; i++) {
        // Print Roll Number, Name, and SGPA of each student
        cout << "Roll No: " << s[i].rollNo 
             << ", Name: " << s[i].name 
             << ", SGPA: " << s[i].sgpa << endl;
    }
}

// Function to search for students with a specific SGPA
void searchSGPA(Student s[], int n, float sgpa) {
    bool found = false; // To track if any students match the given SGPA
    for (int i = 0; i < n; i++) {
        // If a student's SGPA matches the search value
        if (s[i].sgpa == sgpa) {
            found = true; // Mark as found
            // Print their details
            cout << "Roll No: " << s[i].rollNo 
                 << ", Name: " << s[i].name << endl;
        }
    }
    if (!found) {
        // If no student matches the SGPA
        cout << "No students found with SGPA " << sgpa << endl;
    }
}

int main() {
    // Array of 15 students with roll number, name, and SGPA
    Student s[15] = { 
        {1, "Alice", 9.2}, {2, "Bob", 8.8}, {3, "Charlie", 8.7}, {4, "David", 9.0},
        {5, "Eve", 9.5}, {6, "Frank", 7.8}, {7, "Grace", 8.0}, {8, "Hannah", 9.3},
        {9, "Ivy", 9.1}, {10, "Jack", 8.5}, {11, "Kevin", 9.5}, {12, "Luna", 8.9},
        {13, "Mike", 8.6}, {14, "Nina", 8.7}, {15, "Oscar", 8.4} 
    };
    int n = 15; // Total number of students

    // a. Find top 10 toppers
    quickSort(s, 0, n - 1); // Sort the students by SGPA in descending order
    cout << "Top 10 Toppers:" << endl;
    display(s, 10); // Display the top 10 students

    // b. Search for students with a specific SGPA
    float sgpa; // SGPA to search for
    cout << "\nEnter SGPA to search: ";
    cin >> sgpa; // Input SGPA from the user
    searchSGPA(s, n, sgpa); // Search and display students with the entered SGPA

    return 0; // Exit the program
}
