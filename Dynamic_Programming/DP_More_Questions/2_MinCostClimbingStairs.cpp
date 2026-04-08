class Solution {
private:
    int solve(int idx, vector<int>&cost, vector<int> &dp){
        int n = cost.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = cost[idx] + min(solve(idx+1, cost, dp), solve(idx+2, cost, dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(solve(0, cost, dp), solve(1, cost, dp));
    }
};
// Time Complexity : O(n)
// Space Complexity : O(n) for recursion stack + O(n) for dp array = O(n) in case of memorization

//! Tabulation Code
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2, 0);
        dp[n] = 0, dp[n+1] = 0;
        for(int idx=n-1; idx>=0; idx--){
            dp[idx] = cost[idx] + min(dp[idx+1], dp[idx+2]);
        }
        return min(dp[0], dp[1]);
    }
};

//! Tabulation code indexing from 0 to n-1
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);
        dp[0] = cost[0], dp[1] = cost[1];
        for(int idx=2; idx<n; idx++){
            dp[idx] = cost[idx] + min(dp[idx-1], dp[idx-2]);
        }
        return min(dp[n-2], dp[n-1]);
    }
};

//! Space Optimization
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0], prev1 = cost[1];
        for(int idx=2; idx<n; idx++){
            int curr = cost[idx] + min(prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }
};