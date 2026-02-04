class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];
            adj[u].push_back({v, price});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        while(!q.empty()){
            auto it =  q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stops > k) continue;         // we can have at most k stops, so if stops exceed k, we skip further processing
            for(auto itr : adj[node]){
                int adjNode = itr.first;
                int wt = itr.second;
                if(cost + wt < dist[adjNode] && stops <= k){    // stops <= k to ensure we do not exceed k stops
                    dist[adjNode] = cost + wt;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if(dist[dst] != INT_MAX) return dist[dst];
        return -1;
    }
};
//* Time Complexity: O(E) for BFS traversal where E is the number of edges
//* Space Complexity: O(N) for distance array and queue