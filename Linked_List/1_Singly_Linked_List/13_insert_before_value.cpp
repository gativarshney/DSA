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
Node* insertBeforeValue(Node* head, int el, int val){
    if(head == NULL){
        return nullptr;
    }
    if(head->data == val){
        return new Node(el, head);
    }
    Node* temp = head;
    while(temp->next != nullptr){
        if(temp->next->data == val){
            Node* newNode = new Node(el, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {11,22,33,123,34,1,34};
    // vector<int> arr = {};
    Node* head = convertArrToLL(arr);
    head = insertBeforeValue(head, 1000, 33);
    cout << "Linked List : ";
    print(head);
    return 0;
}