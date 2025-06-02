#include<bits/stdc++.h>
using namespace std;
/**********************************************
 * Custom Linked List queue Implementation in C++
 * This code implements a queue using a singly linked list.
 * It supports basic operations like enqueue, dequeue, peek, isEmpty, size, and display.
 * same as ArrayQueue, but using a linked list instead of an array.
 * Time Complexity:
 * - Enqueue: O(1)  
 * - Dequeue: O(1)
 * - Peek: O(1)
 * - IsEmpty: O(1)
 * - Size: O(1)
 * Space Complexity: O(n) where n is the number of elements in the queue
 **********************************************/
template<typename T>
class LinkedListQueue {
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    int queueSize;
public:
    LinkedListQueue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

    void enqueue(T value) {
        Node* newNode = new Node(value);
        if (rearNode) {
            rearNode->next = newNode;
        } else {
            frontNode = newNode; 
        }
        rearNode = newNode;
        queueSize++;
    }


    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue underflow");
        }
        Node* temp = frontNode;
        T value = temp->data;
        frontNode = frontNode->next;
        if (!frontNode) {
            rearNode = nullptr; 
        }
        delete temp;
        queueSize--;
        return value;
    }

    T peek() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return frontNode->data;
    }

    bool isEmpty() {
        return queueSize == 0;
    }

    int size() {
        return queueSize;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* current = frontNode;
        cout << "Queue elements: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};  

int main() {
    LinkedListQueue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.peek() << endl; 
    cout << "Queue size: " << queue.size() << endl; 
    queue.display();
    cout << "Dequeue element: " << queue.dequeue() << endl; 
    cout << "Front element after dequeue: " << queue.peek() << endl; 

    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl; 
    queue.display();
    return 0;
}