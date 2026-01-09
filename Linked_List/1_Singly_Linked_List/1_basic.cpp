#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public: 
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){
    vector<int> arr = {2,5,7,8};
    Node* y = new Node(arr[0]);
    cout << y->data << endl;        // returns the data stored at that memory point
    cout << y->next << endl;
    cout << y << endl;              // returns the memory value
    return 0;
}