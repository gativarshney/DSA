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
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string str = s;
        reverse(str.begin(), str.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(n-1, n-1, s, str, dp);
    }
};
// Time Complexity: O(n*n) for dp array and O(n+n) for recursion stack
// Space Complexity: O(n*n) for dp array and O(n+n) for recursion stack

//* Longest Palindromic Subsequence is same as longest common subsequence of the string and its reverse 
// A palindrome reads the same forward and backward.
// If P is a palindromic subsequence of S, then P will also appear in reverse(S) in the same order.
// Therefore, every palindromic subsequence of S is a common subsequence of S and reverse(S).
// Hence, the longest palindromic subsequence equals the longest common subsequence between S and reverse(S).