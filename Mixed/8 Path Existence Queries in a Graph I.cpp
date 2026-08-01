class DisjointSet{
    vector<int> size, parent;
    public:
    DisjointSet(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for(int i = 0; i <= n; i++){
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

        if(size[ulp_u] > size[ulp_v]){
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
        else{
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int q = queries.size();

        vector<bool> ans(q, false);
        DisjointSet ds(n);

        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] <= maxDiff){
                ds.unionBySize(i, i-1);
            }
        }

        for(int i = 0; i < q; i++){
            int u = queries[i][0];
            int v = queries[i][1];

            if(ds.findUPar(u) == ds.findUPar(v)){
                ans[i] = true;
            }
        }

        return ans;
    }
};
// TC: O(n + q * α(n)) where α is the inverse Ackermann function, which is very slow-growing and can be considered nearly constant for practical input sizes.
// SC: O(n) for the Disjoint Set data structure.