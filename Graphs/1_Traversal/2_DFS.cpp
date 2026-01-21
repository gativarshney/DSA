class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &ls, vector<int> &vis){
        vis[node] = 1;
        ls.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, ls, vis);
            }
        }
    }
public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ls;
        dfs(0, adj, ls, vis);
        return ls;
    }
};
// Time Complexity: O(V + 2*E)  where E is the number of edges in the graph.
// Space Complexity: O(V) for the visited array and the recursion stack, 
// where V is the number of vertices, E is the number of edges in the graph.

//!NOTE
// Each vertex is visited once → O(V).
// Each edge is explored once from the adjacency list.
// In an undirected graph, each edge appears twice, so total adjacency entries are 2E → O(2E).
// Hence total time is O(V + 2E), which simplifies to O(V + E).
// For directed graphs, each edge appears once, so total adjacency entries are E → O(E) 
// Hence total time is O(V + E) for directed graphs as well.