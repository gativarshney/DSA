//! Graph with Binary Search
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

//! Graph with Priority Queue
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Multi-source BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                    dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Modified Dijkstra (Maximum Bottleneck Path)
        priority_queue<vector<int>> pq;
        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.push({dist[0][0], 0, 0});
        best[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int safeness = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (r == n - 1 && c == n - 1)
                return safeness;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n) {

                    int newSafeness = min(safeness, dist[nr][nc]);

                    if (newSafeness > best[nr][nc]) {
                        best[nr][nc] = newSafeness;
                        pq.push({newSafeness, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};
// Time Complexity: O(n² log n)
// Space Complexity: O(n²)

//? safenessSoFar = minimum distance to a thief on the path so far