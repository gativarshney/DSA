class Solution {
private:
    void solve(int idx, vector<int>& nums, int target, vector<int> &output, vector<vector<int>> & ans){
        if(target == 0){
            ans.push_back(output);
            return;
        }
        if(idx >= nums.size() || target < 0) return;

        output.push_back(nums[idx]);
        solve(idx, nums, target - nums[idx], output, ans);
        output.pop_back();

        solve(idx+1, nums, target, output, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, candidates, target, output, ans);
        return ans;
    }
};