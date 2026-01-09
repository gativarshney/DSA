// * Brute Force, TC: O(N*N) SC: O(N)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<=i+n-1; j++){
                int index = j % n;
                if(nums[index] > nums[i]){
                    ans[i] = nums[index];
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(2*n, -1);
        vector<int> ans(2*n, -1);
        stack<int> st;

        for(int i=0; i<n; i++){
            temp[i] = nums[i];
        }
        for(int i=n; i<2*n-1; i++){
            temp[i] = nums[i % n];
        }

        for(int i= temp.size()-1; i>=0; i--){
            while(!st.empty() && st.top() <= temp[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(temp[i]);
        }
        vector<int> res(n, -1);
        for(int i=0; i<n; i++){
            res[i] = ans[i];
        }
        return res;
    }
};
// TC: O(4*N) SC:O(4*N)

//* Most Optimised Solution
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for(int i = 2*n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i % n]) st.pop();
            if(i < n){
                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};
//! TC: O(4*N) SC: O(2*N)