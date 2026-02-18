//! Memoization
class Solution {
private:
    int ways(int n, vector<int> &dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = ways(n-1, dp) + ways(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return ways(n, dp);
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)

//* Optimized using Tabulation with Space Optimization 
class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1, prev = 1;
        for(int i=2; i<=n; i++){
            int curi = prev2 + prev;
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)

//NOTE: The no. of ways for n == 0 is 1 because we choose not to take any step. So, we can say that there is 1 way to climb 0 steps which is to not take any step. This is the base case for our recursion and helps in calculating the number of ways.