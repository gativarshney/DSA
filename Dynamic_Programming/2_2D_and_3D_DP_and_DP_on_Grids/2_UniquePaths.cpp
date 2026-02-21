//! Memoization
class Solution {
private: 
    int cal(int row, int col, vector<vector<int>> &dp){
        if(row < 0 || col < 0) return 0;
        if(row == 0 && col == 0) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        int up = cal(row-1, col, dp);
        int left = cal(row, col-1, dp);
        return dp[row][col] = up + left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return cal(m-1, n-1, dp);
    }
};
//* TC: O(m × n)
//* SC: O(m × n) for dp array + O(m-1 + n-1) for path length (recursive stack space) ≈ O(m × n)

//! Tabular Method
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) dp[0][0] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};