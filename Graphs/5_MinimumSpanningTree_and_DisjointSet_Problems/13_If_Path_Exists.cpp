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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u, v);
        }
        int sourceUPar = ds.findUPar(source);
        int destinationUPar = ds.findUPar(destination);
        if(sourceUPar == destinationUPar) return true;
        return false;
    }
};
// Time Complexity: O(E * α(N)) where E is the number of edges and α(N) is the inverse Ackermann function, which is very slow-growing and can be considered almost constant for practical purposes.
// Space Complexity: O(N) for the Disjoint Set data structure.