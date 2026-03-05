//! Recursion + Memoization
class Solution {
private:
    bool f(int idx, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(target == 0) return true;
        if(dp[idx][target] != -1) return dp[idx][target];
        if(idx == 0) return (nums[idx] == target);
        bool notTake = f(idx-1, target, nums, dp);
        bool take = false;
        if(nums[idx] <= target) take = f(idx-1, target-nums[idx], nums, dp);
        return dp[idx][target] = take | notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        if(sum % 2 == 1) return false;
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(n-1, target, nums, dp);
    }
};
// Time Complexity: O(n*sum)
// Space Complexity: O(n*sum) + O(n) (dp array + recursive stack space)

//! Tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        if(sum % 2 == 1) return false;
        int k = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
        for(int i=0; i<n; i++) dp[i][0] = true;
        if(nums[0] <= k) dp[0][nums[0]] = true;
        for(int idx=1; idx<n; idx++){
            for(int target=1; target<=k; target++){
                bool notTake = dp[idx-1][target];
                bool take = false;
                if(target >= nums[idx]) take = dp[idx-1][target - nums[idx]];
                dp[idx][target] = take | notTake;
            }
        }
        return dp[n-1][k];
    }
};
// Time Complexity: O(n*sum)
// Space Complexity: O(n*sum)

//! Space Optimization
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        if(sum % 2 == 1) return false;
        int k = sum / 2;
        vector<int> prev(k+1, 0), curr(k+1, 0);
        for(int i=0; i<n; i++) prev[0] = true;
        if(nums[0] <= k) prev[nums[0]] = true;
        for(int idx=1; idx<n; idx++){
            for(int target=1; target<=k; target++){
                bool notTake = prev[target];
                bool take = false;
                if(target >= nums[idx]) take = prev[target - nums[idx]];
                curr[target] = take | notTake;
            }
            prev = curr;
        }
        return prev[k];
    }
};
// Time Complexity: O(n*sum)
// Space Complexity: O(sum)