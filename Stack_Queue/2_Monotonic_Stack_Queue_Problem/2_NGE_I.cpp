class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int> st;
        unordered_map<int, int> mpp;
        vector<int> ans(n, -1);
        for(int i=m-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mpp[nums2[i]] = -1;
            }
            else{
                mpp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0; i<n; i++){
            ans[i] = mpp[nums1[i]];
        }
        return ans;
    }
};
// TC: O(n + m)
// SC: O(n + 2*m)

