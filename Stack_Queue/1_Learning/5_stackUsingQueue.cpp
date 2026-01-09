#include<bits/stdc++.h>
using namespace std;

class StackQ{
    queue<int> q;

    public:
    // TC: O(N)
    void push(int x){
        q.push(x);
        int n = q.size();
        for(int i=0; i<n-1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    // TC: O(1)
    void pop(){
        if(q.empty()) {
            cout << "Empty queue" << endl;
            return;
        }
        q.pop();
    }
    int top(){
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }
    bool isEmpty(){
        return q.empty();
    }
    int size(){
        return q.size();
    }
};

int main(){
    StackQ st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;
    st.pop();
    cout << "Top after pop: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;
    cout << "Is empty: " << (st.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}