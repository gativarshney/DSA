class DisjointSet{
    public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_v] > size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += ulp_v;
        } 
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraEdges = 0;
        DisjointSet ds(n);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)) extraEdges++;
            else ds.unionBySize(u, v);
        }
        int components = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i) components++;
        }
        int reqEdges = components - 1;
        if(extraEdges >= reqEdges){
            return reqEdges;
        }
        return -1;
    }
};
//* Time Complexity: O(N + E) for iterating through the connections and performing union-find operations where N is the number of nodes and E is the number of connections
//* Space Complexity: O(N) for the Disjoint Set data structure