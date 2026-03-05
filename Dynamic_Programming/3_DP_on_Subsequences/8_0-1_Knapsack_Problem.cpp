//! Recursion + Memoization
class Solution {
private:
    int solve(int idx, int W, vector<int> &val, vector<int> &wt, vector<vector<int>>&dp){
        if(idx == 0){
            if(wt[0] <= W) return val[0];
            return 0;
        }
        if(dp[idx][W] != -1) return dp[idx][W];
        int notTake = solve(idx-1, W, val, wt, dp);
        int take = -1e9;
        if(wt[idx] <= W) take = val[idx] + solve(idx-1, W-wt[idx], val, wt, dp);
        return dp[idx][W] = max(take, notTake);
        
    }
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return solve(n-1, W, val, wt, dp);
    }
};9
// Time Complexity: O(N*W) where N is the number of items and W is the capacity of the knapsack.
// Space Complexity: O(N*W) for the dp array and O(N) for the recursion stack.

//! Tabulation 
class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        for(int i=wt[0]; i<=W; i++) dp[0][i] = val[0];
        for(int idx=1; idx<n; idx++){
            for(int maxWt=0; maxWt<=W; maxWt++){
                int notTake = dp[idx-1][maxWt];
                int take = -1e9;
                if(wt[idx] <= maxWt) take = val[idx] + dp[idx-1][maxWt-wt[idx]];
                dp[idx][maxWt] = max(take, notTake);
            }
        }
        return dp[n-1][W];
    }
};
// Time Complexity: O(N*W) where N is the number of items and W is the capacity of the knapsack.
// Space Complexity: O(N*W) for the dp array.

//! Space Optimization
class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        if(n == 0) return 0;
        vector<int> prev(W+1, 0), curr(W+1, 0);
        for(int i=wt[0]; i<=W; i++) prev[i] = val[0];
        for(int idx=1; idx<n; idx++){
            for(int maxWt=0; maxWt<=W; maxWt++){
                int notTake = prev[maxWt];
                int take = -1e9;
                if(wt[idx] <= maxWt) take = val[idx] + prev[maxWt-wt[idx]];
                curr[maxWt] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[W];
    }
};
// Time Complexity: O(N*W) where N is the number of items and W is the capacity of the knapsack.
// Space Complexity: O(W) for the dp arrays.

//! Using only one array for space optimization
class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        if(n == 0) return 0;
        vector<int> prev(W+1, 0), curr(W+1, 0);
        for(int i=wt[0]; i<=W; i++) prev[i] = val[0];
        for(int idx=1; idx<n; idx++){
            for(int maxWt=W; maxWt>=0; maxWt--){
                int notTake = prev[maxWt];
                int take = -1e9;
                if(wt[idx] <= maxWt) take = val[idx] + prev[maxWt-wt[idx]];
                prev[maxWt] = max(take, notTake);
            }
        }
        return prev[W];
    }
};
// Time Complexity: O(N*W) where N is the number of items and W is the capacity of the knapsack.
// Space Complexity: O(W) for the dp array.
//* One array is enough because we are iterating from right to left for the maxWt, so we are not overwriting the values that we need to use in the iteration. 

//! Why 0/1 Knapsack uses BACKWARD iteration? - Because each item can be taken ONLY ONCE
//? If you go forward, you might reuse the same item multiple times 👉 That turns it into Unbounded Knapsack (WRONG)


//* In 0/1 Knapsack we iterate backward to prevent using the same item multiple times, while in Unbounded Knapsack we iterate forward to allow reuse of the same item.