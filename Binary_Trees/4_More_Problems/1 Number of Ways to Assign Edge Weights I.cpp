class Solution {

    long long modPow(long long a, long long b) {
        long long res = 1;
        const int MOD = 1e9 + 7;

        while(b) {
            if(b & 1){
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            b = b >> 1;
        }

        return res;
    }

    void dfs(int node, int parent, int depth, vector<vector<int>>& adj, int &maxDepth){
        if(depth > maxDepth){
            maxDepth = depth;
        }
        for(auto it : adj[node]){
            if(it == parent) continue;
            dfs(it, node, depth + 1, adj, maxDepth);
        }
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n+1);

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int maxDepth = 0;

        dfs(1, -1, 0, adj, maxDepth);

        if(maxDepth == 0) return 0;

        return modPow(2, maxDepth - 1);
    }
};

// TC: O(n)
// SC: O(n)

/** 
Approach:
1. Build the tree using an adjacency list.
2. Run DFS from the root node (1) to find the maximum depth d.
3. The path from root to a deepest node contains exactly d edges.
4. Each edge can be assigned either 1 or 2, so total assignments are 2^d.
5. A path cost is odd when the number of edges assigned weight 1 (odd) is odd.
6. Exactly half of all assignments have an odd sum, so the answer is: 2^(d-1)
7. Compute 2^(d-1) mod (10^9+7) using binary exponentiation (modPow function).
**/