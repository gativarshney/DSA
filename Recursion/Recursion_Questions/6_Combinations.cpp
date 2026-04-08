class Solution {
private:
    void solve(int idx, int k, vector<int> &nums, vector<vector<int>> &ans, vector<int> &output){
        if(output.size() == k){
            ans.push_back(output);
            return;
        }
        if(idx >= nums.size()) return;
        if(output.size() > k) return;
        solve(idx+1, k, nums, ans, output);
        output.push_back(nums[idx]);
        solve(idx+1, k, nums, ans, output);
        output.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if(k > n) return ans;
        vector<int> nums;
        for(int i=1; i<=n; i++){
            nums.push_back(i);
        }
        vector<int> output;
        solve(0, k, nums, ans, output);
        return ans;
    }
};