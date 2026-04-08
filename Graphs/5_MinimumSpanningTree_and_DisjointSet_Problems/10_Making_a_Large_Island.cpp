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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) continue;
                int node = i * n + j;
                for(int k=0; k<4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    int adjNode = nr * n + nc;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1){
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int maxArea = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) continue;
                int area = 0;
                unordered_set<int> st;
                for(int k=0; k<4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1){
                        int adjNode = nr * n + nc;
                        int ultimateParentNode = ds.findUPar(adjNode);
                        st.insert(ultimateParentNode);
                    }
                }
                for(auto it : st){
                    area += ds.size[it];
                }
                maxArea = max(maxArea, area + 1); 
            }
        }
        // What if all cells are 1, then we can take the size of any component as the answer.
        for(int i=0; i<n*n; i++){
            maxArea = max(maxArea, ds.size[ds.findUPar(i)]);
        }
        return maxArea;
    }
};
//* Time Complexity: O(n*n*4*α(n*n)) ~ O(n*n) where α is the inverse Ackermann function which is very slow growing and can be considered almost constant.
//* Space Complexity: O(n*n) for the Disjoint Set data structure.