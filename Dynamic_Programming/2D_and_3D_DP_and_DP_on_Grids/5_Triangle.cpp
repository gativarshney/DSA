//? Recursion and Memoization
class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        int n = triangle.size();
        if(i == n-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + solve(i+1, j, triangle, dp);
        int dia = triangle[i][j] + solve(i+1, j+1, triangle, dp);
        return dp[i][j] = min(down, dia);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, triangle, dp);
    }
};
// TC: O(n^2) 
// SC: O(n^2) + O(n) for recursion stack

//? Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int down = triangle[i][j] + dp[i+1][j];
                int dia = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, dia);
            }
        }
        return dp[0][0];
    }
};
// TC: O(n^2)
// SC: O(n^2)

//? Space Optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n, 0);        
        for(int i=0; i<n; i++){
            front[i] = triangle[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            vector<int> cur(n, 0);
            for(int j=i; j>=0; j--){
                int down = triangle[i][j] + front[j];
                int dia = triangle[i][j] + front[j+1];
                cur[j] = min(down, dia);
            }
            front = cur;
        }
        return front[0];
    }
};
// TC: O(n^2)
// SC: O(n)