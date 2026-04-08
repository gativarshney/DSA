class Solution {
private:
    void solve(int idx, vector<int>&nums, vector<int> output, vector<vector<int>> &ans){
        if(idx >=  nums.size()){
            ans.push_back(output);
            return;
        }
        solve(idx+1, nums, output, ans);
        int element = nums[idx];
        output.push_back(element);
        solve(idx+1, nums, output, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, nums, output, ans);
        return ans;
    }
};