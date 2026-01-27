class Solution {
private:
    bool detect(int src, vector<vector<int>>& adj, vector<int>& vis){
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()){
            auto [node, parent] = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if(it != parent){
                    return true;
                }
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
                if(detect(i, adj, vis) == true) return true;
            }
        }
        return false;
    }
};
// Time Complexity: O(V + 2*E) + O(V) + O(V) (for BFS traversal and building adjacency list and check visited)
// Space Complexity: O(V + 2*E) + O(V) (for adjacency list and visited array) + O(V) (for queue in worst case)