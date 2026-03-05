class Solution {
private:
    int findWays(int idx, int sum, vector<int>& nums, vector<vector<int>>&dp){
        if(idx == 0){
            if(sum == 0 && nums[idx] == 0) return 2;
            if(sum == 0 || nums[idx] == sum) return 1;
            return 0;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int notTake = findWays(idx-1, sum, nums, dp);
        int take = 0;
        if(nums[idx] <= sum) take = findWays(idx-1, sum-nums[idx], nums, dp);
        return dp[idx][sum] = take + notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++) total += nums[i];
        if (abs(target) > total) return 0;  // If the absolute value of target is greater than total, it's impossible to achieve the target.
        if((total + target) % 2 != 0) return 0;

        int sum = (total + target) / 2;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return findWays(n-1, sum, nums, dp);
    }
};
// Time Complexity: O(N*sum) where N is the size of the array and sum is the target sum.
// Space Complexity: O(N*sum) for the dp array and O(N) for the recursion stack.