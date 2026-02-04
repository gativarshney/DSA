class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9 + 7;
        vector<vector<pair<int, long long>>> adj(n);
        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            long long t = roads[i][2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()){
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(time > dist[node]) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                long long t = it.second;
                if(time + t < dist[adjNode]){
                    dist[adjNode] = time + t;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if(time + t == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};
// Time Complexity: O((E + V) * logV)
// Space Complexity: O(E + V)