//! Method - 1: Generate everything → remove duplicates later
class Solution {
private:
    void solve(int idx, vector<int> &nums, set<vector<int>> &st){
        if(idx >= nums.size()){
            st.insert(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            solve(idx+1, nums, st);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> vec;
        solve(0, nums, st);
        for(auto it : st){
            vec.push_back(it);
        }
        return vec;
    }
};

//! Method - 2: Avoid duplicates while generating
class Solution {
private:
    void solve(int idx, vector<int> &nums, vector<vector<int>> &ans){
        if(idx >= nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int i=idx; i<nums.size(); i++){
            if(used.count(nums[i])) continue;
            used.insert(nums[i]);
            swap(nums[idx], nums[i]);
            solve(idx+1, nums, ans);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};