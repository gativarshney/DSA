//! Find the City With the Smallest Number of Neighbors at a Threshold Distance
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int> (n, INT_MAX));
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            matrix[u][v] = w;
            matrix[v][u] = w;
        }
        for(int i=0; i<n; i++){
            matrix[i][i] = 0;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX) continue;
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        int mini = INT_MAX;
        int city = -1;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(matrix[i][j] <= distanceThreshold) cnt++;
            }
            if(cnt <= mini){
                mini = cnt;
                city = i;
            }
        }
        return city;
    }
};
//* Time Complexity: O(n^3) due to the Floyd-Warshall algorithm used to compute the shortest paths between all pairs of cities.
//* Space Complexity: O(n^2) for the adjacency matrix used to store the shortest paths between all pairs of cities.

//! Using Dijkstra's Algorithm for each city to find the number of reachable cities within the distance threshold.
class Solution {    
private:
    void dijkstra(int src, vector<vector<pair<int,int>>> &adj, vector<int> &dist){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int mini = INT_MAX;
        int city = -1;
        for(int i=0; i<n; i++){
            vector<int> dist(n, INT_MAX);
            dijkstra(i, adj, dist);
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(dist[j] <= distanceThreshold) cnt++;
            }
            if(cnt <= mini){
                mini = cnt;
                city = i;
            }
        }
        return city;
    }
};