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
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<pair<int, pair<int, int>>> edge;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            edge.push_back({w, {u, v}});
        }
        sort(edge.begin(), edge.end());
        DisjointSet ds(V);
        int mstWt = 0;
        for(auto it : edge){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionBySize(u, v);
                mstWt += wt;
            }
        }
        return mstWt;
    }
};
//* Time Complexity: O(E log E) for sorting the edges and O(E * 4 * α) ~ O(E) for iterating through the edges and performing union-find operations where α is the Inverse Ackermann Function
//* Space Complexity: O(V) for the Disjoint Set data structure and O(E) for storing the edges in the edge list