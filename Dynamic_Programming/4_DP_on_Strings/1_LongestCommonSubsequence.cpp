// Recusrive ; exponential

//! Recursive + Memo
class Solution {
private:
    int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]) return dp[i][j] = 1 + f(i-1, j-1, text1, text2, dp);
        return dp[i][j] = max(f(i-1, j, text1, text2, dp), f(i, j-1, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, text1, text2, dp);
    }
};
// Time Complexity: O(m*n)
// Space Complexity: O(m*n) + O(m+n) for recursion stack and dp array

//! Tabulation
// In this we will shift the index by 1 to avoid negative indexing and we will start from 1 to m and 1 to n
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];   //! we will compare the characters at i-1 and j-1 because we have shifted the index by 1
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
// Time Complexity: O(m*n)
// Space Complexity: O(m*n) for dp array

//! Space Optimization
class Solution {
public:    
int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1] == text2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[n];
    }
};
// Time Complexity: O(m*n)
// Space Complexity: O(n) for dp array