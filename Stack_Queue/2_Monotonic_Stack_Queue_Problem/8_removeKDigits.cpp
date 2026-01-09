class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n) return "0";
        string ans = "";
        stack<char> st;
        for(int i=0; i<n; i++){ //O(N)
            while(!st.empty() && k > 0 && (st.top()-'0' > num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k > 0){   // O(k)
            st.pop();
            k--;
        }
        while(!st.empty()){ // O(N)
            ans += st.top();
            st.pop();
        }
        while(ans.size() != 0 && ans.back() == '0') ans.pop_back(); 
        /// O(N) combining both above and below
        reverse(ans.begin(), ans.end());
        if(ans.empty()) return "0";
        return ans;
    }
};

// TC: O(3*N + k)
// SC: O(2*N)