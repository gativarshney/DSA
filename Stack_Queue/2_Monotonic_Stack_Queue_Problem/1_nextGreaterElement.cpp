#include<bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int> nums){
    int n = nums.size();
    vector<int> ans(n, -1);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[j] > nums[i]){
                ans[i] = nums[j];
                break;
            }
        }
    }
    return ans;
}
// TC: O(N*N) SC: O(N)

vector<int> nextGreater(vector<int> nums){
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for(int i=n-1; i>=0; i--){
        if(st.empty()) ans[i] = -1;
        else{
            if(st.top() > nums[i]){
                ans[i] = st.top();
            }
            else{
                while(!st.empty() && st.top() <= nums[i]){
                    st.pop();
                }
                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
            }
        }
        st.push(nums[i]);
    }
    return ans;
}
//!  Minimised Code of this below

vector<int> nextGreater1(vector<int> nums){
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(nums[i]);
    }
    return ans;
}
//* TC: O(2*N) at max N elements can be removed from stack, SC: O(N)+ O(N) for stack

int main(){
    vector<int> nums = {4,12,5,3,1,2,5,3,1,2,4,6};
    vector<int> ans = nextGreater1(nums);
    cout << "{";
    for(int x : ans) cout << x << " ";
    cout << "}";
    return 0;
}
// ans = {12 -1 6 5 2 5 6 4 2 4 6 -1 }