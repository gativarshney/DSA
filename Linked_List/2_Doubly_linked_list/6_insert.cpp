#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* insertBeforeHead(Node* head, int val){
    Node* temp = new Node(val);
    if(head == nullptr){
        return temp;
    }
    temp->next = head;
    head->back = temp;
    head = temp;
    return head;
}
Node* insertBeforeTail(Node* head, int val){
    Node* newNode = new Node(val);
    Node* temp = head;
    if(head == nullptr) return newNode;
    else if(head->next == nullptr){
        return insertBeforeHead(head, val);
    }
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next->back = newNode;
    temp->next = newNode;
    newNode->back = temp;
    return head;
}
Node* insertBeforeKthElement(Node* head, int val, int k){
    if(k < 1) return head;
    if(k == 1) return insertBeforeHead(head, val);
    
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    if(temp == nullptr) return head;        // 'k' is out of bounds, so do nothing.

    Node* newNode = new Node(val);
    Node* prevNode = temp->back;
    newNode->next = temp;
    newNode->back = prevNode;
    prevNode->next = newNode;
    temp->back = newNode;
    return head;
}
Node* insertBeforeNode(Node* head, Node* givenNode, int val){
    if(givenNode == nullptr) return head;
    if(givenNode == head) return insertBeforeHead(head, val);

    Node* newNode = new Node(val);
    Node* prevNode = givenNode->back;

    newNode->next = givenNode;
    newNode->back = prevNode;

    prevNode->next = newNode;
    givenNode->back = newNode;
    
    return head;
}

Node* arrToLL(vector<int> &arr){
    if(arr.empty()) return NULL;
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    vector<int> arr = {100,200,300,400};
    // vector<int> arr = {100};
    // vector<int> arr = {};

    Node* head = arrToLL(arr);
    // head = insertBeforeHead(head, 99);
    // head = insertBeforeTail(head, 399);
    // head = insertBeforeKthElement(head, 999, 6);
    head = insertBeforeNode(head, head->next->next, 99);
    print(head);
    return 0;
}