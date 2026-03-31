//! Recursion + Memoization
class Solution {
private:
    int f(int idx, int prevIdx, vector<int>& nums, vector<vector<int>> &dp){
        if(idx == nums.size()) return 0;
        if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];
        int notTake = 0, take = 0;
        notTake = f(idx+1, prevIdx, nums, dp);
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            take = 1 + f(idx+1, idx, nums, dp);
        }
        return dp[idx][prevIdx+1] = max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, nums, dp);
    }
};
// Time Complexity: O(n^2)  
// Space Complexity: O(n^2) + O(n) for recursion stack

//! Tabulation Method
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int idx = n-1; idx >= 0; idx--){
            for(int prevIdx = idx-1; prevIdx >= -1; prevIdx--){
                int notTake = 0, take = 0;
                notTake = dp[idx+1][prevIdx+1];
                if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
                    take = 1 + dp[idx+1][idx+1];
                }
                dp[idx][prevIdx+1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};
// +1 is done to handle the case when prevIdx is -1, as we cannot have negative index in dp array. So, in dp for every 2nd index we have done +1 t0 make it 0 based indexing. For example, when prevIdx is -1, we will access dp[idx][0] and when prevIdx is 0, we will access dp[idx][1] and so on.
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

//! Space Optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1, 0), curr(n+1, 0);
        for(int idx = n-1; idx >= 0; idx--){
            for(int prevIdx = idx-1; prevIdx >= -1; prevIdx--){
                int notTake = 0, take = 0;
                notTake = next[prevIdx+1];
                if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
                    take = 1 + next[idx+1];
                }
                curr[prevIdx+1] = max(take, notTake);
            }
            next = curr;
        }
        return next[0];
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n) + O(n) for curr and next arrays

//! Optimized Space using 1D array
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int idx=0; idx<n; idx++){
            for(int prev=0; prev<idx; prev++){
                if(nums[prev] < nums[idx]){
                    dp[idx] = max(dp[idx], 1 + dp[prev]);
                }
            }
        }
        return dp[n-1];
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)
//* Useful for tracing the longest increasing subsequence as well, as we can store the previous index in another array and backtrack to find the actual sequence.

//! Binary Search Method using lower_bound
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return temp.size();
    }
};
// Time Complexity: O(nlogn)
// Space Complexity: O(n)