class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[source.first][source.second] == 0) return -1;
        if(grid[destination.first][destination.second] == 0) return -1;
        if(source == destination) return 0;
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        vector<int> dr = {-1, 0, +1, 0};
        vector<int> dc = {0, +1, 0, -1};
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first, source.second}});
        dist[source.first][source.second] = 0;
        while(!q.empty()){
            int d = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && d + 1 < dist[nr][nc]){
                    dist[nr][nc] = d + 1;
                    if(nr == destination.first && nc == destination.second){
                        return dist[nr][nc];
                    }
                    q.push({dist[nr][nc], {nr, nc}}); 
                }
            }
        }
        return -1;
    }
};
//* Time Complexity: O(N*M) where N and M are the number of rows and columns of the grid
//* Space Complexity: O(N*M) for distance array and queue    
//! Question:
//? Find the shortest path in a binary maze from a source cell to a destination cell. (4 directional movements allowed) (1s represent open cells and 0s represent blocked cells). Return the length of the shortest path, or -1 if no such path exists.