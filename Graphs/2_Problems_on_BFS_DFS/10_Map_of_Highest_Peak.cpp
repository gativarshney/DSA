class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> height(n, vector<int> (m));
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair< pair<int, int>, int >> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j] == 1){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                    height[i][j] = 0;
                }
            }
        }
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int h = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int r = row + dr[i];
                int c = col + dc[i];
                if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]){
                    height[r][c] = h + 1;
                    vis[r][c] = 1;
                    q.push({{r, c}, h+1});
                }
            }
        }
        return height;
    }
};