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
vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& queries, int q){
    vector<vector<int>> grid(n, vector<int>(m, 0));
    DisjointSet ds(m * n);
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int cnt = 0;
    vector<int> ans;
    for(auto it : queries){
        int r = it[0];
        int c = it[1];
        if(grid[r][c] == 1){
            ans.push_back(cnt);
            continue;
        } 
        grid[r][c] = 1;
        cnt++;
        int node = r * m + c;
        for(int k=0; k<4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1){
                int adjNode = nr * m + nc;
                if(ds.findUPar(node) != ds.findUPar(adjNode)){
                    ds.unionBySize(node, adjNode);
                    cnt--;
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}
//* Time Complexity: O(q * 4 * α(n*m)) ~ O(q) where q is the number of queries and α is the inverse Ackermann function which is very slow growing and can be considered almost constant.
//* Space Complexity: O(n*m) for the grid and the Disjoint Set data structure.