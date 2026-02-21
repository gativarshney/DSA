//! Memoization
class Solution {
private: 
    int cal(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid){
        if(row >= 0 && col >= 0 && obstacleGrid[row][col] == 1) return 0;
        if(row < 0 || col < 0) return 0;
        if(row == 0 && col == 0) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        int up = cal(row-1, col, dp, obstacleGrid);
        int left = cal(row, col-1, dp, obstacleGrid);
        return dp[row][col] = up + left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        if(obstacleGrid[0][0] == 1) return 0;
        return cal(m-1, n-1, dp, obstacleGrid);
    }
};
//* TC: O(m × n)
//* SC: O(m × n) for dp array + O(m-1 + n-1) for path length (recursive stack space) ≈ O(m × n)

//! Tabular Method
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
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
//* TC: O(m × n)
//* SC: O(m × n) for dp array

//! Space Optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        vector<int> prev(n, 0);
        for(int i=0; i<m; i++){
            vector<int> cur(n, 0);
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1) cur[j] = 0;
                else if(i == 0 && j == 0) cur[j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = cur[j-1];
                    cur[j] = up + left;
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};
//* TC: O(m × n)
//* SC: O(n) for prev and cur arrays