class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n, 0);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(findUPar(u) == findUPar(v)) return;
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
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DisjointSet ds(m*n);
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int node = i * n + j;
                ds.size[node] = grid[i][j];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int node = i * n + j;
                if(grid[i][j] > 0){
                    for(int k=0; k<4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] > 0){
                            int adjNode = nr * n + nc;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }
        int maxFish = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int node = i * n + j;
                int ultimateParent = ds.findUPar(node);
                int fish = ds.size[ultimateParent];
                maxFish = max(maxFish, fish);
            }
        }
        return maxFish;
    }
};
// Time Complexity: O(m*n*α(m*n)) for traversing the grid and performing union operations.
// Space Complexity: O(m*n) for the Disjoint Set data structure.