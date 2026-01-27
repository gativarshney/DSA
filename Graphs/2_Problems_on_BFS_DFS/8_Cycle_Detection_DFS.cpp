class Solution {
private:
    bool detect(int node, int parent, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(detect(it, node, adj, vis)) return true;
            }
            else if(it != parent){
                return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        int E = edges.size();
        vector<vector<int>> adj(V);
        for(int i=0; i<E; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detect(i, -1, adj, vis) == true) return true;
            }
        }
        return false;
    }
};
// Time Complexity: O(V + 2*E) + O(V) + O(V) (for DFS traversal and building adjacency list and check visited)
// Space Complexity: O(V + 2*E) + O(V) (for adjacency list and visited array) + O(V) (for recursion stack in worst case)