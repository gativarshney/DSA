//! Recursive Approach 
class Solution {
    int f(int i, int j, vector<int>& cuts){
        if(i > j) return 0;
        int mini = 1e9;

        for(int idx = i; idx <= j; idx++){
            int cost = cuts[j+1] - cuts[i-1] + f(i, idx-1, cuts) + f(idx+1, j, cuts);
            mini = min(mini, cost);
        }

        return mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        return f(1, c, cuts);
    }
};
// Time Complexity: Exponential (due to repeated computation of overlapping subproblems)
// Space Complexity: O(C) recursion stack depth

//! Recursive + Memoization
class Solution {
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i > j) return 0;
        int mini = 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        for(int idx = i; idx <= j; idx++){
            int cost = cuts[j+1] - cuts[i-1] + f(i, idx-1, cuts, dp) + f(idx+1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));

        return f(1, c, cuts, dp);
    }
};
// Time Complexity: O(C^3)
// Space Complexity: O(C^2) + O(C) recursion stack.

//! Tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

        for(int i = c; i >= 1; i--){
            for(int j = i; j <= c; j++){
                int mini = 1e9;

                for(int idx = i; idx <= j; idx++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][idx-1] + dp[idx+1][j];
                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }
};
// Time Complexity: O(C^3)
// Space Complexity: O(C^2) for the dp array.

//* NOTE: The order of filling the dp table is crucial.
// i goes from c -> 1 because we need dp[idx+1][j],
// and idx+1 > i, so rows below must already be computed.
//
// j goes from i -> c (forward) because we need dp[i][idx-1],
// and idx-1 < j, so smaller j values must already be computed.
// If j were reversed, dp[i][idx-1] might not be available yet.

//* Simply j --> R to L so it should be L to R in tabulation
//* and i --> R to L so it should be R to L in tabulation.