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

Node* reverseLLBruteForce(Node* head){
    //* Time Complexity : O(2*N) 
    //! Only data is reverse
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    stack<int>st;
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
Node* reverseLinkedList(Node* head){
    //* Time Complexity : O(N) and SC : O(1)
    //! Links are reveresed (Best Optimal)
    if(head == NULL || head->next == NULL) return head;
    Node* current = head;
    Node* last = nullptr;
    while(current != nullptr){
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
    head = last->back;
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
    vector<int> arr = {1,2,3,4,5};
    // vector<int> arr = {1};

    Node* head = arrToLL(arr);
    // head = reverseLL(head);
    head = reverseLinkedList(head);
    print(head);
    return 0;
}