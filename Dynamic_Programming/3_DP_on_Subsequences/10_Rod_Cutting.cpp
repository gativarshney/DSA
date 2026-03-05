//! Recursion + Memoization
class Solution {
private:
    int solve(int idx, int n, vector<int>&price, vector<vector<int>>&dp){
        if(idx == 0){
            return n * price[0];
        }
        if(dp[idx][n] != -1) return dp[idx][n];
        int notTake = solve(idx-1, n, price, dp);
        int take = -1e9;
        int rodLength = idx+1;
        if(rodLength <= n) take = price[idx] + solve(idx, n-rodLength, price, dp);
        return dp[idx][n] = max(take, notTake);
    }
public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(n-1, n, price, dp);
    }
};
// Time Complexity: O(N*N) where N is the length of the price array (or the length of the rod).
// Space Complexity: O(N*N) for the dp array and O(N) for the recursion stack.

//! Tabulation
class Solution {
public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        for(int i=0; i<=n; i++){
            dp[0][i] = i * price[0];
        }
        for(int idx=1; idx<n; idx++){
            for(int N=0; N<=n; N++){
                int notTake = dp[idx-1][N];
                int take = -1e9;
                int rodLength = idx+1;
                if(rodLength <= N) take = price[idx] + dp[idx][N-rodLength];
                dp[idx][N] = max(take, notTake);
            }
        }
        return dp[n-1][n];
    }
};
// Time Complexity: O(N*N) where N is the length of the price array (or the length of the rod).
// Space Complexity: O(N*N) for the dp array.

//! Space Optimization
class Solution {
public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for(int i=0; i<=n; i++){
            prev[i] = i * price[0];
        }
        for(int idx=1; idx<n; idx++){
            for(int N=0; N<=n; N++){
                int notTake = prev[N];
                int take = -1e9;
                int rodLength = idx+1;
                if(rodLength <= N) take = price[idx] + curr[N-rodLength];
                curr[N] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[n];
    }
};
// Time Complexity: O(N*N) where N is the length of the price array (or the length of the rod).
// Space Complexity: O(N) for the dp arrays.

//! 1-D Space Optimization
class Solution {
public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> prev(n+1, 0);
        for(int i=0; i<=n; i++){
            prev[i] = i * price[0];
        }
        for(int idx=1; idx<n; idx++){
            for(int N=0; N<=n; N++){
                int notTake = prev[N];
                int take = -1e9;
                int rodLength = idx+1;
                if(rodLength <= N) take = price[idx] + prev[N-rodLength];
                prev[N] = max(take, notTake);
            }
        }
        return prev[n];
    }
};
// Time Complexity: O(N*N) where N is the length of the price array (or the length of the rod).
// Space Complexity: O(N) for the dp array.