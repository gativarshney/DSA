#include<bits/stdc++.h>
using namespace std;

class QueueStackApproach1{
    stack<int> s1;
    stack<int> s2;

    public:
    // TC: O(2 * N)
    void push(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    //TC: O(1)
    void pop(){
        s1.pop();
    }
    int front(){
        return s1.top();
    }
    bool isEmpty(){
        return s1.empty();
    }
    int size(){
        return s1.size();
    }
};

//*  efficient push / costly pop approach
class QSApproach2{
    stack<int> s1, s2;
    
    public:

    void push(int x){
        s1.push(x);
    }
    void pop(){
        if(!s2.empty()){
            s2.pop();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }
    int front(){
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
};

int main(){
    QueueStack a;
    a.push(10);
    a.push(20);
    a.push(30);
    cout << "Top Element After push " << a.front() << endl;
    a.pop();
    cout <<  "Top element after pop " << a.front() << endl;
    return 0;
}