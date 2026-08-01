class Solution {
    int tr, tc, m, n, obs;

    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int visCells){

        if(i == tr && j == tc){
            int req = m * n - obs - 1;
            if(visCells == req) return 1;
            return 0;
        }

        if(i < 0 || i >= m || j < 0 || j >= n) return 0;

        if(grid[i][j] == -1) return 0;

        int ans = 0;
        if(!vis[i][j]){
            vis[i][j] = 1;
            visCells++;

            ans += dfs(i+1, j, grid, vis, visCells);
            ans += dfs(i, j+1, grid, vis, visCells);
            ans += dfs(i-1, j, grid, vis, visCells);
            ans += dfs(i, j-1, grid, vis, visCells);

            vis[i][j] = 0;
        }

        return ans;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int sr, sc;
        obs = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int curr = grid[i][j];

                if(curr == 1){
                    sr = i;
                    sc = j;
                }
                else if(curr == 2){
                    tr = i;
                    tc = j;
                }
                else if(curr == -1){
                    obs++;
                }

            }
        }

        int ans = dfs(sr, sc, grid, vis, 0);

        return ans;
    }
};