class Solution {
private:
    int f(int i, int j, string &s, string &str, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == str[j]){
            return dp[i][j] = 1 + f(i-1, j-1, s, str, dp);
        }
        return dp[i][j] = max(f(i-1, j, s, str, dp), f(i, j-1, s, str, dp));
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        string str = s;
        reverse(str.begin(), str.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return n - f(n-1, n-1, s, str, dp);
    }
};
// Time Complexity: O(n*n) for dp array and O(n+n) for recursion stack
// Space Complexity: O(n*n) for dp array and O(n+n) for recursion stack