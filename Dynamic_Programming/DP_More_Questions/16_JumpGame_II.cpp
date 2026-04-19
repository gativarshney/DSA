class Solution {
    int solve(int idx, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(idx == n-1){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int minJumps = 1e9;
        for(int i = 1; i <= nums[idx]; i++){
            if(idx + i < n){
                minJumps = min(minJumps, 1 + solve(idx + i, nums, dp));
            }
        }
        return dp[idx] = minJumps;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};
// Time Complexity: O(n^2) in the worst case, where n is the size of the input array. This is because in the worst case, we may have to explore all possible jumps from each index.
// Space Complexity: O(n) due to the recursion stack and the dp array used for memoization.

//! It can be optimized to O(n) using a greedy approach, which is implemented in the next file (Greedy_Algorithm/7_Jumps_II.cpp).