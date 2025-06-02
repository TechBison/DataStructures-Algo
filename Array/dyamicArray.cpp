#include<bits/stdc++.h>
using namespace std;
class DynamicArray {
    int *arr;
    int capacity;
    int size;
public:
    DynamicArray(int cap = 2) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    void push_back(int value) {
        if (size == capacity) {
            // Double the capacity
            capacity *= 2;
            int *newArr = new int[capacity];
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[size++] = value;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

    int getSize() {
        return size;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};
int main() {
    DynamicArray arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    
    cout << "Element at index 0: " << arr.get(0) << endl; // Output: 10
    cout << "Element at index 1: " << arr.get(1) << endl; // Output: 20
    cout << "Element at index 2: " << arr.get(2) << endl; // Output: 30
    cout << "Size of array: " << arr.getSize() << endl; // Output: 3

    return 0;
