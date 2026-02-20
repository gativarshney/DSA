//? Recusrion + Memoization
class Solution {
private:
    int solve(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&dp){
        int m = matrix.size(), n = matrix[0].size();
        if(j < 0 || j >= n) return INT_MAX/2;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == 0) return matrix[i][j];
        int above = matrix[i][j] + solve(i-1, j, matrix, dp);
        int left = matrix[i][j] + solve(i-1, j-1, matrix, dp);
        int right = matrix[i][j] + solve(i-1, j+1, matrix, dp);
        return dp[i][j] = min(above, min(left, right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int mini = INT_MAX;
        for(int k=0; k<n; k++){
            mini = min(mini, solve(m-1, k, matrix, dp));
        }
        return mini;
    }
};
// TC: O(m*n) + O(n) ~ O(m*n)
// SC: O(m*n) + O(m) ~ O(m*n)

//? Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                int above = 1e9, left = 1e9, right = 1e9;
                above = matrix[i][j] + dp[i-1][j];
                if(j-1 >= 0) left = matrix[i][j] + dp[i-1][j-1];
                if(j+1 < m) right = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min(above, min(left, right));
            }
        }
        int ans = dp[m-1][0];
        for(int i=1; i<n; i++){
            ans = min(ans, dp[m-1][i]);
        }
        return ans;
    }
};
// TC: O(m*n)
// SC: O(m*n)

//? Space Optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n, 0);
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            prev[i] = matrix[0][i];
        }
        for(int i=1; i<m; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                int above = 1e9, left = 1e9, right = 1e9;
                above = matrix[i][j] + prev[j];
                if(j-1 >= 0) left = matrix[i][j] + prev[j-1];
                if(j+1 < m) right = matrix[i][j] +prev[j+1];
                curr[j] = min(above, min(left, right));
            }
            prev = curr;
        }
        int ans = prev[0];
        for(int i=1; i<n; i++){
            ans = min(ans, prev[i]);
        }
        return ans;
    }
};
// TC: O(m*n)
// SC: O(n)