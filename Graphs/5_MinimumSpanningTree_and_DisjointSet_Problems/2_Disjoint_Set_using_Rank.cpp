class DisjointSet{
    vector<int> rank, parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    //find ultimate parent
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    //union by rank
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
//* Time Complexity: O(4 * α) ~ O(1) for find and union operations where α is the Inverse Ackermann Function
//* Space Complexity: O(N) for parent and rank arrays

//! Intution: 
// In the union by rank approach, we attach the smaller tree (the one with lower rank) under the root of the larger tree (the one with higher rank). If both trees have the same rank, we can choose either one to be the new root and increment its rank by 1. This helps to keep the tree flat, which optimizes the time complexity of future find operations.
// Find Ultimate Parent: The findUPar function is used to find the ultimate parent (or representative) of a given node. It uses path compression to optimize the find operation, which helps to flatten the structure of the tree and speed up future operations.
// Compression is done by making every node on the path from the node to the root point directly to the root. This way, the next time we need to find the ultimate parent of any of those nodes, it will be a direct access, resulting in O(1) time complexity for subsequent find operations. Otherwise, without path compression, the time complexity for find operations can degrade to O(logN) and O(N) in the worst case (when the tree becomes a linear chain). With path compression, the amortized time complexity for find operations is O(α(N)), where α is the Inverse Ackermann Function, which grows very slowly and is practically constant for all reasonable values of N.