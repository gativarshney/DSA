//! Recursion + Memoization
class Solution {
int solve(int k, vector<int> &nums, vector<int> &dp){
    if(k < 0) return 0;
    if(k == 0) return 1;
    if(dp[k] != -1) return dp[k];
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        ans += solve(k - nums[i], nums, dp);
    }
    return dp[k] = ans;
}
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, -1);
        int ans = solve(target, nums, dp);
        return ans;
    }
};
// Time Complexity: O(N*K) where N is the size of the input array and K is the target value.
// Space Complexity: O(K) for the dp array and O(K) for the recursion stack

//! Tabulation
