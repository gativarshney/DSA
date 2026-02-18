// Maximum sum of non adjacent elements

//! Brute Force
class Solution {
private:
    int solve(int idx, vector<int> &nums){
        if(idx < 0) return 0;
        if(idx == 0) return nums[0];
        int pick = nums[idx] + solve(idx-2, nums);
        int notPick = solve(idx-1, nums);
        return max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(n-1, nums);
    }
};
// TC: O(2^n)
// SC: O(n) recursion stack

//! USing Memoization
class Solution {
private:
    int solve(int idx, vector<int> &nums, vector<int> &dp){
        if(idx < 0) return 0;
        if(idx == 0) return nums[0];
        if(dp[idx] != -1) return dp[idx];
        int pick = nums[idx] + solve(idx-2, nums, dp);
        int notPick = 0 + solve(idx-1, nums, dp);
        return dp[idx] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n-1, nums, dp);
    }
};
// TC: O(n)
// SC: O(n) recursion stack + O(n) for dp array

//! Using Tabulation (Bottom up)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i-2 >= 0) pick += dp[i-2];
            int notPick = 0 + dp[i-1];
            dp[i] = max(pick, notPick);
        }
        return dp[n-1];
    }
};
// TC: O(N), SC: O(N)

//! Space Optimisation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0, prev = nums[0];
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i > 1) pick += prev2;
            int notPick = 0 + prev;
            int curi = max(pick, notPick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};
// TC: O(N), SC: O(1)
