class Solution {
private:
    void solve(int r, int c, vector<vector<int>>&maze, string &path, vector<string>&ans, vector<vector<int>>&vis){
        int n = maze.size();
        if(r < 0 || r >= n || c < 0 || c >= n) return;
        if(r == n-1 && c == n-1){
            ans.push_back(path);
            return;
        }
        if(maze[r][c] == 0) return;
        if(vis[r][c]) return;
        vis[r][c] = 1;
        path.push_back('D');
        solve(r+1, c, maze, path, ans, vis);
        path.pop_back();
        
        path.push_back('L');
        solve(r, c-1, maze, path, ans, vis);
        path.pop_back();
        
        path.push_back('R');
        solve(r, c+1, maze, path, ans, vis);
        path.pop_back();
        
        path.push_back('U');
        solve(r-1, c, maze, path, ans, vis);
        path.pop_back();
        
        vis[r][c] = 0;
    }
public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        if(maze[n-1][n-1] == 0) return ans;
        string path = "";
        vector<vector<int>> vis(n, vector<int>(n, 0));
        solve(0, 0, maze, path, ans, vis);
        return ans;
    }
};