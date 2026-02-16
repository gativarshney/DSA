//! Uing DFS Traversal
class Solution {
private:
    void dfs(vector<vector<int>>& image, vector<vector<int>> &vis, int original, int color, int r, int c){
        int n = image.size();
        int m = image[0].size();
        vis[r][c] = 1;
        image[r][c] = color;
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int row = r + dr[i];
            int col = c + dc[i];
            if(row >= 0 && row < n && col >= 0 && col < m &&
            image[row][col] == original && !vis[row][col]){
                dfs(image, vis, original, color, row, col);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if(color == original) return image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        dfs(image, vis, original, color, sr, sc);
        return image;
    }
};
//* Time Complexity: O(N*M) + O(4*N*M) ~ O(N*M)
//* Space Complexity: O(N*M) + O(N*M) for the visited array and the recursion stack.

//! Using BFS Traversal
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int original = image[sr][sc];
        if(original == color) return image;
        queue<pair<int, int>> q;
        q.push({sr,sc});
        vector<vector<int>> vis(n, vector<int> (m, 0));
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vis[r][c] = 1; 
            image[r][c] = color;
            vector<int> dr = {-1, 0, 1, 0};
            vector<int> dc = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] == original && !vis[nr][nc]){
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};