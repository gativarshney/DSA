class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> bfs;
        int vis[n] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return bfs;
    }
};
// Time Complexity: O(N + 2*E)  where E is the number of edges in the graph.
// Space Complexity: O(3 * N) for the queue, bfs array and the visited array.