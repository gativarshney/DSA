class Solution {
    const int NEG = -1e9;
    const int MOD = 1e9 + 7;
    const int MAXS = 1805;

    int solve(int i, int j, vector<string> &board, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) return NEG;
        if (board[i][j] == 'X') return NEG;

        if (i == 0 && j == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int val = 0;
        if (isdigit(board[i][j])) val = board[i][j] - '0';

        int left = solve(i, j - 1, board, dp);
        int up = solve(i - 1, j, board, dp);
        int diag = solve(i - 1, j - 1, board, dp);

        int best = max({left, up, diag});

        if(best == NEG) return dp[i][j] = NEG;

        return dp[i][j] = best + val;
    }

    int findNumWays(int i, int j, int score, vector<string> &board, vector<vector<vector<int>>> &dp) {

        if (score < 0) return 0;
        if (i < 0 || j < 0) return 0;
        if (board[i][j] == 'X') return 0;

        if (i == 0 && j == 0){
            return score == 0;
        }

        if (dp[i][j][score] != -1) return dp[i][j][score];

        int val = 0;
        if (isdigit(board[i][j])) val = board[i][j] - '0';

        int left = findNumWays(i, j - 1, score - val, board, dp);
        int up = findNumWays(i - 1, j, score - val, board, dp);
        int diag = findNumWays(i - 1, j - 1, score - val, board, dp);

        return dp[i][j][score] = ((left + up) % MOD + diag) % MOD;
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int maxScore = solve(n - 1, n - 1, board, dp);

        if (maxScore < 0) return {0, 0};

        vector<vector<vector<int>>> dp2(n, vector<vector<int>>(n, vector<int>(MAXS, -1)));

        int ways = findNumWays(n - 1, n - 1, maxScore, board, dp2);

        return {maxScore, ways};
    }
};
