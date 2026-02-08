class Solution {
private:
    bool isValid(int r, int c, int n){
        if(r >= 0 && r < n && c >= 0 && c < n) return  true;
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int start = grid[0][0];
        int end = grid[n-1][n-1];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<int> vis(n*n, 0);
        pq.push({start, {0,0}});
        vector<int> dr = {-1, 0, +1, 0};
        vector<int> dc = {0, +1, 0, -1};
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            int cost = row * n + col;
            if(vis[cost]) continue;
            vis[cost] = 1;
            if(row == n-1 && col == n-1) return node;
            for(int i=0; i<4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                int adjCost = nr * n + nc; 
                if(isValid(nr, nc, n) && !vis[adjCost]){
                    int temp = max(node, grid[nr][nc]);
                    pq.push({temp, {nr, nc}});
                }
            }
        }
        return max(start, end);
    }
};
//* Time Complexity: O(N^2 * log(N^2)) = O(N^2 * logN)
//* Space Complexity: O(N^2) for the priority queue and visited array.

// Using Dijkstra's algorithm to find the minimum time required to reach the bottom-right cell from the top-left cell, considering the water level at each cell.
//! Clean and Standard Code
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // Min-heap: {time, {row, col}}
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        pq.push({grid[0][0], {0,0}});
        dist[0][0] = grid[0][0];
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        while(!pq.empty()) {
            auto [time, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();
            if(r == n-1 && c == n-1) return time;
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newTime = max(time, grid[nr][nc]);
                    if(newTime < dist[nr][nc]) {
                        dist[nr][nc] = newTime;
                        pq.push({newTime, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};

//* Time Complexity: O(N^2 * log(N^2)) = O(N^2 * logN) due to the priority queue operations for each cell in the grid.
//* Space Complexity: O(N^2) for the priority queue and distance matrix.


//! Using Union-Find (Disjoint Set Union) 
//* To find the minimum time required to reach the bottom-right cell from the top-left cell, by connecting cells based on their water levels and checking connectivity between the start and end cells.

//? As this is a Dynamic connectivity problem. We are building connectivity gradually as threshold increases. 

class DisjointSet{
    vector<int> size, parent;
    public:
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<tuple<int,int,int>> cells;
        // Store (height, row, col)
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                cells.push_back({grid[r][c], r, c});
            }
        }
        sort(cells.begin(), cells.end());
        DisjointSet ds(n * n);
        vector<vector<int>> active(n, vector<int>(n, 0));      
        //* To keep track of active cells (cells that are submerged at the current water level means whose height is less than or equal to current water level)
        
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        for(auto &[height, r, c] : cells) {
            active[r][c] = 1;
            int node = r * n + c;
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && active[nr][nc]) {
                    int adjNode = nr * n + nc;
                    ds.unionBySize(node, adjNode);
                }
            }
            if(ds.findUPar(0) == ds.findUPar(n*n - 1)) return height;
        }
        return -1;
    }
};
//* Time Complexity: O(N^2 log(N^2)) = O(N^2 logN) due to sorting the cells and union-find operations.
//* Space Complexity: O(N^2) for the union-find data structure and active matrix.