//* TC: O(1), SC: O(2 * N) as elements are stored in pair
class MinStack {
public:

    stack<pair<int,int>> st;

    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }
        else {
            int mini = min(val, st.top().second);
            st.push({val, mini});
        } 
    }
    void pop() {
        st.pop();
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
};

//! Learn this step take example of 15, 10 || mini = 10 but push 8 in stack
//* TC: O(1) SC: O(N) --> Optimised for space
class MinStack {
public:
    stack<long long> st;
    long long mini = INT_MAX;
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else{
            if(val >= mini) st.push(val);
            else{
                long long x = 2LL * val - mini;
                st.push(x);
                mini = val;
            }
        }
    }
    void pop() {
        if(st.empty()) return;
        if(st.top() >= mini) st.pop();
        else{
            mini = 2LL * mini - st.top();
            st.pop();
        }
        if(st.empty()) mini = INT_MAX;
    }
    int top() {
        if(st.top() >= mini) return st.top();
        return mini;
    }
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
