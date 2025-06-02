#include<bits/stdc++.h>
using namespace std;
/**********************************************
 * Custom Linked List Stack Implementation in C++
 * This code implements a stack using a singly linked list.
 * It supports basic operations like push, pop, peek, isEmpty, size, and display.
 * Time Complexity:
 * - Push: O(1)
 * - Pop: O(1)
 * - Peek: O(1)
 * - IsEmpty: O(1)
 * - Size: O(n) where n is the number of elements in the stack
 * Space Complexity: O(n) where n is the number of elements in the stack
 **********************************************/
template<typename T>    
class LinkedListStack {
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* topNode;
    int stackSize;
public:
    LinkedListStack() : topNode(nullptr), stackSize(0) {}

    void push(T value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        stackSize++;
    }

    T pop() {
        if (isEmpty()) {
            throw out_of_range("Stack underflow");
        }
        Node* temp = topNode;
        T value = temp->data;
        topNode = topNode->next;
        delete temp;
        stackSize--;
        return value;
    }

    T peek() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return topNode->data;
    }

    bool isEmpty() {
        return stackSize == 0;
    }

    int size() {
        return stackSize;
    }

    void display() {
        Node* current = topNode;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};
int main() {
    LinkedListStack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack elements after pushing 10, 20, 30: ";
    stack.display(); // Output: 30 20 10

    cout << "Top element (peek): " << stack.peek() << endl; // Output: 30

    cout << "Popped element: " << stack.pop() << endl; // Output: 30
    cout << "Stack elements after popping: ";
    stack.display(); // Output: 20 10

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: No
    cout << "Current stack size: " << stack.size() << endl; // Output: 2

    return 0;
}