//! Recursive approach
class Solution {
    int solve(int i, int j, vector<vector<char>> &mat, int &maxi){
        if(i >= mat.size() || j >= mat[0].size()) return 0;

        int right = solve(i, j+1, mat, maxi);
        int diagonal = solve(i+1, j+1, mat, maxi);
        int down = solve(i+1, j, mat, maxi);

        if(mat[i][j] == '1'){
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        return 0;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        solve(0, 0, matrix, maxi);

        return maxi*maxi;
    }
};

// Time Complexity: O(3^(m*n)) where m and n are the number of rows and columns in the matrix respectively.
// Space Complexity: O(m+n) for the recursive stack space.

//! Memoization approach
class Solution {
    int solve(int i, int j, vector<vector<char>> &mat, int &maxi, vector<vector<int>> &dp){
        if(i >= mat.size() || j >= mat[0].size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j+1, mat, maxi, dp);
        int diagonal = solve(i+1, j+1, mat, maxi, dp);
        int down = solve(i+1, j, mat, maxi, dp);


        if(mat[i][j] == '1'){
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        return dp[i][j] = 0;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        if(matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        solve(0, 0, matrix, maxi, dp);

        return maxi*maxi;
    }
};
// Time Complexity: O(m*n) where m and n are the number of rows and columns in the matrix respectively.
// Space Complexity: O(m*n) for the dp array and O(m+n) for the recursive stack space.

//! Tabulation approach
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int maxi = 0;
        
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){

                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];

                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }

        return maxi * maxi;
    }
};
// Time Complexity: O(m*n) where m and n are the number of rows and columns in the matrix respectively.
// Space Complexity: O(m*n) for the dp array.

//! Space optimized approach
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        int maxi = 0;
        
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){

                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];

                if(matrix[i][j] == '1'){
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                }
                else curr[j] = 0;
            }
            next = curr;
        }

        return maxi * maxi;
    }
};
// Time Complexity: O(m*n) where m and n are the number of rows and columns in the matrix respectively.
// Space Complexity: O(n) for the two 1D dp arrays.

