class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[1] = 0;
        vector<int> parent(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 1});
        while(!minHeap.empty()){
            int node = minHeap.top().second;
            int d = minHeap.top().first;
            minHeap.pop();
            if(d > dist[node]) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(d + wt < dist[adjNode]){
                    dist[adjNode] = d + wt;
                    minHeap.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        vector<int> ans;
        if(dist[n] == INT_MAX) return {-1};
        int node = n;
        while(parent[node] != node){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        ans.push_back(dist[n]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// Time Complexity: O(E log V) + O(V) for path reconstruction
// Space Complexity: O(V) for distance, parent array and priority queue 

//! Question: 
//? Path from node 1 to node n with the shortest distance in a weighted undirected graph.
// If a path exists, return a list of integers where the first element is the total weight of the shortest path, and the remaining elements are the nodes along that path (from 1 to n). If no path exists, return a list containing only {-1}.
