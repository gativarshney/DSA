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
        if(size[ulp_v] > size[ulp_u]){
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 2);
        unordered_map<int, int> stoneNodes;
        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int cnt = 0;
        for(auto it : stoneNodes){
            if(ds.findUPar(it.first) == it.first) cnt++;
        }
        return n - cnt;
    }
};
//* Time Complexity: O(N) + O(α(M)) ~ O(N) where {M is maxRow + maxCol} for iterating through the stones and performing union-find operations where N is the number of stones
//* Space Complexity: O(maxRow + maxCol) for the Disjoint Set data structure and the unordered map to

//! Intution: 
// We can treat each row and column as a node in a graph, and each stone as an edge connecting the corresponding row node and column node. The number of connected components in this graph will give us the number of groups of stones that are connected together. To remove the maximum number of stones, we can remove all but one stone from each connected component. Therefore, the number of stones that can be removed is equal to the total number of stones minus the number of connected components.

// Each row index is a node, Each column index is a node, A stone connects its row node and column node
// So each stone = an edge between: row_node  <---->  column_node

//? We are NOT storing stones in DSU.
//? We are storing: Row-nodes Column-nodes And each stone is just a bridge connecting a row-node and a column-node.

//* We have used map here to ensure that we only count the unique nodes (rows and columns) that are actually connected by stones. This is important because there may be rows or columns that do not have any stones, and we do not want to count those as separate components. By using a map, we can keep track of which nodes are involved in the connections and only count those when determining the number of connected components.

//! Important
// maxRow and maxCol are used to determine the size of the Disjoint Set data structure. We need to ensure that we have enough nodes to represent all the rows and columns. 
// So total number of rowNodes = maxRow + 1 and similarly for col. Thats why size of disjoint set is maxRow + maxCol + 2 as we need nodes here and not index.