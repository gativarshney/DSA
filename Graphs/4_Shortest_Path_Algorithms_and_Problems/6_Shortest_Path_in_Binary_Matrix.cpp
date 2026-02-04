class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1) return -1;
        if(grid[n-1][m-1] == 1) return -1;
        if(n == 1 && m == 1) return 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0,0}});
        vector<vector<int>> visitedCells(n, vector<int>(m, INT_MAX));
        visitedCells[0][0] = 1;
        vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int cells = it.first;
            int row = it.second.first;
            int col = it.second.second;
            for(int i=0; i<8; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m 
                && grid[nr][nc] == 0 && cells + 1 < visitedCells[nr][nc]){
                    int ncell = cells + 1;
                    if(nr == n-1 && nc == m-1){
                        return ncell;
                    }
                    visitedCells[nr][nc] = ncell;
                    q.push({ncell, {nr, nc}});
                }
            }
        }
        return -1;
    }
};
//* Time Complexity: O(N*M) where N and M are the number of rows and columns of the grid
//* Space Complexity: O(N*M) for visitedCells array and queue

//! Further Optimised Verison
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        if(n == 1) return 1;

        queue<pair<int,int>> q;
        q.push({0,0});
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        vector<int> dr = {-1,-1,-1,0,0,1,1,1};
        vector<int> dc = {-1,0,1,-1,1,-1,0,1};

        int pathLength = 1;

        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto [row, col] = q.front();
                q.pop();

                for(int j = 0; j < 8; j++){
                    int nr = row + dr[j];
                    int nc = col + dc[j];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < n
                       && grid[nr][nc] == 0 && !visited[nr][nc]){

                        if(nr == n-1 && nc == n-1)
                            return pathLength + 1;

                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            pathLength++;
        }
        return -1;
    }
};
