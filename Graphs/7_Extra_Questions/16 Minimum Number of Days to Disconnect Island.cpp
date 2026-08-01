class DisjointSet{
    vector<int> size, parent;
    public:
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
    int numOfConnectedComponents(vector<vector<int>>& grid){

        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        DisjointSet ds(m * n);

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 1){

                    int node = n * i + j;

                    for(int k = 0; k < 4; k++){

                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                            int adjNode = nr * n + nc;
                            if(ds.findUPar(node) != ds.findUPar(adjNode)){
                                ds.unionBySize(node, adjNode);
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int node = i * n + j;
                    if(ds.findUPar(node) == node) cnt++;
                }
            }
        }

        return cnt;
    }
public:
    int minDays(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int cnt = numOfConnectedComponents(grid);

        if(cnt >= 2 || cnt == 0) return 0;

        vector<pair<int, int>> ones;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) ones.push_back({i, j});
            }
        }

        for(int i = 0; i < ones.size(); i++){
            int r = ones[i].first;
            int c = ones[i].second;

            grid[r][c] = 0;

            int comp = numOfConnectedComponents(grid);

            if(comp >= 2 || comp == 0) return 1;

            grid[r][c] = 1;
        }

        return 2;
    }
};