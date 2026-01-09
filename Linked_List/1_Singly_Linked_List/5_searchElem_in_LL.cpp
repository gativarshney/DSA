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

bool searchLL(Node* head, int k){
    while(head != NULL){
        if(head->data == k) return true;
        else{
            head = head->next;
        }
    }
    return false;
}
int main(){
    vector<int> arr = {11,22,33,44,55};
    Node* head = convertArrToLL(arr);
    int k;
    cout << "Enter Element to search : ";
    cin >> k;
    if(searchLL(head, k)){
        cout << "Element Found";
    }
    else{
        cout << "Element Not Found"; 
    }
    return 0;
}