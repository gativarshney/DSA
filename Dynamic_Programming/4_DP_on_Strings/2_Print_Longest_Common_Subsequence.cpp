class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        string ans = "";
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int i = m, j = n;
        while(i > 0 && j > 0){
            if(text1[i-1] == text2[j-1]){
                ans += text1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;        
    }
};
// Time Complexity: O(m*n) for dp array and O(m+n) for backtracking
// Space Complexity: O(m*n) for dp array and O(m+n) for backtracking


