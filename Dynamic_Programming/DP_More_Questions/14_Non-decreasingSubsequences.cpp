class Solution {
    bool isNonDec(vector<int> arr){
        for(int i=1; i<arr.size(); i++){
            if(arr[i-1] > arr[i]) return false;
        }
        return true;
    }
    void solve(int idx, vector<int> &nums, vector<int> &output, set<vector<int>> &st){
        if(idx == nums.size()){
            if(output.size() < 2 || !isNonDec(output)) return;
            st.insert(output);
            return;
        }
        output.push_back(nums[idx]);
        solve(idx+1, nums, output, st);
        output.pop_back();

        solve(idx+1, nums, output, st);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        vector<int> output;
        solve(0, nums, output, st);
        vector<vector<int>> ans;
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};
//* Time Complexity: O(2^n * n^2)
// We generate all subsequences (2^n). For each, we check if it is non-decreasing (O(n))
// and insert into a set, which takes O(n log(2^n)) ≈ O(n^2).

//* Space Complexity: O(2^n * n)
// In the worst case, all subsequences are stored in the set.
// Additional O(n) space is used for recursion stack and output vector.                    