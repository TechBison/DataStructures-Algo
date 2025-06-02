#include<bits/stdc++.h>
using namespace std;
/**********************************************
* Custom Array Queue Implementation in C++
* This code implements a queue using a dynamic array.
* It supports basic operations like enqueue, dequeue, peek, isEmpty, size, and display.
* - Enqueue: Adds an element to the rear of the queue.
* - Dequeue: Removes and returns the front element of the queue.
* - Peek: Returns the front element of the queue without removing it.
* - IsEmpty: Checks if the queue is empty.
* - Size: Returns the number of elements in the queue.
* - Display: Displays all elements in the queue.
* Time Complexity:
* - Enqueue: O(1) on average, O(n) in worst case (if resizing is needed)
* - Dequeue: O(1)
* - Peek: O(1)  
* - IsEmpty: O(1)
* - Size: O(1)
* Space Complexity: O(n) where n is the number of elements in the queue       
 **********************************************/

template<typename T>
class ArrayQueue {
    vector<T> arr;
    int frontIndex;
    int rearIndex;
    int currentSize;
public: 
    ArrayQueue() : frontIndex(0), rearIndex(-1), currentSize(0) {}

    void enqueue(T value) {
        if (currentSize == arr.size()) {
            
            vector<T> newArr(arr.size() * 2 + 1);
            for (int i = 0; i < currentSize; i++) {
                newArr[i] = arr[(frontIndex + i) % arr.size()];
            }
            arr = move(newArr);
            frontIndex = 0;
            rearIndex = currentSize - 1;
        }
        rearIndex = (rearIndex + 1) % arr.size();
        arr[rearIndex] = value;
        currentSize++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue underflow");
        }
        T value = arr[frontIndex];
        frontIndex = (frontIndex + 1) % arr.size();
        currentSize--;
        return value;
    }

    T peek() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return arr[frontIndex];
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    int size() {
        return currentSize;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < currentSize; i++) {
            cout << arr[(frontIndex + i) % arr.size()] << " ";
        }
        cout << endl;
    }
};
int main() {
    ArrayQueue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    cout << "Front element: " << queue.peek() << endl; 
    cout << "Queue size: " << queue.size() << endl; 
    
    queue.display();
    
    cout << "Dequeue element: " << queue.dequeue() << endl;
    queue.display(); 
    
    return 0;
}  