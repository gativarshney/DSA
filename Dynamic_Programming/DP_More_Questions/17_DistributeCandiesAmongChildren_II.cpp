//! Recursive
class Solution {
    int ways(int child, int n, int limit){
        if(child == 3 && n == 0) return 1;
        if(child >= 3 && n != 0) return 0;
        int ans = 0;
        for(int i = 0; i <= limit; i++){
            ans += ways(child+1, n - i, limit);
        }
        return ans;
    }
public:
    long long distributeCandies(int n, int limit) {
        return ways(0, n, limit);
    }
};
// Time Complexity: O(limit^3) since we are making three recursive calls for each child and each call can have up to 'limit' iterations.
// Space Complexity: O(1) since we are not using any additional data structures to store

//! Memoization
class Solution {
    int ways(int child, int n, int limit, vector<vector<int>> &dp){
        if(child == 3 && n == 0) return 1;
        if(child >= 3 && n != 0) return 0;
        if(n < 0) return 0;
        int ans = 0;
        if(dp[child][n] != -1) return dp[child][n];
        for(int i = 0; i <= limit; i++){
            ans += ways(child+1, n - i, limit, dp);
        }
        return dp[child][n] = ans;
    }
public:
    long long distributeCandies(int n, int limit) {
        vector<vector<int>> dp(4, vector<int>(n+1, -1));
        return ways(0, n, limit, dp);
    }
};
// Time Complexity: O(4*n*limit) since we are making three recursive calls for each child and each call can have up to 'limit' iterations, and we are also storing results for each child and n combination in the dp array.
// Space Complexity: O(4*n) due to the dp array and the recursive call stack in the worst case when all combinations of child and n are computed.

//! It will give TLE for large inputs, so we can optimize it using a maths + range counting approach.
// We can give each child the minimum number of candies (0) and then distribute the remaining candies one by one to each child until we reach the limit for each child or we run out of candies. This way we can ensure that we are giving the maximum number of candies to each child while still respecting the limit and the total number of candies available.