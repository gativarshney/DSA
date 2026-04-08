class Solution {
private:
    long long mod = 1e9 + 7;
    bool isOutOfBoundary(int r, int c, int m, int n){
        if(r >= 0 && r < m && c >= 0 && c < n) return false;
        return true;
    }
    int dfs(int r, int c, int move, int m, int n, vector<vector<vector<long long>>> &dp){
        if(isOutOfBoundary(r, c, m, n)) return 1;
        if(move == 0) return 0;
        if(dp[move][r][c] != -1) return dp[move][r][c];
        int left = dfs(r, c+1, move-1, m, n, dp);
        int right = dfs(r, c-1, move-1, m, n, dp);
        int up = dfs(r-1, c, move-1, m, n, dp);
        int down = dfs(r+1, c, move-1, m, n, dp);
        return dp[move][r][c] = (((left + right) % mod) + ((up + down) % mod)) % mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long long mod = 1e9 + 7;
        vector<vector<vector<long long>>> dp(maxMove+1, vector<vector<long long>>(m, vector<long long>(n, -1)));
        long long ans = dfs(startRow, startColumn, maxMove, m, n, dp);
        int result = (int)(ans % mod);
        return result;
    }
};