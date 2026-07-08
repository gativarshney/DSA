class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &it : edges){
            adj[it[0]].push_back({it[1], it[2]});
        }

        const long long INF = 1e18;

        vector<vector<long long>> dist(n, vector<long long>(power + 1, INF));

        priority_queue<
        tuple<long long, int, int>,
        vector<tuple<long long, int, int>>,
        greater<tuple<long long, int, int>>
        > pq;

        dist[source][power] = 0;
        pq.push({0, source, power});

        while(!pq.empty()){
            auto [time, u, p] = pq.top();
            pq.pop();

            if(time != dist[u][p]) continue;

            if(p >= cost[u]){
                int np = p - cost[u];
            
                for(auto &[v, wt] : adj[u]){
                    long long newTime = time + wt;
            
                    if(newTime < dist[v][np]){
                        dist[v][np] = newTime;
                        pq.push({newTime, v, np});
                    }
                }
            }
        }

        long long bestTime = INF;
        int bestPower = -1;

        for (int p = 0; p <= power; p++) {
            if (dist[target][p] < bestTime) {
                bestTime = dist[target][p];
                bestPower = p;
            } 
            else if (dist[target][p] == bestTime) {
                bestPower = max(bestPower, p);
            }
        }

        if(bestTime == INF) return {-1, -1};

        return {bestTime, bestPower};
        
    }
};