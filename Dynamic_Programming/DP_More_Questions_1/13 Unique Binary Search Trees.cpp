class Solution {
    int solve(int n, vector<int> &dp){   // n -> number of nodes
        if(n <= 1) return 1;

        if(dp[n] != -1) return dp[n];

        int ans = 0;
        // think i as root node
        for(int i = 1; i <= n; i++){
            ans += solve(i - 1, dp) * solve(n - i, dp);
        }

        return dp[n] = ans;
    }
public:
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)

//! Tabulation
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);

        dp[0] = 1;
        dp[1] = 1;

        // i -> number of nodes 
        // j -> root node
        for(int i = 2; i <= n; i++){
            int ans = 0;
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)


//! This is a *Catalan Number* problem. The number of unique BSTs that can be formed with n nodes is given by the nth Catalan number, which can be computed using dynamic programming. The recursive relation is based on choosing each node as the root and calculating the number of unique BSTs that can be formed with the left and right subtrees.