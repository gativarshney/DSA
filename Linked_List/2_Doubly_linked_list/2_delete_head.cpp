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
Node* deleteHead(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete(temp);
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
    vector<int> arr = {11,22,33,44,55,66};
    Node* head = arrToLL(arr);
    head = deleteHead(head);
    cout << "Linked List : ";
    print(head);
    return 0;
}