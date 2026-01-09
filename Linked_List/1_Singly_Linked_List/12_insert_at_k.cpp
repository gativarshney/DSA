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
Node* insertK(Node* head, int val, int k){
    if(head == NULL){
        if(k == 1) return new Node(val);
        else return nullptr;
    }
    else if(k == 1){
        return new Node(val, head);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == k-1){
            Node* newNode = new Node(val, temp->next);
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
    head = insertK(head, 1000, 3);
    cout << "Linked List : ";
    print(head);
    return 0;
}