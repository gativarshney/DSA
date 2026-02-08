class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        vector<int> vis(V, 0);
        int sum  = 0;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int node = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            if(vis[node] == 1) continue; 
            vis[node] = 1;
            sum += w;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(!vis[adjNode]){
                    pq.push({wt, adjNode});
                }
            }
        }
        return sum;
    }
};
//* Time Complexity: O(E log E) + O(E log V) ~ O(E log V) 
//* Space Complexity: O(V) + O(V) + O(E) ~ O(E) for adjacency list, visited array and priority queue respectively.