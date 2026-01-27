class Solution {
private:
    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int r = row + dr[i];
            int c = col + dc[i];
            if(r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O' && !vis[r][c]){
                dfs(r, c, board, vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<m; i++){
            if(board[0][i] == 'O' && !vis[0][i]) dfs(0, i, board, vis);
            if(board[n-1][i] == 'O' && !vis[n-1][i]) dfs(n-1, i, board, vis);
        }
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O' && !vis[i][0]) dfs(i, 0, board, vis);
            if(board[i][m-1] == 'O' && !vis[i][m-1]) dfs(i, m-1, board, vis);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// * Time Complexity: O(N*M) + O(4*N*M) ~ O(N*M)
//* Space Complexity: O(N*M) + O(N*M) for the visited array and the recursion stack.