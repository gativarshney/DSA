class DisjointSet{
    public:
    vector<int> size, parent;
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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DisjointSet ds(m * n);
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) continue;
                int node = i * n + j;
                for(int k=0; k<4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    int adjNode = nr * n + nc;
                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1){
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int maxArea = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int node = i * n + j;
                    int root = ds.findUPar(node);
                    maxArea = max(maxArea, ds.size[root]);
                }
            }
        }
        return maxArea;
    }
};
//* Time Complexity: O(m*n*4*α(m*n)) ~ O(m*n) where m and n are the dimensions of the grid, and α is the inverse Ackermann function which is very slow growing and can be considered almost constant.
//* Space Complexity: O(m*n) for the Disjoint Set data structure.