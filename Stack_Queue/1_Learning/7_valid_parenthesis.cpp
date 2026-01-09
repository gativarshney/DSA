#include<bits/stdc++.h>
using namespace std;

// TC: O(N) SC: O(N)

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char ch = st.top();
                if(s[i] == ')' && ch == '(') st.pop();
                else if(s[i] == ']' && ch == '[') st.pop();
                else if(s[i] == '}' && ch == '{') st.pop();
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
int main(){
    Solution sol;
    string s = "[][]()){({()[]})}";
    if(sol.isValid(s)){
        cout << "Valid" << endl;
    }
    else{
        cout << "Invalid" << endl;
    }
    return 0;
}