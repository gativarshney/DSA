class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> best(m, vector<int>(n, -1));

        if(grid[0][0] == 1) pq.push({health - 1, {0, 0}});
        else pq.push({health, {0, 0}});

        while(!pq.empty()){
            int h = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;

            pq.pop();

            if(h <= best[r][c]) continue;
            
            best[r][c] = h;

            if(h <= 0) continue;

            if(r == m-1 && c == n-1 && h >= 1) return true;

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && h >= 1){
                    if(grid[nr][nc] == 1){
                        pq.push({h - 1, {nr, nc}});
                    }
                    else{
                        pq.push({h, {nr, nc}});
                    }
                }
            }
        }

        return false;
    }
};

// TC: O(m * n * log(mn))
// SC: O(m * n)

//! This problem can also be solved without using priority queue.