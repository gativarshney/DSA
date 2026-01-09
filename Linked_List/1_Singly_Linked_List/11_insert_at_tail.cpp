#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertArrToLL(vector<int> &arr){
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}
Node* insertTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* tail = new Node(val, temp);
    temp->next = tail;
    tail->next = nullptr;
    return head;
}

int main(){
    vector<int> arr = {11,22,33,123,34,1,34};
    // vector<int> arr = {};
    int value;
    cout << "Enter value to add on tail : ";
    cin >> value;
    Node* head = convertArrToLL(arr);
    head = insertTail(head, value);
    cout << "Linked List : ";
    print(head);
    return 0;
}