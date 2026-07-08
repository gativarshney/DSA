//! Graph + Binary Search on Answers

class Solution {
    bool canReach(vector<vector<int>>& dist, int limit){
        int n = dist.size();

        if(dist[0][0] < limit) return false;
        if(dist[n-1][n-1] < limit) return false;

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        q.push({0, 0});
        vis[0][0] = 1;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            if(r == n-1 && c == n-1) return true;

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < n && dist[nr][nc] >= limit && !vis[nr][nc]){
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        int maxDist = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            maxDist = max(maxDist, dist[r][c]);

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < n && dist[nr][nc] == -1){
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        int low = 0;
        int high = maxDist;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canReach(dist, mid)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return high;
    }
};

// Time Complexity: O(n² log n)
// Space Complexity: O(n²)