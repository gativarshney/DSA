class Solution {
    void solve(int idx, vector<int> &nums, vector<int> &output, set<vector<int>> &st){
        if(idx == nums.size()){
            st.insert(output);
            return;
        }
        solve(idx + 1, nums, output, st);

        output.push_back(nums[idx]);
        solve(idx + 1, nums, output, st);
        output.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> output;
        set<vector<int>> st;
        vector<vector<int>> ans;

        solve(0, nums, output, st);
        for(auto it : st){
            ans.push_back(it);
        }
        st.clear();
        return ans;
    }
};