//! Using Recursion & Memoization
class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int up = grid[i][j] + solve(i-1, j, grid, dp);
        int left = grid[i][j] + solve(i, j-1, grid, dp);
        return dp[i][j] = min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(m-1, n-1, grid, dp);
    }
};
//* TC: O(m*n) 
//* SC: O(m*n) + O(m+n) for recursion stack

//! Tabulation Method
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i > 0) up += dp[i-1][j];
                    else up += 1e9;
                    int left = grid[i][j];
                    if(j > 0) left += dp[i][j-1]; 
                    else left += 1e9;
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
//* TC: O(m*n) 
//* SC: O(m*n)

//! Space Optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, 0);
        for(int i=0; i<m; i++){
            vector<int> cur(n, 0);
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) cur[j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i > 0) up += prev[j];
                    else up += 1e9;

                    int left = grid[i][j];
                    if(j > 0) left += cur[j-1]; 
                    else left += 1e9;

                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};
//* TC: O(m*n)
//* SC: O(n)