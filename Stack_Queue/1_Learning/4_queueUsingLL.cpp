#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class queueLL {
    Node* start;  // front of the queue
    Node* end;    // rear of the queue
    int size;

public:
    queueLL() {
        start = nullptr;
        end = nullptr;
        size = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);
        if (start == nullptr && end == nullptr) {
            start = temp;
            end = temp;
        } else {
            end->next = temp;
            end = temp;
        }
        size += 1;
    }

    void pop() {
        if (start == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = start;
        start = start->next;
        if (start == nullptr){
            end = nullptr;
        }
        delete temp;
        size -= 1;
    }

    int front() {
        if (start == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return start->data;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return start == nullptr;
    }
};

int main() {
    queueLL q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;
    q.pop();
    cout << "Front after pop: " << q.front() << endl;
    cout << "Size: " << q.getSize() << endl;
    cout << "Is empty: " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}