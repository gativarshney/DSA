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
Node* deleteHead(Node* head){
    if(head == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main(){
    vector<int> arr = {11,22,33,123,34,1,34};
    Node* head = convertArrToLL(arr);
    head = deleteHead(head);
    cout << "Linked List : ";
    print(head);
    return 0;
}