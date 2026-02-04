class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> time(n + 1, INT_MAX);
        time[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(t > time[node]) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int tm = it.second; 
                if(t + tm < time[adjNode]){
                    time[adjNode] = t + tm;
                    pq.push({time[adjNode], adjNode});
                }
            }
        }
        int totalTime = 0;
        for(int i=1; i<=n; i++){
            if(time[i] == INT_MAX) return -1;
            totalTime = max(totalTime, time[i]);
        }
        return totalTime;
    }
};
//* Time Complexity: O(E log V) where E is the number of edges and V is the number of vertices
//* Space Complexity: O(V + E) for adjacency list, time array and priority queue

// Dijkstra's Algorithm is used here to find the shortest path from the source node k to all other nodes in the graph. The algorithm efficiently updates the shortest known distances using a priority queue to always expand the least costly node next.