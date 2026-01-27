class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>> &vec ,int row0, int col0){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        vec.push_back({row-row0, col-col0});
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int r = row + dr[i];
            int c = col + dc[i];
            if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == 1){
                dfs(r, c, grid, vis, vec, row0, col0);
            }
        }
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
                
            }
        }
        return st.size();
    }
};
// Time Complexity: O(n*m) (for DFS traversal)
// Space Complexity: O(n*m) (for visited array and recursion stack + set to store distinct islands)