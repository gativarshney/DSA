//! Recursion + Memoization
class Solution {
private:    
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        }
        return dp[i][j] = f(i-1, j, s, t, dp);
    }
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, s, t, dp);
    }
};
// Time Complexity: O(m*n) where m and n are the lengths of the strings s and t respectively.
// Space Complexity: O(m*n) for the dp array and O(m+n) for the recursion stack

//! Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<double>> dp(m+1, vector<double>(n+1, 0));
        for(int i=0; i<=m; i++) dp[i][0] = 1;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[m][n];
    }
};
// Time Complexity: O(m*n) where m and n are the lengths of the strings s and t respectively.
// Space Complexity: O(m*n) for the dp array
//* NOTE: We have used double data type for the dp array to avoid integer overflow, as the number of distinct subsequences can be very large. Finally, we cast the result back to int before returning. As, test case may include repeating characters in the string s, which can lead to a large number of distinct subsequences.

//! Space Optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<double> prev(n+1, 0), curr(n+1, 0);
        prev[0] = curr[0] = 1;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }
                else curr[j] = prev[j];
            }
            prev = curr;
        }
        return (int)prev[n];
    }
};
// Time Complexity: O(m*n) where m and n are the lengths of the strings s and t respectively.
// Space Complexity: O(n) for the dp arrays prev and curr

//! Space Optimization with 1D array
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<double> dp(n+1, 0);
        dp[0] = 1;
        for(int i=1; i<=m; i++){
            for(int j=n; j>=1; j--){
                if(s[i-1] == t[j-1]){
                    dp[j] = dp[j-1] + dp[j];
                }
            }
        }
        return (int)dp[n];
    }
};
// Time Complexity: O(m*n) where m and n are the lengths of the strings s and t respectively.
// Space Complexity: O(n) for the dp array 