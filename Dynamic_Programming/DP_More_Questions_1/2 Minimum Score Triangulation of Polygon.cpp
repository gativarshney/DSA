//! Recursive + Memoization
class Solution {
    int f(int i, int j, vector<int> &val, vector<vector<int>> &dp){
        if(i+1 == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int minScore = 1e9;

        for(int k = i + 1; k < j; k++){
            int score = val[i] * val[k] * val[j] + f(i, k, val, dp) + f(k, j, val, dp);
            minScore = min(minScore, score);
        }

        return dp[i][j] = minScore;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, n-1, values, dp);
    }
};
// TC: O(n^3) due to 3 nested loops
// SC: O(n^2) for the dp array + O(n) for the recursion stack

//! Tabulation
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = i+2; j < n; j++){

                int minScore = 1e9;

                for(int k = i + 1; k < j; k++){
                    int score = values[i] * values[k] * values[j] + dp[i][k] + dp[k][j];
                    minScore = min(minScore, score);
                }

                dp[i][j] = minScore;
            }
        }

        return dp[0][n-1];
    }
};
// TC: O(n^3) due to 3 nested loops
// SC: O(n^2) for the dp array