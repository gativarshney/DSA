class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>>&adj, vector<int>&vis, vector<int>&pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfsCheck(it, adj, vis, pathVis) == true) return true;
            }
            else if(pathVis[it]) return true;
        }
        pathVis[node] = 0;
        return false;
    }
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        int n = edges.size();
        vector<vector<int>> adj(V);
        for(int i=0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfsCheck(i, adj, vis, pathVis) == true) return true;
            }
        }
        return false;
    }
};
//* Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
//* Space Complexity: O(V) + O(V) + O(V) for the adjacency list and the two visited arrays.