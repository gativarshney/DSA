class Solution {
    bool check(int maxEffort, vector<vector<int>>& heights){
        int m = heights.size();
        int n = heights[0].size();

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<vector<int>> vis(m, vector<int> (n, 0));
        vis[0][0] = 1;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            if(r == m-1 && c == n-1) return true;

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]){
                    int effort = abs(heights[r][c] - heights[nr][nc]);
                    if(effort <= maxEffort){
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        
        return false;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mini = min(mini, heights[i][j]);
                maxi = max(maxi, heights[i][j]);
            }
        }

        int low = 0;
        int high = maxi - mini;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(mid, heights)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};