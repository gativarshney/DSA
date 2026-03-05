//! Recursion + Memoization
class Solution {
private:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return 0;
        else if(i < 0){
            int sum = 0;
            for(int k=0; k<=j; k++){    // sum of ASCII values of characters in s2 from index 0 to j
                sum += (int)(s2[k]);
            }
            return sum;
        }
        else if(j < 0){
            int sum = 0;
            for(int k=0; k<=i; k++){    // sum of ASCII values of characters in s1 from index 0 to i
                sum += (int)(s1[k]);
            }
            return sum;
        } 
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = f(i-1, j-1, s1, s2, dp);
        return dp[i][j] = min((int)(s1[i]) + (int)(s2[j]) + f(i-1, j-1, s1, s2, dp), min((int)(s1[i]) + f(i-1, j, s1, s2, dp), (int)(s2[j]) + f(i, j-1, s1, s2, dp)));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int m =  s1.size(), n = s2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, s1, s2, dp);
    }
};

// Time Complexity: O(m*n) where m and n are the lengths of the strings s1 and s2 respectively.
// Space Complexity: O(m*n) for the dp array and O(m+n) for the recursion stack

//! Optimised Recursion + Memoization
class Solution {
private:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp, vector<int> &prefixSum1, vector<int> &prefixSum2){
        if(i < 0 && j < 0) return 0;
        else if(i < 0) return prefixSum2[j];
        else if(j < 0) return prefixSum1[i];
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = f(i-1, j-1, s1, s2, dp, prefixSum1, prefixSum2);
        return dp[i][j] = min((int)(s1[i]) + (int)(s2[j]) + f(i-1, j-1, s1, s2, dp, prefixSum1, prefixSum2), min((int)(s1[i]) + f(i-1, j, s1, s2, dp, prefixSum1, prefixSum2), (int)(s2[j]) + f(i, j-1, s1, s2, dp, prefixSum1, prefixSum2)));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int m =  s1.size(), n = s2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<int> prefixSum1(m, 0), prefixSum2(n, 0);
        if(m > 0) prefixSum1[0] = s1[0];
        if(n > 0) prefixSum2[0] = s2[0];
        for(int k=1; k<m; k++) prefixSum1[k] = prefixSum1[k-1] + (int)(s1[k]);
        for(int k=1; k<n; k++) prefixSum2[k] = prefixSum2[k-1] + (int)(s2[k]);
        return f(m-1, n-1, s1, s2, dp, prefixSum1, prefixSum2);
    }
};
// Time Complexity: O(m*n) where m and n are the lengths of the strings s1 and s2 respectively.
// Space Complexity: O(m*n) for the dp array and O(m+n) for the recursion stack and prefixSum arrays

//! Tabulation
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m =  s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int j=1; j<=n; j++) dp[0][j] = dp[0][j-1] + (int)(s2[j-1]);
        for(int i=1; i<=m; i++) dp[i][0] = dp[i-1][0] + (int)(s1[i-1]);
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min((int)(s1[i-1]) + (int)(s2[j-1]) + dp[i-1][j-1], min((int)(s1[i-1]) + dp[i-1][j], (int)(s2[j-1]) + dp[i][j-1]));
            }
        }
        return dp[m][n];
    }
};
// Time Complexity: O(m*n) where m and n are the lengths of the strings s1 and s2 respectively.
// Space Complexity: O(m*n) for the dp array

//! Space Optimised 
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m =  s1.size(), n = s2.size();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for(int j=1; j<=n; j++) prev[j] = prev[j-1] + (int)(s2[j-1]);
        for(int i=1; i<=m; i++){
            curr[0] = prev[0] + (int)(s1[i-1]);
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
                else curr[j] = min((int)(s1[i-1]) + (int)(s2[j-1]) + prev[j-1], min((int)(s1[i-1]) + prev[j], (int)(s2[j-1]) + curr[j-1]));
            }
            prev = curr;
        }
        return prev[n];
    }
};
// Time Complexity: O(m*n) where m and n are the lengths of the strings s1 and s2 respectively.
// Space Complexity: O(n) for the prev and curr arrays
