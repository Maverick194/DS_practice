#include <iostream>
// #include <algorithm>

using namespace std;

struct Student {
    int studentID;
    string name;
    double GPA;
};

int linearSearchNonRecursive(const Student students[], int size, int targetID) {
    for (int i = 0; i < size; ++i) {
        if (students[i].studentID == targetID) {
            return i; 
        }
    }
    return -1; 
}

int linearSearchRecursive(const Student students[], int size, int targetID, int index = 0) {
    if (index >= size) {
        return -1; 
    }

    if (students[index].studentID == targetID) {
        return index; 
    }

    return linearSearchRecursive(students, size, targetID, index + 1); 
}

int binarySearchNonRecursive(const Student students[], int size, int targetID) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (students[mid].studentID == targetID) {
            return mid; 
        } else if (students[mid].studentID < targetID) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; 
}


int binarySearchRecursive(const Student students[], int targetID, int left, int right) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (students[mid].studentID == targetID) {
        return mid; 
    } else if (students[mid].studentID < targetID) {
        return binarySearchRecursive(students, targetID, mid + 1, right); 
    } else {
        return binarySearchRecursive(students, targetID, left, mid - 1); 
    }
}

int main() {
    const int arraySize = 3;
    Student studentRecords[arraySize] = {
        {101, "Sushant", 3.5},
        {204, "Luffy", 3.2},
        {309, "Zoro", 3.9}
        // Add more student records as needed
    };


    int targetID = 101;

    int linearNonRecursiveResult = linearSearchNonRecursive(studentRecords, arraySize, targetID);
    cout << "Linear Search (Non-Recursive): Student found at index " << linearNonRecursiveResult << endl;

    int linearRecursiveResult = linearSearchRecursive(studentRecords, arraySize, targetID);
    cout << "Linear Search (Recursive): Student found at index " << linearRecursiveResult << endl;

    int binaryNonRecursiveResult = binarySearchNonRecursive(studentRecords, arraySize, targetID);
    cout << "Binary Search (Non-Recursive): Student found at index " << binaryNonRecursiveResult << endl;

    int binaryRecursiveResult = binarySearchRecursive(studentRecords, targetID, 0, arraySize - 1);
    cout << "Binary Search (Recursive): Student found at index " << binaryRecursiveResult << endl;

    return 0;
}
