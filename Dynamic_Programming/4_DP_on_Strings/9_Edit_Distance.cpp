//! Recursion + Memoization
class Solution {
private:
    int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = f(i-1, j-1, word1, word2, dp);
        return dp[i][j] = 1 + min(f(i-1, j-1, word1, word2, dp), min(f(i-1, j, word1, word2, dp), f(i, j-1, word1, word2, dp)));
    } 
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, word1, word2, dp);
    }
};
// Time Complexity: O(m*n) where m and n are the lengths of the strings word1 and word2 respectively.
// Space Complexity: O(m*n) for the dp array and O(m+n) for the recursion stack

//! Tabulation
class Solution { 
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=0; i<=m; i++) dp[i][0] = i;
        for(int j=0; j<=n; j++) dp[0][j] = j;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[m][n];
    }
};
// Time Complexity: O(m*n) where m and n are the lengths of the strings word1 and word2 respectively.
// Space Complexity: O(m*n) for the dp array

//! Space Optimization
class Solution { 
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for(int j=0; j<=n; j++) prev[j] = j;
        for(int i=1; i<=m; i++){
            curr[0] = i;
            for(int j=1; j<=n; j++){
                if(word1[i-1] == word2[j-1]) curr[j] = prev[j-1];
                else curr[j] = 1 + min(prev[j-1], min(prev[j], curr[j-1]));
            }
            prev = curr;
        }
        return prev[n];
    }
};
// Time Complexity: O(m*n) where m and n are the lengths of the strings word1 and word2 respectively.
// Space Complexity: O(n) for the prev and curr arrays

//! Further Space Optimization is not possible as we need the values prev[j-1], prev[j] and curr[j-1] to calculate curr[j]. Hence, the space complexity cannot be reduced further.