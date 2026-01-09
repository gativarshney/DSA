#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next1 = next;
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
        mover =  temp;
    }
    return head;
}
void printLL(Node* head){
    Node* mover = head;
    while(mover != nullptr){
        cout << mover->data << " ";
        mover = mover->next;
    }
}
Node* deleteValue(Node* head, int val){
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        if(temp->data == val){
            prev->next = prev->next->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {11,22,33,44,55,66,77};
    Node* head = convertArrToLL(arr);
    head = deleteValue(head, 28);
    printLL(head);
    return 0;
}