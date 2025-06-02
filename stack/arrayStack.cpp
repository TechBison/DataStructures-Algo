#include<bits/stdc++.h>
using namespace std;
/**********************************************
 * custom stack implementation using an dynamic array
 * functions:
 * - push(T value): Adds an element to the top of the stack.
 * - pop(): Removes and returns the top element of the stack.
 * - peek(): Returns the top element of the stack without removing it.
 * - isEmpty(): Checks if the stack is empty.
 * - size(): Returns the number of elements in the stack.
 * - display(): Displays all elements in the stack.
 * Time Complexity:
 * - push: O(1) on average, O(n) in worst case (if resizing is needed) 
 * - pop: O(1)
 * - peek: O(1)
 * - isEmpty: O(1)
 * Space Complexity: O(n) where n is the number of elements in the stack.
 */
template<typename T>

class ArrayStack {
    vector<T> arr;
    int topIndex;
public:

    ArrayStack() : topIndex(-1) {}

    void push(T value) {
        if (topIndex + 1 == arr.size()) {
            arr.push_back(value);
            topIndex++;
        } else {
            arr[++topIndex] = value;
        }
    }

    T pop() {
        if (topIndex < 0) {
            throw out_of_range("Stack underflow");
        }
        return arr[topIndex--];
    }

    T peek() {
        if (topIndex < 0) {
            throw out_of_range("Stack is empty");
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex < 0;
    }

    int size() {
        return topIndex + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= topIndex; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~ArrayStack() {}

};

int main() {
    ArrayStack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl; 
    cout << "Stack size: " << stack.size() << endl; 

    cout << "Popped element: " << stack.pop() << endl; 
    cout << "New top element: " << stack.peek() << endl; 
    stack.display(); 

    return 0;
}