class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if (k >= m + n - 2) return m + n - 2;

        vector<vector<int>> best(m, vector<int>(n, -1));

        queue<tuple<int, int, int>> q;
        q.push({0, 0, k});
        best[0][0] = k;

        int steps = 0;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [r, c, rem] = q.front();
                q.pop();

                if (r == m - 1 && c == n - 1) return steps;

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                    int newRem = rem - grid[nr][nc];

                    if (newRem < 0) continue;

                    if (best[nr][nc] >= newRem) continue;

                    best[nr][nc] = newRem;
                    q.push({nr, nc, newRem});
                }
            }

            steps++;
        }

        return -1;
    }
};

// TC: O(m * n * k)
// SC: O(m * n)