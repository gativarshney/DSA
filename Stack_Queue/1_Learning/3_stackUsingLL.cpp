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

class StackLL {
    Node* top;
    int size;

public:
    StackLL() {
        top = nullptr;
        size = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size += 1;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size -= 1;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    StackLL st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.peek() << endl;
    st.pop();
    cout << "Top after pop: " << st.peek() << endl;
    cout << "Size: " << st.getSize() << endl;
    cout << "Is empty: " << (st.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}