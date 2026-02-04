class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;

        vector<int> dr = {-1, 0, +1, 0};
        vector<int> dc = {0, +1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(diff > effort[row][col]) continue;
            if(row == n-1 && col == m-1) return diff;   
            // return when we reach destination because if there was a better path, it would have been popped earlier as we are using min-heap
            for(int i=0; i<4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int absDiff = abs(heights[nr][nc] - heights[row][col]);
                    int newEffort = max(absDiff, diff);
                    if(newEffort < effort[nr][nc]){
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};
//* Time Complexity: O(N*M * 4 * log(N*M)) where N and M are the number of rows and columns of the grid
//* Space Complexity: O(N*M) for effort array and priority queue
