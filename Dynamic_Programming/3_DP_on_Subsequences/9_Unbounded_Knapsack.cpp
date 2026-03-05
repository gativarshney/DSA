//! Recursion
// Time Complexity: O(2^N) == exponential where N is the number of items.
// Space Complexity: O(N) for the recursion stack.

//! Recursion + Memoization
int solve(int idx, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>>&dp){
    if(idx == 0){
        return (int)(w / weight[0]) * profit[0];
    }
    if(dp[idx][w] != -1) return dp[idx][w];
    int notTake = solve(idx-1, w, profit, weight, dp);
    int take = -1e9;
    if(weight[idx] <= w) take = profit[idx] + solve(idx, w-weight[idx], profit, weight, dp);
    return dp[idx][w] = max(take, notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return solve(n-1, w, profit, weight, dp);
}
// Time Complexity: O(N*W) where N is the number of items and W is the capacity of the knapsack.
// Space Complexity: O(N*W) + O(N) for dp array and recursion stack.

//! Tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1, 0));
    for(int i=0; i<=w; i++){
        dp[0][i] = ((int)(i / weight[0])) * profit[0];
    }
    for(int idx=1; idx<n; idx++){
        for(int wt=0; wt<=w; wt++){
            int notTake = dp[idx-1][wt];
            int take = -1e9;
            if(weight[idx] <= wt) take = profit[idx] + dp[idx][wt-weight[idx]];
            dp[idx][wt] = max(take, notTake);
        }
    }
    return dp[n-1][w];
}
// Time Complexity: O(N*W) where N is the number of items and W is the capacity of the knapsack.
// Space Complexity: O(N*W) for the dp array.

//! Space Optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int>prev(w+1, 0), curr(w+1, 0);
    for(int i=0; i<=w; i++){
        prev[i] = ((int)(i / weight[0])) * profit[0];
    }
    for(int idx=1; idx<n; idx++){
        for(int wt=0; wt<=w; wt++){
            int notTake = prev[wt];
            int take = -1e9;
            if(weight[idx] <= wt) take = profit[idx] + curr[wt-weight[idx]];
            curr[wt] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[w];
}
// Time Complexity: O(N*W) where N is the number of items and W is the capacity of the knapsack.
// Space Complexity: O(W) for the dp arrays.

//! 1-D Space Optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int>prev(w+1, 0);
    for(int i=0; i<=w; i++){
        prev[i] = ((int)(i / weight[0])) * profit[0];
    }
    for(int idx=1; idx<n; idx++){
        for(int wt=0; wt<=w; wt++){
            int notTake = prev[wt];
            int take = -1e9;
            if(weight[idx] <= wt) take = profit[idx] + prev[wt-weight[idx]];
            prev[wt] = max(take, notTake);
        }
    }
    return prev[w];
}
// Time Complexity: O(N*W) where N is the number of items and W is the capacity of the knapsack.
// Space Complexity: O(W) for the dp array.
//* Note: In the 1-D space optimization, we can directly update the `prev` array since we are only using the previous values for the current iteration. This is possible because we are iterating from left to right, ensuring that we do not overwrite values that are still needed for future calculations.
//? We overwrite the array so that current values become available for reuse immediately.