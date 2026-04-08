class Solution {
private:
    int solve(int n, vector<int> &dp){
        if(n <= 1) return 0;
        if(dp[n] != -1) return dp[n];
        int minCost = INT_MAX;
        for(int i=1; i<n; i++){
            int cost = (i * (n-i)) + solve(i, dp) + solve(n-i, dp);
            minCost = min(minCost, cost);
        }
        return dp[n] = minCost;
    }
public:
    int minCost(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};