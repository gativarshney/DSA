class Solution {
    bool isValid(int r, int c, int m, int n){
        if(r >= 0 && c >= 0 && r < m && c < n) return true;
        return false;
    }
    bool solve(int r, int c, int idx, vector<vector<char>>&board, string &word, vector<vector<int>> &pathVis){
        int m = board.size();
        int n = board[0].size();
        if(idx == word.size() - 1){
            return (board[r][c] == word[idx]);
        }
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        if(board[r][c] == word[idx]){
            pathVis[r][c] = 1;
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(isValid(nr, nc, m, n) && !pathVis[nr][nc]){
                    if(solve(nr, nc, idx+1, board, word, pathVis)) return true;
                }
            }
            pathVis[r][c] = 0;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> pathVis(m, vector<int>(n, 0));
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                if(solve(r, c, 0, board, word, pathVis)) return true;
            }
        }
        return false;
    }
};

//* Time Complexity: O(m*n*4^L) where m and n are the dimensions of the board and L is the length of the word. In the worst case, we might explore all 4 directions for each character in the word.
//* Space Complexity: O(L) due to the recursive stack space, where L is the length of the word. Additionally, we use O(m*n) space for the pathVis vector to keep track of visited cells.


//! Optimized Solution without using extra space for visited cells
class Solution {
    bool solve(int r, int c, int idx, vector<vector<char>>&board, string &word){
        int m = board.size();
        int n = board[0].size();

        if(board[r][c] != word[idx]) return false;
        if(idx == word.size() - 1) return true;
        
        char temp = board[r][c];
        board[r][c] = '#';

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] != '#'){
                if(solve(nr, nc, idx+1, board, word)) return true;
            }
        }
        board[r][c] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                if(solve(r, c, 0, board, word)) return true;
            }
        }
        return false;
    }
};

//* Time Complexity: O(m*n*4^L) where m and n are the dimensions of the board and L is the length of the word. In the worst case, we might explore all 4 directions for each character in the word.
//* Space Complexity: O(L) due to the recursive stack space, where L is the length of the word. We do not use any additional space for visited cells as we modify the board in place to mark visited cells.