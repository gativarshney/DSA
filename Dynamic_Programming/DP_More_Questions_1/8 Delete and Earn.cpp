class Solution {
    int solve(int idx, vector<int> &points, vector<int> &dp){
        if(idx >= points.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int notTake = solve(idx + 1, points, dp);
        int take = points[idx] + solve(idx + 2, points, dp);

        return dp[idx] = max(take, notTake);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        int maxElement = *max_element(nums.begin(), nums.end());

        vector<int> points(maxElement + 1, 0);
        for(int i = 0; i < n; i++){
            points[nums[i]] += nums[i];
        }

        vector<int> dp(maxElement + 2, -1);

        return solve(0, points, dp);
    }
};
// Time Complexity: O(n + m) + O(m) where n = size of nums, m = maxElement
// Space Complexity: O(m) + O(m) where m = maxElement

//! Similar to House Robber