//! Recursion + Memoization
class Solution {
private:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true;
        if(i >= 0 && j < 0) return false;
        if(i < 0 && j >= 0){
            for(int k=0; k<=j; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = f(i-1, j-1, s, p, dp);
        if(p[j] == '*') return dp[i][j] = f(i-1, j, s, p, dp) || f(i, j-1, s, p, dp);
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, s, p, dp);
    }
};
// Time Complexity: O(m*n) where m and n are the lengths of the strings s and p respectively.
// Space Complexity: O(m*n) for the dp array and O(m+n) for the recursion stack

//! Tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i=1; i<=m; i++) dp[i][0] = false;
        for(int j=1; j<=n; j++){
            bool flag = true;
            for(int k=1; k<=j; k++){
                if(p[k-1] != '*') flag = false;
            }
            dp[0][j] = flag;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
};
// Time Complexity: O(m*n) where m and n are the lengths of the strings s and p respectively.
// Space Complexity: O(m*n) for the dp array

//! Space Optimisation
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<bool> prev(n+1, false), curr(n+1, false);
        prev[0] = true;
        for(int j=1; j<=n; j++){
           prev[j] = prev[j-1] && (p[j-1] == '*');
        }
        for(int i=1; i<=m; i++){
            curr[0] = false;
            for(int j=1; j<=n; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') curr[j] = prev[j-1];
                else if(p[j-1] == '*') curr[j] = prev[j] || curr[j-1];
                else curr[j] = false;
            }
            prev = curr;
        }
        return prev[n];
    }
};
// Time Complexity: O(m*n) where m and n are the lengths of the strings s and p respectively.
// Space Complexity: O(n) for the prev and curr arrays