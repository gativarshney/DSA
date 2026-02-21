//! Recursive Solution
class Solution {
private:
    int solve(int i, int j1, int j2, vector<vector<int>>&grid){
        int m = grid.size();
        int n = grid[0].size();
        if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) return -1e9;
        if(i == m-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        int maxi = -1e9;
        for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2=-1; dj2<=1; dj2++){
                int pos1 = j1 + dj1;
                int pos2 = j2 + dj2;
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += solve(i+1, pos1, pos2, grid);
                maxi = max(maxi, value);
            }
        }
        return maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solve(0, 0, n-1, grid);
    }
};
//Time Complexity: O(9^(m*n)) -> Exponential
//Space Complexity: O(m) -> Recursive Stack Space

//! Memoization Solution
class Solution {
private:
    int solve(int i, int j1, int j2, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){
        int m = grid.size();
        int n = grid[0].size();
        if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) return -1e9;
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        if(i == m-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        int maxi = -1e9;
        for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2=-1; dj2<=1; dj2++){
                int pos1 = j1 + dj1;
                int pos2 = j2 + dj2;
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += solve(i+1, pos1, pos2, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(0, 0, n-1, grid, dp);
    }
};
//Time Complexity: O(m*n*n*9) -> O(m*n^2) -> Polynomial
//Space Complexity: O(m*n*n) + O(m) -> O(m*n^2) -> Polynomial

//! Tabulation Solution
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        for(int j1=0; j1<n; j1++){
            for(int j2=0; j2<n; j2++){
                if(j1 == j2) dp[m-1][j1][j2] = grid[m-1][j1];
                else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
        for(int i=m-2; i>=0; i--){
            for(int j1=0; j1<n; j1++){
                for(int j2=0; j2<n; j2++){
                    int maxi = -1e9;
                    for(int dj1=-1; dj1<=1; dj1++){
                        for(int dj2=-1; dj2<=1; dj2++){
                            int value = 0;
                            if(j1 == j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            int pos1 = j1 + dj1;
                            int pos2 = j2 + dj2;
                            if(pos1 < 0 || pos1 >= n || pos2 < 0 || pos2 >= n) continue;
                            value += dp[i+1][pos1][pos2];
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][n-1];
    }
};
// Time Complexity: O(m*n*n*9) -> O(m*n^2) -> Polynomial
// Space Complexity: O(m*n*n) -> O(m*n^2) -> Polynomial

//! Space Optimization Solution
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> front(n, vector<int>(n, 0));
        for(int j1=0; j1<n; j1++){
            for(int j2=0; j2<n; j2++){
                if(j1 == j2) front[j1][j2] = grid[m-1][j1];
                else front[j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
        for(int i=m-2; i>=0; i--){
            vector<vector<int>> curr(n, vector<int>(n, 0));
            for(int j1=0; j1<n; j1++){
                for(int j2=0; j2<n; j2++){
                    int maxi = -1e9;
                    for(int dj1=-1; dj1<=1; dj1++){
                        for(int dj2=-1; dj2<=1; dj2++){
                            int value = 0;
                            if(j1 == j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            int pos1 = j1 + dj1;
                            int pos2 = j2 + dj2;
                            if(pos1 < 0 || pos1 >= n || pos2 < 0 || pos2 >= n) continue;
                            value += front[pos1][pos2];
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][n-1];
    }
};
// Time Complexity: O(m*n*n*9) -> O(m*n^2) -> Polynomial
// Space Complexity: O(n*n) -> O(n^2) -> Polynomial