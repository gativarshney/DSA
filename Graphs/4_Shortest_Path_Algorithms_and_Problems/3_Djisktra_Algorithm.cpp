//! Djisktra's Algorithm Using Min-Heap (Priority Queue)
//? TIME COMPLEXITY : O(E log V) where E is the number of edges and V is the number of vertices in the graph.
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,4 int>>> minHeap;
        minHeap.push({0, src});
        while(!minHeap.empty()){
            int d = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            if(d > dist[node]) continue;    //! important check to avoid processing stale entries

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                if(d + edgeWt < dist[adjNode]){
                    dist[adjNode] = d + edgeWt;
                    minHeap.push({dist[adjNode], adjNode});
                }
            }
        }
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};
//* Time Complexity: O(E log V)
//* Space Complexity: O(V + E) for adjacency list + O(V) for distance array + O(V) for min-heap


//?****************************************************** */
//! Dijkstra's Algorithm using Set (Ordered Set)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        set<pair<int, int>> st;
        st.insert({0, src});
        while(!st.empty()){
            auto it = *(st.begin());
            int d = it.first;
            int node = it.second;
            st.erase(it);
            for(auto i : adj[node]){
                int adjNode = i.first;
                int edgeWt = i.second;
                if(d + edgeWt < dist[adjNode]){
                    if(dist[adjNode] !=  INT_MAX){
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = d + edgeWt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};
//* Time Complexity: O(E log V)
//* Space Complexity: O(V + E) for adjacency list + O(V) for distance array + O(V) for set


//! NOTE:
//? Dijkstra's algorithm is used to find the shortest path from a source vertex to all other vertices in a weighted graph with non-negative edge weights.
//! It does not work with graphs that have negative weight edges. As it will cause infinite loops.
// It uses a priority queue (min-heap) to efficiently get the next vertex with the smallest tentative distance.
// The algorithm iteratively relaxes the edges, updating the shortest known distances to each vertex until all vertices have been processed.
// If a vertex is unreachable from the source, its distance is marked as -1 in the final output.
