//! Using DFS Traversal
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int r = row + dr[i];
            int c = col + dc[i];
            if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == 1){
                dfs(r, c, vis, grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<m; i++){
            if(!vis[0][i] && grid[0][i] == 1) dfs(0, i, vis, grid);
            if(!vis[n-1][i] && grid[n-1][i] == 1) dfs(n-1, i, vis, grid);
        }
        for(int j=0; j<n; j++){
            if(!vis[j][0] && grid[j][0] == 1) dfs(j, 0, vis, grid);
            if(!vis[j][m-1] && grid[j][m-1] == 1) dfs(j, m-1, vis, grid);
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};
// Time Complexity: O(n*m) (for DFS traversal)
// Space Complexity: O(n*m) (for visited array and recursion stack)


//! Using BFS Traversal
class Solution {
public: 
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            if(!vis[0][i] && grid[0][i] == 1){
                q.push({0, i});
                vis[0][i] = 1;
            }
            if(!vis[n-1][i] && grid[n-1][i] == 1){
                q.push({n-1, i});
                vis[n-1][i] = 1;
            }
        }
        for(int j=0; j<n; j++){
            if(!vis[j][0] && grid[j][0] == 1){
                q.push({j, 0});
                vis[j][0] = 1;
            }
            if(!vis[j][m-1] && grid[j][m-1] == 1){
                q.push({j, m-1});
                vis[j][m-1] = 1;
            }
        }
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int r = row + dr[i];
                int c = col + dc[i];
                if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == 1){
                    vis[r][c] = 1;
                    q.push({r, c});
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};
// Time Complexity: O(n*m) (for BFS traversal)
// Space Complexity: O(n*m) (for visited array and queue)