class Solution {
    int solve(int n, vector<int> &dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = n;
        for(int i=1; i*i <= n; i++){
            ans = min(ans, 1 + solve(n - i*i, dp));
        }
        return dp[n] = ans;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

//! Tabulation
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int num = 1; num <= n; num++){
            for(int i=1; i*i <= n; i++){
                if(num - i*i < 0) break;
                dp[num] = min(dp[num], 1 + dp[num - i*i]);
            }
        }
        return dp[n];
    }
};
