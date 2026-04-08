//! Recursion with Memoization
class Solution {
private:
    int solve(int idx, vector<int>&arr, vector<int>&dp){
        int n = arr.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int notTake = solve(idx+1, arr, dp);
        int take = arr[idx] + solve(idx+2, arr, dp);
        return dp[idx] = max(notTake, take);
    }
public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, arr, dp);
    }
};

//! Tabulation
class Solution {
public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+2, 0);
        dp[n] = 0, dp[n+1] = 0;
        for(int idx=n-1; idx>=0; idx--){
            int notTake = dp[idx+1];
            int take = arr[idx] + dp[idx+2];
            dp[idx] = max(notTake, take);
        }
        return dp[0];
    }
};

//! Space Optimization
class Solution {
public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        int next2 = 0, next1 = 0;
        for(int idx=n-1; idx>=0; idx--){
            int notTake = next1;
            int take = arr[idx] + next2;
            int curr = max(notTake, take);
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
};