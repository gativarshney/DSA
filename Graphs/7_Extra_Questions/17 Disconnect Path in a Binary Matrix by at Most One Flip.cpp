class Solution {
    int m, n;
    
    bool dfs(int i, int j, vector<vector<int>> &grid){
        if(i == m-1 && j == n-1) return true;

        if(i >= m || j >= n || grid[i][j] == 0) return false;

        grid[i][j] = 0;

        return dfs(i + 1, j, grid) || dfs(i, j + 1, grid);
    }

public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if(dfs(0, 0, grid) == false) return true;

        grid[0][0] = 1;

        if(dfs(0, 0, grid) == false) return true;

        return false;
    }
};

// TC: O(m*n) for DFS traversal
// SC: O(m*n) for recursion stack in worst case